import rclpy
import numpy as np
import baseclasses.sensorbase as sensbase
from math import sqrt, sin, cos, atan2

from visualization_msgs.msg import MarkerArray

class USBLNode(sensbase.SensorNode):
    def __init__(self):
        '''init_obs_mat = np.array([
            #  x   y   z   r   p   h  dx  dy  dz  dr  dp  dh
            [  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0], #diffx
            [  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0], #diffy
            [  0,  0, -1,  0,  0,  0,  0,  0,  0,  0,  0,  0]])#diffz'''
        
        noise_mat = (np.array([[.5,.5,.5]])*np.identity(3))**2
        
        super().__init__('usbl', 'naiad', 0.5,
                         self.ObservationService, 3, noise_mat)
                         
        # These value that will be read/written to to get the athenas position
        self.declare_parameter('athena_position/x', 0)
        self.declare_parameter('athena_position/y', 0)
            
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
    
    def ObservationService(self, state, dt):
        athena_pos = np.transpose(np.array([[self.get_parameter('athena_position/x').value,
                      self.get_parameter('athena_position/y').value, 0]]))
        naiad_pos = -1*state[:3]
        n_rot = -1*state[3:6]
        translate = np.append(np.eye(4,3), np.append(naiad_pos, [[1]], axis=0), axis=1)
        rotation = np.array([[cos(n_rot[2]), -sin(n_rot[2]), 0], [sin(n_rot[2]), cos(n_rot[2]), 0], [0, 0, 1]])
        '''diffpos = [a-b for a, b in zip(athena_pos, naiad_pos)]
        diffang = atan2(diffpos[1], diffpos[0])
        local_pos = [ # Doesn't account for pitch and roll!
        diffpos[0]*cos(state[5])+diffpos[1]*sin(state[5]),
        diffpos[1]*cos(state[5])-diffpos[0]*sin(state[5]),
        diffpos[2]]'''
        local_pos = np.matmul(rotation, np.matmul(translate, np.append(athena_pos, [[1]]))[:3])
        self.get_logger().info(np.array_str(local_pos))
        return local_pos
    
    def TakeMeasurement(self):
        pass
        
    def SimulatedMeasurement(self, msg):
        self.measure[0,0] = msg.markers[0].pose.position.x
        self.measure[1,0] = msg.markers[0].pose.position.y
        self.measure[2,0] = msg.markers[0].pose.position.z

def main(args=None):
    rclpy.init(args=args)
    node = USBLNode()
    rclpy.spin(node)
    rclpy.shutdown()

if __name__ == "__main__":
    main()
