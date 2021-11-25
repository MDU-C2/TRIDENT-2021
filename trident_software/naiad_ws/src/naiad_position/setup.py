from setuptools import setup

package_name = 'naiad_position'

setup(
    name=package_name,
    version='0.0.0',
    packages=[package_name],
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
            'position_node = naiad_position.naiad_position:main',
            'imu_node = naiad_position.sensor_imu:main',
            'gps_node = naiad_position.sensor_gps:main',
            'usbl_node = naiad_position.sensor_usbl:main',
            'pressure_node = naiad_position.sensor_pressure:main'
        ],
    },
)
