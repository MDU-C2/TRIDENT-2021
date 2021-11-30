
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
from baseclasses.tridentstates import MissionControlState, GotoWaypointStatus, StartMissionStatus, WaypointActionType
from geometry_msgs.msg import Pose, Point, Quaternion      # https://github.com/ros2/common_interfaces/blob/master/geometry_msgs/msg/Pose.msg
from std_srvs.srv import Trigger        # https://github.com/ros2/common_interfaces/blob/master/std_srvs/srv/Trigger.srv
from trident_msgs.srv import LoadMission, GetState, GetGoalPose, GuidanceRequest
from trident_msgs.action import StartMission, GotoWaypoint
from trident_msgs.msg import Waypoint, WaypointAction, Mission
from example_interfaces.srv import AddTwoInts

@pytest.mark.launch_test
def generate_test_description():
    return launch.LaunchDescription([
        launch.actions.DeclareLaunchArgument(
            'node_prefix',
            default_value=[launch.substitutions.EnvironmentVariable('USER'), '_'],
            description='Prefix for node names'),
        launch_ros.actions.Node(
            package='athena_guidance_system', executable='guidance_system', output='screen',
            name=[launch.substitutions.LaunchConfiguration('node_prefix'), 'guidance_system']),
        
        #launch_testing.util.KeepAliveProc(),
        launch_testing.actions.ReadyToTest(),
    ])


class ServiceTester(Node):

    def __init__(self):
        super().__init__('minimal_client_async')

        #Create client for GuidanceRequest test
        self.cliGuidanceRequest = self.create_client(GuidanceRequest, 'guidance_system/guidance/request')
        while not self.cliGuidanceRequest.wait_for_service(timeout_sec=1.0):
            self.get_logger().info('service GuidanceRequest not available, waiting again...')
        self.reqGuidanceRequest = GuidanceRequest.Request()

        #Create client for GuidanceStop test
        self.cliGuidanceStop = self.create_client(Trigger, 'guidance_system/guidance/stop')
        while not self.cliGuidanceStop.wait_for_service(timeout_sec=1.0):
            self.get_logger().info('service GuidanceStop not available, waiting again...')
        self.reqGuidanceStop = Trigger.Request()

        #Create client for GetState test
        self.cliGetState = self.create_client(GetState, 'guidance_system/state/get')
        while not self.cliGetState.wait_for_service(timeout_sec=1.0):
            self.get_logger().info('service GetState not available, waiting again...')
        self.reqGetState = GetState.Request()
        

    def send_request_GuidanceRequest(self):
        self.reqGuidanceRequest.duration = 10 #10 seconds
        self.future = self.cliGuidanceRequest.call_async(self.reqGuidanceRequest)

    def send_request_GetState(self):
        self.future = self.cliGetState.call_async(self.reqGetState)

    def send_request_GuidanceStop(self):
        self.future = self.cliGuidanceStop.call_async(self.reqGuidanceStop)


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
        minimal_client = ServiceTester()
        minimal_client.send_request_GuidanceRequest()
        
        while rclpy.ok():
            rclpy.spin_once(minimal_client)
            if minimal_client.future.done():
                try:
                    response = minimal_client.future.result()
                except Exception as e:
                    minimal_client.get_logger().info(
                        'Service call failed %r' % (e,))
                else:
                    print(response)
                    self.assertEqual(response.accepted, False, "Guidance system accepted parameter should be: False")
                break
            
        minimal_client.destroy_node()

    def test_service2(self):
        minimal_client = ServiceTester()
        minimal_client.send_request_GetState()
        
        while rclpy.ok():
            rclpy.spin_once(minimal_client)
            if minimal_client.future.done():
                try:
                    response = minimal_client.future.result()
                except Exception as e:
                    minimal_client.get_logger().info(
                        'Service call failed %r' % (e,))
                else:
                    print(response)
                    self.assertEqual(response.success, True, "Guidance system success parameter should be: True")
                    self.assertEqual(response.state, 'IDLE', "Guidance system state parameter should be: IDLE")
                break
            
        minimal_client.destroy_node()

    def test_service3(self):
        minimal_client = ServiceTester()
        minimal_client.send_request_GuidanceStop()
        
        while rclpy.ok():
            rclpy.spin_once(minimal_client)
            if minimal_client.future.done():
                try:
                    response = minimal_client.future.result()
                except Exception as e:
                    minimal_client.get_logger().info(
                        'Service call failed %r' % (e,))
                else:
                    print(response)
                    self.assertEqual(response.success, True, "Guidance system success parameter should be: True")
                break
            
        minimal_client.destroy_node()