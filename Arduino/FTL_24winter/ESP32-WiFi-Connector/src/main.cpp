#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <SparkFun_ISM330DHCX.h>
#include <SparkFun_MMC5983MA_Arduino_Library.h>
#include <ArduinoOTA.h>
#define PCA9548_I2C_ADDRESS 0x70  // 멀티플렉서 기본 주소
#define IMU_I2C_ADDRESS 0x6B  
SparkFun_ISM330DHCX imu1, imu2;
SFE_MMC5983MA mag1, mag2;


void setupWiFi() {
  Serial.print("WiFi연결중");
  WiFi.begin("ota에 업로드된 wifi ssid", "ota에 업로드된 wifi 비밀번호");

  while (WiFi.status() != WL_CONNECTED) {
      delay(1000);
      Serial.print(".");
  }

  Serial.println("\nWiFi 연결 완료");
  Serial.print("IP 주소: ");
  Serial.println(WiFi.localIP());
}

void setupOTA() {
  ArduinoOTA.begin();
}

//begin()이 잘 안먹
void selectMultiplexerPort(uint8_t port) {
    Wire.beginTransmission(PCA9548_I2C_ADDRESS);
    Wire.write(1 << port);
    Wire.endTransmission();
    delay(10); 
}
void writeRegister(uint8_t reg, uint8_t value) {
  Wire.beginTransmission(IMU_I2C_ADDRESS);
  Wire.write(reg);
  Wire.write(value);
  Wire.endTransmission();
}

uint8_t readRegister(uint8_t reg) {
  Wire.beginTransmission(IMU_I2C_ADDRESS);
  Wire.write(reg);
  Wire.endTransmission(false);
  Wire.requestFrom(IMU_I2C_ADDRESS, 1);
  return Wire.available() ? Wire.read() : 0;
}



void setup() {
  Serial.begin(115200);
  Wire.begin();
  Wire.setClock(100000); 
  setupWiFi();
  setupOTA();
  /*
  Serial.println("멀티플렉서 + IMU + Magnetometer 초기화 시작...");
  
  // 1번 포트 선택 및 센서 초기화
  selectMultiplexerPort(1);

  delay(50);
  while (!imu1.begin()) {
      Serial.println(" IMU 1 초기화 실패! 재시도 중...");
      while(1);
  }
  Serial.println(" IMU 1 초기화 성공!");
  imu1.deviceReset();
  imu1.resetSensorHub();
  while (!mag1.begin()) {
      Serial.println(" Magnetometer 1 초기화 실패! 재시도 중...");
      while(1);
  }
  Serial.println(" Magnetometer 1 초기화 성공!");

  Serial.println(" IMU 1 초기화 성공! (포트 1)");
  // 7번 포트 선택 및 센서 초기화
  selectMultiplexerPort(7);

  delay(50);
  while (!imu2.begin()) {
    Serial.println("IMU 2 초기화 실패! 재시도 중...");
    while(1);
  }
  imu2.deviceReset();
  imu2.resetSensorHub();
  Serial.println("IMU 2 초기화 성공!");
  while (!mag2.begin()) {
    Serial.println(" Magnetometer 2 초기화 실패! 재시도 중...");
    while(1);
  }
  Serial.println("Magnetometer 2 초기화 성공!");

  Serial.println(" IMU 2 초기화 성공! (포트 7)");
  Serial.println("모든 센서 초기화 완료!");
  */
}



void loop() {
  ArduinoOTA.handle();  // OTA 요청 처리
  delay(10);  // 딜레이를 너무 길게 주면 안 됨
/*
  sfe_ism_data_t accelData1, gyroData1, accelData2, gyroData2;  
  uint32_t magX1, magY1, magZ1, magX2, magY2, magZ2;

    // 1번 포트 선택 후 센서 데이터 읽기
    selectMultiplexerPort(1);
    imu1.getAccel(&accelData1);  // 한 번의 호출로 구조체에 저장
    imu1.getGyro(&gyroData1);  // 한 번의 호출로 구조체에 저장
    mag1.getMeasurementXYZ(&magX1, &magY1, &magZ1);

    // 1번 IMU 데이터 개별 변수로 분리
    float accelX1 = accelData1.xData;
    float accelY1 = accelData1.yData;
    float accelZ1 = accelData1.zData;
    float gyroX1 = gyroData1.xData;
    float gyroY1 = gyroData1.yData;
    float gyroZ1 = gyroData1.zData;

    // 7번 포트 선택 후 센서 데이터 읽기
    selectMultiplexerPort(7);
    imu2.getAccel(&accelData2);
    imu2.getGyro(&gyroData2);
    mag2.getMeasurementXYZ(&magX2, &magY2, &magZ2);

    // 2번 IMU 데이터 개별 변수로 분리
    float accelX2 = accelData2.xData;
    float accelY2 = accelData2.yData;
    float accelZ2 = accelData2.zData;
    float gyroX2 = gyroData2.xData;
    float gyroY2 = gyroData2.yData;
    float gyroZ2 = gyroData2.zData;

  // IMU1 데이터 출력
  Serial.print("IMU1 - Accel: ");
  Serial.print(accelX1); Serial.print(", ");
  Serial.print(accelY1); Serial.print(", ");
  Serial.print(accelZ1);
  
  Serial.print(" | Gyro: ");
  Serial.print(gyroX1); Serial.print(", ");
  Serial.print(gyroY1); Serial.print(", ");
  Serial.print(gyroZ1);
  Serial.println();

  // Magnetometer1 데이터 출력
  Serial.print("Mag1 - X: "); Serial.print(magX1);
  Serial.print(" Y: "); Serial.print(magY1);
  Serial.print(" Z: "); Serial.println(magZ1);

  // IMU2 데이터 출력
  Serial.print("IMU2 - Accel: ");
  Serial.print(accelX2); Serial.print(", ");
  Serial.print(accelY2); Serial.print(", ");
  Serial.print(accelZ2);

  Serial.print(" | Gyro: ");
  Serial.print(gyroX2); Serial.print(", ");
  Serial.print(gyroY2); Serial.print(", ");
  Serial.print(gyroZ2);
  Serial.println();

  // Magnetometer2 데이터 출력
  Serial.print("Mag2 - X: "); Serial.print(magX2);
  Serial.print(" Y: "); Serial.print(magY2);
  Serial.print(" Z: "); Serial.println(magZ2);

  Serial.println("---------------------------------");
  delay(100);  // 데이터 갱신 주기

  */
}