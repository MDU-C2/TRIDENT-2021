import rclpy
from tridentstates import MissionControlState, GotoWaypointStatus, MissionStatus
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

        self._goto_waypoint_feedback

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
        # Client for the navigation node's empty waypoint queue service
        # self.client_request_empty_wp_queue = self.create_client(Trigger, 'nav/wp_queue/empty')
        # Client for the navigtaion node's fill waypoint queue service
        # self.client_fill_wp_queue = self.create_client(Trigger, 'nav/wp_queue/fill')

        self._action_client_goto_waypoint = self.ActionClient(self, Trigger, 'nav/waypoint/go')


        # TODO: Discuss whether it is better to let the mission control handle the progress of the mission and instead
        #       only send a single waypoint to the navigtaion module.
        #       The benefits of this are that:
        #           - we don't get nested actions,
        #           - if the navigation node eventually are supposed to be more intelligent, the node can focus on getting to
        #             the goal without crashing into something, which means that it would plan and create a path to the goal, which 
        #             in essence means that the navigation node would create it's own "mission" to get to the waypoint.
        #           - it is easier to track the progress of a mission
        #       So, the mission control tracks the state of the mission and sends feedback to ground control.
        #       Each waypoint in the mission gets sent to the navigation node one at a time, which internally would
        #       create a path (a list of poses essentially) that would allow the agent to reach the waypoint. The 
        #       navigation node would send the poses one at a time to the motor controler and eventually reach the 
        #       mission goal. The navigation node would continuosly send feedback to mission control in the form of 
        #       distance from goal. Once the goal (a waypoint) is reached, the mission control would send the next 
        #       waypoint in the mission list to the navigation module and the process is repeated.   

    #                   Callbacks
    # -----------------------------------------
    # Goto waypoint callbacks
    # -----------------------
    def _goto_waypoint_feedback_callback(self, feedback):
        self.get_logger().info(f"Goto waypoint feedback: Distance to goal: {feedback.feedback.distance_to_goal}" /
                               f"status: {feedback.feedback.status}, Message: {feedback.feedback.message}")

    def _goto_waypoint_response_callback(self, future):
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

        return self._action_client_goto_waypoint.send_goal_async(goal_msg, feedback_callback=self._goto_waypoint_feedback_callback)

    # Start mission action callbacks
    # -----------------------
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
            goal_future = await self._goto_waypoint_send_goal(waypoint)
            result = goal_future.result()
            if GotoWaypointStatus(result.status) in GotoWaypointStatus.FINISHED:
                waypoints_succeeded += 1
                # Create the feedback message
                feedback_msg = StartMission.Feedback()
                informational = f"Completed waypoint {i+1}. Progress: {i+1}/{total_waypoints}."
            else:
                waypoints_failed += 1
                informational = f"Failed waypoint {i+1}. Progress: {i+1}/{total_waypoints}."

            # Log the informational message
            self.get_logger().info(informational)
            # Check if this was the last waypoint and set the mission status in the feedback msg accordingly
            if i == len(self.mission):
                feedback_msg.status = MissionStatus.FINISHED
            else:
                feedback_msg.status = MissionStatus.EXECUTING

            feedback_msg.waypoints_completed = i+1
            feedback_msg.message = informational
            goal_handle.publish_feedback(feedback_msg)

        # Update mission control state, since the mission is finished.
        self.state = MissionControlState.MISSION_FINISHED
        goal_handle.succeed()
        



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



