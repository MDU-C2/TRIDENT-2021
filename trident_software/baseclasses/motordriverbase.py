
"""Module containing the base class definition for the motor driver nodes.

Author: Johannes Deivard 2021-10
"""
from abc import ABCMeta, abstractmethod
import rclpy
from rclpy.node import Node
from rclpy.action import ActionClient, ActionServer
from std_srvs.srv import Trigger
# from geometry_msgs.msg import Pose, Point, Quaternion
# from trident_msgs.action import GotoPose, HoldPose
from trident_msgs.msg import MotorOutput
from baseclasses.tridentstates import MotorDriverState


class MotorDriverBase(Node, metaclass=ABCMeta):
    """A base class for the motor driver nodes used in Athena and NAIAD designed with
    generalization in mind.
    """

    def __init__(self, node_name):
        super().__init__(node_name)
        self.motor_driver_state = MotorDriverState.IDLE

        # Declare parameters
        self.declare_parameters(
            namespace='',
            parameters=[
                ('motor_output_silence_period',  100), # Milliseconds
                ('num_motors',  2)
            ])
        # Load parameters
        self._motor_output_silence_period = self.get_parameter('motor_output_silence_period').get_parameter_value().integer_value # Milliseconds
        self._num_motors = self.get_parameter('num_motors').get_parameter_value().integer_value

        # Set default motor state to active
        self.motors_killed = False

        # Watchdog timer for the motor output silence (we want the agent to stop if no command is received within a defined timer period)
        self._motor_output_silence_watchdog_timer = self.create_timer(self._motor_output_silence_period, self._motor_output_silence_watchdog_timer_callback)
        self._motor_output_silence_watchdog_timer.cancel() # The timer should be started in the motor outpout message callback

        # Subscriptions
        # -------------
        self._motor_output_subscription = self.create_subscription(
            MotorOutput,
            'motor_control/motor_output',
            self._motor_output_sub_callback,
            1 # TODO: Use deadlines?
        )

        # Services
        # --------
        self._kill_motors_service = self.create_service(
            Trigger,
            'motor_driver/motors/kill',
            self._kill_motors_service_callback
        )
        self._kill_motors_service = self.create_service(
            Trigger,
            'motor_driver/motors/activate',
            self._activate_motors_service_callback
        )

    @abstractmethod
    def _send_motor_value(self, motor_number, value):
        pass
    
    def __send_motor_value(self, motor_number, value):
        """Private wrapper for the _send_motor_value abstract method.
        This wrapper ensures that the killed state of the motors is respected.
        """
        if self.motors_killed:
            self.get_logger().info('Motors are killed. Not sending motor values.')
            return
        self._send_motor_value(motor_number, value)

    def set_zero_motor_output(self):
        """Simply sets all motors output to zero.
        """
        for motor_num in range(self._num_motors):
            self._send_motor_value(motor_num, 0)

    #                   Callbacks
    # -----------------------------------------
    def _kill_motors_service_callback(self, _, response):
        """Callback function for the kill_motors service.
        The motors are killed by setting the motor output to 0 and the motors_killed boolean to True,
        which will hinder any motor values from getting to the motors.
        """
        try:
            self.set_zero_motor_output()
            self.motor_driver_state = MotorDriverState.KILLED
            self.motors_killed = True
            response.success = True
            response.message = "Successfully killed the motors."
        except Exception as e:
            response.success = False
            response.message = f"Failed to kill the motors. Error: {e}"

        return response

    def _activate_motors_service_callback(self, _, response):
        """Callback function for the activate_motors service.
        """
        try:
            self.motor_driver_state = MotorDriverState.ACTIVE
            self.motors_killed = False
            response.success = True
            response.message = "Successfully activated the motors."
        except Exception as e:
            response.success = False
            response.message = f"Failed to activate the motors. Error: {e}"
        
        return response
    

    def _motor_output_silence_watchdog_timer_callback(self):
        """Callback for the motor output silence watchdog timer that simply sets all motor values to 0
        to avoid the agent from escaping form us in case the motor control node stops functioning. 
        """
        self.set_zero_motor_output()
        self.motor_driver_state = MotorDriverState.MOTOR_OUTPUT_SILENCE

    def _motor_output_sub_callback(self, msg):
        """Callback for messages received on the motor_control/motor_output topic.
        Sends the received motor values to the motors via the MiniMaestro.
        Also starts a watchdog timer that sets the motor values to 0 on all motors
        if no motor output message is received within a 100 ms period.
        """
        # Stop the timer so that it doesn't trigger while we are processing the message
        self._motor_output_silence_watchdog_timer.cancel()
        # Check if the motors are supposed to be killed
        if not self.motors_killed:
            motor_values = msg.motor_outputs
            self.get_logger().info(f'Publishing motor output values to the motors. Motor values: {motor_values}')
            self.motor_driver_state = MotorDriverState.ACTIVE
            for motor_num, value in enumerate(motor_values):
                self.__send_motor_value(motor_num, value)
            # Motor values are sent to the motors, reset the watchdog timer
            self._motor_output_silence_watchdog_timer.reset()
        else:
            self.get_logger().info('Motors are currently killed. No motor output sent to the motors.\n' \
                                   'Activate the motors again by calling the motor_driver/motors/activate service.')



