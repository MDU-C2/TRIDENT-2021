import os
import launch
from launch import LaunchDescription
from ament_index_python.packages import get_package_share_directory
from launch_ros.actions import Node


def generate_launch_description():
    config = os.path.join(
        get_package_share_directory('naiad_bringup'),
        'config',
        'system_launch_params.yaml'
    )

    return launch.LaunchDescription([
        launch.actions.DeclareLaunchArgument(name='log_level', default_value='info'),

        Node(
            package='naiad_mission_control',
            namespace='naiad',
            executable='mission_control',
            output='screen',
            name='mission_control',                
            arguments=['--ros-args', '--log-level', launch.substitutions.LaunchConfiguration('log_level')],
            parameters=[config]
        ),
        Node(
            package='naiad_navigation',
            namespace='naiad',
            executable='navigation',
            output='screen',
            name='navigation',
            arguments=['--ros-args', '--log-level', launch.substitutions.LaunchConfiguration('log_level')],
            parameters=[config]
        ),
        Node(
            package='naiad_motor_control',
            namespace='naiad',
            executable='motor_control',
            output='screen',
            name='motor_control',
            arguments=['--ros-args', '--log-level', launch.substitutions.LaunchConfiguration('log_level')],
            parameters=[config]
        ),
        Node(
            package='naiad_driver',
            namespace='naiad',
            executable='motor_driver',
            output='screen',
            name='motor_driver',
            arguments=['--ros-args', '--log-level', launch.substitutions.LaunchConfiguration('log_level')],
            parameters=[config]
        ),
        Node(
            package='naiad_guidance_system',
            namespace='naiad',
            executable='guidance_system',
            output='screen',
            name='guidance_system',
            arguments=['--ros-args', '--log-level', launch.substitutions.LaunchConfiguration('log_level')],
            parameters=[config]
        ),
        # Position and sensor nodes
        Node(
            package='naiad_position',
            namespace='/naiad/position/',
            executable='position_node',
            name='pos',
            arguments=['--ros-args', '--log-level', launch.substitutions.LaunchConfiguration('log_level')],
        ),
        Node(
            package='naiad_position',
            namespace='/naiad/sensor/',
            executable='imu_node',
            name='imu',
            arguments=['--ros-args', '--log-level', launch.substitutions.LaunchConfiguration('log_level')],
        ),
        Node(
            package='naiad_position',
            namespace='/naiad/sensor/',
            executable='gps_node',
            name='gps',
            arguments=['--ros-args', '--log-level', launch.substitutions.LaunchConfiguration('log_level')],
        ),
        Node(
            package='naiad_position',
            namespace='/naiad/sensor/',
            executable='usbl_node',
            name='usbl',
            arguments=['--ros-args', '--log-level', launch.substitutions.LaunchConfiguration('log_level')],
        ),
        Node(
            package='naiad_position',
            namespace='/naiad/sensor/',
            executable='pressure_node',
            name='pressure',
            arguments=['--ros-args', '--log-level', launch.substitutions.LaunchConfiguration('log_level')],
        )
    ])
