from launch import LaunchDescription
from launch_ros.actions import Node


def generate_launch_description():
    return LaunchDescription([
        Node(
            package='athena_mission_control',
            namespace='athena',
            executable='mission_control',
            output='screen',
            name='athena_mission_control'
        ),
        Node(
            package='athena_navigation',
            namespace='athena',
            executable='navigation',
            output='screen',
            name='athena_navigation'
        ),
        Node(
            package='athena_motor_control',
            namespace='athena',
            executable='motor_control',
            output='screen',
            name='athena_motor_control'
        ),
    ])
