#include "constant.h"
#include <esp_now.h>
#include <Wire.h>
#include <Adafruit_INA219.h>

// メイン側で実体化したタイマー変数を外部参照
extern unsigned long lastVoltageTime;
const unsigned long voltageInterval = 2000; // 💡 2秒ごとに電圧と電流を交互に送信（等間隔表示をよりスムーズに）

// INA219のインスタンス
extern Adafruit_INA219 ina219;

// ==========================================================
// 🚀 メインの送信処理
// ==========================================================
void readV() {
  if (millis() - lastVoltageTime >= voltageInterval) {
    lastVoltageTime = millis();
    
    static bool sendFlip = false;
    sendFlip = !sendFlip; // 交互に切り替え

    sendData.header = 99; // 共通電波コード

    if (sendFlip) {
      // 🔋 電圧データをセット
      float currentVolt = ina219.getBusVoltage_V();
      
      // 🎯 【重要】モニターが「電圧」として認識するコード「88」
      sendData.data88 = 88; 
      sendData.voltage = currentVolt;

      Serial.print("【🔋 INA219 送信】電圧: ");
      Serial.print(currentVolt);
      Serial.println(" V");
    } else {
      // 🔌 電流データをセット
      float currentCurrent = ina219.getCurrent_mA();
      
      // 🎯 【重要】モニターが「電流」として認識するコード「85」に変更！
      sendData.data88 = 85; 
      sendData.voltage = currentCurrent;

      Serial.print("【🔌 INA219 送信】電流: ");
      Serial.print(currentCurrent);
      Serial.println(" mA");
    }

    // 📡 ブロードキャストで一斉送信（モニター・ステーション両方に届きます）
    esp_now_send(broadcastAddress, (uint8_t *)&sendData, sizeof(sendData));
  }
}