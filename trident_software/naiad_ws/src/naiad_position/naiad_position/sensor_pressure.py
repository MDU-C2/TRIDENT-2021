import signal
import sys
import rclpy
import numpy as np
import baseclasses.sensorbase as sensbase

from sensor_msgs.msg import FluidPressure

class PressureNode(sensbase.SensorNode):
    def __init__(self):
        super().__init__('pressure', 'naiad', 0.25,
                         1, np.array([1.]))

        # If the is_simulated parameter exists and is set, listen to the simulated sensor.
        # Otherwise, default is False and it will act like normal.
        self.declare_parameter('simulated', False)
        if(self.get_parameter('simulated').value):
            self.simul_sensor = self.create_subscription(
                                FluidPressure, '/naiad/simulation/pressure',
                                self.SimulatedMeasurement, 10)
            self.timer.destroy() # Stop the original timed sensor from running
        else:
            from naiad_driver.naiad_driver import depth_sensor_driver
            self.depth_sensor = depth_sensor_driver()

    def state_guess(self, current_state):
        guess = np.array([0,0,self.measure[0],
                          0,0,0,0,
                          0,0,0,
                          0,0,0])
        noise = np.array([np.inf,np.inf,self.measure_noise[0],
                          np.inf,np.inf,np.inf,np.inf,
                          np.inf,np.inf,np.inf,
                          np.inf,np.inf,np.inf])
        return guess, noise

    def TakeMeasurement(self):
        self.measure[0] = self.depth_sensor.read_sensor()[2]

    def SimulatedMeasurement(self, msg):
        self.measure[0] = msg.fluid_pressure * 0.00010197

def signal_handler(sig, frame):
    rclpy.shutdown()
    sys.exit(0)


def main(args=None):
    signal.signal(signal.SIGINT, signal_handler)
    rclpy.init(args=args)
    node = PressureNode()
    rclpy.spin(node)
    rclpy.shutdown()

if __name__ == "__main__":
    main()
