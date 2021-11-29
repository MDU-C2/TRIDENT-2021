import rclpy
import numpy as np
import baseclasses.sensorbase as sensbase
import jax.numpy as jnp
from squaternion import Quaternion

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
        athena_pos = jnp.transpose(jnp.array([[self.get_parameter('athena_position/x').value,
                      self.get_parameter('athena_position/y').value, 0]]))
        n_pos = -1*state[:3]
        q = -1*Quaternion(state[3], state[4], state[5], state[6])
        translate = jnp.append(jnp.eye(4,3), jnp.append(n_pos, jnp.array([1])).reshape(4,1), axis=1)
        rotation  = jnp.array([[2*(q[0]**2 + q[1]**2)-1,   2*(q[1]*q[2] - q[0]*q[3]), 2*(q[1]*q[3] + q[0]*q[2])],
                               [2*(q[1]*q[2] + q[0]*q[3]), 2*(q[0]**2 + q[2]**2)-1,   2*(q[2]*q[3] - q[0]*q[1])],
                               [2*(q[1]*q[3] - q[0]*q[2]), 2*(q[2]*q[3] + q[0]*q[1]), 2*(q[0]**2 + q[3]**2)-1  ]])
        '''rotation = jnp.array([[jnp.cos(n_rot[2]), -jnp.sin(n_rot[2]), 0],
                              [jnp.sin(n_rot[2]), jnp.cos(n_rot[2]), 0],
                              [0, 0, 1]])'''
        local_pos = jnp.matmul(rotation, jnp.matmul(translate, jnp.append(athena_pos, jnp.array([[1]])).reshape(4,1))[:3])
        #self.get_logger().info(jnp.array_str(local_pos.flatten()))
        return local_pos.flatten()
        '''diffpos = [a-b for a, b in zip(athena_pos, naiad_pos)]
        diffang = atan2(diffpos[1], diffpos[0])
        local_pos = [ # Doesn't account for pitch and roll!
        diffpos[0]*cos(state[5])+diffpos[1]*sin(state[5]),
        diffpos[1]*cos(state[5])-diffpos[0]*sin(state[5]),
        diffpos[2]]'''
    
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
