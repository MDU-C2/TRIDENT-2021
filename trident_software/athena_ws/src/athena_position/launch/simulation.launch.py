from launch import LaunchDescription
from launch_ros.actions import Node


def generate_launch_description():
    return LaunchDescription([
        Node(
            package='athena_position',
            namespace='/athena/position/',
            executable='position_node',
            name='pos'
        ),
        Node(
            package='athena_position',
            namespace='/athena/sensor/',
            executable='imu_node',
            name='imu',
            parameters=[
                {"is_simulated": True}
            ]
        ),
        Node(
            package='athena_position',
            namespace='/athena/sensor/',
            executable='gps_node',
            name='gps',
            parameters=[
                {"is_simulated": True}
            ]
        )
    ])
