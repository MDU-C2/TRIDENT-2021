import rclpy
from rclpy.executors import MultiThreadedExecutor
from geometry_msgs.msg import Pose
from trident_msgs.msg import MotorOutputs, MotorOutput
from baseclasses.motorcontrolbase import MotorControlBase

class MotorControlNode(MotorControlBase):
    """The main node for the motor control module in Athena.
    """
    def __init__(self, node_name):
        super().__init__(node_name)
        self.get_logger().info("Created motor control node.")


def main(args=None):
    rclpy.init(args=args)
    motor_control_node = MotorControlNode("motor_control")
    executor = MultiThreadedExecutor()
    rclpy.spin(motor_control_node, executor)
    rclpy.shutdown()


if __name__=="__main__":
    main()
