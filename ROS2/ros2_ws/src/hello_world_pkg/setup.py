from setuptools import find_packages, setup

package_name = 'hello_world_pkg'

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
    maintainer='root',
    maintainer_email='root@todo.todo',
    description='TODO: Package description',
    license='TODO: License declaration',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
           'hello_world = hello_world_pkg.hello_world:main',
           #lhs= 명령어이름  #rhs= hello_world_pkg안에 hello_node 파일에 있는 main함수 실행
        ],
    },
)
