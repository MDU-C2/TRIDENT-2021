import baseclasses.sensorbase as sensbase
import rclpy
import serial #package is named "pyserial"!
import io
import pynmea2
import numpy as np

class GPSNode(sensbase.SensorNode):
    def __init__(self):
        # NOTE: having an interval of 0 sec may not work! Fix a cleaner solution!
        ''' NOTE: Depending on how the Athena's xyz coordinates are stored,
            the observation matrix may need to be changed to convert it to long-lat'''
        # NOTE: the noise value may need to be changed
        super().__init__('gps', 'athena', 0,
                         np.eye(2,6), 2, np.identity(2)*0.0001**2)
        # Change as needed
        self.ser = serial.Serial(port="/dev/ttyACM0",baudrate=9600,timeout=0.5)
        self.sio = io.TextIOWrapper(io.BufferedRWPair(self.ser, self.ser))
    
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
                    ''' NOTE: It may be useful to change this to more useful
                        units (like meters) later on. You may also want to
                        swap them around (have longitude be x) '''
                    self.measure[0,0] = deci_lat
                    self.measure[1,0] = deci_lon
        except serial.SerialException as e:
            print('Device error: {}'.format(e))
        except pynmea2.ParseError as e:
            print('Parse error: {}'.format(e))

def main(args=None):
    rclpy.init(args=args)
    node = GPSNode()
    rclpy.spin(node)
    rclpy.shutdown()

if __name__ == "__main__":
    main()
