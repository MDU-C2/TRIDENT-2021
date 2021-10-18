import numpy as np
from math import sin, cos
from random import gauss
import baseclasses.positionbase as posbase
import rclpy
from rclpy.node import Node
from test_interfaces.msg import FauxPosition as FauxState

class PosNode(posbase.MainNode):
    def __init__(self):
        super().__init__('faux_pos_node', FauxState, '/faux_state', 0.5,
                         np.transpose(np.array([[0., 0., 0., 0., 0., 0.,]])),
                         np.array([[0., 0., 0., 0., 0., 0.]])*np.identity(6),
                         np.array([[.1, .1, .1, .1, .1, .1]])*np.identity(6),
                         ['/sensor/imu', '/sensor/gps'])
        
        def state_trans(self, prev, control_vec, dt):
            prev[3,0] += -dt*prev[3,0] + dt*control_vec[0,0]
            prev[4,0] += -dt*sprev[4,0] + dt*control_vec[1,0]
            prev[5,0] += -dt*prev[5,0] + dt*control_vec[2,0]
            prev[2,0] += prev[5,0] * dt
            prev[0,0] += (prev[3,0] * cos(prev[2,0]) + 
                          prev[4,0] * sin(prev[2,0]))*dt
            prev[1,0] +=-(-prev[3,0] * sin(prev[2,0])+ 
                          prev[4,0] * cos(prev[2,0]))*dt
            return np.copy(prev)
        
        def state_publish(self):
            msg = FauxState()
            msg.x      = self.state[0, 0]
            msg.y      = self.state[1, 0]
            msg.theta  = self.state[2, 0]
            msg.dx     = self.state[3, 0]
            msg.dy     = self.state[4, 0]
            msg.dtheta = self.state[5, 0]
            self.publisher_.publish(msg)
            self.get_logger().info('Publishing new state')

def main(args=None):
    rclpy.init(args=args)
    
    main_node = PosNode()
    
    rclpy.spin(main_node)
    
    rclpy.shutdown()

if __name__ == "__main__":
    main()
