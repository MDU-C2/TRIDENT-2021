import pygame
import numpy as np
from math import sin, cos
from random import gauss
import rclpy
from rclpy.node import Node

from geometry_msgs.msg import Twist
from trident_msgs.srv import KalmanSensorService
from test_interfaces.msg import FauxPosition as FauxState

# TODO: this is a very bad way to do this
class MainProgNode(Node):
    def __init__(self):
        super().__init__('faux_sensor_n_unit')
        #                                         /Absolute \ /Relative \
        #                                         X   Y   Yaw dX  dY  dYaw
        self.true_state = np.transpose(np.array([[0., 0., 0., 0., 0., 0.,]]))
        self.estim_state = np.copy(self.true_state)

        self.motor_thrust = 0.
        self.motor_spin = 0.
        self.controlsub = self.create_subscription(
            Twist,
            '/turtle1/cmd_vel',
            self.ControlCallback,
            10)
        self.statesub = self.create_subscription(
            FauxState,
            '/faux_state',
            self.StateEstCallback,
            10)
        self.imusrv = self.create_service(
            KalmanSensorService,
            '/sensor/imu',
            self.IMUServCallback)
        self.gpssrv = self.create_service(
            KalmanSensorService,
            '/sensor/gps',
            self.GPSServCallback)
        self.timer = self.create_timer(0.01, self.TimerCalledLoop)

        pygame.init()
        self.clock = pygame.time.Clock()
        self.recv_time = pygame.time.get_ticks()/1000.0

        self.surf = pygame.display.set_mode((480,480))
        
    def IMUServCallback(self, request, response):
        print("IMU callback")
        state = np.reshape(request.state, (-1,1))
        covar = np.reshape(request.covar, (-1,len(request.state)))
        # Fake measure, ofc. Just the true state with some noise added.
        noise = np.transpose(np.array([[50., 50., .2, 20., 20., .1]]))
        measure = noise * np.random.randn(6,1) + self.true_state
        # Fake measure = super simple observation matrix (no Jacobians)
        obs_mat = np.identity(6)
        resid = measure - np.matmul(obs_mat, state)
        resid_covar = np.matmul(np.matmul(
                          obs_mat,
                          covar),
                          np.transpose(obs_mat)) + (noise*np.identity(6))**2
        gain = np.matmul(np.matmul(
                   covar,
                   np.transpose(obs_mat)),
                   np.linalg.inv(resid_covar))
                   
        #print("IMU covariance:\n",resid_covar,"\nState covariance:\n",covar)
        #print("IMU residual:\n",resid,"\nIMU gain:\n",gain,"\nIMU obs matrix:\n",obs_mat)
        
        response.residual = list(resid.flatten())
        response.gain = list(gain.flatten())
        response.observationmatrix = list(obs_mat.flatten())
        return response
    
    def GPSServCallback(self, request, response):
        print("GPS callback")
        state = np.reshape(request.state, (-1,1))
        covar = np.reshape(request.covar, (-1,len(request.state)))
        # Another fake measure. This one only has the absolute vals tho
        noise = np.transpose(np.array([[20., 20., .5]]))
        measure = noise * np.random.randn(3,1) + self.true_state[:3]
        # Matrix reducesthe state to just the absolutes
        obs_mat = np.eye(3,6)
        resid = measure - np.matmul(obs_mat, state)
        resid_covar = np.matmul(np.matmul(
                          obs_mat,
                          covar),
                          np.transpose(obs_mat)) + (noise*np.identity(3))**2
        gain = np.matmul(np.matmul(
                   covar,
                   np.transpose(obs_mat)),
                   np.linalg.inv(resid_covar))
        
        response.residual = list(resid.flatten())
        response.gain = list(gain.flatten())
        response.observationmatrix = list(obs_mat.flatten())
        return response
    
    def StateEstCallback(self, msg):
        print("received state:",msg)
        self.estim_state[0,0] = msg.x
        self.estim_state[1,0] = msg.y
        self.estim_state[2,0] = msg.theta
        self.estim_state[3,0] = msg.dx
        self.estim_state[4,0] = msg.dy
        self.estim_state[5,0] = msg.dtheta
    
    def ControlCallback(self, msg):
        #print("received msg:",msg)
        self.motor_thrust = msg.linear.x*40
        self.motor_spin   = msg.angular.z
        self.recv_time = pygame.time.get_ticks()/1000.0
        
    def DrawUnit(self, surf, x, y, yaw, color):
        lpoints = [[n[0]*cos(yaw)+n[1]*sin(yaw)+x+240,
                    -n[0]*sin(yaw)+n[1]*cos(yaw)-y+240] for n in [
            [ 20,  0],
            [-10, 10],
            [-5,  0],
            [-10,-10]
        ]]
        pygame.draw.aalines(surf, color, True, lpoints)

    def TimerCalledLoop(self):
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                running = False
        
        dt = self.clock.tick()/1000.0
        t = pygame.time.get_ticks()/1000.0
        
        # Reduce and then apply noise accel on deltas
        self.true_state[3,0] -= dt*self.true_state[3,0]
        self.true_state[4,0] -= dt*self.true_state[4,0]
        self.true_state[5,0] -= dt*self.true_state[5,0]
        self.true_state[3,0] += dt*5*cos(t)
        self.true_state[4,0] += dt*5*sin(t)
        self.true_state[5,0] += 0.1*dt*sin(t)
        
        # TODO: Read and apply motors
        if(self.recv_time+1.0 > t):
            self.true_state[3,0] += dt*self.motor_thrust
            self.true_state[5,0] += dt*self.motor_spin
        
        # Update position according to deltas
        self.true_state[2,0] += self.true_state[5,0] * dt
        self.true_state[0,0] +=(self.true_state[3,0] * cos(self.true_state[2,0]) + 
                                self.true_state[4,0] * sin(self.true_state[2,0]))*dt
        self.true_state[1,0] +=-(-self.true_state[3,0] * sin(self.true_state[2,0])+ 
                                  self.true_state[4,0] * cos(self.true_state[2,0]))*dt
        
        self.surf.fill((0,0,0))
        
        self.DrawUnit(self.surf, self.true_state[0,0], self.true_state[1,0], self.true_state[2,0], (127, 127, 127))
        self.DrawUnit(self.surf, self.estim_state[0,0], self.estim_state[1,0], self.estim_state[2,0], (255, 0, 0))
        
        pygame.display.flip()

def main(args=None):
    rclpy.init(args=args)
    
    main_node = MainProgNode()
    
    rclpy.spin(main_node)
    
    rclpy.shutdown()

if __name__ == "__main__":
    main()
