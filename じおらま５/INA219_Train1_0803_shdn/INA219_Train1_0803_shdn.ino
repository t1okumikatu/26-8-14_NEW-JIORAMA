#include "esp_wifi.h"  
#include <WiFi.h>      

// ==========================================================
// INA219_0701_trainS3.ino (メインタブ)
// ==========================================================
#define EXTERN_MAIN 

#include <esp_now.h>
#include "constant.h" 
#include <Wire.h>
#include <Adafruit_INA219.h>

// 🔋 INA219のインスタンス
Adafruit_INA219 ina219;

// タイマー変数
unsigned long lastVoltageTime = 0;
unsigned long wakeUpTime = 0; 

// 制御用変数
bool readyToSendDelay = false;     
float lastMeasuredDelay = 0.0;     
uint8_t targetSpeed1 = 0;
uint32_t currentSpeed1 = 0; 

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
        targetSpeed1 = temp.train1_speed;
        //targetSpeed1 = targetSpeed1/3.35 ; // 速度計算
        Serial.print("targetSpeed1  ");
        Serial.println(targetSpeed1);
        recvData = temp;

        // 🔌 ディープスリープ判定
        if (targetSpeed1 == 0 && temp.train1_poji == 32) {
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

void setup() {
  Serial.begin(115200);
  delay(1000);
  
  // XIAO ESP32-S3のI2Cピン初期化
  Wire.begin(5,6); 
  if (!ina219.begin()) {
    Serial.println("INA219が見つかりません。");
  } else {
    Serial.println("INA219 初期化成功！");
  }

  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  
  // 💡 SHDNピンの初期状態設定（起動時は有効化状態にする）
  pinMode(SHDN, OUTPUT);
  digitalWrite(SHDN, HIGH);
  pinMode(SHDN, INPUT_PULLUP);
  delay(200);

  ledcAttach(in1, freq, resolution);
  ledcAttach(in2, freq, resolution);

  // 📡 Wi-Fi省電力・出力制限設定
  WiFi.mode(WIFI_STA);
  esp_wifi_set_ps(WIFI_PS_MIN_MODEM);
  WiFi.setTxPower(WIFI_POWER_8_5dBm);
  WiFi.disconnect();

  StatiNowpeer(); 
  
  lastVoltageTime = millis(); 
  wakeUpTime = millis();
  
  Serial.println("--- 列車1 起動完了 ---");
  if (justWokeUp) {
    Serial.println("☀️ ディープスリープ（充電）から目覚めました！");
  }
}

void loop() {
  // ⏱️ 1. 2秒ごとの電圧・電流送信タスク
  readV();

  // 🚨 安全ガード解除タイマー
  if (justWokeUp && (millis() - wakeUpTime >= 12000)) {
    justWokeUp = false;
    Serial.println("🔓 安全ガード解除。次回停止時にスリープ可能になりました。");
  }

  // 🚂 2. モーター制御処理
  if (targetSpeed1 == 0) {
    currentSpeed1 = 0; 
    //coast(); 
    brake();
  } else {
    if (currentSpeed1 < targetSpeed1) {
      currentSpeed1++; 
    } else if (currentSpeed1 > targetSpeed1) {
      currentSpeed1--; 
    }
    forward(currentSpeed1*2.3); 
  }
  //forward(80);
  delay(10); 
}