from setuptools import setup

package_name = 'faux_sensor_n_unit'

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
    maintainer='andreas',
    maintainer_email='ramsta.andy@hotmail.com',
    description='TODO: Package description',
    license='TODO: License declaration',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
			'faux_sensor_n_unit = faux_sensor_n_unit.mainprog:main'
			'position_node = faux_sensor_n_unit.posnode:main'
        ],
    },
)
