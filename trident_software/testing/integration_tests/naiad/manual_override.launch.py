
import unittest

import launch
import launch_ros
import launch_ros.actions
import launch.actions
import launch.substitutions

import launch_testing.actions

import pytest
import rclpy
from rclpy.node import Node
import time
from squaternion import Quaternion
from rclpy.action import ActionClient

from geometry_msgs.msg import Pose      # https://github.com/ros2/common_interfaces/blob/master/geometry_msgs/msg/Pose.msg
from std_srvs.srv import SetBool        # https://github.com/ros2/common_interfaces/blob/master/std_srvs/srv/Trigger.srv
from trident_msgs.srv import LoadMission, GetState
from trident_msgs.action import StartMission
from trident_msgs.msg import Waypoint, WaypointAction, Mission
from baseclasses.tridentstates import WaypointActionType

from ament_index_python.packages import get_package_share_directory
import os

@pytest.mark.launch_test
def generate_test_description():
    config = os.path.join(
        get_package_share_directory('naiad_bringup'),
        'config',
        'system_launch_params.yaml'
    )

    args = ['--ros-args', '--log-level', 'warn'] if True else ''

    return launch.LaunchDescription([
        launch.actions.DeclareLaunchArgument(
            'node_prefix',
            default_value=[launch.substitutions.EnvironmentVariable('USER'), '_'],
            description='Prefix for node names',
        ),
        launch_ros.actions.Node(
            package='naiad_mission_control',
            namespace='naiad',
            executable='mission_control',
            output='screen',
            name='mission_control',
            parameters=[config],
            arguments=args
           ),
        launch_ros.actions.Node(
            package='naiad_navigation',
            namespace='naiad',
            executable='navigation',
            output='screen',
            name='navigation',
            parameters=[config],
            arguments=args
           ),
        launch_ros.actions.Node(
            package='naiad_motor_control',
            namespace='naiad',
            executable='motor_control',
            output='screen',
            name='motor_control',
            parameters=[config,
                {'use_sim_odom': True}
            ],
            arguments=args
           ),
        launch_ros.actions.Node(
            package='naiad_driver',
            namespace='naiad',
            executable='motor_driver',
            output='screen',
            name='motor_driver',
            parameters=[config,
                {'simulation': True},
                {'motor_output_scale': 0.5}
            ],
            arguments=args
           ),
        launch_ros.actions.Node(
            package='naiad_guidance_system',
            namespace='naiad',
            executable='guidance_system',
            output='screen',
            name='guidance_system',
            parameters=[config],
            arguments=args
           ),
        launch_ros.actions.Node(
            package='naiad_position',
            namespace='/naiad/position/',
            executable='position_node',
            name='pos',
            arguments=args
          ),
        launch_ros.actions.Node(
            package='naiad_position',
            namespace='/naiad/sensor/',
            executable='imu_node',
            name='imu',
            parameters=[
                {"simulated": True}
            ],
            arguments=args
          ),
        launch_ros.actions.Node(
            package='naiad_position',
            namespace='/naiad/sensor/',
            executable='gps_node',
            name='gps',
            parameters=[
                {"simulated": True}
            ],
            arguments=args
          ),
        launch_ros.actions.Node(
            package='naiad_position',
            namespace='/naiad/sensor',
            executable='usbl_node',
            name='usbl',
            parameters=[
                {"simulated": True}
            ],
            arguments=args
        ),
        launch_ros.actions.Node(
            package='naiad_position',
            namespace='/naiad/sensor',
            executable='pressure_node',
            name='pressure',
            parameters=[
                {"simulated": True}
            ],
            arguments=args
        ),
        #launch_testing.util.KeepAliveProc(),
        launch_testing.actions.ReadyToTest(),
    ])

