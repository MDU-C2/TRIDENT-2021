import rclpy
import numpy as np
import baseclasses.sensorbase as sensbase
from collections import deque
from time import time
from math import sin, cos, pi
from squaternion import Quaternion
import jax.numpy as jnp

from sensor_msgs.msg import Imu

class IMUNode(sensbase.SensorNode):
    def __init__(self):
        '''The IMU measurement vector will look like this
           yaw pitch roll accelx accely accelz gyrox gyroy gyroz
           Since accel will have to always be updated, it will start as 1.
           heading and delta_heading can be copied over directly (after conversion)'''
        todeg = 180/3.14
        '''init_obs_mat = np.array([
            #x y z     r     p     h dx dy dz dr dp dh 
            #[0,0,0,todeg,    0,    0, 0, 0, 0, 0, 0, 0], #r
            #[0,0,0,    0,todeg,    0, 0, 0, 0, 0, 0, 0], #p
            #[0,0,0,    0,    0,todeg, 0, 0, 0, 0, 0, 0], #h
            [0,0,0,    1,    0,    0, 0, 0, 0, 0, 0, 0], #r ###
            [0,0,0,    0,    1,    0, 0, 0, 0, 0, 0, 0], #p # modded for simulation 
            [0,0,0,    0,    0,    1, 0, 0, 0, 0, 0, 0], #h ###
            [0,0,0,    0,    0,    0, 1, 0, 0, 0, 0, 0], #ddx
            [0,0,0,    0,    0,    0, 0, 1, 0, 0, 0, 0], #ddy
            [0,0,0,    0,    0,    0, 0, 0, 1, 0, 0, 0], #ddz
            [0,0,0,    0,    0,    0, 0, 0, 0, 1, 0, 0], #dr
            [0,0,0,    0,    0,    0, 0, 0, 0, 0, 1, 0], #dp
            [0,0,0,    0,    0,    0, 0, 0, 0, 0, 0, 1]], dtype=np.float32)#dh'''
        
        noise_mat = (np.array([[.3, .3, .3, .3, .17, .17, .17]])*np.identity(7))**2
        
        super().__init__('imu', 'naiad', 0.25,
                         self.ObservationService, 7, noise_mat)
                         
        self.acc_history = deque(maxlen=3)
        self.prev_state = np.zeros((13,1))
        self.prev_state_time = time()
        
        self.imu_history = deque(maxlen=30)
            
        # If the is_simulated parameter exists and is set, listen to the simulated sensor.
        # Otherwise, default is False and it will act like normal.
        self.declare_parameter('simulated', False)
        if(self.get_parameter('simulated').value):
            self.simul_sensor = self.create_subscription(
                                Imu, '/naiad/simulation/imu',
                                self.SimulatedMeasurement, 10)
            self.timer.destroy() # Stop the original timed sensor from running
        else:
            import serial
            ser = serial.Serial(port="COM7",baudrate=115200,timeout=0.5)
            ser.close()
    
    def ObservationService(self, state, dt):
        #qw, qx, qy, qz = state[3], state[4], state[5], state[6]
        #roll  = jnp.arctan2(2*(qw*qx + qy*qz), 1-2*(pow(qx,2)+pow(qy,2)))
        #pitch = jnp.arcsin(2*(qw*qy - qz*qx))
        #head  = jnp.arctan2(2*(qw*qz + qx*qy), 1-2*(pow(qy,2)+pow(qz,2)))
        
        return jnp.array([state[3], state[4], state[5], state[6], state[10], state[11], state[12]])
    
    # Redefined to allow dynamic changing of observation matrix
    # Maybe make this a full-fledged function?
    '''def SensorService(self, request, response):
        state = np.reshape(request.state, (-1,1))
        dt = time() - self.prev_state_time
        self.acc_history.append([
            self.prev_state[6,0]-state[6,0] / dt,
            self.prev_state[7,0]-state[7,0] / dt,
            self.prev_state[8,0]-state[8,0] / dt,
        ])
        mean_accs = [
            sum([acc[0] for acc in self.acc_history]) / len(self.acc_history),
            sum([acc[1] for acc in self.acc_history]) / len(self.acc_history),
            sum([acc[2] for acc in self.acc_history]) / len(self.acc_history),
        ]
        self.obs_mod[3, 6] = mean_accs[0] / state[6,0]
                             
        self.obs_mod[4, 7] = mean_accs[1] / state[7,0]
                             
        self.obs_mod[5, 8] = mean_accs[2] / state[8,0]
        
        self.get_logger().info(f"x accel:{self.obs_mod[3, 6]*state[6,0]}")
        self.get_logger().info(f"y accel:{self.obs_mod[4, 7]*state[7,0]}")
        self.get_logger().info(f"z accel:{self.obs_mod[5, 8]*state[8,0]}")
        self.prev_state = np.copy(state)
        self.prev_state_time = time()
        
        return super().SensorService(request, response)'''
    
    def TakeMeasurement(self):
        ser.open()
        ser.read_until() # This "clears" the current line
        try:
            line = ser.readline().decode().split(',')[1:]
            line[-1] = line[-1].split('*')[0]
            type_list = ("yaw", "pitch", "roll", "magx", "magy", "magz",
                         "accelx", "accely", "accelz", "gyrox", "gyroy", "gyroz")
            imu_dict = dict(zip(type_list, line))
            quat = Quaternion.form_euler(imu_dict["roll"],imu_dict["pitch"],imu_dict["yaw"])
            self.imu_history.append([
                quat.w,
                quat.x,
                quat.y,
                quat.z,
                imu_dict["gyrox"],
                imu_dict["gyroy"],
                imu_dict["gyroz"]
            ])
            
            self.measure[:,0] = np.sum(self.imu_history, axis=0) / len(self.imu_history)
        except:
            print("Error reading IMU in the NAIAD!")
        ser.close()
        
    def SimulatedMeasurement(self, msg):
        self.imu_history.append([
            msg.orientation.w,
            msg.orientation.x,
            msg.orientation.y,
            msg.orientation.z,
            msg.angular_velocity.x,
            msg.angular_velocity.y,
            msg.angular_velocity.z
        ])
        self.measure[:,0] = np.sum(self.imu_history, axis=0) / len(self.imu_history)

def main(args=None):
    rclpy.init(args=args)
    node = IMUNode()
    rclpy.spin(node)
    rclpy.shutdown()

if __name__ == "__main__":
    main()
