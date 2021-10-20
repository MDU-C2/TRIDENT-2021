import rclpy
from rclpy.executors import MultiThreadedExecutor
from baseclasses.missioncontrolbase import MissionControlBase


class MissionControlNode(MissionControlBase):
    """The main node for the Mission Control module. 
    """
    def __init__(self, node_name) -> None:
        super().__init__(node_name)
        self.get_logger().info("Created mission control node.")


def main(args=None):
    rclpy.init(args=args)
    mission_control_node = MissionControlNode("mission_control")
    executor = MultiThreadedExecutor()
    rclpy.spin(mission_control_node, executor)
    rclpy.shutdown()


if __name__=="__main__":
    main()
