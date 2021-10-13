import sys
import os

# from setuptools import find_namespace_packages
# baseclasses_package_path = os.path.join( os.path.abspath(__file__).split('trident_software')[0],('trident_software/'))
# test = find_namespace_packages( where=baseclasses_package_path, include='*base')
# print(test)

# sys.path.append(os.path.join( os.path.abspath(__file__).split('trident_software')[0],('trident_software/')))
# sys.path.append(os.path.join( os.path.abspath(__file__).split('trident_software')[0],('trident_software/')))

# sys.path.append("/home/johannes/TRIDENT-2021/trident_software/baseclasses")
# print(sys.path.dir(__file__))
# print(sys.path)
import rclpy
from baseclasses.missioncontrolbase import MissionControlBase


class MissionControlNode(MissionControlBase):
    """The main node for the Mission Control module. 
    """    
    def __init__(self, node_name) -> None:
        super().__init__(node_name)
        rclpy.get_logger().info("Created mission control node.")


def main(args=None):
    rclpy.init(args=args)
    mission_control_node = MissionControlNode("mission_control")
    rclpy.spin(mission_control_node)
    rclpy.shutdown()


if __name__=="__main__":
    main()