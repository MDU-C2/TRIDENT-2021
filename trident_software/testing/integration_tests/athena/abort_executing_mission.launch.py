
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
from threading import Thread

import std_msgs.msg
from baseclasses.tridentstates import MissionControlState, GotoWaypointStatus, StartMissionStatus, WaypointActionType
from geometry_msgs.msg import Pose, Point, Quaternion      # https://github.com/ros2/common_interfaces/blob/master/geometry_msgs/msg/Pose.msg
from std_srvs.srv import Trigger        # https://github.com/ros2/common_interfaces/blob/master/std_srvs/srv/Trigger.srv
from trident_msgs.srv import LoadMission, GetState
from trident_msgs.action import StartMission, GotoWaypoint
from trident_msgs.msg import Waypoint, WaypointAction, Mission
from example_interfaces.srv import AddTwoInts

from squaternion import Quaternion
from rclpy.action import ActionClient
from action_msgs.msg import GoalStatus

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
        self.loadMission = self.create_client(LoadMission, 'mission_control/mission/load')
        while not self.loadMission.wait_for_service(timeout_sec=1.0):
            self.get_logger().info('service LoadMission not available, waiting again...')
        self.reqLoadMission = LoadMission.Request()

        #Create client for abort test
        self.abort = self.create_client(Trigger, 'motor_driver/motors/kill')
        while not self.abort.wait_for_service(timeout_sec=1.0):
            self.get_logger().info('service Abort not available, waiting again...')
        self.reqAbort = Trigger.Request()

        #Create client for GetState test
        self.getStateMissionControl = self.create_client(GetState, 'mission_control/state/get')
        while not self.getStateMissionControl.wait_for_service(timeout_sec=1.0):
            self.get_logger().info('service GetState not available, waiting again...')
        self.reqGetState = GetState.Request()

        self.getStateNavigation = self.create_client(GetState, 'mission_control/state/get')
        while not self.getStateNavigation.wait_for_service(timeout_sec=1.0):
            self.get_logger().info('service GetState not available, waiting again...')
        self.reqGetState = GetState.Request()

        self.getStateMotorControl = self.create_client(GetState, 'mission_control/state/get')
        while not self.getStateMotorControl.wait_for_service(timeout_sec=1.0):
            self.get_logger().info('service GetState not available, waiting again...')
        self.reqGetState = GetState.Request()

        self.getStateMotorDriver = self.create_client(GetState, 'mission_control/state/get')
        while not self.getStateMotorDriver.wait_for_service(timeout_sec=1.0):
            self.get_logger().info('service GetState not available, waiting again...')
        self.reqGetState = GetState.Request()

        self.getStateGuidanceSystem = self.create_client(GetState, 'mission_control/state/get')
        while not self.getStateGuidanceSystem.wait_for_service(timeout_sec=1.0):
            self.get_logger().info('service GetState not available, waiting again...')
        self.reqGetState = GetState.Request()

    def send_request_LoadMission(self):
        for i in range(2):
            mission = Mission()
            waypoint = Waypoint()
            wp_action = WaypointAction()
            wp_action.action_type = WaypointActionType.HOLD
            wp_action.action_param = 5
            pose = Pose()
            pose.position.x = 20.0 + (i*20)
            pose.position.y = 20.0 + (i*20)
            pose.position.z = 0.0
            pose.orientation.x = 0.0
            pose.orientation.y = 0.0
            pose.orientation.z = 0.0
            pose.orientation.w = 1.0
            waypoint.pose = pose
            waypoint.action = wp_action
            mission.waypoints.push(waypoint)
        self.get_logger().info("Loaded mission with 2 waypoints.")
        self.reqLoadMission.mission = mission
        self.future = self.loadMission.call_async(self.reqLoadMission)

    def send_request_Abort(self):
        self.future = self.abort.call_async(self.reqAbort)

    def send_request_GetState(self, module):
        if (module == 'mission_control'):
            self.future = self.getStateMissionControl.call_async(self.reqGetState)
        elif (module == 'navigation'):
            self.future = self.getStateNavigation.call_async(self.reqGetState)
        elif (module == 'motor_control'):
            self.future = self.getStateMotorControl.call_async(self.reqGetState)
        elif (module == 'motor_driver'):
            self.future = self.getStateMotorDriver.call_async(self.reqGetState)
        elif (module == 'guidance_system'):
            self.future = self.getStateGuidanceSystem.call_async(self.reqGetState)
        
