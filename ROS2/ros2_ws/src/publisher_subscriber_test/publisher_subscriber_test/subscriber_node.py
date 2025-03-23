import rclpy 
from rclpy.node import Node
from turtlesim.msg import Pose


class SubscriberTest(Node):
    def __init__(self):
        super().__init__('subscriber_test')
        self.subscription = self.create_subscription(
            Pose,
            '/turtle1/pose',
            self.callback,
            10
        )

    def callback(self, data):
        print("--->")
        #print("/turtle1/pose :", data)
        self.get_logger().info(f"/turtle1/pose : {data}")
        self.get_logger().info(f"X: {data.x}, Y: {data.y}, Theta: {data.theta}")

def main(args=None):
    rclpy.init(args=args)
    node = SubscriberTest()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()  
