# ros2 run turtlesim turtlesim_node 로 turtlesim_node 생성하고 subscriber_test 실행 시
/turtlesim_node  --> /subscriber_test
         |                  |
   /turtle1/pose     <- 구독

# publisher_test 와 subscriber_test 사용시
[publisher_test] ───→ /turtle1/cmd_vel ───→ [turtlesim_node] ───→ /turtle1/pose ───→ [subscriber_test]
