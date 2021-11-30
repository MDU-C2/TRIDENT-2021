import rclpy
import signal
import sys
from rclpy.executors import MultiThreadedExecutor
from baseclasses.missioncontrolbase import MissionControlBase


class MissionControlNode(MissionControlBase):
    """The main node for the Mission Control module in NAIAD.
    """
    def __init__(self, node_name) -> None:
        super().__init__(node_name)
        self.get_logger().info("Created mission control node.")


def signal_handler(sig, frame):
    rclpy.shutdown()
    sys.exit(0)

def main(args=None):
    signal.signal(signal.SIGINT, signal_handler)
    rclpy.init(args=args)
    mission_control_node = MissionControlNode("mission_control")
    executor = MultiThreadedExecutor()
    rclpy.spin(mission_control_node, executor)
    rclpy.shutdown()


if __name__=="__main__":
    main()
