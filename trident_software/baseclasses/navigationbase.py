"""Module containing the base class definition for the navigation nodes.

Author: Johannes Deivard 2021-10
"""
from typing import List # For typehints
from math import sqrt   # For Pythagorean theorem do calculate distance
import rclpy
from baseclasses.tridentstates import GotoWaypointStatus, NavigationState, HoldPoseStatus, GotoPoseStatus, WaypointActionType
from rclpy.node import Node
from rclpy.action import ActionClient, ActionServer

from geometry_msgs.msg import Pose, Point      # https://github.com/ros2/common_interfaces/blob/master/geometry_msgs/msg/Pose.msg
from std_srvs.srv import Trigger        # https://github.com/ros2/common_interfaces/blob/master/std_srvs/srv/Trigger.srv
from trident_msgs.srv import LoadMission
from trident_msgs.action import GotoWaypoint, GotoPose, HoldPose


class NavigationBase(Node):
    """A base class for the navigation nodes used in Athena and NAIAD designed with 
    generalization in mind.
    """

    def __init__(self, node_name) -> None:
        super().__init__(node_name)
        self.goto_waypoint_status = NavigationState.IDLE
        self.path_to_waypoint: List[Pose] = []

        # Keep reference to GotoWaypoint goal handle here so that feedback can be propagated
        self._goto_waypoint_goal_handle = None

        # Create the servers
        # ------------------
        # Server for the Goto waypoint action
        self._action_server_goto_waypoint = ActionServer(
            self,
            GotoWaypoint,
            'navigation/waypoint/go',
            execute_callback=self._action_server_goto_waypoint_execute_callback
        )

        
        # Create the clients
        # ------------------
        self._action_client_goto_pose = ActionClient(self, GotoPose, 'motor_control/pose/go')
        self._goto_pose_get_result_future = None
        self._action_client_hold_pose = ActionClient(self, HoldPose, 'motor_control/pose/hold') # TODO: Implement server in motor
        self._hold_pose_get_result_future = None


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
        # Wait for the server availability
        self._action_client_hold_pose.wait_for_server()

        send_goal_future = self._action_client_hold_pose.send_goal_async(
            goal_msg,
            feedback_callback=self._hold_pose_feedback_callback
        )
        send_goal_future.add_done_callback(self._hold_pose_goal_response_callback)

        return send_goal_future

    
    def _hold_pose_feedback_callback(self, feedback):
        self.get_logger().info(f"Hold pose feedback: Status: {feedback.feedback.status} " /
                               f"Message: {feedback.feedback.message}")
                               # TODO: Log mean pose deviation (computed in motor controller)

        self.get_logger().info('Propagating feedback to GotoWaypoint client.')
        # Propagate feedback to the GotoWaypoint client
        goto_waypoint_feedback_msg = GotoWaypoint.Feedback()
        goto_waypoint_feedback_msg.distance_to_goal = 0 # TEMPORARY! TODO: Compute distance based on current state.
        goto_waypoint_feedback_msg.status = GotoWaypointStatus.HOLDING_POSITION
        goto_waypoint_feedback_msg.message = f"Performing waypoint action: {str(GotoWaypointStatus(goto_waypoint_feedback_msg.status))}." \
                                             f"HoldPose status: {str(HoldPoseStatus(feedback.feedback.status))}"
        self._goto_waypoint_goal_handle.publish_feedback(goto_waypoint_feedback_msg)

    def _hold_pose_goal_response_callback(self, future):
        goal_handle = future.result()
        # Check if the goal was rejected and return early if it was
        if not goal_handle.accepted:
            self.get_logger().info('Hold pose goal rejected.')
            return

        self.get_logger().info('Hold pose goal accepted.')
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

    def _goto_pose_goal_response_callback(self, future):
        goal_handle = future.result()
        # Check if the goal was rejected and return early if it was
        if not goal_handle.accepted:
            self.get_logger().info('Pose goal rejected.')
            return

        self.get_logger().info('Pose goal accepted.')
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


    # Goto waypoint action server callbacks
    # -----------------------
    async def _action_server_goto_waypoint_execute_callback(self, goal_handle):
        """Executes the given goal by sending desired poses to the motor controller.
        Return feedback in the form of distance to goal, goal status and informational message.
        """

        self.get_logger().info('Received GotoWaypoint request.')
        goal_handle.succeed()
        # Validity checks:
        # None for now.

        self.get_logger().info('Computing path to waypoint.')
        # Calculate the initial path
        self.path_to_waypoint = self.compute_path(goal_handle.request.waypoint)
        feedback_msg = GotoWaypoint.Feedback()
        self.get_logger().info('Path computed.')

        # Future work: Start a timer to continously compute the path to the waypoint.
        # Store goal handle for feedback propagation
        self._goto_waypoint_goal_handle = goal_handle
        # Loop through the poses that leads to the waypoint
        for pose in self.path_to_waypoint:
            # Create and publish the initial feedback message.
            # Note: Further feedback messages will be propagated via the GotoPose feedback
            feedback_msg.distance_to_goal = self.distance_to_goal(pose.position, goal_handle.request.waypoint.pose.position)
            feedback_msg.status = GotoWaypointStatus.MOVING
            feedback_msg.message = "Moving to waypoint."
            goal_handle.publish_feedback(feedback_msg)
            # Send the desired state to the motor controller and await the result
            goto_pose_goal_future = await self._goto_pose_send_goal(pose)
            goto_pose_result_future = await self._goto_pose_get_result_future
            goto_pose_result = goto_pose_result_future.result
            # Check goto_pose_result
            if GotoPoseStatus(goto_pose_result.status) == GotoPoseStatus.FINISHED:
                self.get_logger().info(f'Finished going to pose. Message: {goto_pose_result.message} ')
            elif GotoPoseStatus(goto_pose_result.status) == GotoPoseStatus.FAILED:
                self.get_logger().info(f'Failed going to pose. Message {goto_pose_result.message}')

            # Check if the waypoint action is HOLD
            if goal_handle.request.waypoint.action == WaypointActionType.HOLD:
                # Call the motor controller's HoldPose action service
                self._hold_pose_send_goal(
                    goal_handle.request.waypoint.pose,
                    goal_handle.request.waypoint.action.action_param
                )
        
        result = GotoWaypoint.Result()
        result.status = GotoWaypointStatus.FINISHED
        result.message = "Arrived at the waypoint. Goal finished."
        result.distance_to_goal = 0.0 # TEMPORARY! TODO: Use the current state to calculate the distance to the goal.
        
        self.get_logger().info(f'Returning result: {result}')

        return result
