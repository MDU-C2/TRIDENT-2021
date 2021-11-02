import numpy as np
import rclpy
from rclpy.node import Node
from abc import ABC, abstractmethod

from trident_msgs.srv import KalmanSensorService
from std_srvs.srv import SetBool

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
            SetBool,
            '/'+mounted_on+'/sensor/'+sensor_type,
            self.SensorService)
        self.timer = self.create_timer(read_interval, self.TakeMeasurement)
        
    def SensorService(self, request, response):
        # Take in the state and covar
        response.success = True
        response.message = "Hello, world!"

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
