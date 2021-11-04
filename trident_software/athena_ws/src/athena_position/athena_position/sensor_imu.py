import baseclasses.sensorbase as sensbase
import rclpy
import board
import busio
import adafruit_bno055
from time import time
import numpy as np

class IMUNode(sensbase.SensorNode):
    def __init__(self):
        '''The IMU measurement vector will look like this
           accel_x accel_y heading delta_head
           Since accel will have to always be updated, it will start as 1.
           heading and delta_heading can be copied over directly (after conversion)
           Only heading is in degrees. rotation is in rads/sec. odd...'''
        init_obs_mat = np.array([
            #x y      yaw dx dy dyaw
            [0,0,       0, 1, 0,   0], #ddx
            [0,0,       0, 0, 1,   0], #ddy
            [0,0,180/3.14, 0, 0,   0], #  yaw
            [0,0,       0, 0, 0,   1]])# dyaw
        
        # TODO: couldn't find any real noise values, but these should be fine?
        (np.array([[0.1, 0.1, 3, 0.1]])*np.identity(4))**2
        
        super().__init__('imu', 0.25,
                         init_obs_mat, 4, np.identity(4)*0.1**2)
        
        self.prev_state = np.zeros((6,1))
        self.prev_state_time = time()
        self.i2c = busio.I2C(board.SCL, board.SDA)
        self.sensor = adafruit_bno055.BNO055_I2C(self.i2c)
    
    # Redefined to allow dynamic changing of observation matrix
    # Maybe make this a full-fledged function?
    def SensorService(self, request, response):
        state = np.reshape(request.state, (-1,1))
        dt = time() - self.prev_state_time
        self.obs_mat[0, 3] = (self.prev_state[3, 0]-state[3, 0]) /\
                             (dt*state[3, 0])
        self.obs_mat[1, 4] = (self.prev_state[4, 0]-state[4, 0]) /\
                             (dt*state[4, 0])
        self.prev_state = np.copy(state)
        self.prev_state_time = time()
        
        return super().SensorService(request, response)
    
    def TakeMeasurement(self):
        # TODO: Maybe switch readings to follow north-east-down?
        self.measure[0,0] = self.sensor.linear_acceleration[0] # X Accel
        self.measure[1,0] = self.sensor.linear_acceleration[1] # Y Accel
        self.measure[2,0] = self.sensor.euler[0]               # Yaw (heading)
        self.measure[3,0] = self.sensor.gyro[2]                # Rotation

def main(args=None):
    rclpy.init(args=args)
    node = IMUNode()
    rclpy.spin(node)
    rclpy.shutdown()

if __name__ == "__main__":
    main()
