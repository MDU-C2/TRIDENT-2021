
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

from ament_index_python.packages import get_package_share_directory
import sys
import os

@pytest.mark.launch_test
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
            package='athena_mission_control',
            namespace='athena',
            executable='mission_control',
            output='screen',
            name='mission_control',
            parameters=[config]
           ),
        launch_ros.actions.Node(
            package='athena_navigation',
            namespace='athena',
            executable='navigation',
            output='screen',
            name='navigation',
            parameters=[config]
           ),
        launch_ros.actions.Node(
            package='athena_motor_control',
            namespace='athena',
            executable='motor_control',
            output='screen',
            name='motor_control',
            parameters=[config,
                {'use_sim_odom': True}
            ]
           ),
        launch_ros.actions.Node(
            package='athena_driver',
            namespace='athena',
            executable='motor_driver',
            output='screen',
            name='motor_driver',
            parameters=[config,
                {'simulation': True},
                {'motor_output_scale': 0.5}
            ]
           ),
        launch_ros.actions.Node(
            package='athena_guidance_system',
            namespace='athena',
            executable='guidance_system',
            output='screen',
            name='guidance_system',
            parameters=[config]
           ),
        launch_ros.actions.Node(
            package='athena_position',
            namespace='/athena/position/',
            executable='position_node',
            name='pos'
          ),
        launch_ros.actions.Node(
            package='athena_position',
            namespace='/athena/sensor/',
            executable='imu_node',
            name='imu',
            parameters=[
                {"is_simulated": True}
            ]
          ),
        launch_ros.actions.Node(
            package='athena_position',
            namespace='/athena/sensor/',
            executable='gps_node',
            name='gps',
            parameters=[
                {"is_simulated": True}
            ]
          ),
        #launch_testing.util.KeepAliveProc(),
        launch_testing.actions.ReadyToTest(),
        ])

class ServiceTester(Node):

    def __init__(self):
        super().__init__('minimal_client_async')

        #Create client for LoadMission test
        self.cliLoadMission = self.create_client(LoadMission, 'mission_control/mission/load')
        while not self.cliLoadMission.wait_for_service(timeout_sec=1.0):
            self.get_logger().info('service LoadMission not available, waiting again...')
        self.reqLoadMission = LoadMission.Request()

        #Create client for GetState test
        self.cliGetState = self.create_client(GetState, 'mission_control/state/get')
        while not self.cliGetState.wait_for_service(timeout_sec=1.0):
            self.get_logger().info('service GetState not available, waiting again...')
        self.reqGetState = GetState.Request()

    def send_request_LoadMission(self):
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
        self.reqLoadMission.mission = mission
        self.future = self.cliLoadMission.call_async(self.reqLoadMission)

    def send_request_GetState(self):
        self.future = self.cliGetState.call_async(self.reqGetState)

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

    def test_service1(self,test_args):
        time.sleep(5)
        print("test")
