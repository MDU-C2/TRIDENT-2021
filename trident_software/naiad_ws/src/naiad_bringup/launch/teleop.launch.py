from launch import LaunchDescription
from launch_ros.actions import Node


def generate_launch_description():

    return LaunchDescription([
        Node(
            package='teleop_twist_keyboard',
            namespace='naiad',
            executable='teleop_twist_keyboard',
            output='screen',
            name='teleop_twist',
            prefix=["xterm -e"],
            remappings=[
                ('cmd_vel', 'motor_control/teleop/cmd_vel')
            ]
        )
    ])
