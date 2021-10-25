import rclpy
from typing import List
from rclpy.executors import MultiThreadedExecutor
from geometry_msgs.msg import Pose
from trident_msgs.msg import MotorOutputs, MotorOutput
from baseclasses.motorcontrolbase import MotorControlBase

class MotorControlNode(MotorControlBase):
    """The main node for the motor control module. 
    """
    def __init__(self, node_name) -> None:
        super().__init__(node_name)
        self.get_logger().info("Created motor control node.")

    def pid(self, current: Pose, goal: Pose) -> MotorOutputs:
        # TODO: Replace this debug code
        temp = MotorOutputs()
        outputs = []
        for motor in self._motor_config:
            output = MotorOutput()
            output.id = motor["id"]
            output.value = 0.0
            outputs.append(output)
        temp.motor_outputs = outputs
        self.get_logger().info(f"PID returning Motor ouputs: {temp}")
        return temp


def main(args=None):
    rclpy.init(args=args)
    motor_control_node = MotorControlNode("motor_control")
    executor = MultiThreadedExecutor()
    rclpy.spin(motor_control_node, executor)
    rclpy.shutdown()


if __name__=="__main__":
    main()


