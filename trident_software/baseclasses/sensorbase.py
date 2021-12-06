import rclpy
from rclpy.node import Node
import numpy as np
from abc import ABC, abstractmethod
import types
from time import time

from trident_msgs.srv import BasicSensorService

class SensorNode(Node, ABC):
    def __init__(self, sensor_type, mounted_on, read_interval,
                       measure_var_count, noise_matrix):
        super().__init__(mounted_on+'_'+sensor_type)
        self.measure = np.zeros(measure_var_count)
        self.measure_noise = noise_matrix
        
        assert (np.size(self.measure_noise) == measure_var_count),\
            "Noise matrix is not the right shape for the measurement size"
        
        self.srv   = self.create_service(
            BasicSensorService,
            '/'+mounted_on+'/sensor/'+sensor_type,
            self.SensorService)
        self.timer = self.create_timer(read_interval, self.TakeMeasurement)
    
    @abstractmethod
    def state_guess(self, current_state):
        return guess, noise
    
    def SensorService(self, request, response):
        state = np.array(request.state)
        
        guess, noise = self.state_guess(state)
        
        # Craft and send response
        response.guess = guess.astype('float32').tolist()
        response.noise = noise.astype('float32').tolist()
        
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
