import rclpy
import numpy as np
import baseclasses.sensorbase as sensbase
from collections import deque
from time import time
from math import sin, cos, pi
from math import degrees as todeg
from math import radians as torad
from squaternion import Quaternion

from sensor_msgs.msg import Imu

class IMUNode(sensbase.SensorNode):
    def __init__(self):
        noise_mat = np.array([.7, .7, .7, .7, .1, .1, .1, .5, .5, .5])
        
        super().__init__('imu', 'naiad', 0.25,
                         10, noise_mat)
        
        self.imu_history = deque(maxlen=5)
            
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
    
    def state_guess(self, current_state):
        guess = np.array([0,0,0,
                          self.measure[0],self.measure[1],self.measure[2],self.measure[3],
                          0,0,0,
                          self.measure[7],self.measure[8],self.measure[9]])
        noise = np.array([np.inf,np.inf,np.inf,
                          0.2,0.2,0.2,0.2,
                          np.inf,np.inf,np.inf,
                          self.measure_noise[7],self.measure_noise[8],self.measure_noise[9]])
        return guess, noise
    
    def TakeMeasurement(self):
        ser.open()
        ser.read_until() # This "clears" the current line
        try:
            line = ser.readline().decode().split(',')[1:]
            line[-1] = line[-1].split('*')[0]
            type_list = ("yaw", "pitch", "roll", "magx", "magy", "magz",
                         "accelx", "accely", "accelz", "gyrox", "gyroy", "gyroz")
            imu_dict = dict(zip(type_list, line))
            q = Quaternion.from_euler(imu_dict["roll"], imu_dict["pitch"], mu_dict["yaw"], degrees=True)
            self.imu_history.append([
                q.w,
                q.x,
                q.y,
                q.z,
                imu_dict["accelx"],
                imu_dict["accely"],
                imu_dict["accelz"],
                imu_dict["gyrox"],
                imu_dict["gyroy"],
                imu_dict["gyroz"]
            ])
            self.measure = np.sum(self.imu_history, axis=0) / len(self.imu_history)
        except:
            print("Error reading IMU in the NAIAD!")
        ser.close()
        
    def SimulatedMeasurement(self, msg):
        self.imu_history.append([
            msg.orientation.w,
            msg.orientation.x,
            msg.orientation.y,
            msg.orientation.z,
            msg.linear_acceleration.x,
            msg.linear_acceleration.y,
            msg.linear_acceleration.z,
            msg.angular_velocity.x,
            msg.angular_velocity.y,
            msg.angular_velocity.z
        ])
        self.measure = np.sum(self.imu_history, axis=0) / len(self.imu_history)

def main(args=None):
    rclpy.init(args=args)
    node = IMUNode()
    rclpy.spin(node)
    rclpy.shutdown()

if __name__ == "__main__":
    main()
