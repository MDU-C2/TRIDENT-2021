import sys
import threading
from baseclasses.motorcontrolbase import MotorControlBase
import rclpy
from rclpy.executors import MultiThreadedExecutor
from baseclasses.motordriverbase import MotorDriverBase
from trident_msgs.msg import MotorOutputs

import time
from math import sin

# Constants
PWM_FREQUENCY = 50
MICRO = 1000000 # Microseconds in a second
ESC_PW_INTERVAL_CENTER = 1500  # The center of the supported PW interval (1500 microseconds)
ESC_FULL_POWER = 400  # Full power in either direction

class MotorDriverNode(MotorDriverBase):
    """The main node for the motor driver module in Athena.
    """
    def __init__(self, node_name) -> None:
        super().__init__(node_name)
        self.get_logger().info("Created motor driver node.")
        if not self._simulation_env:
            import RPi.GPIO as GPIO
            self._pwm_containers = {}
            # Initialize pwns and setup GPIO
            GPIO.setmode(GPIO.BOARD)
            for motor in self._motor_interface:
                # Set the motor's pin as output
                GPIO.setup(motor["pin"], GPIO.OUT)
                # Create and start the pwn
                pwm = GPIO.PWM(motor["pin"], PWM_FREQUENCY)
                pwm.start(0)
                self._pwm_containers[motor["id"]] = {
                    "pwm": pwm,
                    "pin": motor["pin"]
                }
                # self.get_logger().info(self._pwm_containers)
            # Initialize the ESCs
            self._esc_init_duty_cycle = self.get_duty_cycle(ESC_PW_INTERVAL_CENTER/MICRO)
            for motor_id, pwm_container in self._pwm_containers.items():
                self.get_logger().info(f"Initializing PWM for motor {motor_id} on pin {pwm_container['pin']}.")
                pwm_container["pwm"].ChangeDutyCycle(self._esc_init_duty_cycle)
            # Sleep for a few seconds to allow the ESCs to initialize
            rate = self.create_rate(3, self.get_clock())
            rate.sleep()
            self.get_logger().info("PWMs initialized.")


    # def __del__(self):
    #     """Overrides the del function to ensure that the PWMs are cleaned up properly if the node is destroyed."""
    #     if not self._simulation_env:
    #         self.pwm_cleanup()

    def get_duty_cycle(self, pulse_width):
        """Gets the duty cycle from the pulse width.
        """
        # Minus 80*MICRO here because the pi's PWM is shit and inaccurate and this makes it "right"
        # return 100 * ((pulse_width-(80*MICRO)) / (1/PWM_FREQUENCY))
        return 100 * (pulse_width - 60/MICRO) / (1/PWM_FREQUENCY)

    def get_pulse_width(self, power_percentage):
        """Gets the pulse width from the power percentage.
        """
        clamped = max(-1.0, min(power_percentage, 1.0))
        return ((ESC_FULL_POWER * clamped) + ESC_PW_INTERVAL_CENTER) / MICRO

    def set_power(self, motor_id, power):
        """Sets the motor power to the specfied motor with motor_id.

        Args:
            motor_id (Int): ID of the motor to set the power for.
            power (Float): The power to set, value between -1.0 and 1.0
        """
        self.get_logger().info(f"Set motor {motor_id} power to {power}")
        pwm = self._pwm_containers[str(motor_id)]["pwm"]
        pwm.ChangeDutyCycle(self.get_duty_cycle(self.get_pulse_width(power)))

    def _send_motor_outputs(self, motor_outputs: MotorOutputs):
        """Sends the specified motor value to the motor with specified motor_number.

        Args:
            motor_outputs: The list of motor_id, motor_output pairs that should be sent to the motor.
        """
        self.get_logger().info(f"Send motor outputs: {motor_outputs}")
        # Loop through the motor outputs
        for motor_output in motor_outputs:
            # Set the specified power for the motor with the specified ID
            self.set_power(motor_output["motor_id"], motor_output["motor_output"])

    def pwm_cleanup(self):
        """Cleans up the PWMs by stopping them and setting the GPIO outputs to low.
        """
        if not self._simulation_env:
            self.get_logger().info(f"Node deletion in progress. Cleaning up GPIO.")
            import RPi.GPIO as GPIO
            for pwm_container in self._pwm_containers.values():
                pwm_container["pwm"].stop()
                GPIO.output(pwm_container["pin"], GPIO.LOW)
            GPIO.cleanup()


def main(args=None):
    rclpy.init(args=args)
    motor_driver_node = MotorDriverNode("motor_driver")
    executor = MultiThreadedExecutor()
    spin_thread = threading.Thread(target=rclpy.spin, args=(motor_driver_node, executor), daemon=True)
    spin_thread.start()
    spin_thread.join()
    # motor_driver_node.pwm_cleanup()
    rclpy.shutdown()


if __name__=="__main__":
    main()
