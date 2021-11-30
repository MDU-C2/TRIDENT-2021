
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

import std_msgs.msg
from baseclasses.motorcontrolbase import MotorControlBase
from std_srvs.srv import Trigger        # https://github.com/ros2/common_interfaces/blob/master/std_srvs/srv/Trigger.srv
from std_srvs.srv import SetBool
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


class MinimalClientAsync(Node):

    def __init__(self):
        super().__init__('minimal_client_async')
        self.cli = self.create_client(SetBool, 'naiad/motor_control/manual_override')
        while not self.cli.wait_for_service(timeout_sec=1.0):
            self.get_logger().info('service not available, waiting again...')
        self.req = SetBool.Request()

    def send_request(self):
        self.req.data = True
        self.future = self.cli.call_async(self.req)

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
        self.node = rclpy.create_node('test_manual_override')

    def tearDown(self):
        self.node.destroy_node()

    def test_manual_override_service(self):
        minimal_client = MinimalClientAsync()
        minimal_client.send_request()
        
        while rclpy.ok():
            rclpy.spin_once(minimal_client)
            if minimal_client.future.done():
                try:
                    response = minimal_client.future.result()
                except Exception as e:
                    minimal_client.get_logger().info(
                        'Service call failed %r' % (e,))
                else:
                    self.assertTrue(response.success)
                break
            
        minimal_client.destroy_node()
