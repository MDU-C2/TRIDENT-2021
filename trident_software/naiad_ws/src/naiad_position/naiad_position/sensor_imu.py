import baseclasses.sensorbase as sensbase
import rclpy
from time import time
import serial

class IMUNode(sensbase):
    def __init__(self):
        '''The IMU measurement vector will look like this
           yaw pitch roll accelx accely accelz gyrox gyroy gyroz
           Since accel will have to always be updated, it will start as 1.
           heading and delta_heading can be copied over directly (after conversion)'''
        todeg = 180/3.14
        init_obs_mat = np.array([
            #x y z     p     y     r dx dy dz dp dy dr 
            [0,0,0,    0,todeg,    0, 0, 0, 0, 0, 0, 0], #y
            [0,0,0,todeg,    0,    0, 0, 0, 0, 0, 0, 0], #p
            [0,0,0,    0,    0,todeg, 0, 0, 0, 0, 0, 0], #r
            [0,0,0,    0,    0,    0, 1, 0, 0, 0, 0, 0], #ddx
            [0,0,0,    0,    0,    0, 0, 1, 0, 0, 0, 0], #ddy
            [0,0,0,    0,    0,    0, 0, 0, 1, 0, 0, 0], #ddz
            [0,0,0,    0,    0,    0, 0, 0, 0, 0, 0, 1], #dr
            [0,0,0,    0,    0,    0, 0, 0, 0, 1, 0, 0], #dp
            [0,0,0,    0,    0,    0, 0, 0, 0, 0, 1, 0]])#dy
        
        noise_mat = (np.array([[2, .5, .5, .0001, .0001, .0001, .17, .17, .17]])*np.identity(9))**2
        
        super().__init__('imu', 'naiad', 0.25,
                         init_obs_mat, 9, noise_mat)
        
        self.prev_state = np.transpose(np.zeros((12,1)))
        self.prev_state_time = time()

        ser = serial.Serial(port="COM7",baudrate=115200,timeout=0.5)
        ser.close()
    
    # Redefined to allow dynamic changing of observation matrix
    # Maybe make this a full-fledged function?
    def SensorService(self, request, response):
        state = np.reshape(request.state, (-1,1))
        dt = time() - self.prev_state_time
        self.obs_mat[3, 6] = (self.prev_state[6,0]-state[6,0]) /\
                             (dt*state[6,0])
        self.obs_mat[4, 7] = (self.prev_state[7,0]-state[7,0]) /\
                             (dt*state[7,0])
        self.obs_mat[5, 8] = (self.prev_state[8,0]-state[8,0]) /\
                             (dt*state[8,0])
        self.prev_state = np.copy(state)
        self.prev_state_time = time()
        
        super().SensorService(request, response)
    
    def TakeMeasurement(self):
        # TODO: Maybe switch readings to follow north-east-down?
        ser.open()
        ser.read_until() # This "clears" the current line
        try:
            line = ser.readline().decode().split(',')[1:]
            line[-1] = line[-1].split('*')[0]
            type_list = ("yaw", "pitch", "roll", "magx", "magy", "magz",
                         "accelx", "accely", "accelz", "gyrox", "gyroy", "gyroz")
            imu_dict = dict(zip(type_list, line))
            self.measure[0,0] = imu_dict["yaw"]
            self.measure[1,0] = imu_dict["pitch"]
            self.measure[2,0] = imu_dict["roll"]
            self.measure[3,0] = imu_dict["accelx"]
            self.measure[4,0] = imu_dict["accely"]
            self.measure[5,0] = imu_dict["accelz"]
            self.measure[6,0] = imu_dict["gyrox"]
            self.measure[7,0] = imu_dict["gyroy"]
            self.measure[8,0] = imu_dict["gyroz"]
        except:
            print("Error reading IMU in the NAIAD!")
        ser.close()

def main(args=None):
    rclpy.init(args=args)
    node = IMUNode()
    rclpy.spin(node)
    rclpy.shutdown()

if __name__ == "__main__":
    main()
