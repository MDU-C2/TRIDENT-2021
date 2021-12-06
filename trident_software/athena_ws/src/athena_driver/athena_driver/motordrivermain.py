import sys
import threading
from collections import deque
from baseclasses.motorcontrolbase import MotorControlBase
import rclpy
import serial
from baseclasses.motordriverbase import MotorDriverBase
from cola2_msgs.msg import Setpoints
from rclpy.executors import MultiThreadedExecutor
from trident_msgs.msg import MotorOutputs



class MotorDriverNode(MotorDriverBase):
    """The main node for the motor driver module in NAIAD.
    """
    def __init__(self, node_name) -> None:
        super().__init__(node_name)
        self.get_logger().info("Created motor driver node.")
        self.serial_max_write_rate = self.create_rate(100)
        self.writing_serial = False
        self.serial_write_deque = deque(maxlen=2)

        if not self._simulation_env:
            # import subprocess
            # process = subprocess.Popen(
            #     "ls -l /dev/serial/by-id | grep usb-Pololu_Corporation_Pololu_Mini_Maestro_12-Channel_USB_Servo_Controller_00146301-if00",
            #     stdout=subprocess.PIPE)
            # result = process.stdout.read()
            # if "ttyACM" not in result:
            #     self.get_logger().info("Could not find MiniMaestry tty.")
            #     raise Exception("Could not find MiniMaestro tty.")
            # ttyacm = result.split("tty")[-1]

            # self.ser = serial.Serial(port=f"/dev/tty{ttyacm}",baudrate=9600,timeout=0.5)
            self.ser = serial.Serial(
                port="/dev/serial/by-id/usb-Pololu_Corporation_Pololu_Mini_Maestro_12-Channel_USB_Servo_Controller_00146301-if00",
                baudrate=9600,
                timeout=0.5,
                write_timeout=1
            )
            # Start write thread
            self.serial_write_thread = threading.Thread(target=self.serial_write_thread_fn, args=(self.serial_write_deque))
        
    def serial_write_thread_fn(self, write_queue: deque):
        while True:
            try:
                values = write_queue.popleft()
                self.ser.write(values)
            except IndexError as e:
                pass
            self.serial_max_write_rate.sleep()

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
    def motor_output_to_mm_output(output):
        clamped = MotorDriverNode.clamp(-1.0, output, 1.0)
        return int(6000+(clamped*2000))

    def _send_motor_outputs(self, motor_outputs: MotorOutputs):
        """Sends the specified motor value to the motor with specified motor_number.

        Args:
            motor_outputs: The list of motor_id, motor_output pairs that should be sent to the motor.
        """
        if self.writing_serial:
            return
        self.writing_serial = True
        mm_query = bytearray(4)
        mm_query[0] = 0x84 # Set target
        for motor_output in motor_outputs:
            # Translate the motor id to the correct mini maestro id
            maestro_id = [motor["maestro_id"] for motor in self._motor_interface if motor["id"] == motor_output.id][0]
            mm_query[1] =  maestro_id
            mm_output = MotorDriverNode.motor_output_to_mm_output(motor_output.value * self._motor_output_scale)
            mm_query[2:] = self.integer_to_maestro_bytes(mm_output)
            try:
                self.get_logger().info(f"Sending motor value {mm_output} to motor with id {motor_output.id} (on maestro_id={maestro_id})")
                self.serial_write_deque.append(mm_query)
                # self.ser.write(mm_query)
                self.get_logger().info(f"Successfully wrote to serial.")
            except serial.SERIAL_TIMEOUT_EXCEPTION:
                self.get_logger().info(f"SERIAL WRITE TIMED OUT.")
        self.writing_serial = False



def main(args=None):
    rclpy.init(args=args)
    motor_driver_node = MotorDriverNode("motor_driver")
    executor = MultiThreadedExecutor()
    rclpy.spin(motor_driver_node, executor)
    # spin_thread = threading.Thread(target=rclpy.spin, args=(motor_driver_node, executor), daemon=True)
    # spin_thread.start()
    # spin_thread.join()
    # motor_driver_node.pwm_cleanup()
    rclpy.shutdown()


if __name__=="__main__":
    main()