class MinimalActionClient(Node):

    def __init__(self):
        super().__init__('minimal_client_async')
        self.actcli = ActionClient(self, StartMission, 'mission_control/mission/start')
        self.action_finished = False
        self.waypoints_completed = 0

    def start_mission(self):
        goal_msg = {}
        
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
        self.get_logger().info(f"status: {feedback.feedback.status}, Message: {feedback.feedback.message}, Waypoints completed: {feedback.feedback.waypoints_completed}")
        self.waypoints_completed = feedback.feedback.waypoints_completed
        self.get_logger().info('Propagating feedback to GotoWaypoint client.')

    def get_result_callback(self, future):
        self.finalresult = future.result().result
        self.finalstatus = future.result().status
        if self.finalstatus == GoalStatus.STATUS_SUCCEEDED:
            self.get_logger().info('Goal succeeded! Result: {0}'.format(self.finalresult))
        else:
            self.get_logger().info('Goal failed with status: {0}'.format(self.finalstatus))

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
        self.node = rclpy.create_node('integration_test_athena_link')

    def tearDown(self):
        self.node.destroy_node()

    def test_service1(self,test_args):
        time.sleep(5)
        print("test")

    '''
    Step 1:
    Check each module state
    '''
    def test_get_state_1(self,proc_output):
        minimal_client = ServiceTester()
        minimal_client.send_request_GetState('mission_control')
        
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
                    self.assertEqual(response.success, True, "Mission control success parameter should be: True")
                    self.assertEqual(response.state, 'IDLE', "Mission control state parameter should be: IDLE")
                break
        
        minimal_client.send_request_GetState('navigation')
        
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
                    self.assertEqual(response.success, True, "Navigation success parameter should be: True")
                    self.assertEqual(response.state, 'IDLE', "Navigation state parameter should be: IDLE")
                break

        minimal_client.send_request_GetState('motor_control')
        
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
                    self.assertEqual(response.success, True, "Motor control success parameter should be: True")
                    self.assertEqual(response.state, 'IDLE', "Motor control state parameter should be: IDLE")
                break

        minimal_client.send_request_GetState('motor_driver')
        
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
                    self.assertEqual(response.success, True, "Motor driver success parameter should be: True")
                    self.assertEqual(response.state, 'IDLE', "Motor driver state parameter should be: IDLE")
                break

        minimal_client.send_request_GetState('guidance_system')
        
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
    
    '''
    Step 2:
    Load mission with two waypoints
    '''
    def test_load_mission_2(self):
        minimal_client = ServiceTester()
        minimal_client.send_request_LoadMission()
        
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
                    self.assertEqual(response.success, True, "Mission control success parameter should be: True")
                break
            
        minimal_client.destroy_node()

    '''
    Step 3:
    Check mission control state
    '''
    def test_get_state_3(self,proc_output):
        minimal_client = ServiceTester()
        minimal_client.send_request_GetState('mission_control')
        
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
                    self.assertEqual(response.success, True, "Mission control success parameter should be: True")
                    self.assertEqual(response.state, 'IDLE', "Mission control state parameter should be: IDLE")
                break

        minimal_client.destroy_node()

    '''
    Step 4/5/6:
    Start mission plan
    '''
    def test_start_mission_4_5_6(self,proc_output):
        # Step 4:
        # Create and start the Action client that sends the GotoPose service call
        action_client = MinimalActionClient()
        action_client.start_mission()

        # Step 5:
        # Get current state of each module
        time.sleep(3)
        minimal_client = ServiceTester()
        minimal_client.send_request_GetState('mission_control')
        
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
                    self.assertEqual(response.success, True, "Mission control success parameter should be: True")
                    self.assertEqual(response.state, 'EXECUTING_MISSION', "Mission control state parameter should be: EXECUTING_MISSION")
                break
        
        minimal_client.send_request_GetState('navigation')
        
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
                    self.assertEqual(response.success, True, "Navigation success parameter should be: True")
                    self.assertEqual(response.state, 'EXECUTING', "Navigation state parameter should be: EXECUTING")
                break

        minimal_client.send_request_GetState('motor_control')
        
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
                    self.assertEqual(response.success, True, "Motor control success parameter should be: True")
                    self.assertEqual(response.state, 'EXECUTING', "Motor control state parameter should be: EXECUTING")
                break

        minimal_client.send_request_GetState('motor_driver')
        
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
                    self.assertEqual(response.success, True, "Motor driver success parameter should be: True")
                    self.assertEqual(response.state, 'ACTIVE', "Motor driver state parameter should be: ACTIVE")
                break

        minimal_client.send_request_GetState('guidance_system')
        
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

        # Step 6:
        # Wait for target to reach first waypoint
        while(action_client.waypoints_completed != 1):
            rclpy.spin_once(action_client)

        # When first waypoint has been reached, send abort command
        minimal_client = ServiceTester()
        minimal_client.send_request_Abort()
        
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
                    self.assertEqual(response.success, True, "Motor driver success parameter should be: True")
                break

        minimal_client.send_request_GetState('motor_driver')
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
                    self.assertEqual(response.success, True, "Motor driver success parameter should be: True")
                    self.assertEqual(response.state, 'KILLED', "Motor driver state parameter should be: KILLED")
                break
            
        minimal_client.destroy_node()