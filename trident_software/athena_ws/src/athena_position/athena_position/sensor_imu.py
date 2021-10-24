import baseclasses.sensorbase as sensbase
import board
import busio
import adafruit_bno055
from time import time

class GPSNode(sensbase):
    def __init__(self):
        '''The IMU measurement vector will look like this
           accel_x accel_y heading delta_head
           Since accel will have to always be updated, it will start as 0.
           heading and delta_heading can be copied over directly'''
        init_obs_mat = np.zeros((4,6))
        init_obs_mat[2, 2] = 1.
        init_obs_mat[3, 5] = 1.
        
        super().__init__('imu', 'athena', 0.25
                         init_obs_mat, 4, np.identity(2)*0.1**2)
        # Replace noise with real noise values! (probably in data sheet)
        
        self.prev_state = np.transpose(np.zeros((6,1)))
        self.prev_state_time = time()
        self.i2c = busio.I2C(board.SCL, board.SDA)
        self.sensor = adafruit_bno055.BNO055_I2C(i2c)
    
    # Redefined to allow dynamic changing of observation matrix
    # Maybe make this a full-fledged function?
    def SensorService(self, request, response):
        state = np.reshape(request.state, (-1,1))
        dt = time() - self.prev_state_time
        self.obs_mat[0, 3] = (self.prev_state[3, 0]-state[3, 0]) /
                             (dt*state[3, 0])
        self.obs_mat[1, 4] = (self.prev_state[4, 0]-state[4, 0]) /
                             (dt*state[4, 0])
        self.prev_state = np.copy(state)
        self.prev_state_time = time()
        
        super().SensorService(request, response)
    
    def TakeMeasurement(self):
        # TODO: Maybe switch readings to follow north-east-down?
        self.measure[0,0] = sensor.linear_acceleration[0] # X Accel
        self.measure[1,0] = sensor.linear_acceleration[1] # Y Accel
        self.measure[2,0] = sensor.euler[0]               # Yaw (heading)
        self.measure[3,0] = sensor.gyro[2]                # Rotation

def main(args=None):
    rclpy.init(args=args)
    node = GPSNode()
    sclpy.spin(node)
    rclpy.shutdown()

if __name__ == "__main__":
    main()
