import rclpy
import serial
import queue
import setproctitle
from multiprocessing import Process, Manager, Lock, current_process
from baseclasses.motordriverbase import MotorDriverBase
from cola2_msgs.msg import Setpoints
from rclpy.executors import MultiThreadedExecutor
from trident_msgs.msg import MotorOutputs


def serial_write_process_fn(write_queue, node):
   ser = serial.Serial(
       port="/dev/serial/by-id/usb-Pololu_Corporation_Pololu_Mini_Maestro_12-Channel_USB_Servo_Controller_00146301-if00",
       baudrate=9600,
       timeout=0.5,
    #    write_timeout=1
   )
   setproctitle.setproctitle(current_process().name)
   while True:
        values = write_queue.get()
        node.get_logger().debug(f"Attempting to write values to serial: {values}")
        ser.write(values)
        node.get_logger().debug(f"Successfully wrote to serial: {values}")


class MotorDriverNode(MotorDriverBase):
    """The main node for the motor driver module in NAIAD.
    """
    def __init__(self, node_name) -> None:
        super().__init__(node_name)
        self.get_logger().info("Created motor driver node.")

        if not self._simulation_env:
            self.queue_manager = Manager()
            self.serial_write_queue = self.queue_manager.Queue(len(self._motor_interface)*2)
            self.serial_write_queue_lock = self.queue_manager.Lock()

            # Start serial write process
            self.serial_write_process = Process(target=serial_write_process_fn, args=(self.serial_write_queue, self))
            self.serial_write_process.name = "serial_write_motor"
            self.serial_write_process.start()
        

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
        mm_query = bytearray(4)
        mm_query[0] = 0x84 # Set target
        for motor_output in motor_outputs:
            # Translate the motor id to the correct mini maestro id
            maestro_id = [motor["maestro_id"] for motor in self._motor_interface if motor["id"] == motor_output.id][0]
            mm_query[1] =  maestro_id
            mm_output = MotorDriverNode.motor_output_to_mm_output(motor_output.value * self._motor_output_scale)
            mm_query[2:] = self.integer_to_maestro_bytes(mm_output)
            self.get_logger().debug(f"Sending motor value {mm_output} to motor with id {motor_output.id} (on maestro_id={maestro_id})")
            try:
                self.serial_write_queue.put(mm_query, block=True, timeout=0.2)
            except queue.Full:
                self.get_logger().debug(f"Could not send motor values to queue: queue is full. (timed out 0.2s)")
                


def main(args=None):
    rclpy.init(args=args)
    motor_driver_node = MotorDriverNode("motor_driver")
    executor = MultiThreadedExecutor()
    rclpy.spin(motor_driver_node, executor)
    rclpy.shutdown()


if __name__=="__main__":
    main()

