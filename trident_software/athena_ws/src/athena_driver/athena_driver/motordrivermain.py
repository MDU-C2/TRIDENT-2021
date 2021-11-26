import rclpy
import signal
import sys
from rclpy.executors import MultiThreadedExecutor
from baseclasses.motordriverbase import MotorDriverBase
from trident_msgs.msg import MotorOutputs


class MotorDriverNode(MotorDriverBase):
    """The main node for the motor driver module in Athena.
    """
    def __init__(self, node_name) -> None:
        super().__init__(node_name)
        self.get_logger().info("Created motor driver node.")



    def _send_motor_outputs(self, motor_outputs: MotorOutputs):
        """Sends the specified motor value to the motor with specified motor_number.

        Args:
            motor_outputs: The list of motor_id, motor_output pairs that should be sent to the motor.
        """
        # TODO: Implement real world drivers
        pass


def signal_handler(sig, frame):
    rclpy.shutdown()
    sys.exit(0)

def main(args=None):
    signal.signal(signal.SIGINT, signal_handler)
    rclpy.init(args=args)
    motor_driver_node = MotorDriverNode("motor_driver")
    executor = MultiThreadedExecutor()
    rclpy.spin(motor_driver_node, executor)
    rclpy.shutdown()


if __name__=="__main__":
    main()
