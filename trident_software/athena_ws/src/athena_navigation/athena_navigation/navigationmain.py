import rclpy
import sys
import os
from baseclasses.navigationbase import NavigationBase

def main(args=None):
    rclpy.init(args=args)
    navigation_node = NavigationBase("navigation")
    try:
        rclpy.spin(navigation_node)
    except KeyboardInterrupt:
        pass
    finally:
        navigation_node.destroy_node()
        rclpy.shutdown()


if __name__=="__main__":
    main()