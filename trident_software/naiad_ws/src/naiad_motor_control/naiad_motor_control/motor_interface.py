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
        for motor in msg.motors:
            mm_query[1] = motor.ID
            # TODO: Change this to use the actual motor power message, rather than this junk
            motor_target = int(Clamp(4000, 6000+2000*motor.power, 8000))
            mm_query[2:] = IntegerToMaestroBytes(motor_target)
            self.ser.write(mm_query)
            
def main(args=None):
    rclpy.init(args=args)

    motor_interface = MotorInterface()

    rclpy.spin(motor_interface)

    # Destroy the node explicitly
    # (optional - otherwise it will be done automatically
    # when the garbage collector destroys the node object)
    motor_interface.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
