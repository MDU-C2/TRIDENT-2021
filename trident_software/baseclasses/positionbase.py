import rclpy
from rclpy.node import Node
import numpy as np
from random import gauss
from time import time, sleep
from abc import ABC, abstractmethod

from trident_msgs.msg import State
from trident_msgs.srv import KalmanSensorService

class PosNode(Node, ABC):
    def __init__(self, name, pub_topic_name, interval,
                 start_state, start_covar, proc_noise, sensor_list):
                 
        # Basic inits to create node, publisher, and periodic func #
        #----------------------------------------------------------#
        super().__init__(name)
        self.publisher_ = self.create_publisher(State, pub_topic_name, 10)
        #timer_period = interval
        #self.timer = self.create_timer(timer_period, self.timer_callback)
        
        # Inits for all the Kalman-related variables #
        #-------------------------------------------#
        self.state = np.copy(start_state)
        self.covar = np.copy(start_covar)
        self.proc_noise = np.copy(proc_noise)
        
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
    def state_trans(self, prev, control_vec, dt):
        return prev
    
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
        req.state = list(pred_state.flatten())
        req.covar = list(pred_covar.flatten())
        try:
            future = sensor_handle.call_async(req)
            #rclpy.spin_until_future_complete(self, future)
            start_time = time()
            while rclpy.ok():
                rclpy.spin_once(self)
                if future.done():
                    resp = future.result()
                    x_size = len(pred_state)
                    y_size = len(resp.residual)
                    return(np.reshape(resp.gain,               (x_size, y_size)),
                           np.reshape(resp.residual,           (-1,1)          ),
                           np.reshape(resp.observationmatrix,  (y_size, x_size)))
                elif time() - start_time > 3:
                    raise Exception("Service took too long (more than three seconds)!")
        except Exception as e:
                print("Couldn't get values from a service:",e)
    
    # This SHOULDN'T be changed! Returns both the new state and the jacobian
    # Jacobian through complex step differentiation
    # Source: https://se.mathworks.com/matlabcentral/fileexchange/18189-learning-the-extended-kalman-filter?s_tid=mwa_osa_a
    def jacobian_csd(self, func, state, control, dt):
        new_state = func(state, control, dt) 
        n = state.shape[0]
        m = new_state.shape[0]
        A = np.zeros((m,n))
        h = n * pow(2,-51) # Just a small number here, I think?
        for k in range(n):
            state1 = state.astype('complex64')
            state1[k, 0] = complex(state1[k, 0], h)
            A[:, k] = np.transpose((func(state1, control, dt)).imag/h) 
        return (new_state, A)
    
    # This SHOULDN'T be changed! This is the main function, handling EKF and sending state
    def spin(self):
        while True:
            # Predict new state (and get the state transition matrix thru Jacobian)
            # TODO: add control vector
            pred_state, state_trans_mat = self.jacobian_csd(self.state_trans, self.state, 0, 1)
            # Add noise
            pred_state += np.matmul(self.proc_noise, np.random.randn(pred_state.shape[0], 1))
            # Predict covariance of new state
            pred_covar = np.matmul(np.matmul(
                            state_trans_mat,
                            self.covar),
                            np.transpose(state_trans_mat)
                         ) + self.proc_noise

            # Here we go through all of the different sensors
            # TODO: none of this truly is implemented yet, since no sensors!
            for sensor in self.sensor_handles:
                try:
                    # Get the values from the sensors
                    gain, resid, obs_mat = self.service_call(sensor, pred_state, pred_covar)
                    # Check for cheeky nans
                    if(np.isnan(gain).any() or np.isnan(resid).any() or np.isnan(obs_mat).any()):
                        raise Exception("The sensor",sensor,"returned a NaN!")
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
                    self.get_logger().warn("Skipping sensor due to failure! " + e)
            
            # Finally, set the state and covariance to the new ones!
            self.state = pred_state
            self.covar = pred_covar
            
            # AND publish the new state
            self.state_publish()
            
            sleep(0.5)

def main(args=None):
    rclpy.init(args=args)
    
    pos_node = PosNode("unnamed_position_node", "unnamed_current_state", 1)
    
    #rclpy.spin(main_node)
    pos_node.spin()
    
    pos_node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
