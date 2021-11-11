import os
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
        Node(
            package='athena_mission_control',
            namespace='athena',
            executable='mission_control',
            output='screen',
            name='mission_control',
            parameters=[config]
        ),
        Node(
            package='athena_navigation',
            namespace='athena',
            executable='navigation',
            output='screen',
            name='navigation',
            parameters=[config]
        ),
        Node(
            package='athena_motor_control',
            namespace='athena',
            executable='motor_control',
            output='screen',
            name='motor_control',
            parameters=[config,
                {'use_sim_odom': True}
            ]
        ),
        Node(
            package='athena_driver',
            namespace='athena',
            executable='motor_driver',
            output='screen',
            name='motor_driver',
            parameters=[config,
                {'simulation': True}
            ]
        ),
        Node(
            package='athena_guidance_system',
            namespace='athena',
            executable='guidance_system',
            output='screen',
            name='guidance_system',
            parameters=[config]
        ),
    ])
