import rclpy
from rclpy.executors import MultiThreadedExecutor
from baseclasses.navigationbase import NavigationBase
import signal
import sys

def signal_handler(sig, frame):
    rclpy.shutdown()
    sys.exit(0)

class NavigationNode(NavigationBase):
    """The main node for the navigation module in Athena.
    """
    def __init__(self, node_name) -> None:
        super().__init__(node_name)
        self.get_logger().info("Created navigation node.")


def main(args=None):
    rclpy.init(args=args)
    signal.signal(signal.SIGINT, signal_handler)
    navigation_node = NavigationNode("navigation")
    executor = MultiThreadedExecutor()
    rclpy.spin(navigation_node, executor)
    rclpy.shutdown()


if __name__=="__main__":
    main()
