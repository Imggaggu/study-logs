# 🐢 ROS 2 Practice with Turtlesim
## 📌🐢 Turtlesim 전체 실습 흐름: 거북이 생성부터 제어, 소멸까지

### ✅ 1. 거북이 노드 실행하기

먼저 `turtlesim_node`를 실행하여 시뮬레이터에 거북이를 띄웁니다:

```bash

ros2 run turtlesim turtlesim_node
```

> 실행 후 GUI 창에 파란 배경 + 거북이 🐢가 뜨면 성공!
> 

---

### 📡 Chapter 2-1: 토픽 (Topic) – 거북이 움직이기

### ✅ 1. 활성화된 토픽 목록 보기

```bash

ros2 topic list
```

예시 출력:

```bash

/turtle1/cmd_vel
/turtle1/pose
/rosout
```

### ✅ 2. 토픽 메시지 타입 확인

```bash

ros2 topic info /turtle1/cmd_vel
```

예시 출력:

```

Type: geometry_msgs/msg/Twist
Publisher count: 0
Subscriber count: 1

```

---

### ✅ 3. 메시지 타입 구조 확인

이제 `/turtle1/cmd_vel`에 발행할 수 있는 **Twist 메시지 구조**를 확인합니다:

```bash

ros2 interface show geometry_msgs/msg/Twist

```

출력 예시:

```bash

geometry_msgs/msg/Vector3 linear
geometry_msgs/msg/Vector3 angular

OR

Vector3  linear
        float64 x
        float64 y
        float64 z
Vector3  angular
        float64 x
        float64 y
        float64 z

```

즉, `Twist` 메시지는 `linear`, `angular`이라는 두 벡터 필드를 가지며 각각 x, y, z 값을 설정할 수 있습니다.

### ✅ 4. 거북이 움직이기 (토픽 퍼블리시)

```bash

ros2 topic pub --rate 1 /turtle1/cmd_vel geometry_msgs/msg/Twist \
"{linear: {x: 2.0, y: 0.0, z: 1.8}, angular: {x: 0.0, y: 0.0, z: 1.8}}"

```

- `-rate 1`: 1초에 한 번씩 메시지를 발행 (헤르츠)
- `linear.x = 2.0`: 앞으로 전진
- `angular.z = 1.8`: 오른쪽 회전

> Ctrl + C를 누르면 발행을 멈출 수 있어요.
> 

---

## 🧾 Chapter 2-2: 서비스 (Service) – 거북이 순간이동

### ✅ 1. 어떤 서비스가 있는지 확인

```bash

ros2 service list

```

### ✅ 2. 특정 서비스의 타입 확인

```bash

ros2 service type /turtle1/teleport_absolute
```

### ✅ 3.서비스 요청 구조 확인

```bash

ros2 interface show turtlesim/srv/TeleportAbsolute
```

### ✅ 4. 거북이 순간이동 (서비스 호출)

```bash

ros2 service call /turtle1/teleport_absolute turtlesim/srv/TeleportAbsolute \
"{x: 2, y: 3, theta: 2}"
```

- 거북이를 (2, 3) 위치로 `theta=2`의 방향으로 순간이동시킵니다.

---