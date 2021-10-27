import rclpy
from rclpy.node import Node
import subprocess

class MotorInterface(Node):
    def __init__(self):
        super().__init__('/naiad/motor_interface')
        self.sub = self.create_subscription(
            MessageTypeHere,
            '/naiad/motor_power',
            self.SetMotorPower,
            10)
        self.sub
    
    def SetMotorPower(self, msg):
        for motor in msg.motors:
            # TODO: Change this to use the actual motor power message, rather than this junk
            motor_target = int(Clamp(4000, 6000+2000*motor.power, 8000))
            ret = subprocess.run(["UscCmd", "--servo", str(motor.ID)+","+str(motor_target)])
            if ret.returncode != 0:
                print("UscCmd didn't exit properly! motor:", motor.ID)
            
def main(args=None):
    rclpy.init(args=args)
    motor_interface = MotorInterface()
    rclpy.spin(motor_interface)
    motor_interface.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
