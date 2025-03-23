import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist

class PublisherTest(Node):
    def __init__(self):
        super().__init__('publisher_test')

        # 퍼블리셔 설정: /turtle1/cmd_vel 토픽에 Twist 메시지 타입
        self.publisher_ = self.create_publisher(
            Twist,
            '/turtle1/cmd_vel',
            10
        )

        # 0.5초(2Hz)마다 콜백 실행
        timer_period = 0.5
        self.timer = self.create_timer(timer_period, self.timer_callback)

    def timer_callback(self):
        msg = Twist()
        msg.linear.x = 2.0     # 앞으로 전진
        msg.angular.z = 1.0    # 오른쪽 회전
        self.publisher_.publish(msg)
        self.get_logger().info(f'Published cmd_vel: linear.x={msg.linear.x}, angular.z={msg.angular.z}')

def main(args=None):
    rclpy.init(args=args)
    node = PublisherTest()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
