"""Module containing the base class definition for the motor control nodes.

Author: Johannes Deivard 2021-11
"""
from abc import ABCMeta, abstractmethod
import numpy as np
from math import sqrt, pi, atan2, log, degrees, radians 
from collections import deque
from squaternion import Quaternion as SQuaternion # Simple quaternion calculations
from simple_pid import PID
import json
import rclpy
from rclpy.node import Node
from rclpy.action import ActionClient, ActionServer, GoalResponse, CancelResponse
from std_msgs.msg import String
from std_srvs.srv import SetBool
from geometry_msgs.msg import Pose, Point, Quaternion, Twist
from nav_msgs.msg import Odometry
from trident_msgs.action import GotoPose, HoldPose
from trident_msgs.msg import MotorOutputs, MotorOutput, State, PidParam
from trident_msgs.srv import GetState
from baseclasses.tridentstates import HoldPoseStatus, GotoPoseStatus, MotorControlState

from rclpy.callback_groups import ReentrantCallbackGroup


class MotorControlBase(Node, metaclass=ABCMeta):
    """A base class for the motor control nodes used in Athena and NAIAD designed with
    generalization in mind.
    """

    def __init__(self, node_name):
        super().__init__(node_name)
        # Parameters
        self.declare_parameters(
            namespace='',
            parameters=[
                ('motor_update_frequency', 50.0), # Hz
                ('pas_orientation_update_freq', 2), # Hz
                ('pas_threshold', 0.0), # Point and Shoot threshold in meters
                ('goal_distance_slack', 0.2), # Meters
                ('goal_orientation_slack', 0.1), # Percent
                ('pitch_limit', 85), # Degrees
                ('motor_config', ""),
                ('pid_config', ""),
                ('use_sim_odom', False),
            ])

        # LOAD PARAMETERS
        # ---------------
        # PAS computation update frequency parameter
        self._pas_orientation_update_freq = self.get_parameter('pas_orientation_update_freq').get_parameter_value().double_value # Hz
        # Motor config parameters, see config file for information about structure
        self._motor_config = json.loads(self.get_parameter('motor_config').get_parameter_value().string_value)
        self._pid_config = json.loads(self.get_parameter('pid_config').get_parameter_value().string_value)
        # Motor control update frequency
        self._motor_update_frequency = self.get_parameter('motor_update_frequency').get_parameter_value().double_value # Hz
        # Threshold for when to compute orientation internally instead of using goal orientation.
        self._pas_threshold = self.get_parameter('pas_threshold').get_parameter_value().double_value # Hz
        # The accepted slack for considering the GotoPose goal finished
        self._goto_pose_goal_distance_slack = self.get_parameter('goal_distance_slack').get_parameter_value().double_value # Hz
        self._goto_pose_goal_orientation_slack = self.get_parameter('goal_orientation_slack').get_parameter_value().double_value # Hz
        # The allowed pitch angle, used to limit the throttle when the agent gets closer to the limit to avoid the agent from tipping over.
        self._pitch_limit = self.get_parameter('pitch_limit').get_parameter_value().double_value # Degres
        # Get the use_sim_odom parameter that determines if we should use the simulation real odom values instead of the position modules state
        self._use_sim_odom = self.get_parameter('use_sim_odom').get_parameter_value().bool_value

        # Set initial motor control state to IDLE
        self._motor_control_state = MotorControlState.IDLE
        self._prev_state = MotorControlState.IDLE
        # Boolean that controls the manual override, if manual override is True, the motor control will not send any output values to the motor driver.
        self._manual_override = False
        # The last known state of the agent.
        self._agent_state: State = State()
        # The current goal pose received from either GotoPose action or HoldPose action.
        self._goal_pose = None
        # Boolean that keeps track on whether the HoldPose time has been reached.
        self._hold_pose_time_reached = False
        # The latest computation of the point and shoot orientation.
        # (This is updated by a timer callback set to the pas_orientation_update_freq)
        self._pas_orientation = None
        # Tracks the state history, used to determine if we are accelerating or not
        self._state_history = deque(maxlen=10)
        # Boolean that determines if the z-axis should be used in the distance_to_goal calculations.
        # If the motor config contains a motor that can affect the position in the z axis, use the z delta in distance
        # to goal calculations. If not, don't use it.
        self._use_z_in_distance_to_goal = bool(max([abs(motor["pose_effect"]["z"]) for motor in self._motor_config]))

        # SET DEFAULT STATE 
        p = Point()
        p.x, p.y, p.z = (0.0, 0.0, 0.0)
        q = Quaternion()
        q.x ,q.y, q.z, q.w = (0.0, 0.0, 0.0, 1.0)
        self._agent_state.pose.position = p
        self._agent_state.pose.orientation = q
        ##########################################


        # Create the PID objects
        self._pids = {
            "x":     PID(self._pid_config["p"]["x"],     self._pid_config["i"]["x"],     self._pid_config["d"]["x"], output_limits=(-0.5,0.5)),
            "y":     PID(self._pid_config["p"]["y"],     self._pid_config["i"]["y"],     self._pid_config["d"]["y"], output_limits=(-0.5,0.5)),
            "z":     PID(self._pid_config["p"]["z"],     self._pid_config["i"]["z"],     self._pid_config["d"]["z"], output_limits=(-0.5,0.5)),
            "pitch": PID(self._pid_config["p"]["pitch"], self._pid_config["i"]["pitch"], self._pid_config["d"]["pitch"], output_limits=(-0.5,0.5)),
            "yaw":   PID(self._pid_config["p"]["yaw"],   self._pid_config["i"]["yaw"],   self._pid_config["d"]["yaw"], error_map=MotorControlBase.pi_clip, output_limits=(-0.5,0.5)),
            "roll":  PID(self._pid_config["p"]["roll"],  self._pid_config["i"]["roll"],  self._pid_config["d"]["roll"], output_limits=(-0.5,0.5))
        }

        # Rate object with relative sleeping period that controls the motor update frequency
        self._motor_update_rate = self.create_rate(self._motor_update_frequency)

        # Subscriptions
        # -------------
        if self._use_sim_odom:
            self._state_subscription = self.create_subscription(
                Odometry,
                'simulation/odometry',
                self._sim_odom_listener_callback,
                1 # History depth, only keep the last received message
            )
        else:
            self._state_subscription = self.create_subscription(
                State,
                'position/state',
                self._state_listener_callback,
                1 # History depth, only keep the last received message
            )
        self._teleop_twist_subscription = self.create_subscription(
            Twist,
            'motor_control/teleop/cmd_vel',
            self._teleop_twist_callback,
            2 # Keep 2 messages to act as a tiny buffer
        )
        self._pid_param_set_subscription = self.create_subscription(
            PidParam,
            'motor_control/param/pid/set',
            self._pid_param_set_callback,
            10
        )

        # Publishers
        # ----------
        self._motor_outputs_publisher = self.create_publisher(
            MotorOutputs,
            'motor_control/motor_output',
            1 # History depth, only keep the last received message
        )
        self._motor_control_state_publisher = self.create_publisher(
            String,
            'motor_control/state',
            10
        )

        # Create the servers
        # ------------------
        # Action server for the GotoPose action
        self._action_server_goto_pose = ActionServer(
            self,
            GotoPose,
            'motor_control/pose/go',
            execute_callback=self._action_server_goto_pose_execute_callback,
            cancel_callback=self._action_server_goto_pose_on_cancel_callback
        )
        # Action server for the HoldPose action
        self._action_server_hold_pose = ActionServer(
            self,
            HoldPose,
            'motor_control/pose/hold',
            execute_callback=self._action_server_hold_pose_execute_callback,
            cancel_callback=self._action_server_hold_pose_on_cancel_callback
        )
        # Manual override service
        self._server_manual_override = self.create_service(
            SetBool,
            'motor_control/manual_override',
            self._server_manual_override_callback
        )

        # Service to retrieve the state of the node
        self._get_state_server = self.create_service(
            GetState,
            'motor_control/state/get',
            self._get_state_callback
        )

    @staticmethod
    def pi_clip(angle):
        if angle > 0:
            if angle > pi:
                return angle - 2*pi
        else:
            if angle < -pi:
                return angle + 2*pi
        return angle

    def disable_pids(self):
        """Disable the pids by setting the auto_mode to false, meaning that
        no new values will be calculated.
        """
        for pid in self._pids.values():
            pid.auto_mode = False

    def enable_pids(self):
        """Enable the pids by turning auto_mode on and setting the last_output to 0,
        which means that the I-term will be reset to zero.
        """
        for pid in self._pids.values():
            pid.set_auto_mode(True, last_output=0)


    def _update_node_state(self, new_state):
        """Updates the node's state and publish the new state to the state topic.
        """
        if self._prev_state is MotorControlState(new_state):
            self._prev_state = self._motor_control_state
        self._motor_control_state = MotorControlState(new_state)
        msg = String()
        msg.data = str(self._motor_control_state)
        self.get_logger().info(f"Publishing new state: {msg.data}")
        self._motor_control_state_publisher.publish(msg)


    def pid(self, current: Pose, goal: Pose) -> MotorOutputs:
        """Computes the output value for each motor by PID:ing the position and orientation (x,y,z,roll,pitch,yaw)

        Args:
            current (Pose): Current pose (position and orientation)
            goal (Pose): Goal pose (position and orientation)

        Returns:
            MotorOutputs: List of values to send to each motor (motor number, value)
        """
        # Check if we have a goal pose
        if current is None or goal is None:
            return None
        # Retrieve goal orientations in euler angles
        goal_orientation = SQuaternion(w=goal.orientation.w, x=goal.orientation.x, y=goal.orientation.y, z=goal.orientation.z).to_euler(degrees=False)
        current_orientation = SQuaternion(w=current.orientation.w, x=current.orientation.x, y=current.orientation.y, z=current.orientation.z).to_euler(degrees=False)

        goals = {
            "x":     goal.position.x,
            "y":     goal.position.y,
            "z":     goal.position.z,
            "roll":  goal_orientation[0],
            "pitch": goal_orientation[1],
            "yaw":   goal_orientation[2]
        }
        currents = {
            "x":     current.position.x,
            "y":     current.position.y,
            "z":     current.position.z,
            "roll":  current_orientation[0],
            "pitch": current_orientation[1],
            "yaw":   current_orientation[2]
        }

        # Since the agents only moves forward in their own x axis, we need to translate the
        # goal to a distance to the goal. This works since we always use point and shoot so we will
        # only move closer to the goal if we are looking in the right direction.
        goals["x"] = 0
        currents["x"] = - self.distance_to_goal(current.position, goal.position)

        # Check if the agent is within 0.1m of the target,
        if abs(currents["x"]) < 0.4:
            smallest_angle_to_goal = abs(((goals["yaw"] - currents["yaw"] + pi) % 2*pi) - pi)
            # Check if the goal is behind the agent ( > 120 degrees)
            if smallest_angle_to_goal > (2*pi)/3:
                self.get_logger().info(f"Goal is behind agent. Smallest angle to goal: {degrees(smallest_angle_to_goal)} (>90 degrees). Allowing reverse.")
                # Reverse the distance to make the agent reverse instead of turn and go forward
                currents["x"] *= -1
                # Also make the desired yaw the opposite direction so it is reversing instead of turning
                goals["yaw"] = (goals["yaw"] + 180) % 360

        # Create the motor outputs list
        motor_outputs = []
        # ... and the control values dict
        control_values = {}

        # First update setpoint from goal pose for all pids
        # and then calculate the control value and store it in the list
        for key, pid_ in self._pids.items():
            pid_.setpoint = goals[key]
            control_values[key] = pid_(currents[key])
            self.get_logger().info(f"{key} PID components: {pid_.components}")
        self.get_logger().info(f"Control values: {control_values}")
        

        current_pitch_degrees = degrees(currents["pitch"])
        pitch_percentage_of_limit = current_pitch_degrees / self._pitch_limit
        # NOTE: This inline function returns a scaling value that is 0 when the input x == z, which is
        #       the percentage of the pitch limit. E.g., a pitch limit of 45 degrees and z=0.9, the scaling value
        #       will be zero when the agent's pitch is 0.9*45=40.5, meaning that the pid affecting x will be set to 0.
        #       When the pitch is greater than 40.5 in this example, the output value will be negative, meaning that
        #       the agent will try very hard not to hit the pitch limit.
        pitch_vel_scaling_fn = lambda x, z: 1 - (x/z)**4
        # Scale the x/y pid contorl values based on current pitch to avoid the agent from tipping over.
        pitch_vel_scaling =  pitch_vel_scaling_fn(pitch_percentage_of_limit, 0.9)
        control_values["x"] *= pitch_vel_scaling
        control_values["y"] *= pitch_vel_scaling

        # # Compute the total velocity vector
        total_vel = sqrt(self._agent_state.twist.linear.x**2 + self._agent_state.twist.linear.y**2) # + self._agent_state.twist.linear.z**2)
        self.get_logger().info(f"VELOCITY: {total_vel}")
        # Check if the agent is accelerating which means the thrust should be limited by the log velocity function
        # if self.is_accelerating():
        #     # Scale the x/y pid control values based on the current velocity
        #     # to avoid jerky acceleration
        #     linear_vel_log_fn = lambda linear_vel: min(log(0.1*linear_vel + 1.01), 1.0)
        #     # NOTE: This does not work very well, probably needs a lot of fine tuning.
        #     # Get the linear velocity log scaling
        #     linear_thruster_scaling = linear_vel_log_fn(total_vel)
        #     self.get_logger().info(f"Agent accelerating, linear thruster scaling active: Linear control value={control_values['x']}, Scaling factor={linear_thruster_scaling}")
        #     control_values["x"] *= linear_thruster_scaling
        #     control_values["y"] *= linear_thruster_scaling

        delta_yaw = abs(goals["yaw"] - currents["yaw"])
        # Set the x to 0 if our yaw error is larger than ~2 degrees
        if delta_yaw > 0.034906585:
            control_values["x"] = 0
            control_values["y"] = 0


        # Compute the output for each motor
        for motor in self._motor_config:
            # Create the motor output msg
            output = MotorOutput()
            output.id = motor["id"]
            # Compute the output value for the motor by multiplying the control value with the pose_effect value for each key (x,y,z,roll,pitch,yaw)
            output.value = sum([motor["pose_effect"][key] * control_value for key, control_value in control_values.items()])
            motor_outputs.append(output)

        outputs_msg = MotorOutputs()
        outputs_msg.motor_outputs = motor_outputs
        self.get_logger().info(f"PID computed motor outputs: {outputs_msg}")

        return outputs_msg


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

        # Pythagorean theorem, the _use_z_in_distance_to_goal determines if the z difference should matter or not.
        return sqrt((x1-x2)**2 + (y1-y2)**2 + ((z1-z2)**2 * self._use_z_in_distance_to_goal))

    
    def _goto_pose_goal_reached(self, goal: Pose) -> bool:
        """Checks wheter the GotoPose goal is reached or not. The accepted state allows for some
        slack, defined as instance variables. This method uses the current agent state as the
        reference state.

        Args:
            goal (Pose): The goal pose to compare with.

        Returns:
            bool: Boolean that indicates whether the goal is reached or not.
        """
        current = self._agent_state.pose
        dist = self.distance_to_goal(current.position, goal.position)
        self.get_logger().info(f"Distance to goal: {dist}")
        orientation_errors = [(goal.orientation.x - current.orientation.x),# / goal.orientation.x,
                              (goal.orientation.y - current.orientation.y),# / goal.orientation.y,
                              (goal.orientation.z - current.orientation.z),# / goal.orientation.y,
                              (goal.orientation.w - current.orientation.w) #/ goal.orientation.y
                            ]

        return dist <= self._goto_pose_goal_distance_slack and max(orientation_errors) <= self._goto_pose_goal_orientation_slack

    def calculate_delta_pose(self, pose_a: Pose, pose_b: Pose) -> Pose:
        """Calculates the difference between two Poses: pose_a and pose_b.

        Args:
            pose_a (Pose): First pose.
            pose_b (Pose): Second pose.

        Returns:
            Pose: Returns the pose delta.
        """
        position_delta = Point()
        position_delta.x = pose_b.position.x - pose_a.position.x
        position_delta.y = pose_b.position.y - pose_a.position.y
        position_delta.z = pose_b.position.z - pose_a.position.z

        orientation_delta = Quaternion()
        orientation_delta.x = pose_b.orientation.x - pose_a.orientation.x
        orientation_delta.y = pose_b.orientation.y - pose_a.orientation.y
        orientation_delta.z = pose_b.orientation.z - pose_a.orientation.z
        orientation_delta.w = pose_b.orientation.w - pose_a.orientation.w

        delta_pose = Pose()
        delta_pose.position = position_delta
        delta_pose.orientation = orientation_delta

        return delta_pose

    def _twist_to_motor_outputs(self, twist_msg) -> MotorOutputs:
        """Converts the contents of a twist message into actual motor output values.
        The computations are based on pose_effect value in the motor_config json string
        for each motor in the system_launch_params.yaml file.

        Args:
            twist_msg (Twist): Twist message that should be converted.

        Returns:
            MotorOutputs: Motor outputs based on the twist message.
        """
        base_speed = 1 # TODO: This needs to be discussed.
        motor_outputs = []
        # PID the pitch and roll so the agents stay level during teleop
        self._pids["pitch"].setpoint = 0
        self._pids["roll"].setpoint = 0
        curr_orientation = SQuaternion(w=self._agent_state.pose.orientation.w,
                            x=self._agent_state.pose.orientation.x,
                            y=self._agent_state.pose.orientation.y,
                            z=self._agent_state.pose.orientation.z).to_euler(degrees=False)
        roll_control = self._pids["roll"](curr_orientation[0])
        pitch_control = self._pids["pitch"](curr_orientation[1])

        self.get_logger().info(f"Roll_control = {roll_control}")
        self.get_logger().info(f"pitch_control = {pitch_control}")
        self.get_logger().info("Converting twist_msg to motor outputs.")
        for motor in self._motor_config:
            output = MotorOutput()
            output.id = motor["id"]
            # Compute the value for the motor based on the linear and angular values in the twist message
            output.value = (motor["pose_effect"]["x"] * twist_msg.linear.x +
                            motor["pose_effect"]["y"] * twist_msg.linear.y +
                            motor["pose_effect"]["z"] * twist_msg.linear.z +
                            motor["pose_effect"]["yaw"] * twist_msg.angular.z +
                            motor["pose_effect"]["roll"] * roll_control +
                            motor["pose_effect"]["pitch"] * pitch_control)

            output.value *= base_speed
            motor_outputs.append(output)

        return motor_outputs

    def is_accelerating(self):
        """Uses the agent's state history deque to determine if the agent is accelerating
        or not.
        """
        # Pre-allocate list for small performance increase
        delta_vels = np.empty((len(self._state_history)-1))
        for i in range(len(self._state_history)-1):
            # Get the total velocity vector of i and i+1 and compute the difference. If the difference is positive,
            # the agent is accelerating.
            delta_vels[i] = sqrt(self._state_history[i+1].twist.linear.x**2 + self._state_history[i+1].twist.linear.y**2) - \
                            sqrt(self._state_history[i].twist.linear.x**2 + self._state_history[i].twist.linear.y**2)
        # If the majority of the delta_vels are positive, we consider the agent to be accelerating.
        # NOTE: This approach is robust to small acceleration errors but reacts slow when the agent's acceleration
        #       is changing.
        return sum(delta_vels > 0) > (len(self._state_history) / 2)


    #                   Callbacks
    # -----------------------------------------
    def _pid_param_set_callback(self, msg):
        """Read the json string and increment/decrement the pid config param.
        (NOTE: Perhaps slightly confusin method name)
        """
        # Update the corresponding PID object
        if msg.pid_element.lower() == "p":
            self._pids[msg.key].Kp = round(self._pids[msg.key].Kp + msg.value, 2)
        elif msg.pid_element.lower() == "i":
            self._pids[msg.key].Ki = round(self._pids[msg.key].Ki + msg.value, 2)
        elif msg.pid_element.lower() == "d":
            self._pids[msg.key].Kd = round(self._pids[msg.key].Kd + msg.value, 2)
        # Update the value in the pid config property
        self._pid_config[msg.pid_element][msg.key] += msg.value
        new_pid_config = json.dumps(self._pid_config)
        # self.get_logger().info(f"New PID config: {new_pid_config}")
        new_param = rclpy.parameter.Parameter('pid_config', rclpy.Parameter.Type.STRING, new_pid_config)
        self.get_logger().info(f"Incrementing PID param: {msg}")
        self.set_parameters([new_param])

    def _get_state_callback(self, _, response):
        """Simple getter for the node's state.
        """
        response.success = True
        response.state = str(self._motor_control_state)
        response.int_state = self._motor_control_state

        return response

    def _teleop_twist_callback(self, msg):
        """Callback for the teleop twist cmd vel message subcription.
        The teleop only works if manual override is set to True.
        NOTE: No validity checks for the twist message is in place, which means that it is possible to send linear and
              angular velocities that the agent can't handle or translate due to the motor configuration that is used.
        """
        if not self._manual_override:
            self.get_logger().info("Received teleop message but manual override is currently not active. Discarding message.")
            return
        # Translate the cmd vel into motor values
        motor_outputs = self._twist_to_motor_outputs(msg)
        # Create and publish the motor output message
        motor_msg = MotorOutputs()
        motor_msg.motor_outputs = motor_outputs
        self.get_logger().info(f"Received and translated teleop message to motor outputs. Sending motor outputs to motor driver.\nOutputs: {motor_outputs}")
        self._motor_outputs_publisher.publish(motor_msg)


    def _server_manual_override_callback(self, request, response):
        """Tries to set the manual override property.
        """
        try:
            self._manual_override = request.data
            response.success = True
            response.message = f"Successfully set manual override to {request.data}."
            if request.data == True:
                self.disable_pids()
                # Enable only roll and pitch so that the agents stays level (only works on NAIAD)
                self._pids["roll"].auto_mode = True
                self._pids["pitch"].auto_mode = True
                self._update_node_state(MotorControlState.MANUAL_OVERRIDE)
            else:
                self.enable_pids()
                self._update_node_state(self._prev_state)
        except Exception as e:
            response.success = False
            response.message = f"Something went wrong when setting manual override property. The manual override is currently set to: {self._manual_override}\n" \
                               f"Error message: {e}."

        return response

    def _update_pas_orientation(self):
        """Computes and updates the point and shoot orientation needed to go straight from the current position to
         the goal position. Uses the object properties _agent_state and _goal_pose to get current and goal position.

        Returns:
            Quaternion: Orientation needed to "shoot".
        """
        current = self._agent_state.pose.position
        
        goal = self._goal_pose.position
        # Create vector from the two points
        pas_vec = (goal.x - current.x, goal.y - current.y, goal.z - current.z)
        pas_yaw_angle = atan2(pas_vec[1], pas_vec[0])
        self.get_logger().info(f"Computed new PaS yaw angle: {pas_yaw_angle}")
        # TODO: Account for all angles, not only yaw.
        q_temp = SQuaternion.from_euler(0,0,pas_yaw_angle, degrees=False)

        pas_q = Quaternion()
        pas_q.x = q_temp.x
        pas_q.y = q_temp.y
        pas_q.z = q_temp.z
        pas_q.w = q_temp.w
        self.get_logger().info(f"Updating point and shoot orientation: {pas_q}")
        current_angles = SQuaternion(w=self._agent_state.pose.orientation.w, x=self._agent_state.pose.orientation.x,y=self._agent_state.pose.orientation.y,z=self._agent_state.pose.orientation.z,).to_euler(degrees=True)
        self.get_logger().info(f"Agent current angles in degrees: {current_angles}")
        self._pas_orientation = pas_q

    # State listener callback
    def _state_listener_callback(self, msg: State):
        """Callback for the subscribtion to the position/state topic that contains state messages with the msg type Pose.
        The callback reads the state and updates the agent_state property.
        """
        self.get_logger().info(f"Received state update. New state of the agent is: {msg}")
        self._agent_state = msg
        # Add the state to the history deque
        self._state_history.append(self._agent_state)

    # Sim odom listener callback
    def _sim_odom_listener_callback(self, msg: Odometry):
        """Callback for the subscribtion to the simulation odom topic that contains state messages
        with the msg type nav_msgs/Odom. The callback reads the state and updates the agent_state property.
        """
        temp_state = State()
        temp_state.pose = msg.pose.pose
        temp_state.twist = msg.twist.twist
        # self.get_logger().info(f"Received odom update. New state of the agent is: {temp_state}")
        self._agent_state = temp_state
        # Add the state to the history deque
        self._state_history.append(self._agent_state)


    def _running_std_update(self, existing_aggregate, new_values):
        """Algorithm for computing variance in a single pass to save memory and computational power.
        Fore more information see Welford's online algorithm: https://en.wikipedia.org/wiki/Algorithms_for_calculating_variance.
        """
        new_values = np.array([new_values.position.x, new_values.position.y, new_values.position.z,
                    new_values.orientation.x, new_values.orientation.y, new_values.orientation.y, new_values.orientation.z])

        (count, means, M2) = existing_aggregate
        count += 1
        delta = new_values - means #[a-m for a,m in zip(new_values, means)]
        means = means + (delta / count) #[m + (d/count) for m,d in zip(means, delta)]
        delta2 = new_values - means #[a-m for a,m in zip(new_values, means)]
        M2 = M2 + (delta*delta2) # [m + (d1*d2) for m,d1,d2 in zip(M2, delta, delta2)]

        return (count, means, M2)

    def _finalize_running_std(self, existing_aggregate):
        """Retrieves the mean, variance and sample variance from an aggregate.
        See Welford's online algorithm: https://en.wikipedia.org/wiki/Algorithms_for_calculating_variance
        """
        (count, means, M2) = existing_aggregate
        if count < 2:
            return float("nan")
        else:
            (means, variances, sample_variances) = (means, M2 / count, M2 / (count - 1))
            return (means, variances, sample_variances)

    def pose_from_list(self, list_):
        """Helper function that returns a Pose created from a list with position x,y,z and orientation x,y,z,w in that order."""
        pose = Pose()
        pose.position.x, pose.position.y, pose.position.z = list_[0], list_[1], list_[2]
        pose.orientation.x, pose.orientation.y, pose.orientation.z, pose.orientation.w = list_[3], list_[4], list_[5], list_[6]

        return Pose()

    # HoldPose callbacks
    # ------------------
    def _set_hold_pose_time_reached(self):
        """Callback for the hold pose timer that gets executed when the HoldPose request duration is reached."""
        self.get_logger().info(f'Holding duration reached.')
        self._hold_pose_time_reached = True

    def _action_server_hold_pose_on_cancel_callback(self, goal_handle):
        """When a cancel is requested, we just set the hold_pose_time_reached
        to true, and lets the execute callback handle the rest.
        """
        self.get_logger().info("Received cancel request. Cancelling...")
        self._hold_pose_time_reached = True

        return CancelResponse.ACCEPT
    

    def _action_server_hold_pose_execute_callback(self, goal_handle):
        """Execution callback for the HoldPose action. Executes the goal with the help of PID regulation
        of the motors.
        """
        self.get_logger().info(f'Received HoldPose goal: {goal_handle.request}')
        self._update_node_state(MotorControlState.EXECUTING)
        # Update object properties
        self._goal_pose = goal_handle.request.pose
        # Compute and update initial PaS orientation
        self._update_pas_orientation()
        # Create timer that continuously updates the PaS orientation
        pas_orientation_timer = self.create_timer(1/self._pas_orientation_update_freq, self._update_pas_orientation)

        # Variables that tracks the mean pose deviation
        mean_pose = [self._agent_state.pose.position.x, self._agent_state.pose.position.y, self._agent_state.pose.position.z,
                    self._agent_state.pose.orientation.x, self._agent_state.pose.orientation.y, self._agent_state.pose.orientation.y, self._agent_state.pose.orientation.z]
        mean_pose_m2 = [0] * 7
        mean_pose_count = 1

        if goal_handle.request.duration > 0:
            # Start the hold pose timer
            hold_pose_timer = self.create_timer(goal_handle.request.duration, self._set_hold_pose_time_reached)
        # Start time for the hold action
        hold_start_time = self.get_clock().now().seconds_nanoseconds()[0]
        # Loop as long as the time goal hasn't been reached
        while(not self._hold_pose_time_reached):
            current_pos = self._agent_state.pose.position
            desired_pos = goal_handle.request.pose.position
            current_orientation = self._agent_state.pose.orientation
            desired_orientation = goal_handle.request.pose.orientation
            # Calculate distance between desired position and current position.
            distance_to_goal = self.distance_to_goal(current_pos, desired_pos)
            # Check if the distance is within the point_and_shoot_threshold.
            if distance_to_goal < self._pas_threshold:
                # Set the desired orientation to the point and shoot orientation.
                desired_orientation = self._pas_orientation

            desired_pose = Pose()
            desired_pose.position = desired_pos
            desired_pose.orientation = desired_orientation

            # Create feedback message
            feedback_msg = HoldPose.Feedback()
            if self._manual_override:
                self.get_logger().info('Manual override is active. Not sending motor values to motor driver this iteration.')
                feedback_msg.status = HoldPoseStatus.HOLDING
                feedback_msg.message = "Manual override is active. Objetive will continue once manual override is switched off."

            else:
                motor_outputs_msg = self.pid(self._agent_state.pose, desired_pose)
                # self.get_logger().info(f'Publishing motor output values to the motor driver. Motor values: {motor_outputs_msg.motor_outputs}')
                self._motor_outputs_publisher.publish(motor_outputs_msg)
                feedback_msg.status = HoldPoseStatus.HOLDING
                feedback_msg.message = "Holding pose."

            # Calculate pose mean and variance
            mean_pose_count, mean_pose, mean_pose_m2 = self._running_std_update((mean_pose_count, mean_pose, mean_pose_m2), self._agent_state.pose)
            means, variance, _ = self._finalize_running_std((mean_pose_count, mean_pose, mean_pose_m2))
            feedback_msg.pose_mean = self.pose_from_list(means)
            feedback_msg.pose_variance = self.pose_from_list(variance)
            # Publish the feedback message
            goal_handle.publish_feedback(feedback_msg)

            self.get_logger().info(f'{feedback_msg.message}')
            # Relative sleep according to the goto_pose_rate.
            self._motor_update_rate.sleep()
        
        # GOAL FINISHED
        # -------------
        # Stop the PaS orientation timer
        pas_orientation_timer.cancel()
        # ... and the hold_pose timer
        if goal_handle.request.duration != 0:
            hold_pose_timer.cancel()
        # Send 0 as the final motor output values so the agent stops acting since the goal is finished.
        motor_output_msg = MotorOutputs()
        outputs = []
        for motor in self._motor_config:
            output = MotorOutput()
            output.id = motor["id"]
            output.value = 0.0
            outputs.append(output)
        motor_output_msg.motor_outputs = outputs
        self.get_logger().info(f'Goal reached. Stopping motors by publishing {motor_output_msg.motor_outputs} to the motor driver.')
        self._motor_outputs_publisher.publish(motor_output_msg)
        # Result message
        hold_end_time = self.get_clock().now().seconds_nanoseconds()[0]
        goal_handle.succeed()
        result = HoldPose.Result()
        result.status = HoldPoseStatus.FINISHED
        result.duration = hold_end_time - hold_start_time
        result.message = f"Finished holding pose for {result.duration} seconds. Goal finished."
        # Calculate the final mean and variance
        mean_pose_count, mean_pose, mean_pose_m2 = self._running_std_update((mean_pose_count, mean_pose, mean_pose_m2), self._agent_state.pose)
        means, variance, _ = self._finalize_running_std((mean_pose_count, mean_pose, mean_pose_m2))
        result.pose_mean = self.pose_from_list(means)
        result.pose_variance = self.pose_from_list(variance)

        self.get_logger().info(f'Returning result: {result}')
        # Update the motor control node state
        self._update_node_state(MotorControlState.IDLE)
        # Reset the hold_pose_time_reached
        self._hold_pose_time_reached = False

        return result

    # GotoPose callbacks
    # -----------------

    def _action_server_goto_pose_on_cancel_callback(self, goal_handle):
        """When a cancel is requested, we just set the hold_pose_time_reached
        to true, and lets the execute callback handle the rest.
        """
        self.get_logger().info("Received cancel request. Cancelling...")

        return CancelResponse.ACCEPT

    def _action_server_goto_pose_execute_callback(self, goal_handle):
        """Execution callback for the GotoPose action. Executes the goal with the help of PID regulation
        of the motors.
        
        The motor controller behaves similar to a point and shoot approach, which means if the desired
        position is outside of an accepted threshold, the motor controller will compute its own desired
        orientation that will point straight at the desired position and prioritize the orientation over
        the position in the PID regulation. This will in turn lead to behavior mimicking the point and
        shoot approach.
        """
        self.get_logger().info(f'Received goal: {goal_handle.request}')
        self._update_node_state(MotorControlState.EXECUTING)
        # Update object properties
        self._goal_pose = goal_handle.request.pose
        # Compute and update initial PaS orientation
        self._update_pas_orientation()
        # Create timer that continuously updates the PaS orientation
        pas_orientation_timer = self.create_timer(1/self._pas_orientation_update_freq, self._update_pas_orientation)

        self._motor_update_rate = self.create_rate(self._motor_update_frequency)
        # Loop as long as the goal isn't reached.
        while(not self._goto_pose_goal_reached(goal_handle.request.pose) and not goal_handle.is_cancel_requested):
            current_pos = self._agent_state.pose.position
            desired_pos = goal_handle.request.pose.position
            current_orientation = self._agent_state.pose.orientation
            desired_orientation = goal_handle.request.pose.orientation
            # Calculate distance between desired position and current position.
            distance_to_goal = self.distance_to_goal(current_pos, desired_pos)
            # Check if the distance is within the point_and_shoot_threshold.
            if distance_to_goal > self._pas_threshold:
                # Set the desired orientation to the point and shoot orientation.
                desired_orientation = self._pas_orientation

            desired_pose = Pose()
            desired_pose.position = desired_pos
            desired_pose.orientation = desired_orientation

            # Create feedback message
            feedback_msg = GotoPose.Feedback()
            if self._manual_override:
                self.get_logger().info('Manual override is active. Not sending motor values to motor driver this iteration.')
                feedback_msg.status = GotoPoseStatus.WAITING
                feedback_msg.message = "Manual override is active. Objetive will continue once manual override is switched off."

            else:
                motor_outputs_msg = self.pid(self._agent_state.pose, desired_pose)
                # self.get_logger().info(f'Publishing motor output values to the motor driver. Motor values: {motor_outputs_msg.motor_outputs}')
                self._motor_outputs_publisher.publish(motor_outputs_msg)
                feedback_msg.status = GotoPoseStatus.MOVING_TO_POSE
                feedback_msg.message = "Moving to pose."

            feedback_msg.distance_to_goal = distance_to_goal
            feedback_msg.delta_pose = self.calculate_delta_pose(self._agent_state.pose, goal_handle.request.pose)
            # Publish the feedback message
            goal_handle.publish_feedback(feedback_msg)

            self.get_logger().info(f'{feedback_msg.message}')
            # Relative sleep according to the goto_pose_rate.
            self._motor_update_rate.sleep()

        # GOAL FINISHED
        # -------------
        # Stop the PaS orientation timer
        pas_orientation_timer.cancel()
        # Send 0 as the final motor output values so the agent stops acting since the goal is finished.
        motor_output_msg = MotorOutputs()
        outputs = []
        for motor in self._motor_config:
            output = MotorOutput()
            output.id = motor["id"]
            output.value = 0.0
            outputs.append(output)
        motor_output_msg.motor_outputs = outputs
        self.get_logger().info(f'Goal reached. Stopping motors by publishing {motor_output_msg.motor_outputs} to the motor driver.')
        self._motor_outputs_publisher.publish(motor_output_msg)

        goal_handle.succeed()
        result = GotoPose.Result()
        result.status = GotoPoseStatus.FINISHED
        result.message = "Arrived at the goal pose. Goal finished."
        result.distance_to_goal = self.distance_to_goal(self._agent_state.pose.position, goal_handle.request.pose.position)

        self.get_logger().info(f'Returning result: {result}')

        self._update_node_state(MotorControlState.IDLE)

        return result
