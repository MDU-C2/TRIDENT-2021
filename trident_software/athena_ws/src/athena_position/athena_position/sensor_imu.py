import signal
import sys
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
        noise_mat = np.array([.3, .3, .3, .3, .1, .1, .1, .17, .17, .17])

        super().__init__('imu', 'athena', 0.25,
                         10, noise_mat)

        self.imu_history = deque(maxlen=5)

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
        guess = np.array([0,0,0,
                          self.measure[0],self.measure[1],self.measure[2],self.measure[3],
                          0,0,0,
                          self.measure[7],self.measure[8],self.measure[9]])
        noise = np.array([np.inf,np.inf,np.inf,
                          0.1,0.1,0.1,0.1,
                          np.inf,np.inf,np.inf,
                          self.measure_noise[7],self.measure_noise[8],self.measure_noise[9]])
        return guess, noise

    def TakeMeasurement(self):
        # TODO: Check that these are all correct!

        new_measurement = [
            self.sensor.quaternion[0],          # QW
            self.sensor.quaternion[1],          # QX
            self.sensor.quaternion[2],          # QY
            self.sensor.quaternion[3],          # QZ
            self.sensor.linear_acceleration[0], # X Accel
            self.sensor.linear_acceleration[1], # Y Accel
            self.sensor.linear_acceleration[2], # Z Accel
            self.sensor.gyro[0],                # X Rot
            self.sensor.gyro[1],                # Y Rot
            self.sensor.gyro[2]                 # Z Rot
        ]
        if None in new_measurement or np.NaN in new_measurement:
            return
        self.imu_history.append(new_measurement)
        self.measure = np.sum(self.imu_history, axis=0) / len(self.imu_history)

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

def signal_handler(sig, frame):
    rclpy.shutdown()
    sys.exit(0)

def main(args=None):
    signal.signal(signal.SIGINT, signal_handler)
    rclpy.init(args=args)
    node = IMUNode()
    rclpy.spin(node)
    rclpy.shutdown()

if __name__ == "__main__":
    main()
