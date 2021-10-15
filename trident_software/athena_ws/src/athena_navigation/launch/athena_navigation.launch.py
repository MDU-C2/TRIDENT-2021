
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
from example_interfaces.srv import AddTwoInts

@pytest.mark.rostest
def generate_test_description():
    return launch.LaunchDescription([
        launch.actions.DeclareLaunchArgument(
            'node_prefix',
            default_value=[launch.substitutions.EnvironmentVariable('USER'), '_'],
            description='Prefix for node names'),
        launch_ros.actions.Node(
            package='athena_navigation', executable='navigation', output='screen',
            name=[launch.substitutions.LaunchConfiguration('node_prefix'), 'navigation']),
        
        #launch_testing.util.KeepAliveProc(),
        launch_testing.actions.ReadyToTest(),
    ])


class MinimalClientAsync(Node):

    def __init__(self):
        super().__init__('minimal_client_async')
        self.cli = self.create_client(AddTwoInts, 'nav/wp_queue/empty')
        while not self.cli.wait_for_service(timeout_sec=1.0):
            self.get_logger().info('service not available, waiting again...')
        self.req = AddTwoInts.Request()

    def send_request(self,a,b):
        self.req.a = a
        self.req.b = b
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
        self.node = rclpy.create_node('test_navigation_link')

    def tearDown(self):
        self.node.destroy_node()

    def test_service1(self):
        minimal_client = MinimalClientAsync()
        minimal_client.send_request(7,5)
        
        while rclpy.ok():
            rclpy.spin_once(minimal_client)
            if minimal_client.future.done():
                try:
                    response = minimal_client.future.result()
                except Exception as e:
                    minimal_client.get_logger().info(
                        'Service call failed %r' % (e,))
                else:
                    #minimal_client.get_logger().info('Result of add_two_ints: for %d + %d = %d' %(minimal_client.req.a, minimal_client.req.b, response.sum))
                    self.assertEqual(response.sum, 12)
                break
            
        minimal_client.destroy_node()

    def test_service2(self):
        minimal_client = MinimalClientAsync()
        minimal_client.send_request(7,7)
        
        while rclpy.ok():
            rclpy.spin_once(minimal_client)
            if minimal_client.future.done():
                try:
                    response = minimal_client.future.result()
                except Exception as e:
                    minimal_client.get_logger().info(
                        'Service call failed %r' % (e,))
                else:
                    #minimal_client.get_logger().info('Result of add_two_ints: for %d + %d = %d' %(minimal_client.req.a, minimal_client.req.b, response.sum))
                    self.assertEqual(response.sum, 12)
                break
            
        minimal_client.destroy_node()