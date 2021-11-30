import rclpy
import numpy as np
import baseclasses.sensorbase as sensbase
from collections import deque
from time import time
from math import sin, cos, pi
from math import degrees as todeg
from squaternion import Quaternion

from sensor_msgs.msg import Imu

class IMUNode(sensbase.SensorNode):
    def __init__(self):
        noise_mat = np.array([.3, .3, .5, .1, .1, .1, .17, .17, .17])
        
        super().__init__('imu', 'athena', 0.25,
                         9, noise_mat)
        
        self.imu_history = deque(maxlen=30)
            
        # If the is_simulated parameter exists and is set, listen to the simulated sensor.
        # Otherwise, default is False and it will act like normal.
        self.declare_parameter('simulated', False)
        if(self.get_parameter('simulated').value):
            self.simul_sensor = self.create_subscription(
                                Imu, '/athena/simulation/imu',
                                self.SimulatedMeasurement, 10)
            self.timer.destroy() # Stop the original timed sensor from running
        else:
            import board
            import busio
            import adafruit_bno055
            self.i2c = busio.I2C(board.SCL, board.SDA)
            self.sensor = adafruit_bno055.BNO055_I2C(self.i2c)
    
    def state_guess(self, current_state):
        if(self.get_parameter('simulated').value):
            quat = Quaternion.from_euler(self.measure[0],self.measure[1],self.measure[2])
        else:
            quat = Quaternion.from_euler(self.measure[0],self.measure[1],self.measure[2],
            degrees = True)
        guess = np.array([0,0,0,
                          quat.w,quat.x,quat.y,quat.z,
                          0,0,0,
                          self.measure[6],self.measure[7],self.measure[8]])
        noise = np.array([np.inf,np.inf,np.inf,
                          0.2,0.2,0.2,0.2,
                          np.inf,np.inf,np.inf,
                          self.measue_noise[6],self.measue_noise[7],self.measue_noise[8]])
        return guess, noise
    
    def TakeMeasurement(self):
        # TODO: Check that these are all correct!
        self.imu_history.append([
            self.sensor.euler[2],               # Roll  ???
            self.sensor.euler[1],               # Pitch ???
            self.sensor.euler[0],               # Yaw
            self.sensor.linear_acceleration[0], # X Accel
            self.sensor.linear_acceleration[1], # Y Accel
            self.sensor.linear_acceleration[2], # Z Accel
            self.sensor.gyro[0],                # X Rot
            self.sensor.gyro[1],                # Y Rot
            self.sensor.gyro[2]                 # Z Rot
        ])
        self.measure = np.sum(self.imu_history, axis=0) / len(self.imu_history)

    def SimulatedMeasurement(self, msg):
        q = Quaternion(w=msg.orientation.w, x=msg.orientation.x, y=msg.orientation.y, z=msg.orientation.z)
        euler = q.to_euler()
        self.imu_history.append([
            euler[0],
            euler[1],
            euler[2],
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
