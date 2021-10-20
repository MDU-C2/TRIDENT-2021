import numpy as np
import math
import time
from .pid.pid import PID
from .pid.pid_utils import PIDUtils,MinimalSubscriber

import rclpy
from rclpy.node import Node

def main():
   print("starting...")
    
   rclpy.init()
   motor_control = MinimalSubscriber()
   rclpy.spin(motor_control)

   motor_control.destroy_node()
   rclpy.shutdown()

if __name__ == '__main__':
   main()