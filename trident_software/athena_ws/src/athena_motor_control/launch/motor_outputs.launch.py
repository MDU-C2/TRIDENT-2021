from ament_index_python.packages import get_package_share_directory
from baseclasses.motorcontrolbase import MotorControlBase
from trident_msgs.msg import MotorOutputs, MotorOutput, State
from cola2_msgs.msg import Setpoints
from rclpy.node import Node
from std_srvs.srv import SetBool
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
import std_msgs.msg
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
            namespace='athena', package='athena_motor_driver', executable='motor_driver', output='screen', parameters=[config],
            name=['motor_driver']),
        
        #launch_testing.util.KeepAliveProc(),
        launch_testing.actions.ReadyToTest(),
    ])

class Publisher(Node):
    def __init__(self):
        super().__Init__('publisher')
        self.publisher = self.create_publisher(MotorOutputs, 'athena/motor_control/motor_output', 10)

class Subscriber(Node):
    def __init__(self):
        super().__Init__('subscriber')
        self.publisher = self.create_subscriber(SetPoints, 'athena/simulation/thruster_setpoints', 10)

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
        self.node = rclpy.create_node('test_motor_outputs')

    def tearDown(self):
        self.node.destroy_node()

    def test_manual_override_service(self):
