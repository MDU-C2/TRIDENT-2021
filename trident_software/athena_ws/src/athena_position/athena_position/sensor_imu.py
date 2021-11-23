import baseclasses.sensorbase as sensbase
import rclpy
from time import time
import numpy as np
from sensor_msgs.msg import Imu
from squaternion import Quaternion

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
            #[0,0,180/3.14, 0, 0,   0], #  yaw
            [0,0,       1, 0, 0,   0], #  yaw (for sim)
            [0,0,       0, 0, 0,   1]])# dyaw
        
        # TODO: couldn't find any real noise values, but these should be fine?
        #noise_mat = (np.array([[0.1, 0.1, 3, 0.1]])*np.identity(4))**2
        noise_mat = (np.array([[0.00001745, 0.00001745, 0.000001745, 0.000001745]])*np.identity(4))**2
        
        super().__init__('imu', 'athena', 0.25,
                         init_obs_mat, 4, noise_mat)
        
        self.prev_state = np.zeros((6,1))
        self.prev_state_time = time()

        # If the is_simulated parameter exists and is set, listen to the simulated sensor.
        # Otherwise, default is False and it will act like normal.
        self.declare_parameter('is_simulated', False)
        if(self.get_parameter('is_simulated').value):
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
    
    # Redefined to allow dynamic changing of observation matrix
    # Maybe make this a full-fledged function?
    def SensorService(self, request, response):
        state = np.reshape(request.state, (-1,1))
        dt = time() - self.prev_state_time
        self.obs_mod[0, 3] = (self.prev_state[3, 0]-state[3, 0]) /\
                             (dt*state[3, 0])
        self.obs_mod[1, 4] = (self.prev_state[4, 0]-state[4, 0]) /\
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

    def SimulatedMeasurement(self, msg):
        #self.get_logger().info("Message: %s" % msg)
        '''self.measure[0,0] = msg.linear_acceleration.x/100 + 99*self.measure[0,0]/100
        self.measure[1,0] = msg.linear_acceleration.y/100 + 99*self.measure[1,0]/100
        q = Quaternion(msg.orientation.w, msg.orientation.x, msg.orientation.y, msg.orientation.z)
        self.measure[2,0] = q.to_euler()[2]/100 + 99*self.measure[2,0]/100
        self.measure[3,0] = msg.angular_velocity.z/100 + 99*self.measure[3,0]/100'''
        self.measure[0,0] = msg.linear_acceleration.x
        self.measure[1,0] = msg.linear_acceleration.y
        #self.get_logger().info("Base quat: %s" % msg.orientation)
        q = Quaternion(w=msg.orientation.w, x=msg.orientation.x, y=msg.orientation.y, z=msg.orientation.z)
        #self.get_logger().info("Euler: %s" % str(q.to_euler()))
        self.measure[2,0] = q.to_euler()[2]
        self.measure[3,0] = msg.angular_velocity.z

def main(args=None):
    rclpy.init(args=args)
    node = IMUNode()
    rclpy.spin(node)
    rclpy.shutdown()

if __name__ == "__main__":
    main()
