import rclpy
from rclpy.node import Node

from LoadMissionPlan.srv import LoadMissionPlan

class NavigationBase(Node):

    def __init__(self, node_name):
        super().__init__(node_name)
        self.srv = self.create_service(LoadMissionPlan, 'nav/wp_queue/', self.load_mission_plan_callback)

    def load_mission_plan_callback(self, request, response):
        for latitude,longitude in request.latitude,request.longitude:
            self.get_logger().info('Incoming request\na: %d b: %d' % (latitude, longitude))

        response = 1
        return response