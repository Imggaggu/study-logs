from setuptools import find_packages, setup

package_name = 'publisher_subscriber_test'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='ggaggu',
    maintainer_email='ggaggu@todo.todo',
    description='TODO: Package description',
    license='TODO: License declaration',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'subscriber_node = publisher_subscriber_test.subscriber_node:main',
            'publisher_node = publisher_subscriber_test.publisher_node:main',

        ],
    },
)
