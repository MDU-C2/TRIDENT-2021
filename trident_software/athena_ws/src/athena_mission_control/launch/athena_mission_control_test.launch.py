
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
from trident_msgs.srv import LoadMission, GetState
from trident_msgs.action import StartMission, GotoWaypoint
from trident_msgs.msg import Waypoint, WaypointAction, Mission
from example_interfaces.srv import AddTwoInts

@pytest.mark.rostest
def generate_test_description():
    return launch.LaunchDescription([
        launch.actions.DeclareLaunchArgument(
            'node_prefix',
            default_value=[launch.substitutions.EnvironmentVariable('USER'), '_'],
            description='Prefix for node names'),
        launch_ros.actions.Node(
            package='athena_mission_control', executable='mission_control', output='screen',
            name=[launch.substitutions.LaunchConfiguration('node_prefix'), 'navigation']),
        
        #launch_testing.util.KeepAliveProc(),
        launch_testing.actions.ReadyToTest(),
    ])


class MinimalClientAsync(Node):

    def __init__(self):
        super().__init__('minimal_client_async')
        self.cli = self.create_client(LoadMission, 'mission_control/mission/load')
        while not self.cli.wait_for_service(timeout_sec=1.0):
            self.get_logger().info('service not available, waiting again...')
        self.req = LoadMission.Request()

    def send_request(self):
        mission = Mission()
        waypoint = Waypoint()
        wp_action = WaypointAction()
        wp_action.action_type = WaypointActionType.HOLD
        wp_action.action_param = 5
        pose = Pose()
        pose.position.x = 3.0
        pose.position.y = 3.0
        pose.position.z = 3.0
        pose.orientation.x = 0.0
        pose.orientation.y = 0.0
        pose.orientation.z = 0.0
        pose.orientation.w = 1.0
        waypoint.pose = pose
        waypoint.action = wp_action
        mission.waypoints = [waypoint]
        self.get_logger().info("Loaded debug mission.")
        self.req.mission = mission

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
        self.node = rclpy.create_node('test_mission_control_link')

    def tearDown(self):
        self.node.destroy_node()

    def test_service1(self):
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
                    print(response)
                    self.assertEqual(response.success, True, "Response should be True")
                    self.assertEqual(response.success, True, "Response should be True")
                break
            
        minimal_client.destroy_node()
    '''
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
    '''