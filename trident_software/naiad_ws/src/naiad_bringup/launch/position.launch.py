from launch import LaunchDescription
from launch_ros.actions import Node


def generate_launch_description():
    return LaunchDescription([
        Node(
            package='naiad_position',
            namespace='/naiad/position/',
            executable='position_node',
            name='pos'
        ),
        Node(
            package='naiad_position',
            namespace='/naiad/sensor/',
            executable='imu_node',
            name='imu',
            parameters=[
                {"is_simulated": True}
            ]
        ),
        Node(
            package='naiad_position',
            namespace='/naiad/sensor/',
            executable='gps_node',
            name='gps',
            parameters=[
                {"is_simulated": True}
            ]
        )
    ])
