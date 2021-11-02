import numpy as np
import rclpy
from rclpy.node import Node
from abc import ABC, abstractmethod

from trident_msgs.srv import KalmanSensorService

class SensorNode(Node, ABC):
    def __init__(self, sensor_type, mounted_on, read_interval,
                       observation_matrix, measure_var_count, noise_matrix):
        super().__init__(mounted_on+'_'+sensor_type)
        self.obs_mat = observation_matrix
        self.measure = np.zeros((measure_var_count, 1))
        self.m_noise = noise_matrix
        assert (self.obs_mat.shape[0] == measure_var_count),\
            "Matrix is not the right shape for the measurement size"
        # I think?
        assert (self.m_noise.shape[0] == measure_var_count and self.m_noise.shape[1] == measure_var_count),\
            "Noise matrix is not the right shape for the measurement size"
        
        self.srv   = self.create_service(
            KalmanSensorService,
            '/'+mounted_on+'/sensor/'+sensor_type,
            self.SensorService)
        self.timer = self.create_timer(read_interval, self.TakeMeasurement)
        
    def SensorService(self, request, response):
        # Take in the state and covar
        state = np.reshape(request.state, (-1,1))
        covar = np.reshape(request.covar, (-1,state.shape[0]))
        
        # Perform the needed EKF steps
        # TODO: allow observation matrix OR function
        residual = self.measure - np.matmul(self.obs_mat, state)
        residual_covar = np.matmul(np.matmul(
                             self.obs_mat,
                             covar),
                             np.transpose(self.obs_mat)) + self.m_noise
        kalman_gain = np.matmul(np.matmul(
                          covar,
                          np.transpose(self.obs_mat)),
                          np.linalg.inv(residual_covar))
        
        # Craft and send response
        response.residual          = residual.flatten().astype('float32').tolist()
        response.gain              = kalman_gain.flatten().astype('float32').tolist()
        response.observationmatrix = self.obs_mat.flatten().astype('float32').tolist()
        #print("Request:",  request)
        print("Response:", response)
        print("First Gain Type:", type(response.gain[0]))

        return response
    
    @abstractmethod
    def TakeMeasurement(self):
        pass

def main(args=None):
    rclpy.init(args=args)
    node = SensorNode()
    rclpy.spin(node)
    rclpy.shutdown()

if __name__ == "__main__":
    main()
