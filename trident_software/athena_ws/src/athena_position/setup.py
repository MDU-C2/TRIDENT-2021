from setuptools import setup
import os

package_name = 'athena_position'

baseclasses_package_path = os.path.join(
    os.path.abspath(__file__).split('TRIDENT-2021')[0],
    ('TRIDENT-2021/trident_software/baseclasses')
)

messages_package_path = os.path.join(
    os.path.abspath(__file__).split('TRIDENT-2021')[0],
    ('TRIDENT-2021/trident_software/msgs_ws')
)

setup(
    name=package_name,
    version='0.0.0',
    package_dir={'baseclasses': baseclasses_package_path},
    packages=[package_name, 'baseclasses'],
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='johannes',
    maintainer_email='johannes@todo.todo',
    description='TODO: Package description',
    license='TODO: License declaration',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'position_node = athena_position.athena_position:main',
            'imu_node = athena_position.sensor_imu:main',
            'gps_node = athena_position.sensor_gps:main'
        ],
    },
)