class MinimalServiceClient(Node):
    def __init__(self):
        super().__init__('get_state_client')
        self.mission_control_getstate = self.create_client(GetState, 'naiad/mission_control/state/get')
        self.navigation_getstate = self.create_client(GetState, 'naiad/navigation/state/get')
        self.motor_control_getstate = self.create_client(GetState, 'naiad/motor_control/state/get')
        self.motor_driver_getstate = self.create_client(GetState, 'naiad/motor_driver/state/get')
        self.guidance_system_getstate = self.create_client(GetState, 'naiad/guidance_system/state/get')
        self.cliLoadMission = self.create_client(LoadMission, 'naiad/mission_control/mission/load')
        self.manual_override = self.create_client(SetBool, 'naiad/motor_control/manual_override')

        while not self.mission_control_getstate.wait_for_service(timeout_sec=1.0):
            self.get_logger().info('mission control service not available, waiting again...')
        while not self.navigation_getstate.wait_for_service(timeout_sec=1.0):
            self.get_logger().info('navigation service not available, waiting again...')
        while not self.motor_control_getstate.wait_for_service(timeout_sec=1.0):
            self.get_logger().info('motor control service not available, waiting again...')
        while not self.motor_driver_getstate.wait_for_service(timeout_sec=1.0):
            self.get_logger().info('motor driver service not available, waiting again...')
        while not self.guidance_system_getstate.wait_for_service(timeout_sec=1.0):
            self.get_logger().info('guidance system service not available, waiting again...')
        while not self.cliLoadMission.wait_for_service(timeout_sec=1.0):
            self.get_logger().info('service LoadMission not available, waiting again...')
        while not self.manual_override.wait_for_service(timeout_sec=1.0):
            self.get_logger().info('service manual override not available, waiting again...')

        self.mission_control_req = GetState.Request()
        self.navigation_req = GetState.Request()
        self.motor_control_req = GetState.Request()
        self.motor_driver_req = GetState.Request()
        self.guidance_system_req = GetState.Request()
        self.reqLoadMission = LoadMission.Request()
        self.reqManualOverride = SetBool.Request()

    def send_getstate_request(self, module):
        if module == "mission_control":
            self.mission_control_future = None
            self.mission_control_future = self.mission_control_getstate.call_async(self.mission_control_req)
        elif module == "navigation":
            self.navigation_future = None
            self.navigation_future = self.navigation_getstate.call_async(self.navigation_req)
        elif module == "motor_control":
            self.motor_control_future = None
            self.motor_control_future = self.motor_control_getstate.call_async(self.motor_control_req)
        elif module == "motor_driver":
            self.motor_driver_future = None
            self.motor_driver_future = self.motor_driver_getstate.call_async(self.motor_driver_req)
        elif module == "guidance_system":
            self.guidance_system_future = None
            self.guidance_system_future = self.guidance_system_getstate.call_async(self.guidance_system_req)
        else:
            print("Error: Invalid request parameter")
            exit(1)

    def send_load_request(self, points):
        mission = Mission()
        for point in points:
            waypoint = Waypoint()
            wp_action = WaypointAction()
            if point[7]:
                wp_action.action_type = WaypointActionType.HOLD
                wp_action.action_param = point[6]
            else:
                wp_action.action_type = WaypointActionType.NO_ACTION
                wp_action.action_param = 0
            pose = Pose()
            pose.position.x = point[0]
            pose.position.y = point[1]
            pose.position.z = point[2]
            q = Quaternion.from_euler(point[3], point[4], point[5], degrees=True)
            pose.orientation.x = q.x
            pose.orientation.y = q.y
            pose.orientation.z = q.z
            pose.orientation.w = q.w
            waypoint.pose = pose
            waypoint.action = wp_action
            mission.waypoints.append(waypoint)
        self.get_logger().info("Loaded debug mission.")
        self.reqLoadMission.mission = mission
        self.load_future = self.cliLoadMission.call_async(self.reqLoadMission)

    def send_manual_override_request(self, value):
        self.reqManualOverride.data = value
        self.manual_override_future = None
        self.manual_override_future = self.manual_override.call_async(self.reqManualOverride)

