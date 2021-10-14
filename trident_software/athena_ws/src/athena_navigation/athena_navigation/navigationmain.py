import rclpy
import sys
import os
from baseclasses.navigationbase import NavigationBase

def main(args=None):
    rclpy.init(args=args)
    navigation_node = NavigationBase("navigation")
    rclpy.spin(navigation_node)
    rclpy.shutdown()


if __name__=="__main__":
    main()