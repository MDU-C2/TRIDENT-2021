import rclpy
import numpy as np
import baseclasses.sensorbase as sensbase

class USBLNode(sensbase):
    def __init__(self):
        init_obs_mat = np.array([
            #  x   y   z   r   p   h  dx  dy  dz  dr  dp  dh
            [  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0], #diffx
            [  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0], #diffy
            [  0,  0, -1,  0,  0,  0,  0,  0,  0,  0,  0,  0]])#diffz
        
        noise_mat = (np.array([[.5,.5,.5]])*np.identity(3))**2
        
        super().__init__('usbl', 'naiad', 0.5,
                         init_obs_mat, 9, noise_mat)
                         
        self.prev_state = np.transpose(np.zeros((12,1)))
        self.prev_state_time = time()
            
        # If the is_simulated parameter exists and is set, listen to the simulated sensor.
        # Otherwise, default is False and it will act like normal.
        self.declare_parameter('simulated', False)
        if(self.get_parameter('simulated').value):
            self.simul_sensor = self.create_subscription(
                                Imu, '/naiad/simulation/usbl',
                                self.SimulatedMeasurement, 10)
            self.timer.destroy() # Stop the original timed sensor from running
        else:
            self.get_logger.error("REAL USBL NOT IMPLEMENTED!")
    
    def TakeMeasurement(self):
        pass
        
    def SimulatedMeasurement(self, msg):
        self.measure[0,0] = 4
        self.measure[1,0] = 4
        self.measure[2,0] = 4

def main(args=None):
    rclpy.init(args=args)
    node = USBLNode()
    rclpy.spin(node)
    rclpy.shutdown()

if __name__ == "__main__":
    main()