class MinimalActionClient(Node):

    def __init__(self):
        super().__init__('load_mission_client')
        self.cliStartMission = ActionClient(self, StartMission, 'naiad/mission_control/mission/start')
        self.mission_done = False
        self.start_waypoints_completed = 0

    def send_start_request(self):
        start = StartMission.Goal()
        self.start_future = self.cliStartMission.send_goal_async(start, self.start_mission_feedback_callback)
        self.start_future.add_done_callback(self.start_mission_response_callback)

    def start_mission_feedback_callback(self, feedback_msg):
        start_feedback = feedback_msg.feedback
        self.start_waypoints_completed = start_feedback.waypoints_completed

    def start_mission_response_callback(self, future):
        handle = future.result()
        if not handle.accepted:
            self.get_logger().info('Start mission action rejected.')
            return

        self.start_result_future = handle.get_result_async()
        self.start_result_future.add_done_callback(self.start_mission_done_callback)

    def start_mission_done_callback(self, future):
        self.start_mission_result = future.result().result
        self.mission_done = True

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
        self.node = rclpy.create_node('manual_override_test')

    def tearDown(self):
        self.node.destroy_node()

    def test_service1(self, test_args):
        service_client = MinimalServiceClient()
        action_client = MinimalActionClient()

        #--------------------------
        # (1) Get states of modules
        #--------------------------
        service_client.send_getstate_request("mission_control")
        rclpy.spin_until_future_complete(service_client, service_client.mission_control_future)
        service_client.send_getstate_request("navigation")
        rclpy.spin_until_future_complete(service_client, service_client.navigation_future)
        service_client.send_getstate_request("motor_control")
        rclpy.spin_until_future_complete(service_client, service_client.motor_control_future)
        service_client.send_getstate_request("motor_driver")
        rclpy.spin_until_future_complete(service_client, service_client.motor_driver_future)
        service_client.send_getstate_request("guidance_system")
        rclpy.spin_until_future_complete(service_client, service_client.guidance_system_future)

        rclpy.logging.get_logger("TEST").info("Checking states...")
        self.assertEqual(service_client.mission_control_future.result().state, 'NO_MISSION')
        self.assertEqual(service_client.navigation_future.result().state, 'IDLE')
        self.assertEqual(service_client.motor_control_future.result().state, 'IDLE')
        self.assertEqual(service_client.motor_driver_future.result().state, 'IDLE')
        self.assertEqual(service_client.guidance_system_future.result().state, 'IDLE')

        #--------------------------
        # (2) Load mission
        #--------------------------
        time.sleep(0.5)
        service_client.send_load_request([[5.0, 5.0, 3.0, 0.0, 0.0, 0.0, 2, True],
                                          [0.0, 0.0, 3.0, 0.0, 0.0, 0.0, 2, False]])
        rclpy.logging.get_logger("TEST").info("Sending load mission request")
        rclpy.spin_until_future_complete(service_client, service_client.load_future)
        self.assertTrue(service_client.load_future.result().success)

        #--------------------------
        # (3) Get state of mission control
        #--------------------------
        time.sleep(0.5)
        service_client.send_getstate_request("mission_control")
        rclpy.spin_until_future_complete(service_client, service_client.mission_control_future)
        service_client.send_getstate_request("navigation")
        rclpy.spin_until_future_complete(service_client, service_client.navigation_future)
        service_client.send_getstate_request("motor_control")
        rclpy.spin_until_future_complete(service_client, service_client.motor_control_future)
        service_client.send_getstate_request("motor_driver")
        rclpy.spin_until_future_complete(service_client, service_client.motor_driver_future)
        service_client.send_getstate_request("guidance_system")
        rclpy.spin_until_future_complete(service_client, service_client.guidance_system_future)

        rclpy.logging.get_logger("TEST").info("Checking states...")
        self.assertEqual(service_client.mission_control_future.result().state, 'MISSION_LOADED')
        self.assertEqual(service_client.navigation_future.result().state, 'IDLE')
        self.assertEqual(service_client.motor_control_future.result().state, 'IDLE')
        self.assertEqual(service_client.motor_driver_future.result().state, 'IDLE')
        self.assertEqual(service_client.guidance_system_future.result().state, 'IDLE')

        #--------------------------
        # (4) Start mission
        #--------------------------
        time.sleep(0.5)
        action_client.send_start_request()
        rclpy.logging.get_logger("TEST").info("Sending start mission request")
        rclpy.spin_until_future_complete(action_client, action_client.start_future)

        #--------------------------
        # (5) Get state of modules
        #--------------------------
        time.sleep(0.5)
        service_client.send_getstate_request("mission_control")
        rclpy.spin_until_future_complete(service_client, service_client.mission_control_future)
        service_client.send_getstate_request("navigation")
        rclpy.spin_until_future_complete(service_client, service_client.navigation_future)
        service_client.send_getstate_request("motor_control")
        rclpy.spin_until_future_complete(service_client, service_client.motor_control_future)
        service_client.send_getstate_request("motor_driver")
        rclpy.spin_until_future_complete(service_client, service_client.motor_driver_future)
        service_client.send_getstate_request("guidance_system")
        rclpy.spin_until_future_complete(service_client, service_client.guidance_system_future)

        rclpy.logging.get_logger("TEST").info("Checking states...")
        self.assertEqual(service_client.mission_control_future.result().state, 'EXECUTING_MISSION')
        self.assertEqual(service_client.navigation_future.result().state, 'EXECUTING')
        self.assertEqual(service_client.motor_control_future.result().state, 'EXECUTING')
        self.assertEqual(service_client.motor_driver_future.result().state, 'ACTIVE')
        self.assertEqual(service_client.guidance_system_future.result().state, 'IDLE')

        #--------------------------
        # (6) Await 1st waypoint complete and turn on manual override
        #--------------------------
        rclpy.logging.get_logger("TEST").info("Wait for 1st waypoint to complete...")
        while action_client.start_waypoints_completed < 1:
            rclpy.spin_once(action_client)
        rclpy.logging.get_logger("TEST").info("Send manual override ON request...")
        service_client.send_manual_override_request(True)
        rclpy.spin_until_future_complete(service_client, service_client.manual_override_future)
        try:
            response = service_client.manual_override_future.result()
        except Exception as e:
            service_client.get_logger().info('Service call failed %r' % (e,))
        else:
            self.assertTrue(response.success)

        #--------------------------
        # (7) Get state of modules
        #--------------------------
        time.sleep(0.5)
        service_client.send_getstate_request("mission_control")
        rclpy.spin_until_future_complete(service_client, service_client.mission_control_future)
        service_client.send_getstate_request("navigation")
        rclpy.spin_until_future_complete(service_client, service_client.navigation_future)
        service_client.send_getstate_request("motor_control")
        rclpy.spin_until_future_complete(service_client, service_client.motor_control_future)
        service_client.send_getstate_request("motor_driver")
        rclpy.spin_until_future_complete(service_client, service_client.motor_driver_future)
        service_client.send_getstate_request("guidance_system")
        rclpy.spin_until_future_complete(service_client, service_client.guidance_system_future)

        rclpy.logging.get_logger("TEST").info("Checking states...")
        self.assertEqual(service_client.mission_control_future.result().state, 'EXECUTING_MISSION')
        self.assertEqual(service_client.navigation_future.result().state, 'EXECUTING')
        self.assertEqual(service_client.motor_control_future.result().state, 'MANUAL_OVERRIDE')
        self.assertEqual(service_client.motor_driver_future.result().state, 'MOTOR_OUTPUT_SILENCE')
        self.assertEqual(service_client.guidance_system_future.result().state, 'IDLE')

        #--------------------------
        # (8) Turn off manual override
        #--------------------------
        rclpy.logging.get_logger("TEST").info("Send manual override OFF request...")
        service_client.send_manual_override_request(False)
        rclpy.spin_until_future_complete(service_client, service_client.manual_override_future)
        try:
            response = service_client.manual_override_future.result()
        except Exception as e:
            service_client.get_logger().info('Service call failed %r' % (e,))
        else:
            self.assertTrue(response.success)

        #--------------------------
        # (9) Get state of modules
        #--------------------------
        time.sleep(0.5)
        service_client.send_getstate_request("mission_control")
        rclpy.spin_until_future_complete(service_client, service_client.mission_control_future)
        service_client.send_getstate_request("navigation")
        rclpy.spin_until_future_complete(service_client, service_client.navigation_future)
        service_client.send_getstate_request("motor_control")
        rclpy.spin_until_future_complete(service_client, service_client.motor_control_future)
        service_client.send_getstate_request("motor_driver")
        rclpy.spin_until_future_complete(service_client, service_client.motor_driver_future)
        service_client.send_getstate_request("guidance_system")
        rclpy.spin_until_future_complete(service_client, service_client.guidance_system_future)

        rclpy.logging.get_logger("TEST").info("Checking states...")
        self.assertEqual(service_client.mission_control_future.result().state, 'EXECUTING_MISSION')
        self.assertEqual(service_client.navigation_future.result().state, 'EXECUTING')
        self.assertEqual(service_client.motor_control_future.result().state, 'EXECUTING')
        self.assertEqual(service_client.motor_driver_future.result().state, 'ACTIVE')
        self.assertEqual(service_client.guidance_system_future.result().state, 'IDLE')

        #--------------------------
        # (10) Await mission finish response
        #--------------------------
        time.sleep(0.5)
        while not action_client.mission_done:
            rclpy.spin_once(action_client)
        self.assertTrue(action_client.start_mission_result.success)
        rclpy.logging.get_logger("TEST").info("Got mission finish response")

        #--------------------------
        # (11) Get state of modules
        #--------------------------
        time.sleep(0.5)
        service_client.send_getstate_request("mission_control")
        rclpy.spin_until_future_complete(service_client, service_client.mission_control_future)
        service_client.send_getstate_request("navigation")
        rclpy.spin_until_future_complete(service_client, service_client.navigation_future)
        service_client.send_getstate_request("motor_control")
        rclpy.spin_until_future_complete(service_client, service_client.motor_control_future)
        service_client.send_getstate_request("motor_driver")
        rclpy.spin_until_future_complete(service_client, service_client.motor_driver_future)
        service_client.send_getstate_request("guidance_system")
        rclpy.spin_until_future_complete(service_client, service_client.guidance_system_future)

        rclpy.logging.get_logger("TEST").info("Checking states...")
        self.assertEqual(service_client.mission_control_future.result().state, 'MISSION_FINISHED')
        self.assertEqual(service_client.navigation_future.result().state, 'IDLE')
        self.assertEqual(service_client.motor_control_future.result().state, 'IDLE')
        self.assertEqual(service_client.motor_driver_future.result().state, 'MOTOR_OUTPUT_SILENCE')
        self.assertEqual(service_client.guidance_system_future.result().state, 'IDLE')

        service_client.destroy_node()
