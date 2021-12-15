import signal
import sys
import rclpy
import numpy as np
from baseclasses import positionbase
from trident_msgs.msg import State
from math import sin, cos, pi, tau

from rclpy.executors import MultiThreadedExecutor
import threading
from squaternion import Quaternion

class AthenaPosNode(positionbase.PosNode):
    def __init__(self):

        init_state = np.zeros(13)  # Starts at 0,0
        init_noise = np.array([0.2, 0.2, 100, 0.8, 100, 100, 0.8, 0.2, 0.2, 100, 100, 100, 0.2]) # These are just guesses!

        super().__init__("athena_position_node", "state", 0.5,
                         init_state, init_noise, ["/athena/sensor/imu", "/athena/sensor/gps"],
                         2, "/athena/simulation/thruster_setpoints")

    def state_trans(self, prev, dt):
        x, y, z, qw, qx, qy, qz, dx, dy, dz, dr, dp, dh = prev
        quat = Quaternion(qw,qx,qy,qz)
        ang_vel_quat = Quaternion(0,0,0,dh)*dt*.5
        rotated = (ang_vel_quat*quat)+quat
        heading = np.arctan2(2*(qw*qz), 1-2*pow(qz, 2))
        transition = np.array([
            x+dx*np.cos(heading)*dt+dy*np.sin(heading)*dt,
            y+dy*np.sin(heading)*dt+dy*np.cos(heading)*dt,
            z,
            rotated.w,
            rotated.x,
            rotated.y,
            rotated.z,
            1.1*self.control_vec[0]+1.1*self.control_vec[1],
            0,
            0,
            0,
            0,
            5.2*self.control_vec[0]-5.2*self.control_vec[1]])
        return transition

    def get_ctrl_vec(self, msg):
        self.get_logger().info("Control vector: %s" % msg)
        self.control_vec[0] = msg.setpoints[0]
        self.control_vec[1] = msg.setpoints[1]

    def state_publish(self):
        msg = State()
        msg.pose.position.x = self.state[0]
        msg.pose.position.y = self.state[1]
        msg.pose.position.z = self.state[2]
        msg.pose.orientation.w = self.state[3]
        msg.pose.orientation.x = self.state[4]
        msg.pose.orientation.y = self.state[5]
        msg.pose.orientation.z = self.state[6]
        msg.twist.linear.x  = self.state[7]
        msg.twist.linear.y  = self.state[8]
        msg.twist.linear.z  = self.state[9]
        msg.twist.angular.x = self.state[10]
        msg.twist.angular.y = self.state[11]
        msg.twist.angular.z = self.state[12]
        self.publisher_.publish(msg)

def signal_handler(sig, frame):
    rclpy.shutdown()
    sys.exit(0)

def main(args=None):
    signal.signal(signal.SIGINT, signal_handler)
    rclpy.init(args=args)
    athena_pos_node = AthenaPosNode()
    # Create an executor thread that spins the node
    executor = MultiThreadedExecutor()
    executor.add_node(athena_pos_node)
    executor_thread = threading.Thread(target=executor.spin)
    executor_thread.start()
    # Run the main loop in the node
    athena_pos_node.spin()
    # Wait for the executor to finish
    executor_thread.join()

    naiad_pos_node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
