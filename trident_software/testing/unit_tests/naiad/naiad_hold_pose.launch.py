import unittest

import launch
import launch_ros
import launch_ros.actions
import launch.actions
import launch.substitutions

import launch_testing.actions
import launch_testing_ros

from threading import Thread
import pytest
import rclpy
from rclpy.node import Node
import time
from squaternion import Quaternion
from rclpy.action import ActionClient

from action_msgs.msg import GoalStatus
import std_msgs.msg
from baseclasses.motorcontrolbase import MotorControlBase
from std_srvs.srv import Trigger        # https://github.com/ros2/common_interfaces/blob/master/std_srvs/srv/Trigger.srv
from std_srvs.srv import SetBool
from trident_msgs.action import GotoPose, HoldPose
from trident_msgs.srv import GetState
import os
from ament_index_python.packages import get_package_share_directory


@pytest.mark.rostest
def generate_test_description():
    config = os.path.join(
        get_package_share_directory('naiad_bringup'),
        'config',
        'system_launch_params.yaml'
    )

    return launch.LaunchDescription([
        launch.actions.DeclareLaunchArgument(
            'node_prefix',
            default_value=[launch.substitutions.EnvironmentVariable('USER'), '_'],
            description='Prefix for node names'),
        launch_ros.actions.Node(
            namespace='naiad', package='naiad_motor_control', executable='motor_control', output='screen', parameters=[config],
            name=['motor_control']),
        
        #launch_testing.util.KeepAliveProc(),
        launch_testing.actions.ReadyToTest(),
    ])


class MinimalServiceClient(Node):
    def __init__(self):
        super().__init__('service_clientent_async')
        self.sercli = self.create_client(GetState, 'naiad/motor_control/state/get')
        while not self.sercli.wait_for_service(timeout_sec=1.0):
            self.get_logger().info('service not available, waiting again...')
        self.req = GetState.Request()

    def send_request(self):
        self.finalresult = self.sercli.call(self.req)

class MinimalActionClient(Node):

    def __init__(self):
        super().__init__('minimal_client_async')
        self.actcli = ActionClient(self, HoldPose, 'naiad/motor_control/pose/hold')
        self.action_finished = False

    def send_goal(self, x, y, z, yaw, pitch, roll, duration):
        goal_msg = HoldPose.Goal()
        goal_msg.pose.position.x = x
        goal_msg.pose.position.y = y
        goal_msg.pose.position.z = z
        q = Quaternion.from_euler(yaw, pitch, roll, degrees=True)
        goal_msg.pose.orientation.x = q.x
        goal_msg.pose.orientation.y = q.y
        goal_msg.pose.orientation.z = q.z
        goal_msg.pose.orientation.w = q.w
        goal_msg.duration = duration
        
        self.get_logger().info('Waiting for action server...')
        self.actcli.wait_for_server()

        self.get_logger().info('Sending goal request')
        self.send_goal_future = self.actcli.send_goal_async(goal_msg, feedback_callback=self.feedback_callback)
        self.send_goal_future.add_done_callback(self.goal_response_callback)

    def goal_response_callback(self, future):
        goal_handle = future.result()
        if not goal_handle.accepted:
            self.get_logger().info('Goal rejected.')
            return

        self.get_logger().info('Goal accepted.')

        self.result_future = goal_handle.get_result_async()
        self.result_future.add_done_callback(self.get_result_callback)

    def feedback_callback(self, feedback):
        self.get_logger().info(f"status: {feedback.feedback.status}, Message: {feedback.feedback.message}")

    def get_result_callback(self, future):
        self.finalresult = future.result().result
        self.finalstatus = future.result().status
        self.action_finished = True


class TestTalkerListenerLink(unittest.TestCase):

    @classmethod
    def setUpClass(cls):
        # Initialize the ROS context for the test node
        rclpy.init()

    @classmethod
    def tearDownClass(cls):
        # Shutdown the ROS context
        rclpy.shutdown()

    def setUp(self):
        # Create a ROS node for tests
        self.node = rclpy.create_node('test_holdpose')

    def tearDown(self):
        self.node.destroy_node()

    def test_goto_pose(self):
        # Create and start the Action client that sends the GotoPose service call
        action_client = MinimalActionClient()
        action_client.send_goal(0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 3)
        while(not action_client.action_finished):
            rclpy.spin_once(action_client)

        # When above is finished, create and start the Service client that requests the GetState information
        service_client = MinimalServiceClient()
        spin_thread = Thread(target=rclpy.spin, args=(service_client,))
        spin_thread.start()
        service_client.send_request()

        # Print and check if the goal was reached and if the motor controller was IDLE afterwards
        print("Action result: %s" % (action_client.finalstatus))
        self.assertEqual(action_client.finalstatus, GoalStatus.STATUS_SUCCEEDED, "Hold pose failed.")
        print("Motor control hold duration: %s" % (action_client.finalresult.duration))
        self.assertEqual(action_client.finalresult.duration, 3, "Motor control should hold position for 3 seconds.")
        print("Motor control state: %s" % (service_client.finalresult.state))
        self.assertEqual(service_client.finalresult.state, 'IDLE', "Motor control state parameter should be: IDLE")
        

