import rclpy
import numpy as np
import baseclasses.positionbase as posbase
from trident_msgs.msg import State
from math import sin, cos, pi, tau

from rclpy.executors import MultiThreadedExecutor
import threading
from squaternion import Quaternion

import jax.numpy as jnp

class NaiadPosNode(posbase.PosNode):
    def __init__(self):
        
        init_state = np.zeros((13,1))  # Starts at 0,0
        init_covar = np.zeros((13,13)) # Starts with no uncertainty
        init_noise = (np.array([0.25, 0.25, 0.25, 0.2, 0.2, 0.2, 0.2, 0.05, 0.05, 0.05, 0.05, 0.05, 0.05])*np.identity(13))**2 # These are just guesses!
            
        super().__init__("naiad_position_node", "state", 0.5,
                         init_state, init_covar, init_noise, ["/naiad/sensor/imu", "/naiad/sensor/gps", "/naiad/sensor/pressure"],
                         6, "/naiad/simulation/thruster_setpoints")
    
    def state_trans(self, prev, dt):
        x, y, z, qw, qx, qy, qz, dx, dy, dz, dr, dp, dh = prev
        quat = Quaternion(qw,qx,qy,qz)
        ang_vel_quat = Quaternion(0,dr,dp,dh)*dt*.5
        rotated = (ang_vel_quat*quat)+quat
        heading = jnp.arctan2(2*(qw*qz + qx*qy), 1-2*(pow(qy, 2)+pow(qz, 2)))
        # This transition func assumes the NAIAD is level.
        transition = jnp.array([
            x+dx*jnp.cos(heading)*dt+dy*jnp.sin(heading)*dt,
            y+dx*jnp.sin(heading)*dt+dy*jnp.cos(heading)*dt,
            z+dz*dt,
            rotated.w,
            rotated.x,
            rotated.y,
            rotated.z,
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
        msg.pose.orientation.w = self.state[3,0]
        msg.pose.orientation.x = self.state[4,0]
        msg.pose.orientation.y = self.state[5,0]
        msg.pose.orientation.z = self.state[6,0]
        msg.twist.linear.x     = self.state[7,0]
        msg.twist.linear.y     = self.state[8,0]
        msg.twist.linear.z     = self.state[9,0]
        msg.twist.angular.x    = self.state[10,0]
        msg.twist.angular.y    = self.state[11,0]
        msg.twist.angular.z    = self.state[12,0]
        self.publisher_.publish(msg)
    
def main(args=None):
    rclpy.init(args=args)
    naiad_pos_node = NaiadPosNode()
    # Create an executor thread that spins the node
    executor = MultiThreadedExecutor()
    executor.add_node(naiad_pos_node)
    executor_thread = threading.Thread(target=executor.spin)
    executor_thread.start()
    # Run the main loop in the node
    naiad_pos_node.spin()
    # Wait for the executor to finish
    executor_thread.join()

    naiad_pos_node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
