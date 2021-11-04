import rclpy
from rclpy.executors import MultiThreadedExecutor
from baseclasses.motordriverbase import MotorDriverBase
from trident_msgs.msg import MotorOutputs
from cola2_msgs.msg import Setpoints

class MotorDriverNode(MotorDriverBase):
    """The main node for the motor driver module in NAIAD.
    """
    def __init__(self, node_name) -> None:
        super().__init__(node_name)
        self.get_logger().info("Created motor driver node.")
        self._simulation = True

        # if self._simulation:
            # import 
        # self._sim_motor_publisher = self.create_publisher(
        # )

    def _send_motor_values(self, motor_outputs: MotorOutputs):
        """Sends the specified motor value to the motor with specified motor_number.

        Args:
            motor_outputs: The list of motor_id, motor_output pairs that should be sent to the motor.
        """
        # Reset the motor output silence watchdog timer.
        self._motor_output_silence_watchdog_timer.reset()
        if self._simulation:
            # Create the thruster Setpoints message
            msg = Setpoints()
            outputs = []
            for motor_output in motor_outputs:
                # Scale the output value to stonefish values (-1, 1)
                val = float(motor_output.value / 100)
                outputs.append(val)
            msg.setpoints = outputs
            self.get_logger().info(f"Publishing motor outputs to simulation. Outputs: {msg}")
            self._sim_motor_publisher.publish(msg)

        # TODO: Implement real world drivers


def main(args=None):
    rclpy.init(args=args)
    motor_driver_node = MotorDriverNode("motor_driver")
    executor = MultiThreadedExecutor()
    rclpy.spin(motor_driver_node, executor)
    rclpy.shutdown()


if __name__=="__main__":
    main()

