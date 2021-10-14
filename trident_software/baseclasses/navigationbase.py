import rclpy
from rclpy.node import Node

#from trident_msgs.srv import LoadMissionPlan
from example_interfaces.srv import AddTwoInts

class NavigationBase(Node):
    def __init__(self, node_name):
        super().__init__(node_name)
        self.srv = self.create_service(AddTwoInts, 'nav/wp_queue/empty', self.load_mission_plan_callback)

    def load_mission_plan_callback(self, request, response):
        #for latitude,longitude in request.a,request.b:
        self.get_logger().info('Incoming request\na: %d b: %d' % (request.a, request.b))
        response.sum = request.a + request.b
        return response
        