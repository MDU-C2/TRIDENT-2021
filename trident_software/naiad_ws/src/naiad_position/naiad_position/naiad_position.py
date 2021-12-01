import rclpy
import numpy as np
import baseclasses.positionbase as posbase
from trident_msgs.msg import State
from math import sin, cos, pi, tau

from rclpy.executors import MultiThreadedExecutor
import threading
from squaternion import Quaternion
import signal
import sys

import jax.numpy as jnp

class NaiadPosNode(posbase.PosNode):
    def __init__(self):
        
        init_state = np.zeros((12,1))  # Starts at 0,0
        init_covar = np.zeros((12,12)) # Starts with no uncertainty
        init_noise = (np.array([0.25, 0.25, 0.25, 0.8, 0.8, 0.2, 0.05, 0.05, 0.05, 0.05, 0.05, 0.05])*np.identity(12))**2 # These are just guesses!
            
        super().__init__("naiad_position_node", "state", 0.5,
                         init_state, init_covar, init_noise, ["/naiad/sensor/imu", "/naiad/sensor/gps", "/naiad/sensor/pressure"],
                         6, "/naiad/simulation/thruster_setpoints")
    
    def state_trans(self, prev, dt):
        '''h = prev[5,0]
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
        transition = np.matmul(trans_mat,prev)'''
        x, y, z, r, p, h, dx, dy, dz, dr, dp, dh = prev
        # This transition func assumes the NAIAD is level.
        ClampRot = lambda r: (((r)+pi) % tau)-pi
        transition = jnp.array([
            x+dx*jnp.cos(h)*dt+dy*jnp.sin(h)*dt,
            y+dx*jnp.sin(h)*dt+dy*jnp.cos(h)*dt,
            z+dz*dt,
            ClampRot(r+dr*dt),
            ClampRot(p+dp*dt),
            ClampRot(h+dh*dt),
            -1.125 *self.control_vec[0,0]-1.125 *self.control_vec[1,0],
            0,
            -0.5625*self.control_vec[2,0]-0.5625*self.control_vec[3,0]-0.5625*self.control_vec[4,0]-0.5625*self.control_vec[5,0],
             2.3749*self.control_vec[2,0]-2.3749*self.control_vec[3,0]+2.3749*self.control_vec[4,0]-2.3749*self.control_vec[5,0],
             1.375 *self.control_vec[2,0]+1.375 *self.control_vec[3,0]-1.375 *self.control_vec[4,0]-1.375 *self.control_vec[5,0],
            -2.874 *self.control_vec[0,0]+2.874 *self.control_vec[1,0]])
        return transition
    
    def get_ctrl_vec(self, msg):
        self.get_logger().info("Control vector: %s" % msg)
        self.control_vec[:,0] = msg.setpoints
    
    def state_publish(self):
        msg = State()
        msg.pose.position.x    = self.state[0,0]
        msg.pose.position.y    = self.state[1,0]
        msg.pose.position.z    = self.state[2,0]
        q = Quaternion.from_euler(self.state[3,0], self.state[4,0], self.state[5,0])
        msg.pose.orientation.x = q.x
        msg.pose.orientation.y = q.y
        msg.pose.orientation.z = q.z
        msg.pose.orientation.w = q.w
        msg.twist.linear.x     = self.state[6,0]
        msg.twist.linear.y     = self.state[7,0]
        msg.twist.linear.z     = self.state[8,0]
        msg.twist.angular.x    = self.state[9,0]
        msg.twist.angular.y    = self.state[10,0]
        msg.twist.angular.z    = self.state[11,0]
        self.publisher_.publish(msg)
    
def signal_handler(sig, frame):
    sys.exit(0)

def main(args=None):
    signal.signal(signal.SIGINT, signal_handler)
    rclpy.init(args=args)
    naiad_pos_node = NaiadPosNode()
    # Create an executor thread that spins the node
    executor = MultiThreadedExecutor()
    executor.add_node(naiad_pos_node)
    executor_thread = threading.Thread(target=executor.spin)
    executor_thread.daemon = True
    executor_thread.start()
    # Run the main loop in the node
    naiad_pos_node.spin()
    # Wait for the executor to finish
    while executor_thread.is_alive():
        time.sleep(1)

    naiad_pos_node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
