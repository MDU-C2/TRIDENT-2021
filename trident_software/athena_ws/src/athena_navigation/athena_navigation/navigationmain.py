import rclpy
from rclpy.executors import MultiThreadedExecutor
from baseclasses.navigationbase import NavigationBase


class NavigationNode(NavigationBase):
    """The main node for the navigation module in Athena.
    """
    def __init__(self, node_name) -> None:
        super().__init__(node_name)
        self.get_logger().info("Created navigation node.")


def main(args=None):
    rclpy.init(args=args)
    navigation_node = NavigationNode("navigation")
    executor = MultiThreadedExecutor()
    rclpy.spin(navigation_node, executor)
    rclpy.shutdown()


if __name__=="__main__":
    main()
