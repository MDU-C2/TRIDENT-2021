#!/usr/bin/env python3
import rclpy

from trident_msgs.msg import PidParam
from rcl_interfaces.srv import GetParameters

import sys, select, termios, tty



SETTINGS = termios.tcgetattr(sys.stdin)

def getKey():
    tty.setraw(sys.stdin.fileno())
    select.select([sys.stdin], [], [], 0)
    key = sys.stdin.read(1)
    termios.tcsetattr(sys.stdin, termios.TCSADRAIN, SETTINGS)
    return key

def print_increments(pid_increments):
    print(f"Current increments:\tp={pid_increments['p']},\ti={pid_increments['i']},\td={pid_increments['d']}")

def print_affected_pid(affected_pid):
    print(f"Currently affecting PID: {affected_pid}")


def main(args=None):
    if args is None:
        args = sys.argv
    print(args)
    welcome_msg = """
    Bindings for changing affected PID:
        key | u | i | o | j     | k   | l 
        PID | x | y | z | pitch | yaw | roll

    Bindings for updating P/I/D values:
             |          key          |
     element | increment | decrement |
        Kp   | q         | z
        Ki   | w         | x
        Kd   | e         | c

    Increasing/decreasing the increment values by 0.01 (hold shift key):
               |          key          |
     increment | increase  | decrease  |
        Kp     | Q         | Z
        Ki     | W         | X
        Kd     | E         | C

    CTRL-C to quit
    """

    # Bindings for changing the currently affected PID
    change_affected_pid_bindings = {
        'u': 'x',
        'i': 'y',
        'o': 'z',
        'j': 'pitch',
        'k': 'yaw',
        'l': 'roll',

    }
    # Bindings for incrementing pid values
    pid_bindings={
            'q':("p", 1.0), # p+
            'z':("p",-1.0), # p-
            'w':("i", 1.0), # i+
            'x':("i",-1.0), # i-
            'e':("d", 1.0), # d+
            'c':("d",-1.0)  # d-
            }

    # Bindings for increaseing/decreasing the pid increment
    change_pid_increment_bindings = {
            'Q':("p", 0.01),
            'Z':("p",-0.01),
            'W':("i", 0.01),
            'X':("i",-0.01),
            'E':("d", 0.01),
            'C':("d",-0.01)

    }
    # Default pid increment/decrement values
    pid_increments = {
        'p': 0.01,
        'i': 0.01,
        'd': 0.01
    }

    rclpy.init()
    node = rclpy.create_node('teleop_twist_keyboard')
    	
    param_publisher = node.create_publisher(PidParam, f'{args[1]}/motor_control/param/pid/set', 10)
    current_params_client = node.create_client(GetParameters, f"{args[1]}/motor_control/get_parameters")
    current_pid_key = "x"

    try:
        print(welcome_msg)
        param_msg = PidParam()
        while(1):
            key = getKey()

            # If the pressed key is a key that increment/decrement a pid value
            if key in pid_bindings.keys():
                param_msg.pid_element = pid_bindings[key][0]
                param_msg.key = current_pid_key
                param_msg.value = pid_bindings[key][1] * pid_increments[pid_bindings[key][0]]
                current_params_request = GetParameters.Request()
                current_params_request.names = ['pid_config']
                future = current_params_client.call_async(current_params_request)
                rclpy.spin_until_future_complete(node, future)
                current_params = future.result()
                print(current_params)

            # If the pressed key is a key that increases/decreases the pid increment value
            elif key in change_pid_increment_bindings.keys():
                pid_increments[change_pid_increment_bindings[key][0]] = round(pid_increments[change_pid_increment_bindings[key][0]] + change_pid_increment_bindings[key][1], 2)
                print_increments(pid_increments)
            # If the presser key is a key that changes the affected PID
            elif key in change_affected_pid_bindings.keys():
                current_pid_key = change_affected_pid_bindings[key]
                print_affected_pid(current_pid_key)
            elif key == '\x03':
                break
                
            param_publisher.publish(param_msg)

    except Exception as e:
        print(e)

    finally:
        termios.tcsetattr(sys.stdin, termios.TCSADRAIN, SETTINGS)

if __name__=='__main__':
    main()