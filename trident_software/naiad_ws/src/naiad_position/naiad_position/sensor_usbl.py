import rclpy
import numpy as np
import baseclasses.sensorbase as sensbase
from squaternion import Quaternion

from visualization_msgs.msg import MarkerArray

class USBLNode(sensbase.SensorNode):
    def __init__(self):
        
        noise_mat = np.array([.5,.5,.5])
        
        super().__init__('usbl', 'naiad', 0.5,
                         3, noise_mat)
                         
        # These value that will be read/written to to get the athenas position
        self.declare_parameter('athena_position/x', 0.)
        self.declare_parameter('athena_position/y', 0.)
            
        # If the is_simulated parameter exists and is set, listen to the simulated sensor.
        # Otherwise, default is False and it will act like normal.
        self.declare_parameter('simulated', False)
        if(self.get_parameter('simulated').value):
            self.simul_sensor = self.create_subscription(
                                MarkerArray, '/naiad/simulation/usbl',
                                self.SimulatedMeasurement, 10)
            self.timer.destroy() # Stop the original timed sensor from running
        else:
            self.get_logger.error("REAL USBL NOT IMPLEMENTED!")
    
    def state_guess(self, current_state):
        athena_pos = np.array([self.get_parameter('athena_position/x').value,
                      self.get_parameter('athena_position/y').value, 0])
        q = Quaternion(current_state[3], current_state[4], current_state[5], current_state[6])
        #self.get_logger().info("Rotation Quat: %s" % q)
        rotation = np.array([[1-2*(q[2]**2 + q[3]**2),   2*(q[1]*q[2] - q[0]*q[3]), 2*(q[0]*q[2] + q[1]*q[3])],
                             [2*(q[1]*q[2] + q[0]*q[3]), 1-2*(q[1]**2 + q[3]**2),   2*(q[2]*q[3] - q[0]*q[1])],
                             [2*(q[1]*q[3] - q[0]*q[2]), 2*(q[0]*q[1] + q[2]*q[3]), 1-2*(q[1]**2 + q[2]**2)  ]])
        
        #self.get_logger().info("Rotation matrix: %s" % np.array_str(rotation))
        
        global_athena_distance = np.matmul(rotation, self.measure)
        absolute_world_pos = athena_pos - global_athena_distance
        
        #self.get_logger().info("USBL Absolute pos guess: %s" % np.array_str(absolute_world_pos))
        guess = np.array([absolute_world_pos[0], absolute_world_pos[1], absolute_world_pos[2],
                         0,0,0,0,
                         0,0,0,
                         0,0,0])
        noise = np.array([0.5,0.5,2,
                          np.inf,np.inf,np.inf,np.inf,
                          np.inf,np.inf,np.inf,
                          np.inf,np.inf,np.inf])
        return guess, noise
    
    def TakeMeasurement(self):
        pass
        
    def SimulatedMeasurement(self, msg):
        self.measure[0] = msg.markers[0].pose.position.x
        self.measure[1] = msg.markers[0].pose.position.y
        self.measure[2] = msg.markers[0].pose.position.z

def main(args=None):
    rclpy.init(args=args)
    node = USBLNode()
    rclpy.spin(node)
    rclpy.shutdown()

if __name__ == "__main__":
    main()
