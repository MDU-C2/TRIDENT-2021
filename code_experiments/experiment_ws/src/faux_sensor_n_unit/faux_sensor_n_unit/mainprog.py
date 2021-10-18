import pygame
import numpy as np
from math import sin, cos
from random import gauss
import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist

# TODO: this is a very bad way to do this
class MainProgNode(Node):
    def __init__(self):
        super().__init__('faux_sensor_n_unit')
        #                                    /Absolute \ /Relative \
        #                                    X   Y   Yaw dX dY  dYaw
        self.true_state = np.transpose(np.array([[0., 0., 0., 0., 0., 0.,]]))

        self.motor_thrust = 0.
        self.motor_spin = 0.
        self.subscription = self.create_subscription(
            Twist,
            '/turtle1/cmd_vel',
            self.ControlCallback,
            10)
        self.timer = self.create_timer(0.01, self.TimerCalledLoop)

        pygame.init()
        self.clock = pygame.time.Clock()
        self.recv_time = pygame.time.get_ticks()/1000.0

        self.surf = pygame.display.set_mode((480,480))
        
    def IMUServCallback(self, request, response):
        pass
    
    def GPSServCallback(self, request, response):
        
        
    def ControlCallback(self, msg):
        print("received msg:",msg)
        self.motor_thrust = msg.linear.x*40
        self.motor_spin   = msg.angular.z
        self.recv_time = pygame.time.get_ticks()/1000.0
        
    def DrawUnit(self, surf, x, y, yaw):
        lpoints = [[n[0]*cos(yaw)+n[1]*sin(yaw)+x+240,
                    -n[0]*sin(yaw)+n[1]*cos(yaw)-y+240] for n in [
            [ 20,  0],
            [-10, 10],
            [-5,  0],
            [-10,-10]
        ]]
        pygame.draw.aalines(surf, (255, 0, 0), True, lpoints)

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
        
        self.DrawUnit(self.surf, self.true_state[0,0], self.true_state[1,0], self.true_state[2,0])
        
        pygame.display.flip()

def main(args=None):
    rclpy.init(args=args)
    
    main_node = MainProgNode()
    
    rclpy.spin(main_node)
    
    rclpy.shutdown()

if __name__ == "__main__":
    main()
