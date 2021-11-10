from setuptools import setup
import os

package_name = 'faux_sensor_n_unit'

baseclasses_package_path = os.path.join(
    os.path.abspath(__file__).split('TRIDENT-2021')[0],
    ('TRIDENT-2021/trident_software/baseclasses')
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
    maintainer='andreas',
    maintainer_email='ramsta.andy@hotmail.com',
    description='TODO: Package description',
    license='TODO: License declaration',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
			'faux_sensor_n_unit = faux_sensor_n_unit.mainprog:main',
			'position_node = faux_sensor_n_unit.posnode:main'
        ],
    },
)
