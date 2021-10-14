import rclpy
from rclpy.node import Node
import rospy
import numpy as np
from random import gauss

from example_interfaces.msg import String

class MainNode(Node):
    def __init__(self, name, pub_topic_type, pub_topic_name, interval,
                 start_state, start_covar, proc_noise, sensor_list):
                 
        # Basic inits to create node, publisher, and periodic func #
        #----------------------------------------------------------#
        super().__init__(name)
        self.publisher_ = self.create_publisher(pub_topic_type, pub_topic_name, 10)
        timer_period = interval
        self.timer = self.create_timer(timer_period, self.timer_callback)
        
        # Inits for all the Kalman-related variables #
        #-------------------------------------------#
        self.state = np.copy(start_state)
        self.covar = np.copy(start_covar)
        self.proc_noise = np.copy(proc_noise)
        
        # Error detection on the different variables #
        #--------------------------------------------#
        assert(self.state.shape[1] = 1),\
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
            rospy.wait_for_service(service_name)
            try:
                #TODO: Fix a service for this (take x and P, return y, H, and K)
                self.sensor_handles.append(
                    rospy.ServiceProxy(service_name, KalmanSensorService))
            except rospy.ServiceException as e:
                print("Couldn't add handle for",service_name,":",e)
        
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
    def state_trans(self, prev, control_vec):
        return np.transpose(np.array([[prev[0,0]*prev[6,0], 
                                       prev[1,0]*prev[7,0], 
                                       prev[2,0]*prev[8,0], 
                                       prev[3,0]*prev[9,0],  
                                       prev[4,0]*prev[10,0], 
                                       prev[5,0]*prev[11,0], 
                                       prev[6,0], 
                                       prev[7,0], 
                                       prev[8,0], 
                                       prev[9,0], 
                                       prev[10,0], 
                                       prev[11,0]]]))
    
    # The topic publisher function
    # This too should be changed to an appropriate message!
    def state_publish(self):
        msg = String()
        msg.data = "Change to a good message type, then put state here!"
        self.publisher_.publish(msg)
        self.get_logger().info('Publishing new state')
    
    # This SHOULDN'T be changed! This function calls and receives values from services
    def service_call(self, sensor_handle, pred_state, pred_covar):
        try:
            resp = sensor_handle(pred_state.flatten(), pred_covar.flatten())
            x_size = len(pred_state)
            y_size = len(resp.residual)
            return(np.reshape(resp.gain,               (y_size, x_size)),
                   np.reshape(resp.residual,           (-1,1)          ),
                   np.reshape(resp.observationmatrix), (x_size, y_size))
        except rospy.ServiceException as e:
                print("Couldn't get values from a service:",e)
    
    # This SHOULDN'T be changed! Returns both the new state and the jacobian
    # Jacobian through complex step differentiation
    # Source: https://se.mathworks.com/matlabcentral/fileexchange/18189-learning-the-extended-kalman-filter?s_tid=mwa_osa_a
    def jacobian_csd(self, func, state, control):
        new_state = func(state, control) 
        n = state.shape[0]
        m = new_state.shape[0]
        A = np.zeros((m,n))
        h = n * pow(2,-51) # Just a small number here, I think?
        for k in range(n):
            state1 = state.astype('complex64')
            state1[k, 0] = complex(state1[k, 0], h)
            A[:, k] = np.transpose((func(state1, control)).imag/h) 
        return (new_state, A)
    
    # This SHOULDN'T be changed! This is the main function, handling EKF and sending state
    def timer_callback(self):
        # Predict new state (and get the state transition matrix thru Jacobian)
        # TODO: add control vector
        pred_state, state_trans_mat = self.jacobian_csd(self.state_trans, self.state, 0)
        # Add noise
        pred_state += np.matmul(self.proc_noise, np.random.randn(self.state.shape[1], 1))
        # Predict covariance of new state
        pred_covar = np.matmul(np.matmul(
                        state_trans_mat,
                        self.covar),
                        np.transpose(state_trans_mat)
                     ) + self.proc_noise
        
        # Here we go through all of the different sensors
        # TODO: none of this is implemented yet, since no sensors!
        for sensor in self.sensor_handles:
            try:
                # Get the values from the sensors
                gain, resid, obs_mat = service_call(sensor, pred_state, pred_covar)
                # Update the state estimate
                pred_state = pred_state + np.matmul(gain, resid)
                # Update the covariance estimate
                pred_covar = np.matmul(
                                np.identity(pred_state.shape[0]) - np.matmul(
                                    gain,
                                    observe_matrix),
                                pred_covar)
            except:
                print("Skipping sensor due to failure!")
        
        # Finally, set the state and covariance to the new ones!
        self.state = pred_state
        self.cover 0 pred_covar
            
'''            observed, observe_matrix = self.jacobian_csd(sensor['obs_func'], pred_state, 0)
            residual = sensor['last_read'] - observed
            resid_covar = np.matmul(np.matmul(
                             observe_matrix,
                             pred_covar),
                             np.transpose(observe_matrix)
                          ) + sensor['obs_noise']
            gain = np.matmul(np.matmul(
                       pred_covar,
                       np.transpose(observe_matrix)),
                       resid_covar**-1)
            pred_state = pred_state + np.matmul(gain, residual)
            pred_covar = np.matmul(np.identity(pred_state.shape[0]) - np.matmul(gain, observe_matrix), pred_covar)'''

def main(args=None):
    rclpy.init(args=args)
    
    main_node = MainNode("unnamed_position_node", "unnamed_current_state", 1)
    
    rclpy.spin(main_node)
    
    main_node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
