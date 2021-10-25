import rclpy
from rclpy.node import Node
import serial

def IntegerToMaestroBytes(value):
    mm_value = bytearray(2)
    mm_value[0] = (value & 0x7f)
    mm_value[1] = ((value >> 7) & 0x7f)
    return mm_value

def Clamp(minim, value, maxim):
    max(minim, min(value, maxim))

class MotorInterface(Node):
    def __init__(self):
        self.ser = serial.Serial(port="COM7",baudrate=9600,timeout=0.5)
        super().__init__('/naiad/motor_interface')
        self.sub = self.create_subscription(
            MessageTypeHere,
            '/naiad/motor_power',
            self.SetMotorPower,
            10)
        self.sub
    
    def SetMotorPower(self, msg):
        mm_query = bytearray(4)
        mm_query[0] = 0x84 # Set target
        for motor_idx in range(1, 6+1):
            mm_query[1] = motor_idx
            # TODO: Change this to use the actual motor power message, rather than this junk
            motor_target = int(Clamp(4000, 6000+2000*msg[motor_idx].power, 8000))
            mm_query[2:]= IntegerToMaestroBytes(motor_target)
            self.ser.write(mm_query)
