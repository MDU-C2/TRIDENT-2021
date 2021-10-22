import baseclasses.sensorbase as sensbase
import board
import busio
import adafruit_bno055

class GPSNode(sensbase):
    def __init__(self):
        # The IMU error will likely grow with time!
        super().__init__('imu', 'athena', 0.25
                         np.identity(6), 6, np.identity(6)*2**2)
        
        self.i2c = busio.I2C(board.SCL, board.SDA)
        self.sensor = adafruit_bno055.BNO055_I2C(i2c)
    
    def TakeMeasurement(self):
        accel_x = sensor.linear_acceleration[0]
        accel_y = sensor.linear_acceleration[1]
        gyro_z  = sensor.gyro[2]
        yaw     = sensor.euler[0]
        
        print("Accelerometer (m/s^2){ X:",round(sensor.linear_acceleration[0], 3),"Y:",round(sensor.linear_acceleration[1], 3),"Z:",round(sensor.linear_acceleration[2], 3),"                    ")
        print("Gyroscope (deg){ X:",round(sensor.gyro[0], 3),"Y:",round(sensor.gyro[1], 3),"Z:",round(sensor.gyro[2], 3),"                    ")
        print("Magnetic (µT){ X:",round(sensor.magnetic[0], 3),"Y:",round(sensor.magnetic[1], 3),"Z:",round(sensor.magnetic[2], 3),"                    ")
        print("Yaw:",sensor.euler[0], "Pitch:", sensor.euler[2], "Roll:", sensor.euler[1], "                    ")
        print("\033[2A\033[2A\033[2A\033[2A\033[2A", end="")

def main(args=None):
    rclpy.init(args=args)
    node = GPSNode()
    sclpy.spin(node)
    rclpy.shutdown()

if __name__ == "__main__":
    main()
