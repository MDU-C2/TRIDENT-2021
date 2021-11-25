import numpy as np
import rclpy
from rclpy.node import Node
from abc import ABC, abstractmethod
import types
from time import time
from jax import jacfwd
import jax.numpy as jnp

from trident_msgs.srv import KalmanSensorService

class SensorNode(Node, ABC):
    def __init__(self, sensor_type, mounted_on, read_interval,
                       observation_model, measure_var_count, noise_matrix):
        super().__init__(mounted_on+'_'+sensor_type)
        self.obs_mod = observation_model
        self.measure = np.zeros((measure_var_count, 1))
        self.m_noise = noise_matrix
        
        ismatrix = isinstance(self.obs_mod, np.ndarray)
        assert (not ismatrix or self.obs_mod.shape[0] == measure_var_count),\
            "Matrix is not the right shape for the measurement size, and isn't a function"
        # I think?
        assert (self.m_noise.shape[0] == measure_var_count and self.m_noise.shape[1] == measure_var_count),\
            "Noise matrix is not the right shape for the measurement size"
        
        self.srv   = self.create_service(
            KalmanSensorService,
            '/'+mounted_on+'/sensor/'+sensor_type,
            self.SensorService)
        self.timer = self.create_timer(read_interval, self.TakeMeasurement)
        
        self.ismatrix = isinstance(self.obs_mod, np.ndarray)
    
    '''def jacobian(self, func, state, dt):
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
    
    def SensorService(self, request, response):
        # Take in the state and covar
        state = np.reshape(request.state, (-1,1))
        covar = np.reshape(request.covar, (-1,state.shape[0]))
        
        # Perform the needed EKF steps
        # self.get_logger().info("Measure: %s" % self.measure)
        if(self.ismatrix):
            obs_mat = self.obs_mod
        else:
            obs_jacob = jacfwd(self.obs_mod)
            #self.get_logger().info("TEST %s" % jnp.array_str(jnp.array(state.flatten())))
            obs_mat = obs_jacob(jnp.array(state.flatten()))#self.jacobian(self.obs_mod, state, dt)
            
        residual = self.measure - np.matmul(obs_mat, state)
        residual_covar = np.matmul(np.matmul(
                             obs_mat,
                             covar),
                             np.transpose(obs_mat)) + self.m_noise
        kalman_gain = np.matmul(np.matmul(
                          covar,
                          np.transpose(obs_mat)),
                          np.linalg.inv(residual_covar))
        
        # self.get_logger().info("Residual: %s" % residual)
        # self.get_logger().info("Gain: %s" % kalman_gain)
        # self.get_logger().info("Observation matrix: %s" % obs_mat)
        
        # Craft and send response
        response.residual          = residual.flatten().astype('float32').tolist()
        response.gain              = kalman_gain.flatten().astype('float32').tolist()
        response.observationmatrix = obs_mat.flatten().astype('float32').tolist()
        #print("Request:",  request)
        #self.get_logger().info("Request: %s" % request)
        #self.get_logger().info("Response: %s" % response)

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
