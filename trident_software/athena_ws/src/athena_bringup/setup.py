import os
from glob import glob
from setuptools import setup

package_name = 'athena_bringup'


baseclasses_package_path = os.path.join(
    os.path.abspath(__file__).split('trident_software')[0],
    ('trident_software/baseclasses')
)

setup(
    name=package_name,
    version='0.0.0',
    package_dir={
        'baseclasses': baseclasses_package_path,
    },
    packages=[package_name, 'baseclasses'],
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
        (os.path.join('share', package_name), glob('launch/*.launch.py')),
        (os.path.join('share', package_name, 'config'), glob('config/*.yaml'))

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
        ],
    },
)
