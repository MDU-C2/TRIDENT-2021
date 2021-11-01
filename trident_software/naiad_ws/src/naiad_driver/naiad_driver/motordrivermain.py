import rclpy
from rclpy.executors import MultiThreadedExecutor
from baseclasses.motordriverbase import MotorDriverBase

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

    def _send_motor_value(self, motor_number: int, value: int):
        """Sends the specified motor value to the motor with specified motor_number.

        Args:
            motor_number (int): The number of the motor that should receive the value
            value (int): Value for the motor output
        """
        # TODO: Implement this function
        if self._simulation:
            pass


def main(args=None):
    rclpy.init(args=args)
    motor_driver_node = MotorDriverNode("motor_driver")
    executor = MultiThreadedExecutor()
    rclpy.spin(motor_driver_node, executor)
    rclpy.shutdown()


if __name__=="__main__":
    main()

