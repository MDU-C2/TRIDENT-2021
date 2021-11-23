import rclpy
from rclpy.executors import MultiThreadedExecutor
from baseclasses.motordriverbase import MotorDriverBase
from trident_msgs.msg import MotorOutputs
import serial


class MotorDriverNode(MotorDriverBase):
    """The main node for the motor driver module in Athena.
    """
    def __init__(self, node_name) -> None:
        super().__init__(node_name)
        self.get_logger().info("Created motor driver node.")

        self.ser = serial.Serial(port="COM7",baudrate=9600,timeout=0.5)


    @staticmethod
    def integer_to_maestro_bytes(value):
        mm_value = bytearray(2)
        mm_value[0] = (value & 0x7f)
        mm_value[1] = ((value >> 7) & 0x7f)

        return mm_value

    @staticmethod
    def clamp(minim, value, maxim):
        return max(minim, min(value, maxim))

    @staticmethod
    def scale_to_mm_output(output):
        return output*2000

    def _send_motor_outputs(self, motor_outputs: MotorOutputs):
        """Sends the specified motor value to the motor with specified motor_number.

        Args:
            motor_outputs: The list of motor_id, motor_output pairs that should be sent to the motor.
        """
        # TODO: Implement real world drivers
        mm_query = bytearray(4)
        mm_query[0] = 0x84 # Set target
        for id_, value in motor_outputs.motor_outputs:
            mm_query[1] = id_
            # TODO: Change this to use the actual motor power message, rather than this junk
            motor_target = int(Clamp(4000, 6000+2000*motor.power, 8000))
            mm_query[2:] = IntegerToMaestroBytes(motor_target)
            self.ser.write(mm_query)




def main(args=None):
    rclpy.init(args=args)
    motor_driver_node = MotorDriverNode("motor_driver")
    executor = MultiThreadedExecutor()
    rclpy.spin(motor_driver_node, executor)
    rclpy.shutdown()


if __name__=="__main__":
    main()
