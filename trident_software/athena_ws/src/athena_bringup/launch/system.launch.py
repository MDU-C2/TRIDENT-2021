import os
import launch
from launch import LaunchDescription
from ament_index_python.packages import get_package_share_directory
from launch_ros.actions import Node


def generate_launch_description():
    config = os.path.join(
        get_package_share_directory('athena_bringup'),
        'config',
        'system_launch_params.yaml'
    )

    return LaunchDescription([
        launch.actions.DeclareLaunchArgument(name='log_level', default_value='info'),
        Node(
            package='athena_mission_control',
            namespace='athena',
            executable='mission_control',
            output='screen',
            name='mission_control',
            arguments=['--ros-args', '--log-level', launch.substitutions.LaunchConfiguration('log_level')],
            parameters=[config]
        ),
        Node(
            package='athena_navigation',
            namespace='athena',
            executable='navigation',
            output='screen',
            name='navigation',
            arguments=['--ros-args', '--log-level', launch.substitutions.LaunchConfiguration('log_level')],
            parameters=[config]
        ),
        Node(
            package='athena_motor_control',
            namespace='athena',
            executable='motor_control',
            output='screen',
            name='motor_control',
            arguments=['--ros-args', '--log-level', launch.substitutions.LaunchConfiguration('log_level')],
            parameters=[config]
        ),
        Node(
            package='athena_driver',
            namespace='athena',
            executable='motor_driver',
            output='screen',
            name='motor_driver',
            arguments=['--ros-args', '--log-level', launch.substitutions.LaunchConfiguration('log_level')],
            parameters=[config]
        ),
        Node(
            package='athena_guidance_system',
            namespace='athena',
            executable='guidance_system',
            output='screen',
            name='guidance_system',
            arguments=['--ros-args', '--log-level', launch.substitutions.LaunchConfiguration('log_level')],
            parameters=[config]
        ),
        Node(
            package='athena_position',
            namespace='/athena/position/',
            executable='position_node',
            name='pos',
            arguments=['--ros-args', '--log-level', launch.substitutions.LaunchConfiguration('log_level')],
        ),
        Node(
            package='athena_position',
            namespace='/athena/sensor/',
            executable='imu_node',
            name='imu',
            arguments=['--ros-args', '--log-level', launch.substitutions.LaunchConfiguration('log_level')],
        ),
        Node(
            package='athena_position',
            namespace='/athena/sensor/',
            executable='gps_node',
            name='gps',
            arguments=['--ros-args', '--log-level', launch.substitutions.LaunchConfiguration('log_level')],
        )
    ])
