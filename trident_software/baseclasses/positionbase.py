import rclpy
from rclpy.node import Node
import numpy as np
from random import gauss
from time import time, sleep
from abc import ABC, abstractmethod
import threading
from concurrent.futures import ThreadPoolExecutor

from std_msgs.msg import String
from trident_msgs.msg import State
from trident_msgs.srv import BasicSensorService
from cola2_msgs.msg import Setpoints

class PosNode(Node, ABC):
    def __init__(self, name, pub_topic_name, interval,
                 start_state, predict_noise, sensor_list,
                 ctrl_v_size, ctrl_v_top_name):
                 
        # Basic inits to create node, publisher, and periodic func #
        #----------------------------------------------------------#
        super().__init__(name)
        self.declare_parameters(
            namespace='',
            parameters=[
                ('position_update_frequency', 10.0), # Hz
            ])
        # Load parameters
        self._position_update_frequency = self.get_parameter('position_update_frequency').get_parameter_value().double_value # Hz
        # Create the rate object at which the position node's spin loop operates at
        self._position_update_rate = self.create_rate(self._position_update_frequency)
        # Create a thread pool executor with 2 threads that will execute the service calls to the sensors
        self._service_call_pool = ThreadPoolExecutor(2)

        self.publisher_ = self.create_publisher(State, pub_topic_name, 10)
        
        self.last_state_time = time()
        self.get_logger().info("If this shows up, the simulation messages are still being used for control vector")
        self.ctrl_vec_sub_ = self.create_subscription(Setpoints, ctrl_v_top_name, self.get_ctrl_vec, 10)
        
        # Inits for all the Kalman-related variables #
        #--------------------------------------------#
        self.state = np.copy(start_state)
        self.predict_noise = np.copy(predict_noise)
        self.control_vec = np.zeros(ctrl_v_size)
        
        # Error detection on the different variables #
        #--------------------------------------------#
        state_size = np.size(start_state)
        noise_size = np.size(predict_noise)
        assert(np.size(predict_noise) == np.size(start_state)),\
               "Prediction noise array isn't same size as state array!"
               
        assert(type(sensor_list) == list),\
               "Sensor list isn't a list!"
        assert(all(isinstance(x, str) for x in sensor_list)),\
               "Not all items in the list are strings!"
        
        # Connect to each of the sensor list's services #
        #-----------------------------------------------#
        self.sensor_handles = []
        for service_name in sensor_list:
            cli = self.create_client(BasicSensorService, service_name)
            while not cli.wait_for_service(timeout_sec=1.0):
                print(service_name,"is taking a while...")
            self.sensor_handles.append(cli)
        
        #----------------------------------------------------------------#
        # Following are some examples of inputs for the kalman variables #
        #----------------------------------------------------------------#
        '''A current state estimate, containing coordinates, orientation,
           and velocities.
                   X   Y   Z  quatW quatX quatY quatZ  dX  dY  dZ  dRoll  dPtch  dHdng'''
        #np.array([0., 0., 0.,    0.,   0.,   0.,   0., 0., 0., 0.,    0.,    0.,    0.])
        
        '''A prediction noise array'''
        #np.array([0.3, 0.3, 0.3, 0.1, 0.1, 0.1, 0.1, 0.2, 0.2, 0.2, 0.1, 0.1, 0.1])
        
        '''A sensor list, containing some fake data for the four required points'''
        #[
        #    '/sensor/trilateration',
        #    '/sensor/computervision',
        #    '/sensor/pressure',
        #    '/sensor/imu',
        #]

    # The state transition function (predicting the next state)
    # This is only a placeholder, and should be changed in every implementation!
    @abstractmethod
    def state_trans(self, prev, dt):
        return prev

    # This is the control vector retreival function
    # Naturally, change in every implementation
    @abstractmethod
    def get_ctrl_vec(self, msg):
        pass
    
    # The topic publisher function
    # This too should be changed to an appropriate message!
    @abstractmethod
    def state_publish(self):
        msg = String()
        msg.data = "Change to a good message type, then put state here!"
        self.publisher_.publish(msg)
        self.get_logger().info('Publishing new state')
    
    # This SHOULDN'T be changed! This function calls and receives values from services
    def service_call(self, sensor_handle, pred_state):
        req = BasicSensorService.Request()
        req.state = pred_state.tolist()
        try:
            # NOTE: This service call is blocking. This only works because rclpy.spin()
            # is called in a separate thread in main. The service calls are also called from a ThreadPoolExecutor,
            # so they won't block and will be handled simultaneously, which also works as an extra precaution against deadlocks.
            resp = sensor_handle.call(req)

            return(np.array(resp.guess),
                   np.array(resp.noise))
        except Exception as e:
                self.get_logger().info(f"Couldn't get values from a service: {e}")
    
    # This SHOULDN'T be changed! This is the main function, handling EKF and sending state
    def spin(self):
        while True:
            # Predict new state using motor- and movement values
            dt = time() - self.last_state_time
            self.last_state_time = time()
            pred_state = self.state_trans(self.state, dt)
            
            # Create two nested arrays containing each sensor's guess and noise
            all_guesses = np.array(pred_state)
            all_noises  = np.array(self.predict_noise)

            # Send the service calls via the ThreadPoolExecutor
            pool_futures = self._service_call_pool.map(self.service_call,
                                                       self.sensor_handles,
                                                       [pred_state]*len(self.sensor_handles),
                                                       timeout=1)
            try:
                # Loop through the results
                for result, sensor in zip(list(pool_futures), self.sensor_handles):
                        # Get the values from the sensors
                        guess, noise = result
                        # Check for cheeky nans
                        if(np.isnan(guess).any() or np.isnan(noise).any()):
                            raise Exception("The sensor ", sensor, " returned a NaN!")
                        # Add the guess and noise values to their respective piles
                        all_guesses = np.vstack([all_guesses, guess])
                        all_noises  = np.vstack([all_noises,  noise])
            except Exception as e:
                self.get_logger().warn("Skipping sensor due to failure! Error:" + str(e))
            
            # The quaternions are special, and so must be computed separately
            # WARNING: Doing the quats separately means this base isn't entirely flexible!
            # Source: https://stackoverflow.com/questions/12374087/average-of-multiple-quaternions
            try:
                all_quats   = all_guesses[:,3:7]
                all_q_noise = all_noises[:,3:7]
                weights_sum_to_one = (1/all_q_noise) / np.sum((1/all_q_noise), axis=0)
                weighted_quat_T = np.transpose(all_quats * weights_sum_to_one)
                eigen_vecs = np.linalg.eig(np.matmul(weighted_quat_T, np.transpose(weighted_quat_T)))[1]
                largest_eigen_vec = eigen_vecs[:,0] # This is almost certainly wrong!
                
                # Finally, set the state to the new "composite" state.
                self.state = np.average(all_guesses, axis=0, weights=1/all_noises)
                self.state[3:7] = largest_eigen_vec
            except Exception as e:
                self.get_logger().warn("Skipping writing new value! Error:" + str(e))
            
            # AND publish the new state
            self.state_publish()
            # Sleep until next update interval
            self._position_update_rate.sleep()

def main(args=None):
    rclpy.init(args=args)
    
    pos_node = PosNode("unnamed_position_node", "unnamed_current_state", 1)
    # Create an executor thread that spins the node
    executor = MultiThreadedExecutor()
    executor.add_node(pos_node)
    executor_thread = threading.Thread(target=executor.spin)
    executor_thread.start()
    # Run the main loop in the node
    pos_node.spin()
    # Wait for the executor to finish
    executor_thread.join()
    
    rclpy.shutdown()

if __name__ == '__main__':
    main()
