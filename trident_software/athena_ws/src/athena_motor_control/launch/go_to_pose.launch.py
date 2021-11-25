
import unittest

import launch
import launch_ros
import launch_ros.actions
import launch.actions
import launch.substitutions

import launch_testing.actions
import launch_testing_ros

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
import os
from ament_index_python.packages import get_package_share_directory


@pytest.mark.rostest
def generate_test_description():
    config = os.path.join(
        get_package_share_directory('athena_bringup'),
        'config',
        'system_launch_params.yaml'
    )

    return launch.LaunchDescription([
        launch.actions.DeclareLaunchArgument(
            'node_prefix',
            default_value=[launch.substitutions.EnvironmentVariable('USER'), '_'],
            description='Prefix for node names'),
        launch_ros.actions.Node(
            namespace='athena', package='athena_motor_control', executable='motor_control', output='screen', parameters=[config],
            name=['motor_control']),
        
        #launch_testing.util.KeepAliveProc(),
        launch_testing.actions.ReadyToTest(),
    ])


class MinimalClientAsync(Node):

    def __init__(self):
        super().__init__('minimal_client_async')
        self.actcli = ActionClient(self, GotoPose, 'athena/motor_control/pose/go')

    def send_goal(self, x, y, z, yaw, pitch, roll):
        goal_msg = GotoPose.Goal()
        goal_msg.pose.position.x = x
        goal_msg.pose.position.y = y
        goal_msg.pose.position.z = z
        q = Quaternion.from_euler(yaw, pitch, roll, degrees=True)
        goal_msg.pose.orientation.x = q.x
        goal_msg.pose.orientation.y = q.y
        goal_msg.pose.orientation.z = q.z
        goal_msg.pose.orientation.w = q.w
        
        self.get_logger().info('Waiting for action server...')
        self.actcli.wait_for_server()

        self.get_logger().info('Sending goal request')
        self.send_goal_future = self.actcli.send_goal_async(goal_msg, feedback_callback=self.feedback_callback)
        self.send_goal_future.add_done_callback(self.goal_response_callback)

    def goal_response_callback(self, future):
        goal_handle = future.result()
        if not goal_handle.accepted:
            self.get_logger().info('Goal rejected :(')
            return

        self.get_logger().info('Goal accepted :)')

        self._get_result_future = goal_handle.get_result_async()
        self._get_result_future.add_done_callback(self.get_result_callback)

    def feedback_callback(self, feedback):
        self.get_logger().info(f"Goto pose feedback: Distance to goal: {feedback.feedback.distance_to_goal}" \
                               f"status: {feedback.feedback.status}, Message: {feedback.feedback.message}")

        self.get_logger().info('Propagating feedback to GotoWaypoint client.')
        # Propagate feedback to the GotoWaypoint client
        goto_waypoint_feedback_msg = GotoWaypoint.Feedback()
        goto_waypoint_feedback_msg.distance_to_goal = feedback.feedback.distance_to_goal
        goto_waypoint_feedback_msg.status = GotoWaypointStatus.MOVING
        goto_waypoint_feedback_msg.message = "Moving to waypoint."

    def get_result_callback(self, future):
        result = future.result().result
        status = future.result().status
        if status == GoalStatus.STATUS_SUCCEEDED:
            self.get_logger().info('Goal succeeded! Result: {0}'.format(result.distance_to_goal))
        else:
            self.get_logger().info('Goal failed with status: {0}'.format(status))

        # Shutdown after receiving a result
        #rclpy.shutdown()

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
        self.node = rclpy.create_node('test_gotopose')

    def tearDown(self):
        self.node.destroy_node()

    def test_manual_override_service(self):
        minimal_actcli = MinimalClientAsync()
        future = minimal_actcli.send_goal(2.0, 2.0, 0.0, 0.0, 0.0, 0.0)
        rclpy.spin(minimal_actcli)
        
        """
        while rclpy.ok():
            rclpy.spin(minimal_actcli)
            if minimal_actcli.future.done():
                try:
                    response = minimal_client.future.result()
                except Exception as e:
                    minimal_client.get_logger().info(
                        'Service call failed %r' % (e,))
                else:
                    self.assertTrue(response.success)
                break
            
        """
        #minimal_actcli.destroy_node()
        rclpy.shutdown()
