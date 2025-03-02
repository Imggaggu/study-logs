#include <WiFi.h>
#include <Arduino_ESP32_OTA.h>
#include <ArduinoOTA.h>
#include <Preferences.h> 

Preferences preferences;
#define MAX_WIFI_SSID 2 
const char* ssidList[MAX_WIFI_SSID] = {"첫번째 wifi ssid 입력", "두번째 wifi ssid 입력"};
const char* passwordList[MAX_WIFI_SSID] = {"첫번째 wifi 비밀번호 입력","두번째 wifi 비밀번호 입력"};


void connectToBestWiFi() {
    Serial.println("\n 저장된 Wi-Fi 네트워크 스캔 중...");
    int bestNetwork = -1;
    int bestSignal = -100;  // 초기값 설정 (신호 강도 dBm)

    WiFi.mode(WIFI_STA);
    WiFi.disconnect();
    delay(1000);
    
    int numNetworks = WiFi.scanNetworks();  // 주변 Wi-Fi 검색
    Serial.printf("🔎 %d개의 Wi-Fi 감지됨.\n", numNetworks);

    // 저장된 Wi-Fi 중에서 가장 강한 신호 찾기
    for (int i = 0; i < numNetworks; i++) {
        Serial.printf("%s (신호: %d dBm)\n", WiFi.SSID(i).c_str(), WiFi.RSSI(i));
        for (int j = 0; j < MAX_WIFI_SSID; j++) {
            if (WiFi.SSID(i) == ssidList[j] && WiFi.RSSI(i) > bestSignal) {
                bestSignal = WiFi.RSSI(i);
                bestNetwork = j;
            }
        }
    }

    // 가장 강한 Wi-Fi에 연결
    if (bestNetwork != -1) {
        Serial.printf("\n가장 강한 Wi-Fi: %s (신호: %d dBm)\n", ssidList[bestNetwork], bestSignal);
        WiFi.begin(ssidList[bestNetwork], passwordList[bestNetwork]);

        int attempts = 0;
        while (WiFi.status() != WL_CONNECTED && attempts < 15) {
            delay(1000);
            Serial.print(".");
            attempts++;
        }

        if (WiFi.status() == WL_CONNECTED) {
            Serial.println("\nWi-Fi 연결 성공!");
            Serial.print("IP 주소: ");
            Serial.println(WiFi.localIP());
            preferences.putString("lastSSID", ssidList[bestNetwork]);  // 마지막 연결한 Wi-Fi 저장
        } else {
            Serial.println("\n Wi-Fi 연결 실패! 다시 시도하세요.");
        }
    } else {
        Serial.println("\n 저장된 Wi-Fi 중 연결 가능한 네트워크 없음!");
    }
}
void setupOTA() {
    Serial.println("OTA 초기화 시작...");
    ArduinoOTA.setHostname("ESP32_OTA");

    ArduinoOTA.onStart([]() {
        Serial.println("OTA 업데이트 시작...");
    });

    ArduinoOTA.onEnd([]() {
        Serial.println("OTA 업데이트 완료!");
    });

    ArduinoOTA.onProgress([](unsigned int progress, unsigned int total) {
        Serial.printf("OTA 진행 중: %u%%\r", (progress * 100) / total);
    });

    ArduinoOTA.onError([](ota_error_t error) {
        Serial.printf("OTA 오류 발생! Error[%u]: ", error);
        if (error == OTA_AUTH_ERROR) Serial.println("인증 실패");
        else if (error == OTA_BEGIN_ERROR) Serial.println("시작 실패");
        else if (error == OTA_CONNECT_ERROR) Serial.println("연결 실패");
        else if (error == OTA_RECEIVE_ERROR) Serial.println("데이터 수신 실패");
        else if (error == OTA_END_ERROR) Serial.println("업데이트 완료 후 오류");
    });

    ArduinoOTA.begin();
    Serial.println("OTA Ready! 이제 무선 업로드 가능!");
}

void setup() {
    Serial.begin(115200);
    preferences.begin("wifi", false);
    
    Serial.println("\n이전 Wi-Fi 정보 불러오기...");
    String lastSSID = preferences.getString("lastSSID", "");

    // 마지막으로 연결한 Wi-Fi가 있으면 다시 연결 시도
    if (lastSSID != "") {
        Serial.println("마지막 Wi-Fi: " + lastSSID);
        for (int i = 0; i < MAX_WIFI_SSID; i++) {
            if (lastSSID == ssidList[i]) {
                WiFi.begin(ssidList[i], passwordList[i]);
                int attempts = 0;
                while (WiFi.status() != WL_CONNECTED && attempts < 15) {
                    delay(1000);
                    Serial.print(".");
                    attempts++;
                }
                if (WiFi.status() == WL_CONNECTED) {
                    Serial.println("\n이전 Wi-Fi 재연결 성공!");
                    Serial.print("IP 주소: ");
                    Serial.println(WiFi.localIP());
                    setupOTA();
                    return;  // 성공했으면 setup 종료
                }
            }
        }
    }
    if (WiFi.status() != WL_CONNECTED) {
            // 저장된 Wi-Fi 네트워크 중 가장 강한 신호로 연결
        connectToBestWiFi();
         
    }
    // OTA 기능 활성화
    setupOTA();
}


void loop() {
    if (WiFi.status() != WL_CONNECTED) {
        Serial.println("\n Wi-Fi 끊김 다시 연결 시도");
        connectToBestWiFi();

    }
    ArduinoOTA.handle();
    delay(5000);
}