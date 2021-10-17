"""Module containing the base class definition for the Mission contorl nodes.

Author: Johannes Deivard

Last edited: 2021-10-17 by Johannes Deivard
"""
import rclpy
from tridentstates import MissionControlState, GotoWaypointStatus, StartMissionStatus
from rclpy.node import Node
from rclpy.action import ActionClient, ActionServer

from geometry_msgs.msg import Pose      # https://github.com/ros2/common_interfaces/blob/master/geometry_msgs/msg/Pose.msg
from std_srvs.srv import Trigger        # https://github.com/ros2/common_interfaces/blob/master/std_srvs/srv/Trigger.srv
from trident_msgs.srv import LoadMission
from trident_msgs.action import StartMission, GotoWaypoint



class MissionControlBase(Node):
    """A base class for the mission control modules in Athena and NAIAD designed with
    generalization in mind.
    """
    def __init__(self, node_name) -> None:
        super().__init__(node_name)
        self.state = MissionControlState.NO_MISSION
        self.mission = None

        # Create the servers
        # ------------------
        # Server for the mission control's load mission service
        self._server_load_mission = self.create_service(LoadMission, 'mission_control/mission/load', self.server_load_mission_callback)
        self._action_server_start_mission = ActionServer(
            self,
            StartMission,
            'mission_control/mission/start',
            execute_callback=self._action_server_start_mission_execute_callback,
        )
        
        # Create the clients
        # ------------------
        self._action_client_goto_waypoint = self.ActionClient(self, Trigger, 'navigation/waypoint/go')


    #                   Callbacks
    # -----------------------------------------
    # Goto waypoint action client callbacks
    # -----------------------
    def _goto_waypoint_feedback_callback(self, feedback):
        self.get_logger().info(f"Goto waypoint feedback: Distance to goal: {feedback.feedback.distance_to_goal}" /
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
        status = future.result().status
        distance_to_goal = future.result().distance_to_goal
        message = future.result().message
        self.get_logger().info(f"Mission finished {distance_to_goal}m from the goal with status: {GotoWaypointStatus(status)}. {message}")

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

        self._action_client_goto_waypoint.send_goal_async(
            goal_msg,
            feedback_callback=self._goto_waypoint_feedback_callback
        )

        self._action_client_goto_waypoint.add_done_callback(self._goto_waypoint_goal_response_callback)

        return self._action_client_goto_waypoint

    # Start mission action server callbacks
    # ------------------------------
    async def _action_server_start_mission_execute_callback(self, goal_handle):
        """Executes the given goal by telling the navigation module to start the mission.
        """
        total_waypoints = len(self.mission)
        waypoints_succeeded = 0
        waypoints_failed = 0

        # Update mission control state
        self.state = MissionControlState.EXECUTING_MISSION
        self.get_logget().info(f"Starting to execute mission with {total_waypoints} waypoints.")

        for i, waypoint in enumerate(self.mission):
            goto_waypoint_goal_future = await self._goto_waypoint_send_goal(waypoint)
            goto_waypoint_result = goto_waypoint_goal_future.result()
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
            if i == len(self.mission):
                feedback_msg.status = StartMissionStatus.FINISHED
            else:
                feedback_msg.status = StartMissionStatus.EXECUTING

            feedback_msg.waypoints_completed = i+1
            feedback_msg.message = informational
            goal_handle.publish_feedback(feedback_msg)

        # Update mission control state, since the mission is finished.
        self.state = MissionControlState.MISSION_FINISHED
        goal_handle.succeed()
        
        result = StartMission.Result()
        result.status = StartMissionStatus.FINISHED
        result.message = f"Mission with {total_waypoints} waypoints finished."

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
            response.success = False
            response.message = "Cannot load a mission with 0 waypoints."

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



