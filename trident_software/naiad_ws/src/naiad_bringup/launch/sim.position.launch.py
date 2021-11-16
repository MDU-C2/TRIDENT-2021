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
                {"simulated": True}
            ]
        ),
        Node(
            package='naiad_position',
            namespace='/naiad/sensor/',
            executable='gps_node',
            name='gps',
            parameters=[
                {"simulated": True}
            ]
        ),
        Node(
            package='naiad_position',
            namespace='/naiad/sensor/',
            executable='usbl_node',
            name='usbl',
            parameters=[
                {"simulated": True}
            ]
        )
    ])
