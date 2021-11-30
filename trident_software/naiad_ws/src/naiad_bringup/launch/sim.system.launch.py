import os
from launch import LaunchDescription
from ament_index_python.packages import get_package_share_directory
from launch_ros.actions import Node


def generate_launch_description():
    config = os.path.join(
        get_package_share_directory('naiad_bringup'),
        'config',
        'system_launch_params.yaml'
    )

    return LaunchDescription([
        Node(
            package='naiad_mission_control',
            namespace='naiad',
            executable='mission_control',
            output='screen',
            name='mission_control',
            parameters=[config]
        ),
        Node(
            package='naiad_navigation',
            namespace='naiad',
            executable='navigation',
            output='screen',
            name='navigation',
            parameters=[config]
        ),
        Node(
            package='naiad_motor_control',
            namespace='naiad',
            executable='motor_control',
            output='screen',
            name='motor_control',
            parameters=[config,
                {'use_sim_odom': False}
            ]
        ),
        Node(
            package='naiad_driver',
            namespace='naiad',
            executable='motor_driver',
            output='screen',
            name='motor_driver',
            parameters=[config,
                {'simulation': True},
                {'motor_output_scale': 0.8}
            ]
        ),
        Node(
            package='naiad_guidance_system',
            namespace='naiad',
            executable='guidance_system',
            output='screen',
            name='guidance_system',
            parameters=[config]
        ),
        # Position and sensor nodes
        Node(
            package='naiad_position',
            namespace='/naiad/position/',
            executable='position_node',
            name='pos',
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
        ),
        Node(
            package='naiad_position',
            namespace='/naiad/sensor/',
            executable='pressure_node',
            name='pressure',
            parameters=[
                {"simulated": True}
            ]
        )
    ])
