#include "esp_wifi.h"  
#include <WiFi.h>      

// ==========================================================
// SHDN_readVnasi_Train2.ino (メインタブ)
// ==========================================================
#define EXTERN_MAIN 

#include <esp_now.h>
#include "constant.h" 
#include <Wire.h>
#define CAMERA_MODEL_XIAO_ESP32S3 // Has PSRAM
#include "camera_pins.h"
#include "esp_camera.h"

// タイマー変数
unsigned long lastVoltageTime = 0;
unsigned long wakeUpTime = 0; 

// 制御用変数
bool readyToSendDelay = false;     
float lastMeasuredDelay = 0.0;     
uint8_t targetSpeed2 = 0;
uint32_t currentSpeed2 = 0; 


// 💤 ディープスリープ用フラグ
RTC_DATA_ATTR bool justWokeUp = false; 

// 🛑 モジュール停止用関数
void stopModule() {
  Serial.println("🛑 monitaからのSTOP命令を受信: モジュールを停止します (SHDN -> LOW)");
  pinMode(SHDN, OUTPUT);
  digitalWrite(SHDN, LOW);
}

// ▶️ 【追加】モジュール再開用関数
void startModule() {
  Serial.println("▶️ monitaからのSTART命令を受信: モジュールを再開します (SHDN -> HIGH)");
  pinMode(SHDN, OUTPUT);
  digitalWrite(SHDN, HIGH);
  pinMode(SHDN, INPUT_PULLUP);
}

// ===== ESP-NOW 受信コールバック =====
#if ESP_IDF_VERSION >= ESP_IDF_VERSION_VAL(4, 4, 0)
void OnDataRecv(const esp_now_recv_info *info, const uint8_t *incomingData, int len) {
  const uint8_t *mac = info->src_addr;
#else
void OnDataRecv(const uint8_t *mac_addr, const uint8_t *incomingData, int len) {
  const uint8_t *mac = mac_addr;
#endif

  if (len >= sizeof(CombinedPayload)) {
    CombinedPayload temp;
    memcpy(&temp, incomingData, sizeof(CombinedPayload));

    if (mac[0] == 0xFF) {
      return;
    }
    
    if (temp.header == 99) {
      
      // 🚨 monitaからのSTOP命令 (data88 == 99) 
      if (temp.data88 == 99) {
        brake();        // 即座にブレーキ
        stopModule();   // モジュール出力停止
        return;
      }

      // ▶️ monitaからのSTART命令 (data88 == 1) 
      if (temp.data88 == 1) {
        startModule();  // モジュール出力復帰
        return;
      }

      // 🟢 通常の運行データ (data88 == 88)
      if (temp.data88 == 88) {
        targetSpeed2 = temp.train2_speed;
        targetSpeed2 = targetSpeed2 ; // 速度計算
        Serial.print("targetSpeed2  ");
        Serial.println(targetSpeed2);
        recvData = temp;

        // 🔌 ディープスリープ判定
        if (targetSpeed2 == 0 && temp.train2_poji == 22) {
          if (justWokeUp == false) {
            Serial.println("💤 poji:21 に停止しました。1分間の充電スリープに入ります...");
            delay(500);

            esp_sleep_enable_timer_wakeup(60ULL * 1000000ULL); 
            justWokeUp = true; 

            esp_deep_sleep_start(); 
          }
        }
      }
    }
  }
}

// ===== ESP-NOW 送信コールバック =====
void OnDataSent(const wifi_tx_info_t *info, esp_now_send_status_t status) {}
void startCameraServer();
void setupLedFlash(int pin);
void setup() {
  Serial.begin(115200);
  delay(1000);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  
  // 💡 SHDNピンの初期状態設定（起動時は有効化状態にする）
  pinMode(SHDN, OUTPUT);
  digitalWrite(SHDN, HIGH);
  pinMode(SHDN, INPUT_PULLUP);
  delay(200);

  ledcAttach(in1, freq, pwm_resolution);
  ledcAttach(in2, freq, pwm_resolution);

  // 📡 Wi-Fi省電力・出力制限設定
  WiFi.mode(WIFI_STA);
  esp_wifi_set_ps(WIFI_PS_MIN_MODEM);
  WiFi.setTxPower(WIFI_POWER_8_5dBm);
  WiFi.disconnect();

  StatiNowpeer(); 
  
  lastVoltageTime = millis(); 
  wakeUpTime = millis();
  
  Serial.println("--- 列車2 起動完了 ---");
  if (justWokeUp) {
    Serial.println("☀️ ディープスリープ（充電）から目覚めました！");
  }
  setup_camera();
}

void loop() {
  

  // 🚨 安全ガード解除タイマー
  if (justWokeUp && (millis() - wakeUpTime >= 15000)) {
    justWokeUp = false;
    Serial.println("🔓 安全ガード解除。次回停止時にスリープ可能になりました。");
  }

  // 🚂 2. モーター制御処理
  if (targetSpeed2 == 0) {
    currentSpeed2 = 0; 
    coast(); 
    //brake();
  } else {
    if (currentSpeed2 < targetSpeed2) {
      currentSpeed2++; 
    } else if (currentSpeed2 > targetSpeed2) {
      currentSpeed2--; 
    }
    forward(currentSpeed2); 
  }
  //forward(200);//110>>130>150
  //delay(10); 
}