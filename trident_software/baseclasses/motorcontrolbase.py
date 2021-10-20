"""Module containing the base class definition for the motor control nodes.

Author: Johannes Deivard 2021-10
"""
from typing import List # For typehints
from math import sqrt   # For Pythagorean theorem to calculate distance
import rclpy
from rclpy.node import Node
from rclpy.action import ActionClient, ActionServer
from geometry_msgs.msg import Pose, Point, Quaternion
from trident_msgs.action import GotoPose, HoldPose
from trident_msgs.msg import MotorOutput
from baseclasses.tridentstates import HoldPoseStatus, GotoPoseStatus, MotorControlState

from rclpy.callback_groups import ReentrantCallbackGroup

class MotorControlBase(Node):
    """A base class for the motor control nodes used in Athena and NAIAD designed with
    generalization in mind.
    """

    def __init__(self, node_name, num_motors = 2, motor_config = None, pid_config = None):
        super().__init__(node_name)
        # Parameters
        self.declare_parameters(
            namespace='',
            parameters=[
                ('motor_update_frequency', 5.0), # Hz
                ('point_and_shoot_threshold', 0.0) # Meter
            ])

        self.motor_control_state = MotorControlState.IDLE

        self._num_motors = num_motors # TODO: Get this value from the motor_config
        # The last known state of the agent.
        self.agent_state: Pose = Pose()
        # SET HARDCODED STATE FOR TESTING PURPOSES
        p = Point()
        p.x, p.y, p.z = (1.0, 2.0, 3.0)
        q = Quaternion()
        q.x ,q.y, q.z, q.w = (0.0, 0.0, 0.0, 1.0)
        self.agent_state.position = p
        self.agent_state.orientation = q
        ##########################################

        # Motor control update frequency
        self._motor_update_frequency = self.get_parameter('motor_update_frequency').get_parameter_value().double_value # Hz
        # Rate object with relative sleeping periood
        self._motor_update_rate = self.create_rate(self._motor_update_frequency)
        # Threshold for when to compute orientation internally instead of using goal orientation.
        self.point_and_shoot_threshold: float = self.get_parameter('point_and_shoot_threshold').get_parameter_value().double_value # Hz
        # The accepted slack for considering the GotoPose goal finished
        self.goto_pose_goal_distance_slack = 0.2 # meter
        self.goto_pose_goal_orientation_slack = 0.1 # 10 percent


        # Subscriptions
        self._state_subscribtion = self.create_subscription(
            Pose,
            'position/state',
            self._state_listener_callback,
            1 # History depth, only keep the last received message
        )
        # Publishers
        self._motor_output_publisher = self.create_publisher(
            MotorOutput,
            'motor_control/motor_output',
            1 # History depth, only keep the last received message
        )

        # Create the servers
        # ------------------
        # Action server for the GotoPose action
        self._action_server_goto_pose = ActionServer(
            self,
            GotoPose,
            'motor/pose/go',
            execute_callback=self._action_server_goto_pose_execute_callback,
        )

    def distance_to_goal(self, current: Point, goal: Point) -> float:
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

    def compute_point_and_shoot_orientation(self, current: Point, goal: Point) -> Quaternion: 
        """Computes the orientation needed to go straight from the current position to
         the goal position.

        Args:
            current (Point): Current position.
            goal (Point): Goal position.

        Returns:
            Quaternion: Orientation needed to "shoot".
        """
        # TODO: Implement this function.
        return Quaternion()
    
    def _goto_pose_goal_reached(self, goal: Pose) -> bool:
        """Checks wheter the GotoPose goal is reached or not. The accepted state allows for some
        slack, defined as instance variables. This method uses the current agent state as the
        reference state.

        Args:
            goal (Pose): The goal pose to compare with.

        Returns:
            bool: Boolean that indicates whether the goal is reached or not.
        """
        # TODO: Read current state 
        current = Pose()
        dist = self.distance_to_goal(current.position, goal.position)
        orientation_errors = ((goal.orientation.x - current.orientation.x) / goal.orientation.x, 
                              (goal.orientation.y - current.orientation.y) / goal.orientation.y,
                              (goal.orientation.z - current.orientation.z) / goal.orientation.y,
                              (goal.orientation.w - current.orientation.w) / goal.orientation.y
                            )

        return dist <= self.goto_pose_goal_distance_slack and max(orientation_errors) <= self.goto_pose_goal_orientation_slack

    def calculate_delta_pose(self, pose_a: Pose, pose_b: Pose) -> Pose:
        """Calculates the difference between two Poses: pose_a and pose_b.

        Args:
            pose_a (Pose): First pose.
            pose_b (Pose): Second pose.

        Returns:
            Pose: Returns the pose delta.
        """
        position_delta = Point(pose_b.position.x - pose_a.position.x,
                               pose_b.position.y - pose_a.position.y,
                               pose_b.position.z - pose_a.position.z)
        orientation_delta = Quaternion((pose_b.orientation.x - pose_a.orientation.x),
                                       (pose_b.orientation.y - pose_a.orientation.y),
                                       (pose_b.orientation.z - pose_a.orientation.z),
                                       (pose_b.orientation.w - pose_a.orientation.w))
        delta_pose = Pose()
        delta_pose.position = position_delta
        delta_pose.orientation = orientation_delta

        return delta_pose


    #                   Callbacks
    # -----------------------------------------
    # State listener callback
    def _state_listener_callback(self, msg: Pose):
        """Callback for the subscribtion to the position/state topic that contains state messages with the msg type Pose.
        The callback reads the state and updates the agent_state property.
        """
        self.get_logger().info(f"Received state update. New state of the agent is: {msg}")
        self.agent_state = msg


    # GotoPose callbacks
    # -----------------
    def _action_server_goto_pose_execute_callback(self, goal_handle):
        """Execution callback for the GotoPose action. Executes the goal with the help of PID regulation
        of the motors.
        
        The motor controller behaves similar to a point and shoot approach, which means if the desired
        position is outside of an accepted threshold, the motor controller will compute its own desired
        orientation that will point straight at the desired position and prioritize the orientation over
        the position in the PID regulation. This will in turn lead to behavior mimicking the point and
        shoot approach.
        """
        self.get_logger().info(f'Received goal.')
        self.motor_control_state = MotorControlState.EXECUTING
        # Loop as long as the goal isn't reached.
        i = 0 # For testing
        while(i < 50):
            i+=1
        # while(not self._goto_pose_goal_reached(goal_handle.request)):
            current_pos = self.agent_state.position
            desired_pos = goal_handle.request.pose.position
            current_orientation = self.agent_state.orientation
            desired_orientation = goal_handle.request.pose.orientation
            # Calculate distance between desired position and current position.
            distance_to_goal = self.distance_to_goal(current_pos, desired_pos)
            # Check if the distance is within the point_and_shoot_threshold.
            if distance_to_goal < self.point_and_shoot_threshold:
                # Compute an orientation that conforms with the "point" in point and shoot.
                desired_orientation = self.compute_point_and_shoot_orientation(current_pos, desired_pos)

            # TODO: PID here

            # TODO: Send REAL values to motor driver
            motor_output_msg = MotorOutput()
            motor_output_msg.motor_outputs = [42, 42]
            self.get_logger().info(f'Publishing motor output values to the motor driver. Motor values: {motor_output_msg.motor_outputs}')
            self._motor_output_publisher.publish(motor_output_msg)

            # Create and send feedback
            feedback_msg = GotoPose.Feedback()
            feedback_msg.status = GotoPoseStatus.MOVING_TO_POSE
            feedback_msg.message = "Moving to pose."
            feedback_msg.distance_to_goal = distance_to_goal
            # TODO: Calculate delta pose.
            #feedback_msg.delta_pose = self.calculate_delta_pose(current_state, goal_handle.request.pose)
            goal_handle.publish_feedback(feedback_msg)

            self.get_logger().info(f'{feedback_msg.message}')
            # Relative sleep according to the goto_pose_rate.
            self._motor_update_rate.sleep()

        # Send 0 as the final motor output values so the agent stops acting since the goal is finished.
        motor_output_msg = MotorOutput()
        motor_output_msg.motor_outputs = [0] * self._num_motors
        self.get_logger().info(f'Goal reached. Stopping motors by publishing {motor_output_msg.motor_outputs} to the motor driver.')
        self._motor_output_publisher.publish(motor_output_msg)

        goal_handle.succeed()
        result = GotoPose.Result()
        result.status = GotoPoseStatus.FINISHED
        result.message = "Arrived at the goal pose. Goal finished."
        result.distance_to_goal = 0.0 # TODO: self.distance_to_goal(self.agent_state.position, goal_handle.request.pose.position) # TEMPORARY! TODO: Use the current state to calculate the distance to the goal.

        self.get_logger().info(f'Returning result: {result}')

        return result


    # TODO: HoldPose Callback