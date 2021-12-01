import rclpy
from rclpy.node import Node
import numpy as np
from random import gauss
from time import time, sleep
from abc import ABC, abstractmethod
import threading
from concurrent.futures import ThreadPoolExecutor
from rclpy.exceptions import ROSInterruptException

from jax import jacfwd
import jax.numpy as jnp

from std_msgs.msg import String
from trident_msgs.msg import State
from trident_msgs.srv import KalmanSensorService
from cola2_msgs.msg import Setpoints

class PosNode(Node, ABC):
    def __init__(self, name, pub_topic_name, interval,
                 start_state, start_covar, proc_noise, sensor_list,
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
        #timer_period = interval
        #self.timer = self.create_timer(timer_period, self.timer_callback)
        self.last_state_time = time()
        self.get_logger().info("If this shows up, the simulation messages are still being used for control vector")
        self.ctrl_vec_sub_ = self.create_subscription(Setpoints, ctrl_v_top_name, self.get_ctrl_vec, 10)
        
        # Inits for all the Kalman-related variables #
        #--------------------------------------------#
        self.state = np.copy(start_state)
        self.covar = np.copy(start_covar)
        self.proc_noise = np.copy(proc_noise)
        self.control_vec = np.zeros((ctrl_v_size,1))
        self.jacobian = jacfwd(self.state_trans)
        
        # Error detection on the different variables #
        #--------------------------------------------#
        assert(self.state.shape[1] == 1),\
               "Given state isn't vertical/isn't a vector!"
        state_size = self.state.shape[0]
        assert(self.covar.shape[0] == state_size and self.covar.shape[1] == state_size),\
               "Covariance matrix dimensions don't match state!"
        assert(self.proc_noise.shape[0] == state_size and self.proc_noise.shape[1] == state_size),\
               "Process noise matrix dimensions don't match state!"
               
        assert(type(sensor_list) == list),\
               "Sensor list isn't a list!"
        assert(all(isinstance(x, str) for x in sensor_list)),\
               "Not all items in the list are strings!"
        
        # Connect to each of the sensor list's services #
        #-----------------------------------------------#
        self.sensor_handles = []
        for service_name in sensor_list:
            cli = self.create_client(KalmanSensorService, service_name)
            while not cli.wait_for_service(timeout_sec=1.0):
                print(service_name,"is taking a while...")
            self.sensor_handles.append(cli)
        
        #----------------------------------------------------------------#
        # Following are some examples of inputs for the kalman variables #
        #----------------------------------------------------------------#
        '''A current state estimate (x), containing coordinates, orientation,
           and velocities. Initialized "upright", as is standard
                                             x   y   z   pit yaw rol dx  dy  dz  dp  dy  dr'''
        #np.transpose(np.array([[0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0.]]))
        
        '''A current estimate covariance (accuracy) matrix (P). The elementwise
           multiplication with an identity matrix initializes it to a
           "diagonal" array, making it a simple list of variances.
           If you're sending in standard deviations, you'll want to square them first!'''
        #np.multiply(
        #    np.array([[0.3, 0.3, 0.3, 0.2, 0.2, 0.2, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1]]),
        #    np.identity(12))
        
        '''A process noise covariance matrix (Q)'''
        #np.multiply(
        #    np.array([[0.3, 0.3, 0.3, 0.1, 0.1, 0.1, 0.2, 0.2, 0.2, 0.1, 0.1, 0.1]]),
        #    np.identity(12))
        
        '''A sensor list, containing some fake data for the four required points'''
        #[
        #    '/sensor/trilateration',
        #    '/sensor/computervision',
        #    '/sensor/pressure',
        #    '/sensor/imu',
        #]
    
    # The state transition function (predicting the next step)
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
    def service_call(self, sensor_handle, pred_state, pred_covar):
        req = KalmanSensorService.Request()
        req.state = pred_state.flatten().tolist()
        req.covar = pred_covar.flatten().tolist()
        try:
            # NOTE: This service call is blocking. This only works because rclpy.spin()
            # is called in a separate thread in main. The service calls are also called from a ThreadPoolExecutor,
            # so they won't block and will be handled simultaneously, which also works as an extra precaution against deadlocks.
            resp = sensor_handle.call(req)
            x_size = len(pred_state)
            y_size = len(resp.residual)

            return(np.reshape(resp.gain,               (x_size, y_size)),
                   np.reshape(resp.residual,           (-1,1)          ),
                   np.reshape(resp.observationmatrix,  (y_size, x_size)))
        except Exception as e:
                self.get_logger().info(f"Couldn't get values from a service: {e}")
    
    # This SHOULDN'T be changed! Returns both the new state and the jacobian
    # Jacobian through complex step differentiation
    # Source: https://se.mathworks.com/matlabcentral/fileexchange/18189-learning-the-extended-kalman-filter?s_tid=mwa_osa_a
    '''def jacobian_csd(self, func, state, dt):
        new_state = func(state, dt)
        n = state.shape[0]
        m = new_state.shape[0]
        A = np.zeros((m,n))
        
        dx = 1e-8
        for j in range(n):
            Dxj = (abs(state[j,0])*dx if state[j,0] != 0 else dx)
            x_plus = [(xi if k != j else xi + Dxj) for k, xi in enumerate(state.flatten().tolist())]
            A[:, j] = (func(np.transpose(np.array([x_plus])), dt) - new_state).flatten()/Dxj
        return (new_state, A)'''
    ''' h = n * pow(2,-51) # Just a small number here, I think?
    for k in range(n):
        state1 = np.copy(state).astype('complex64')
        state1[k, 0] = complex(state1[k, 0], h)
        A[:, k] = np.transpose((func(state1, dt)).imag/h) 
    return (new_state, A)'''
    
    # This SHOULDN'T be changed! This is the main function, handling EKF and sending state
    def spin(self):
        while True:
            # Predict new state (and get the state transition matrix thru Jacobian)
            dt = time() - self.last_state_time
            self.last_state_time = time()
            pred_state = np.array(self.state_trans(jnp.array(self.state).flatten(), dt).reshape(-1,1), dtype=float)
            #self.get_logger().info(np.array_str(pred_state))
            state_trans_mat = np.array(self.jacobian(jnp.array(self.state).flatten(), dt), dtype=float)
            #self.get_logger().info(np.array_str(state_trans_mat))
            #self.get_logger().info("State type: %s Matrix type: %s" % (str(type(pred_state)), str(type(state_trans_mat))))
            # Add noise
            pred_state += np.matmul(self.proc_noise, np.random.randn(pred_state.shape[0], 1))
            # Predict covariance of new state
            pred_covar = np.matmul(np.matmul(
                            state_trans_mat,
                            self.covar),
                            np.transpose(state_trans_mat)
                         ) + self.proc_noise


            # Send the service calls via the ThreadPoolExecutor
            pool_futures = self._service_call_pool.map(self.service_call,
                                                       self.sensor_handles,
                                                       [pred_state]*len(self.sensor_handles),
                                                       [pred_covar]*len(self.sensor_handles),
                                                       timeout=1)
            try:
                # Loop through the results
                for result, sensor in zip(list(pool_futures), self.sensor_handles):
                        # Get the values from the sensors
                        gain, resid, obs_mat = result
                        # Check for cheeky nans
                        if(np.isnan(gain).any() or np.isnan(resid).any() or np.isnan(obs_mat).any()):
                            raise Exception("The sensor ", sensor, " returned a NaN!")
                        # Update the state estimate
                        #print(gain, resid)
                        pred_state = pred_state + np.matmul(gain, resid)
                        # Update the covariance estimate
                        pred_covar = np.matmul(
                                        np.identity(pred_state.shape[0]) - np.matmul(
                                            gain,
                                            obs_mat),
                                        pred_covar)
            except Exception as e:
                self.get_logger().warn("Skipping sensor due to failure! Error:" + str(e))
                

            # # Here we go through all of the different sensors
            # # TODO: none of this truly is implemented yet, since no sensors!
            # for sensor in self.sensor_handles:
            #     try:
            #         # Get the values from the sensors
            #         gain, resid, obs_mat = self.service_call(sensor, pred_state, pred_covar)
            #         # Check for cheeky nans
            #         if(np.isnan(gain).any() or np.isnan(resid).any() or np.isnan(obs_mat).any()):
            #             raise Exception("The sensor",sensor,"returned a NaN!")
            #         # Update the state estimate
            #         #print(gain, resid)
            #         pred_state = pred_state + np.matmul(gain, resid)
            #         # Update the covariance estimate
            #         pred_covar = np.matmul(
            #                         np.identity(pred_state.shape[0]) - np.matmul(
            #                             gain,
            #                             obs_mat),
            #                         pred_covar)
            #     except Exception as e:
            #         self.get_logger().warn("Skipping sensor due to failure! " + str(e))
            
            # Finally, set the state and covariance to the new ones!
            self.state = pred_state
            self.covar = pred_covar
            
            # AND publish the new state
            self.state_publish()
            # Sleep until next update interval
            try:
                self._position_update_rate.sleep()
            except ROSInterruptException:
                break

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
