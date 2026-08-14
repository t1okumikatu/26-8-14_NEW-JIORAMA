#ifndef CONSTANT_H
#define CONSTANT_H

#include <Arduino.h>

// 📡 ブロードキャストアドレス
static const uint8_t broadcastAddress[6] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};

// ⚙️ モーター制御用の定数
#ifndef VALUE_MAX
#define VALUE_MAX 255
#endif

const int in1 = 23;       // モーター制御ピン1
const int in2 = 22;       // モーター制御ピン2
const int SHDN = 3;      // 💡 SHDN端子ピン（基板のピン番号に合わせて変更してください）
const int freq = 5000;    // PWM周波数
const int resolution = 8; // PWM解像度（8bit: 0〜255）

// ==========================================================
// 🎯 【送受信共通】24バイト統合構造体
// ==========================================================
struct CombinedPayload {
  uint8_t header;       // data[0]  (常に 99)
  uint8_t train1_speed; // data[1]
  uint8_t fb_light3;    // data[2]
  uint8_t train2_speed; // data[3]  (列車2のターゲット速度)
  uint8_t fb_light4;    // data[4]
  uint8_t train3_speed; // data[5]
  uint8_t data5_light;  // data[6]
  uint8_t train4_speed; // data[7]
  uint8_t data6_light;  // data[8]
  uint8_t train1_poji;  // data[9]
  uint8_t train2_poji;  // data[10]
  uint8_t train3_poji;  // data[11]
  uint8_t train4_poji;  // data[12]
  uint8_t Data5_SIn;    // data[13]
  uint8_t Data6_SOut;   // data[14]
  uint8_t Data7_Sub;    // data[15]
  uint8_t Data8_Main;   // data[16]
  uint8_t ctr;          // data[17]
  uint8_t startbutton;  // data[18]
  uint8_t data88;       // data[19]  (88:通常, 85:電流, 99:STOP命令)

  float voltage;        // バッテリー電圧 または 計測された遅延時間ms
} __attribute__((packed));

#ifdef EXTERN_MAIN
  CombinedPayload sendData;
  CombinedPayload recvData;
#else
  extern CombinedPayload sendData;
  extern CombinedPayload recvData;
#endif


// 🛠️ 別タブにある関数の外部宣言
extern void forward(uint32_t pwm);
extern void brake();
extern void coast();
extern void readV();
extern void StatiNowpeer();
extern void stopModule(); 
extern void startModule(); // 💡 START処理用の宣言を追加

#endif /* CONSTANT_H */