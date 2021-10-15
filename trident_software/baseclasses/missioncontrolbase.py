import rclpy
from rclpy.node import Node
from rclpy.action import ActionClient, ActionServer

from geometry_msgs.msg import Pose      # https://github.com/ros2/common_interfaces/blob/master/geometry_msgs/msg/Pose.msg
from std_srvs.srv import Trigger        # https://github.com/ros2/common_interfaces/blob/master/std_srvs/srv/Trigger.srv
from trident_msgs.srv import LoadMission
from trident_msgs.action import StartMission



class MissionControlBase(Node):
    """A base class for the mission control modules in Athena and NAIAD designed with generalization in mind.
    """
  
    def __init__(self, node_name) -> None:
        super().__init__(node_name)
        self.mission = None
        
        # Create the clients
        # ------------------
        # Client for the navigation node's empty waypoint queue service
        self.client_request_empty_wp_queue = self.create_client(Trigger, 'nav/wp_queue/empty')
        # Client for the navigtaion node's fill waypoint queue service
        self.client_fill_wp_queue = self.create_client(Trigger, 'nav/wp_queue/fill')

        # Create the servers
        # ------------------
        # Server for the mission control's load mission service
        self.server_load_mission = self.create_service(LoadMission, 'mission_control/mission/load', self.server_load_mission_callback)
        self._action_server_start_mission = ActionServer(
            self,
            StartMission, 
            'mission_control/mission/start',
            execute_callback=self._action_server_start_mission_execute_callback,
        )

        # TODO: Discuss whether it is better to let the mission control handle the progress of the mission and instead
        #       only send a single waypoint to the navigtaion module.
        #       The benefits of this are that:
        #           - we don't get nested actions,
        #           - if the navigation node eventually are supposed to be more intelligent, the node can focus on getting to
        #             the goal without crashing into something, which means that it would plan and create a path to the goal, which 
        #             in essence means that the navigation node would create it's own "mission" to get to the waypoint.
        #           - it is easier to track the progress of a mission
        #       So, the mission control tracks the state of the mission and sends feedback to ground control.
        #       Each waypoint in the mission gets sent to the navigation node one at a time, which internally would
        #       create a path (a list of poses essentially) that would allow the agent to reach the waypoint. The 
        #       navigation node would send the poses one at a time to the motor controler and eventually reach the 
        #       mission goal. The navigation node would continuosly send feedback to mission control in the form of 
        #       distance from goal. Once the goal (a waypoint) is reached, the mission control would send the next 
        #       waypoint in the mission list to the navigation module and the process is repeated.   

    # Callbacks
    # ------------------
    async def _action_server_start_mission_execute_callback(self, goal_handle):
        """Executes the given goal by telling the navigation module to start the mission.
        """
        feedback_msg = StartMission.Feedback()

        


    def server_load_mission_callback(self, request, response):
        """Callback function for the mission_control/mission/load server.

        Args:
            request: Contains the mission to load.
            response: Boolean succcess and string message for information.
        """
        # Validity checks:
        # Empty mission
        if len(request.mission.waypoints) == 0:
            response.success = False
            response.message = "Cannot load a mission with 0 waypoints."

            return response
            
        try:
            self.get_logger().info(f"Received mission with {len(request.mission.waypoints)} waypoints.")
            self.mission = request.mission
            response.success = True
            response.message = f"Mission with {len(request.mission.waypoints)} waypoints loaded."

        except TypeError as error:
            self.mission = None
            response.success = False
            response.message = f"Failed to load the mission. Error: {error}"
        
        return response



