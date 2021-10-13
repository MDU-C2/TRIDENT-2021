import rclpy
from rclpy.node import Node

from geometry_msgs.msg import Pose      # https://github.com/ros2/common_interfaces/blob/master/geometry_msgs/msg/Pose.msg
from std_srvs.srv import Trigger        # https://github.com/ros2/common_interfaces/blob/master/std_srvs/srv/Trigger.srv


# Pose

class MissionControlBase(Node):
    """A base class for the mission control modules in Athena and NAIAD designed with generalization in mind.
    """
  
    def __init__(self, node_name) -> None:
        super().__init__(node_name)
        
        # Create the clients
        # Client for the navigation module's empty waypoint queue service
        self.request_empty_wp_queue_client = self.create_client(Trigger, 'nav/wp_queue/empty')
        self.fill_wp_queue_client = self.create_client(Trigger, 'nav/wp_queue/fill')

