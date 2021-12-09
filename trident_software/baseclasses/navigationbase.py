"""Module containing the base class definition for the navigation nodes.

Author: Johannes Deivard 2021-10
"""
from typing import List # For typehints
from math import sqrt
from threading import Event
import rclpy
from baseclasses.tridentstates import GotoWaypointStatus, NavigationState, HoldPoseStatus, GotoPoseStatus, WaypointActionType
from rclpy.node import Node
from rclpy.action import ActionClient, ActionServer, CancelResponse, GoalResponse

from geometry_msgs.msg import Pose, Point      # https://github.com/ros2/common_interfaces/blob/master/geometry_msgs/msg/Pose.msg
from std_srvs.srv import Trigger        # https://github.com/ros2/common_interfaces/blob/master/std_srvs/srv/Trigger.srv
from std_msgs.msg import String
from trident_msgs.msg import State
from trident_msgs.srv import GetGoalPose, GetState
from trident_msgs.action import GotoWaypoint, GotoPose, HoldPose


class NavigationBase(Node):
    """A base class for the navigation nodes used in Athena and NAIAD designed with
    generalization in mind.
    """
    def __init__(self, node_name) -> None:
        super().__init__(node_name)
        # The last known state of the agent.
        self._agent_state: State = State()
        # Keeps track of the status of the GotoWaypoint action
        self._goto_waypoint_status = None
        self.path_to_waypoint: List[Pose] = []
        # Parameter to keep track of the current goal pose, so that it can be used in the GoalPose getter service
        self._current_goal_pose = None
        self._navigation_state = NavigationState.IDLE

        # Event that keeps track on whether the GotoPose action has finished or not.
        self._goto_pose_done_event = Event()
        # Event that keeps track on whether the GotoPose action has finished or not.
        self._hold_pose_done_event = Event()
        # Keep track of the goal handles, so that they can be canceled
        self._goto_pose_goal_handle = None
        self._hold_pose_goal_handle = None
        # Keep reference to GotoWaypoint goal handle here so that feedback can be propagated
        self._goto_waypoint_goal_handle = None

        # Create the servers
        # ------------------
        # Server for the Goto waypoint action
        self._action_server_goto_waypoint = ActionServer(
            self,
            GotoWaypoint,
            'navigation/waypoint/go',
            execute_callback=self._action_server_goto_waypoint_execute_callback,
            cancel_callback=self._action_server_goto_waypoint_cancel_goal
        )
        # Service to communicate the current goal pose to those who wants to know (e.g., guidance system)
        self._get_goal_pose_server = self.create_service(
            GetGoalPose,
            'navigation/waypoint/get/goal_pose',
            self._get_goal_pose_callback
        )
        # Service to retrieve the state of the node
        self._get_state_server = self.create_service(
            GetState,
            'navigation/state/get',
            self._get_state_callback
        )

        
        # Create the clients
        # ------------------
        self._action_client_goto_pose = ActionClient(
            self,
            GotoPose,
            'motor_control/pose/go'
        )
        self._goto_pose_get_result_future = None
        self._action_client_hold_pose = ActionClient(
            self,
            HoldPose,
            'motor_control/pose/hold'
        )
        self._hold_pose_get_result_future = None

        # Subscriptions
        # -------------
        self._state_subscription = self.create_subscription(
            State,
            'position/state',
            self._state_listener_callback,
            1 # History depth, only keep the last received message
        )
        # Publishers
        # ----------
        self._goto_waypoint_status_publisher = self.create_publisher(
            String,
            'navigation/waypoint/go/status',
            1 # Only keep the latest status update
        )

    def _update_goto_waypoint_status(self, new_status):
        """Updates the goto waypoint status and publish the new status to the status topic
        that is subscribed to by the guidance system, among others.
        """
        self._goto_waypoint_status = GotoWaypointStatus(new_status)
        msg = String()
        msg.data = str(self._goto_waypoint_status)
        self.get_logger().info(f"Publishing new status for GotoWaypoint action: {msg.data}")
        self._goto_waypoint_status_publisher.publish(msg)

    def compute_path(self, waypoint) -> List[Pose]:
        """Computes a path to reach the desired state at the waypoint.
        For now, we use a simple approach and just add a Pose identical to the waypoint,
        but in the future, more complex logic can be implemented here.

        This function should be made asynchronous and continuosly update the optimal path
        to the waypoint by incorporating sensor data in the planning process so that obstacles
        can be avoided.

        Args:
            waypoint (Waypoint): The desired end state.

        Returns:
            List[Pose]: A list of poses that will be sent to the motor controller to reach the
                        Waypoint state intelligently.
        """

        poses = []
        poses.append(waypoint.pose)
        # TODO: Possibly set the self.path_to_waypoint to the poses list.
        # Note that this would update a list that is being looped.

        return poses

    def distance_to_goal(self, current, goal) -> float:
        """Calculates the distance between the goal and the current state.

        Args:
            current (Point): The current poisiton.
            goal (Point): The goal position.

        Returns:
            float: Distance (in meters??)
        """
        # Unpack the positions
        x1, y1, z1 = (current.x, current.y, current.z)
        x2, y2, z2 = (goal.x, goal.y, goal.z)

        # Pythagorean theorem
        return sqrt((x1-x2)**2 + (y1-y2)**2 + (z1-z2)**2)



    #                   Callbacks
    # --------------------------------------------
    # Agent state listener callback
    def _state_listener_callback(self, msg: State):
        """Callback for the subscribtion to the position/state topic that contains state messages with the msg type Pose.
        The callback reads the state and updates the agent_state property.
        """
        self.get_logger().info(f"Received state update. New state of the agent is: {msg}")
        self._agent_state = msg

    def _get_state_callback(self, _, response):
        """Simple getter for the node's state.
        """
        response.success = True
        response.state = str(self._navigation_state)
        response.int_state = self._navigation_state

        return response

    def _get_goal_pose_callback(self, _, response):
        """Simple getter for the current goal pose.
        """
        if self._current_goal_pose is not None:
            response.goal_pose = self._current_goal_pose
            response.success = True
            response.message = f"Successfully retrieved goal pose: {self._current_goal_pose}"
        else:
            response.success = False
            response.message = "Failed to retrieve goal pose: No goal is set."

        return response

    # Hold pose action client callbacks
    # ---------------------------------
    def _hold_pose_send_goal(self, pose: Pose, duration: int):
        """Packs the pose and duration into a goal message and sends the goal to the
        hold pose action server that is served by the motor controller node.

        Args:
            pose (Pose): Goal pose
            duration (int): Duration in seconds to hold the pose. 0 = Infinite
        Returns:
            Future that can be waited on.
        """
        goal_msg = HoldPose.Goal()
        goal_msg.pose = pose
        goal_msg.duration = duration
        # Update the current goal pose paramter
        self._current_goal_pose = pose

        # Wait for the server availability
        self._action_client_hold_pose.wait_for_server()

        send_goal_future = self._action_client_hold_pose.send_goal_async(
            goal_msg,
            feedback_callback=self._hold_pose_feedback_callback
        )
        send_goal_future.add_done_callback(self._hold_pose_goal_response_callback)

        return send_goal_future

    
    def _hold_pose_feedback_callback(self, feedback):
        self.get_logger().info(f"Hold pose feedback: Status: {feedback.feedback.status} " \
                               f"Message: {feedback.feedback.message}\nVariance: {feedback.feedback.pose_variance}\nMean: {feedback.feedback.pose_mean}")

        self.get_logger().info('Propagating feedback to GotoWaypoint client.')
        # Propagate feedback to the GotoWaypoint client
        goto_waypoint_feedback_msg = GotoWaypoint.Feedback()
        goto_waypoint_feedback_msg.distance_to_goal = -1.337 # self.distance_to_goal(self._agent)
        goto_waypoint_feedback_msg.status = GotoWaypointStatus.HOLDING_POSITION
        goto_waypoint_feedback_msg.message = f"Performing waypoint action: {str(GotoWaypointStatus(goto_waypoint_feedback_msg.status))}." \
                                             f"HoldPose status: {str(HoldPoseStatus(feedback.feedback.status))}"
        self._goto_waypoint_goal_handle.publish_feedback(goto_waypoint_feedback_msg)
        self._update_goto_waypoint_status(GotoWaypointStatus.HOLDING_POSITION)

    def _hold_pose_goal_response_callback(self, future):
        goal_handle = future.result()
        # Check if the goal was rejected and return early if it was
        if not goal_handle.accepted:
            self.get_logger().info('Hold pose goal rejected.')
            return

        self.get_logger().info('Hold pose goal accepted.')
        self._hold_pose_goal_handle = goal_handle
        # Create the future that gets completed when the action is finished
        self._hold_pose_get_result_future = goal_handle.get_result_async()
        # Add the callback for when the future is completed
        self._hold_pose_get_result_future.add_done_callback(self._hold_pose_get_result_callback)

        return self._hold_pose_get_result_future

    def _hold_pose_get_result_callback(self, future):
        """Callback for the result future of the GotoPose action.

        Args:
            future (Future): Result future that is finished.
        """
        message = future.result().result.message
        duration = future.result().result.duration
        self.get_logger().info(f"HoldPose finished. Held position for {duration} seconds. Message: {message}")
        # Signal that the action has finished
        self._hold_pose_done_event.set()

    def _hold_pose_cancel_done(self, future):
        cancel_response = future.result()
        if len(cancel_response.goals_canceling) > 0:
            self.get_logger().info('Hold pose goal successfully canceled')
        else:
            self.get_logger().info('Hold pose goal failed to cancel')
        self._hold_pose_done_event.set()

    # Goto pose action client callbacks
    # -----------------------
    def _goto_pose_send_goal(self, pose):
        """Packs the pose into a goal message and sends the goal to the goto pose action server
        that is served by the motor controller node.

        Args:
            pose (Pose): Goal pose
        Returns:
            Future that can be waited on.
        """
        goal_msg = GotoPose.Goal()
        goal_msg.pose = pose
        # Update the current goal pose paramter
        self._current_goal_pose = pose
        # Wait for the server availability
        self._action_client_goto_pose.wait_for_server()

        goto_pose_send_goal_future = self._action_client_goto_pose.send_goal_async(
            goal_msg,
            feedback_callback=self._goto_pose_feedback_callback
        )
        goto_pose_send_goal_future.add_done_callback(self._goto_pose_goal_response_callback)

        return goto_pose_send_goal_future

    def _goto_pose_feedback_callback(self, feedback):
        self.get_logger().info(f"Goto pose feedback: Distance to goal: {feedback.feedback.distance_to_goal}" \
                               f"status: {feedback.feedback.status}, Message: {feedback.feedback.message}")

        self.get_logger().info('Propagating feedback to GotoWaypoint client.')
        # Propagate feedback to the GotoWaypoint client
        goto_waypoint_feedback_msg = GotoWaypoint.Feedback()
        goto_waypoint_feedback_msg.distance_to_goal = feedback.feedback.distance_to_goal
        goto_waypoint_feedback_msg.status = GotoWaypointStatus.MOVING
        goto_waypoint_feedback_msg.message = "Moving to waypoint."
        self._goto_waypoint_goal_handle.publish_feedback(goto_waypoint_feedback_msg)
        self._update_goto_waypoint_status(GotoWaypointStatus.MOVING)

    def _goto_pose_goal_response_callback(self, future):
        goal_handle = future.result()
        # Check if the goal was rejected and return early if it was
        if not goal_handle.accepted:
            self.get_logger().info('Pose goal rejected.')
            return

        self.get_logger().info('Pose goal accepted.')
        self._goto_pose_goal_handle = goal_handle
        # Create the future that gets completed when the action is finished
        self._goto_pose_get_result_future = goal_handle.get_result_async()
        # Add the callback for when the future is completed
        self._goto_pose_get_result_future.add_done_callback(self._goto_pose_get_result_callback)

        return self._goto_pose_get_result_future

    def _goto_pose_get_result_callback(self, future):
        """Callback for the result future of the GotoPose action.

        Args:
            future (Future): Result future that is finished.
        """
        status = future.result().result.status
        distance_to_goal = future.result().result.distance_to_goal
        message = future.result().result.message
        if status == GotoPoseStatus.FINISHED:
            self.get_logger().info(f"GotoPose finished {distance_to_goal}m from the goal. Message: {message}")
        elif status == GotoPoseStatus.FAILED:
            self.get_logger().info(f"GotoPose failed {distance_to_goal}m from the goal. Message: {message}")
        # Signal that the action has finished
        self._goto_pose_done_event.set()

    def _goto_pose_cancel_done(self, future):
        cancel_response = future.result()
        if len(cancel_response.goals_canceling) > 0:
            self.get_logger().info('Goto pose goal successfully canceled')
        else:
            self.get_logger().info('Goto pose goal failed to cancel')
        self._goto_pose_done_event.set()


    # Goto waypoint action server callbacks
    # -----------------------
    def _action_server_goto_waypoint_cancel_goal(self, goal_handle):
        """Accepts or rejects the cancel request."""
        self.get_logger().info("Received goto waypoint cancel request.")
        try:
            cancel_future = self._goto_pose_goal_handle.cancel_goal_async()
            cancel_future.add_done_callback(self._goto_pose_cancel_done)
            cancel_future = self._hold_pose_goal_handle.cancel_goal_async()
            cancel_future.add_done_callback(self._hold_pose_cancel_done)
        except Exception as e:
            self.get_logger().info(f"Tried to cancel goto_pose/hold_pose goal, but failed. Error message: {e}")
        
        return CancelResponse.ACCEPT

    async def _action_server_goto_waypoint_execute_callback(self, goal_handle):
        """Executes the given goal by sending desired poses to the motor controller.
        Return feedback in the form of distance to goal, goal status and informational message.
        """

        self.get_logger().info('Received GotoWaypoint request.')
        # Validity checks:
        # None for now.

        self.get_logger().info('Computing path to waypoint.')
        # Calculate the initial path
        self.path_to_waypoint = self.compute_path(goal_handle.request.waypoint)
        feedback_msg = GotoWaypoint.Feedback()
        self.get_logger().info('Path computed.')
        self._navigation_state = NavigationState.EXECUTING

        # Future work: Start a timer to continously compute the path to the waypoint.
        # Store goal handle for feedback propagation
        self._goto_waypoint_goal_handle = goal_handle
        # Loop through the poses that leads to the waypoint
        for pose in self.path_to_waypoint:            # Check if a cancel was requested
            if goal_handle.is_cancel_requested:
                break

            self._goto_pose_done_event.clear()
            # Create and publish the initial feedback message.
            # Note: Further feedback messages will be propagated via the GotoPose feedback
            feedback_msg.distance_to_goal = self.distance_to_goal(pose.position, goal_handle.request.waypoint.pose.position)
            feedback_msg.status = GotoWaypointStatus.MOVING
            feedback_msg.message = "Moving to waypoint."
            goal_handle.publish_feedback(feedback_msg)
            self._update_goto_waypoint_status(GotoWaypointStatus.MOVING)
            # Send the desired state to the motor controller
            self._goto_pose_send_goal(pose)
            # ... and await the result via the appropriate event
            self._goto_pose_done_event.wait()

        # Check if the waypoint action is HOLD
        if goal_handle.request.waypoint.action.action_type == WaypointActionType.HOLD and not goal_handle.is_cancel_requested:
            self.get_logger().info(f'Waypoint goal reached. Now performing HOLD action for {goal_handle.request.waypoint.action.action_param} seconds.')
            self._hold_pose_done_event.clear()
            # Call the motor controller's HoldPose action service
            self._hold_pose_send_goal(
                goal_handle.request.waypoint.pose,
                goal_handle.request.waypoint.action.action_param
            )
            self._hold_pose_done_event.wait()
            self.get_logger().info('HoldPose goal finished.')

        # Create the result message and populate it
        result = GotoWaypoint.Result()
        if goal_handle.is_cancel_requested:
            goal_handle.canceled()
            self.get_logger().info("Mission goal canceled.")
            result.message = "GotoWaypoint goal canceled."
        else:
            goal_handle.succeed()
            result.message = "Arrived at the waypoint and action finished. Goal finished."
        result.status = GotoWaypointStatus.FINISHED
        result.distance_to_goal = self.distance_to_goal(self._agent_state.pose.position, goal_handle.request.waypoint.pose.position)

        self.get_logger().info(f'Returning result: {result}')
        self._navigation_state = NavigationState.IDLE
        return result
