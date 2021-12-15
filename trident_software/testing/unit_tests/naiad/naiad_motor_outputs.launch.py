from ament_index_python.packages import get_package_share_directory
from baseclasses.motorcontrolbase import MotorControlBase
from trident_msgs.msg import MotorOutputs, MotorOutput, State
from cola2_msgs.msg import Setpoints
from rclpy.node import Node
from std_srvs.srv import SetBool
from std_srvs.srv import Trigger        # https://github.com/ros2/common_interfaces/blob/master/std_srvs/srv/Trigger.srv
from threading import Thread
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
            namespace='naiad', package='naiad_driver', executable='motor_driver', output='screen', parameters=[config, {'simulation': True}, {'motor_output_scale': 0.5}],
            name=['motor_driver']),
        
        #launch_testing.util.KeepAliveProc(),
        launch_testing.actions.ReadyToTest(),
    ])

class TestNode(Node):
    def __init__(self):
        super().__init__('publisher')

        self.msg = MotorOutputs()

        self.publisher = self.create_publisher(MotorOutputs, 'naiad/motor_control/motor_output', 10)
        self.get_logger().info('Publishing motor_outputs at 1Hz...')
        timer_period = 1
        self.timer = self.create_timer(timer_period, self.pub_callback)
        self.subscriber = self.create_subscription(Setpoints, 'naiad/simulation/thruster_setpoints', self.sub_callback, 10)
        self.get_logger().info('Listening for thruster setpoints...')
        self.done = False

    def pub_callback(self):
        self.msg.motor_outputs = [MotorOutput(id=1, value=0.4), MotorOutput(id=2, value=0.3), MotorOutput(id=3, value=0.4), MotorOutput(id=4, value=0.3), MotorOutput(id=5, value=0.4), MotorOutput(id=6, value=0.3)]
        self.publisher.publish(self.msg)
            
    def sub_callback(self, msg):
        self.msg = msg
        self.get_logger().info('Recieved message: %s' % self.msg.setpoints)
        self.publisher.destroy()
        self.destroy_node()
        self.done = True

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

    def test_motor_outputs(self):
        test_node = TestNode()

        while not test_node.done:
            rclpy.spin_once(test_node)

        self.assertTrue(type(test_node.msg) is Setpoints, "Did not recieve message with type \"Setpoints\"")

