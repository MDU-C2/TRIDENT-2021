import baseclasses.sensorbase as sensbase
import rclpy
import numpy as np
from math import sin, cos, sqrt, asin
from math import radians as torad
from sensor_msgs.msg import NavSatFix
import signal
import sys

def hav(theta):
    return (1-cos(theta))/2

class GPSNode(sensbase.SensorNode):
    def __init__(self):
        # NOTE: having an interval of 0 sec may not work! Fix a cleaner solution!

        # Values which convert meters-from-C2 to degrees latitude-longitude
        self.origin = (59.6175744, 16.5609494)
        earth_radius = 6362257 # Approximate! (but good enough at C2's latitude)
        self.m_per_deg_lat = 2*earth_radius*asin(sqrt(
            hav(torad(1.0)) + cos(torad(self.origin[0]))*cos(torad(self.origin[0]+1))*hav(0.0)
        ))
        self.m_per_deg_lon = 2*earth_radius*asin(sqrt(
            hav(0.0) + cos(torad(self.origin[0]))**2 *hav(torad(1.0))
        ))
        
        # NOTE: the noise value may need to be changed
        super().__init__('gps', 'naiad', 0,
                         2, np.array([0.000005, 0.000005]))
        
        # If the is_simulated parameter exists and is set, listen to the simulated sensor.
        # Otherwise, default is False and it will act like normal.
        self.declare_parameter('simulated', False)
        if(self.get_parameter('simulated').value):
            self.simul_sensor = self.create_subscription(
                                NavSatFix, '/naiad/simulation/gps',
                                self.SimulatedMeasurement, 10)
            self.timer.destroy() # Stop the original timed sensor from running
        else:
            import serial #package is named "pyserial"!
            import io
            import pynmea2
            self.ser = serial.Serial(port="/dev/ttyACM0",baudrate=9600,timeout=0.5)
            self.sio = io.TextIOWrapper(io.BufferedRWPair(self.ser, self.ser))
    
    def state_guess(self, current_state):
        #self.get_logger().info("Latitude: %s Longitude: %s" % (self.measure[0], self.measure[1]))
        guess = np.array([(self.measure[0]-self.origin[0])*self.m_per_deg_lat,
                          (self.measure[1]-self.origin[1])*self.m_per_deg_lon, 0,
                          0,0,0,0,
                          0,0,0,
                          0,0,0])
        noise = np.array([self.measure_noise[0], self.measure_noise[1],np.inf,
                          np.inf,np.inf,np.inf,np.inf,
                          np.inf,np.inf,np.inf,
                          np.inf,np.inf,np.inf])
        return guess, noise
    
    def TakeMeasurement(self):
        try:
            line = self.sio.readline()
            if line != '': # The GPS gives empy lines sometimes. Ignore 'em
                msg = pynmea2.parse(line)
                name = msg.__class__.__name__
                if name == "GGA":
                    # Conversion from deg°min' to decimal.
                    deci_lat = int(msg.lat[:2]) + float(msg.lat[2:])/60
                    deci_lon = int(msg.lon[:3]) + float(msg.lon[3:])/60
                    if(msg.lat_dir == 'S'): deci_lat *= -1
                    if(msg.lon_dir == 'W'): deci_lon *= -1
                    ''' NOTE: This returns the distance in lat+long from the origin '''
                    self.measure[0] = deci_lat
                    self.measure[1] = deci_lon
        except serial.SerialException as e:
            print('Device error: {}'.format(e))
        except pynmea2.ParseError as e:
            print('Parse error: {}'.format(e))

    def SimulatedMeasurement(self, msg):
        if msg.status.status != -1:
            self.measure[0] = msg.latitude
            self.measure[1] = msg.longitude
            self.measure_noise = np.array([1., 1.])
        else:
            self.measure_noise = np.array([np.inf, np.inf]) # Set the noise to inifnite if the gps in unavailable

def signal_handler(sig, frame):
    rclpy.shutdown()
    sys.exit(0)

def main(args=None):
    signal.signal(signal.SIGINT, signal_handler)
    rclpy.init(args=args)
    node = GPSNode()
    rclpy.spin(node)
    rclpy.shutdown()

if __name__ == "__main__":
    main()
