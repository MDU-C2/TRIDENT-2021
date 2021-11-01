import rclpy
import numpy as np
from basenodes import positionbase
from trident.msgs import NaiadState
from math import sin, cos

class NaiadPosNode(PosNode):
    def __init__(self):
        
        init_state = np.zeros((12,1))  # Starts at 0,0
        init_covar = np.zeros((12,12)) # Starts with no uncertainty
        init_noise = (np.array([0.5, 0.5, 0.5, 0.4, 0.4, 0.4, 0.2, 0.2, 0.2, 0.1, 0.1, 0.1])*np.identity(12))**2 # These are just guesses!
            
        super().__init__("naiad_position_node", pub_topic_type, "/naiad/state", 0.5,
                         init_state, init_covar, init_noise, ["/naiad/sensor/imu"])
    
    def state_trans(self, prev, control_vec, dt):
        h = prev[5,1]
        trans_mat = np.array([
            #x  y  z  r  p  h         dx         dy dz dr dp dh
            [1, 0, 0, 0, 0, 0, dt*sin(h), dt*cos(h),  0,  0,  0,  0], #x
            [0, 1, 0, 0, 0, 0, dt*cos(h), dt*sin(h),  0,  0,  0,  0], #y
            [0, 0, 1, 0, 0, 0,         0,         0, dt,  0,  0,  0], #z
            [0, 0, 0, 1, 0, 0,         0,         0,  0, dt,  0,  0], #r
            [0, 0, 0, 0, 1, 0,         0,         0,  0,  0, dt,  0], #p
            [0, 0, 0, 0, 0, 1,         0,         0,  0,  0,  0, dt], #h
            [0, 0, 0, 0, 0, 0,         1,         0,  0,  0,  0,  0], #dx
            [0, 0, 0, 0, 0, 0,         0,         1,  0,  0,  0,  0], #dy
            [0, 0, 0, 0, 0, 0,         0,         0,  1,  0,  0,  0], #dz
            [0, 0, 0, 0, 0, 0,         0,         0,  0,  1,  0,  0], #dr
            [0, 0, 0, 0, 0, 0,         0,         0,  0,  0,  1,  0], #dp
            [0, 0, 0, 0, 0, 0,         0,         0,  0,  0,  0,  1]])#dh
        # TODO: add the contol vector, using the motor config.
        transition = np.matmul(trans_mat,prev)
        return transition
    
    def state_publish(self):
        msg = NaiadState()
        msg.x          = self.state[0]
        msg.y          = self.state[1]
        msg.z          = self.state[2]
        msg.roll       = self.state[3]
        msg.pitch      = self.state[4]
        msg.heading    = self.state[5]
        msg.velx       = self.state[6]
        msg.vely       = self.state[7]
        msg.velz       = self.state[8]
        msg.velroll    = self.state[9]
        msg.velpitch   = self.state[10]
        msg.velheading = self.state[11]
        self.publisher_.publish(msg)
    
def main(args=None):
    rclpy.init(args=args)
    naiad_pos_node = NaiadPosNode()
    naiad_pos_node.spin()
    naiad_pos_node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
