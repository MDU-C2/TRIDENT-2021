from setuptools import setup
import os

package_name = 'motor_control'
submodules = 'motor_control/pid'

class_path = os.path.join(
    os.path.abspath(__file__).split('TRIDENT-2021')[0],
    ('TRIDENT-2021/code_experiments/experiment_ws/src/motor_control/motor_control')
)

setup(
    name=package_name,
    version='0.0.0',
    packages=[package_name, submodules],
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='athena',
    maintainer_email='valentinjohan@outlook.com',
    description='TODO: Package description',
    license='TODO: License declaration',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'motor_control = motor_control.motormain:main'
        ],
    },
)
