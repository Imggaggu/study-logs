import rclpy
from rclpy.node import Node

class HelloNode(Node):
  def __init__(self):
    super().__init__("hello_world")
    self.get_logger().info("Hello World!")

def main (args=None):
  rclpy.init(args=args)
  node = HelloNode()
  rclpy.spin(node)  # 계속 실행하면서 ros 메시지 대기
  node.destroy_node() #노드 종료
  #rclpy.shutdown()#ros 종료