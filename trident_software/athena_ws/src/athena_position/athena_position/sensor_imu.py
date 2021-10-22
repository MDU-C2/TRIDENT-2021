import baseclasses.sensorbase as sensbase
import board
import busio
import time
import adafruit_bno055

class GPSNode(sensbase):
    def __init__(self):
        # The IMU error will likely grow with time!
        # Might be better to have a more complex observation matrix instead?
        super().__init__('imu', 'athena', 0.25
                         np.identity(6), 6, np.identity(6)*2**2)
        
        self.last_run = 
        self.i2c = busio.I2C(board.SCL, board.SDA)
        self.sensor = adafruit_bno055.BNO055_I2C(i2c)
    
    def TakeMeasurement(self):
        accel_x = sensor.linear_acceleration[0]
        accel_y = sensor.linear_acceleration[1]
        gyro_z  = sensor.gyro[2]
        yaw     = sensor.euler[0]
        
        self.measure[2,0] = yaw

def main(args=None):
    rclpy.init(args=args)
    node = GPSNode()
    sclpy.spin(node)
    rclpy.shutdown()

if __name__ == "__main__":
    main()
