from ament_index_python.packages import get_package_share_directory
from rclpy.node import Node
from std_srvs.srv import Trigger        # https://github.com/ros2/common_interfaces/blob/master/std_srvs/srv/Trigger.srv
import launch
import launch.actions
import launch.substitutions
import launch_ros
import launch_ros.actions
import launch_testing.actions
import launch_testing_ros
import os
import pytest
import rclpy
import time
import unittest

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
            namespace='athena', package='athena_driver', executable='motor_driver', output='screen', parameters=[config, {'simulation': True}, {'motor_output_scale': 0.5}],
            name=['motor_driver']),
        
        #launch_testing.util.KeepAliveProc(),
        launch_testing.actions.ReadyToTest(),
    ])

class MinimalServiceClient(Node):
    def __init__(self):
        super().__init__('service_clientent_async')
        self.sercli = self.create_client(Trigger, 'athena/motor_driver/motors/kill')
        while not self.sercli.wait_for_service(timeout_sec=1.0):
            self.get_logger().info('service not available, waiting again...')
        self.req = Trigger.Request()

    def send_request(self):
        self.future = self.sercli.call_async(self.req)


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
        self.node = rclpy.create_node('test_motors_kill')

    def tearDown(self):
        self.node.destroy_node()

    def test_motors_kill(self):
        rclpy.logging.get_logger("Test").info('Creating service client...')
        service_client = MinimalServiceClient()
        rclpy.logging.get_logger("Test").info('Sending Kill request...')
        service_client.send_request()

        while rclpy.ok():
            rclpy.spin_once(service_client)
            if service_client.future.done():
                try:
                    response = service_client.future.result()
                except Exception as e:
                    service_client.get_logger().info(
                        'Service call failed %r' % (e,))
                else:
                    print(response)
                    self.assertTrue(response.success, "Motor driver kill success parameter should be: True")
                break
            
        service_client.destroy_node()
