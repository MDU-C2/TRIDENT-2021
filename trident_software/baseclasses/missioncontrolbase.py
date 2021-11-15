"""Module containing the base class definition for the Mission control nodes.

Author: Johannes Deivard 2021-10
"""
import rclpy
from threading import Event
from baseclasses.tridentstates import MissionControlState, GotoWaypointStatus, StartMissionStatus, WaypointActionType
from rclpy.node import Node
from rclpy.action import ActionClient, ActionServer

from geometry_msgs.msg import Pose, Point, Quaternion      # https://github.com/ros2/common_interfaces/blob/master/geometry_msgs/msg/Pose.msg
from std_srvs.srv import Trigger        # https://github.com/ros2/common_interfaces/blob/master/std_srvs/srv/Trigger.srv
from trident_msgs.srv import LoadMission, GetState
from trident_msgs.action import StartMission, GotoWaypoint
from trident_msgs.msg import Waypoint, WaypointAction, Mission



class MissionControlBase(Node):
    """A base class for the mission control modules in Athena and NAIAD designed with
    generalization in mind.
    """
    def __init__(self, node_name) -> None:
        super().__init__(node_name)
        self._mission_control_state = MissionControlState.NO_MISSION
        self.mission = None
        # Event that keeps track on whether an action has finished or not.
        self._goto_waypoint_done_event = Event()


        # self.get_logger().info('Creating servers.')
        # Create the servers
        # ------------------
        # Server for the mission control's load mission service
        self._server_load_mission = self.create_service(LoadMission, 'mission_control/mission/load', self.server_load_mission_callback)
        # self.get_logger().info('LoadMission server created.')
        self._action_server_start_mission = ActionServer(
            self,
            StartMission,
            'mission_control/mission/start',
            execute_callback=self._action_server_start_mission_execute_callback,
        )
        # self.get_logger().info('StartMission action server created.')

        # Service to retrieve the state of the node
        self._get_state_server = self.create_service(
            GetState,
            'mission_control/state/get',
            self._get_state_callback
        )
        
        # Create the clients
        # ------------------
        self._action_client_goto_waypoint = ActionClient(self, GotoWaypoint, 'navigation/waypoint/go')
        self._goto_waypoint_get_result_future = None
        # self.get_logger().info('GotoWaypoint action client created.')


        # Load the debug mission
        mission = Mission()
        wp_list = []
            
        waypoint = Waypoint()
        wp_action = WaypointAction()
        wp_action.action_type = WaypointActionType.HOLD
        wp_action.action_param = 3
        pose = Pose()
        pose.position.x = 0.0
        pose.position.y = 10.0
        pose.position.z = 0.0
        pose.orientation.x = 0.0
        pose.orientation.y = 0.0
        pose.orientation.z = 0.0
        pose.orientation.w = 0.0
        waypoint.pose = pose
        waypoint.action = wp_action
        wp_list.append(waypoint)

        waypoint = Waypoint()
        wp_action = WaypointAction()
        wp_action.action_type = WaypointActionType.HOLD
        wp_action.action_param = 3
        pose = Pose()
        pose.position.x = 10.0
        pose.position.y = 10.0
        pose.position.z = 0.0
        pose.orientation.x = 0.0
        pose.orientation.y = 0.0
        pose.orientation.z = 0.0
        pose.orientation.w = 0.0
        waypoint.pose = pose
        waypoint.action = wp_action
        wp_list.append(waypoint)

        waypoint = Waypoint()
        wp_action = WaypointAction()
        wp_action.action_type = WaypointActionType.HOLD
        wp_action.action_param = 3
        pose = Pose()
        pose.position.x = 10.0
        pose.position.y = 0.0
        pose.position.z = 0.0
        pose.orientation.x = 0.0
        pose.orientation.y = 0.0
        pose.orientation.z = 0.0
        pose.orientation.w = 0.0
        waypoint.pose = pose
        waypoint.action = wp_action
        wp_list.append(waypoint)

        waypoint = Waypoint()
        wp_action = WaypointAction()
        wp_action.action_type = WaypointActionType.HOLD
        wp_action.action_param = 3
        pose = Pose()
        pose.position.x = 0.0
        pose.position.y = 0.0
        pose.position.z = 0.0
        pose.orientation.x = 0.0
        pose.orientation.y = 0.0
        pose.orientation.z = 0.0
        pose.orientation.w = 0.0
        waypoint.pose = pose
        waypoint.action = wp_action
        wp_list.append(waypoint)

        self.get_logger().info("Loaded debug mission.")
        mission.waypoints = wp_list
        self.mission = mission


    #                   Callbacks
    # -----------------------------------------
    def _get_state_callback(self, _, response):
        """Simple getter for the node's state.
        """
        response.success = True
        response.state = str(self._mission_control_state)
        response.int_state = self._mission_control_state

        return response

    # Goto waypoint action client callbacks
    # -----------------------
    def _goto_waypoint_feedback_callback(self, feedback):
        self.get_logger().info(f"Goto waypoint feedback: Distance to goal: {feedback.feedback.distance_to_goal}" \
                               f"status: {feedback.feedback.status}, Message: {feedback.feedback.message}")

    def _goto_waypoint_goal_response_callback(self, future):
        goal_handle = future.result()
        # Check if the goal was rejected and return early if it was
        if not goal_handle.accepted:
            self.get_logger().info('Waypoint goal rejected.')
            return

        self.get_logger().info('Waypoint goal accepted.')
        # Create the future that gets completed when the action is finished
        self._goto_waypoint_get_result_future = goal_handle.get_result_async()
        # Add the callback for when the future is completed
        self._goto_waypoint_get_result_future.add_done_callback(self._goto_waypoint_get_result_callback)

        return self._goto_waypoint_get_result_future

    def _goto_waypoint_get_result_callback(self, future):
        """Callback for the result future of the GotoWaypoint action.

        Args:
            future (Future): Result future that is finished.
        """
        status = future.result().result.status
        distance_to_goal = future.result().result.distance_to_goal
        message = future.result().result.message
        self.get_logger().info(f"Mission finished {distance_to_goal}m from the goal with status: {GotoWaypointStatus(status)}. {message}")
        # Signal that the event is finished
        self._goto_waypoint_done_event.set()


    def _goto_waypoint_send_goal(self, waypoint):
        """Packs the waypoint into a goal message and sends the goal to the action server.

        Args:
            waypoint (Waypoint): Goal waypoint
        Returns:
            Future that can be waited on.
        """
        goal_msg = GotoWaypoint.Goal()
        goal_msg.waypoint = waypoint
        self._action_client_goto_waypoint.wait_for_server()

        goto_waypoint_send_goal_future = self._action_client_goto_waypoint.send_goal_async(
            goal_msg,
            feedback_callback=self._goto_waypoint_feedback_callback
        )

        goto_waypoint_send_goal_future.add_done_callback(self._goto_waypoint_goal_response_callback)

        return goto_waypoint_send_goal_future

    # Start mission action server callbacks
    # ------------------------------
    async def _action_server_start_mission_execute_callback(self, goal_handle):
        """Executes the given goal by telling the navigation module to start the mission.
        """
        total_waypoints = len(self.mission.waypoints)
        waypoints_succeeded = 0
        waypoints_failed = 0

        # Update mission control state
        self._mission_control_state = MissionControlState.EXECUTING_MISSION
        self.get_logger().info(f"Starting to execute mission with {total_waypoints} waypoints.")

        for i, waypoint in enumerate(self.mission.waypoints):
            self._goto_waypoint_done_event.clear()
            # self.get_logger().info(f"Awaiting goto_waypoint_send_goal")
            goto_waypoint_goal_future = self._goto_waypoint_send_goal(waypoint)
            # Wait for the GotoWaypoint action to finish by waiting on the event property.
            self._goto_waypoint_done_event.wait()
            goto_waypoint_result = self._goto_waypoint_get_result_future.result().result
            self.get_logger().info(f"goto_waypoint_result: {goto_waypoint_result}.")

            if GotoWaypointStatus(goto_waypoint_result.status) in GotoWaypointStatus.FINISHED:
                waypoints_succeeded += 1
                # Create the feedback message
                informational = f"Completed waypoint {i+1}. Progress: {i+1}/{total_waypoints}."
            else:
                waypoints_failed += 1
                informational = f"Failed waypoint {i+1}. Progress: {i+1}/{total_waypoints}."

            # Log the informational message
            self.get_logger().info(informational)
            feedback_msg = StartMission.Feedback()
            # Check if this was the last waypoint and set the mission status in the feedback msg accordingly
            if i == total_waypoints:
                feedback_msg.status = StartMissionStatus.FINISHED
            else:
                feedback_msg.status = StartMissionStatus.EXECUTING

            feedback_msg.waypoints_completed = i+1
            feedback_msg.message = informational
            goal_handle.publish_feedback(feedback_msg)

        # Update mission control state, since the mission is finished.
        self._mission_control_state = MissionControlState.MISSION_FINISHED
        # goal_handle.succeed()
        
        # Set the goal state
        goal_handle.succeed()
        result = StartMission.Result()
        result.success = True if StartMissionStatus.FINISHED else False
        result.message = f"Mission with {total_waypoints} waypoints finished."
        self.get_logger().info(result.message)

        return result


    def server_load_mission_callback(self, request, response):
        """Callback function for the mission_control/mission/load server.

        Args:
            request: Contains the mission to load.
            response: Boolean succcess and string message for information.
        """
        # Validity checks:
        # Empty mission
        if len(request.mission.waypoints) == 0:
            mission = Mission()
            wp_list = []
            
            waypoint = Waypoint()
            wp_action = WaypointAction()
            wp_action.action_type = WaypointActionType.HOLD
            wp_action.action_param = 3
            pose = Pose()
            pose.position.x = 0.0
            pose.position.y = 20.0
            pose.position.z = -2.0
            pose.orientation.x = 0.0
            pose.orientation.y = 0.0
            pose.orientation.z = 0.0
            pose.orientation.w = 0.0
            waypoint.pose = pose
            waypoint.action = wp_action
            wp_list.append(waypoint)

            waypoint = Waypoint()
            wp_action = WaypointAction()
            wp_action.action_type = WaypointActionType.HOLD
            wp_action.action_param = 3
            pose = Pose()
            pose.position.x = 20.0
            pose.position.y = 20.0
            pose.position.z = -2.0
            pose.orientation.x = 0.0
            pose.orientation.y = 0.0
            pose.orientation.z = 0.0
            pose.orientation.w = 0.0
            waypoint.pose = pose
            waypoint.action = wp_action
            wp_list.append(waypoint)

            waypoint = Waypoint()
            wp_action = WaypointAction()
            wp_action.action_type = WaypointActionType.HOLD
            wp_action.action_param = 3
            pose = Pose()
            pose.position.x = 20.0
            pose.position.y = 0.0
            pose.position.z = -2.0
            pose.orientation.x = 0.0
            pose.orientation.y = 0.0
            pose.orientation.z = 0.0
            pose.orientation.w = 0.0
            waypoint.pose = pose
            waypoint.action = wp_action
            wp_list.append(waypoint)

            waypoint = Waypoint()
            wp_action = WaypointAction()
            wp_action.action_type = WaypointActionType.HOLD
            wp_action.action_param = 3
            pose = Pose()
            pose.position.x = 0.0
            pose.position.y = 0.0
            pose.position.z = -2.0
            pose.orientation.x = 0.0
            pose.orientation.y = 0.0
            pose.orientation.z = 0.0
            pose.orientation.w = 0.0
            waypoint.pose = pose
            waypoint.action = wp_action
            wp_list.append(waypoint)

            self.get_logger().info("Loaded debug mission.")
            mission.waypoints = wp_list
            self.mission = mission
            response.success = True
            response.message = "Loaded debug mission"

            # response.success = False
            # response.message = "Cannot load a mission with 0 waypoints."

            return response
            
        try:
            self.get_logger().info(f"Received mission with {len(request.mission.waypoints)} waypoints.")
            self.mission = request.mission
            response.success = True
            response.message = f"Mission with {len(request.mission.waypoints)} waypoints loaded."

        except TypeError as error:
            self.mission = None
            response.success = False
            response.message = f"Failed to load the mission. Error: {error}"
        
        return response



