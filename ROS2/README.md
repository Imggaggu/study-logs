# 🐢 Begin ROS 2 
## 📌 1. 환경 설정 (필수 Alias)

`.bashrc`에 아래 alias를 추가해두면 매번 명령어를 길게 칠 필요 없이 **편리하게 ROS 환경을 설정**할 수 있습니다.

```bash

# ROS2 환경 설정
alias humble="source /opt/ros/humble/setup.bash; ros_domain; echo 'ROS2 humble is activated!'"

# bashrc 재적용
alias sb="source ~/.bashrc; echo 'bashrc is reloaded'"

# ROS Domain 설정 (멀티 노드 실행 시 유용)
alias ros_domain="export ROS_DOMAIN_ID=YOUR_DOMAINNUMBER; echo 'ROS_DOMAIN_ID=YOUR_DOMAINNUMBER'"

#YOUR_DOMAINNUMBER 를 숫자로 바꾸어 설정해주세요

```

### ✅ 사용 방법

터미널에서 아래처럼 입력하세요:

```bash

humble   # ROS 2 humble 환경 + 도메인 설정

```

또는 `.bashrc` 변경 후에는:

```bash

sb       # bashrc 재적용
```


## 📌2. 📦 ROS 2 패키지 생성하기

패키지는 `src/` 디렉토리 안에서 생성해야 합니다.

### 예: Python 패키지 생성

```bash

cd ~/study-logs/ROS2/ros2_ws/src
ros2 pkg create my_package --build-type ament_python --dependencies rclpy

```

또는 C++ 패키지 생성 시:

```bash

ros2 pkg create my_cpp_pkg --build-type ament_cmake --dependencies rclcpp

```

## 📌3. 🛠️ 빌드하기

패키지를 만든 후에는 워크스페이스 루트에서 빌드해야 합니다:

```bash

cd ~/study-logs/ROS2/ros2_ws
colcon build

```

빌드가 끝나면 환경 설정도 다시 해주세요:

```bash

source install/setup.bash

```

---
## 📌 4. 🚀 실행 예시


노드를 실행하려면 다음과 같이 입력합니다:

```bash

ros2 run my_package my_script
```

또는 C++ 노드일 경우:

```bash

ros2 run my_cpp_pkg my_node

```
