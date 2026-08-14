#ifndef CONSTANT_H
#define CONSTANT_H

#include <Arduino.h>

// ブロードキャストアドレス
static const uint8_t broadcastAddress[6] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};

// ==========================================================
// 🎯 【これ一つでOK】送受信共通の24バイト統合構造体
// ==========================================================
struct CombinedPayload {
  uint8_t header;       // data[0]  (99)
  uint8_t train1_speed; // data[1]
  uint8_t fb_light3;    // data[2]
  uint8_t train2_speed; // data[3]
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
  uint8_t data88;       // data[19]  (88)

  float voltage;        // 💡 列車2の電圧（4バイト）も同じ箱に入れます！
} __attribute__((packed));

// ==========================================================
// 🔧 構造体の実体管理（送受で同じ構造体を使います）
// ==========================================================
#ifdef EXTERN_MAIN
  extern CombinedPayload sendData;     // 送信用
  extern CombinedPayload recvData;     // 受信用
  extern CombinedPayload lastSendData; // 前回送信分（変化抽出用）
  extern unsigned long lastSendTime;
#else
  CombinedPayload sendData;
  CombinedPayload recvData;
  CombinedPayload lastSendData;
  unsigned long lastSendTime = 0;
#endif

// ==========================================================
// 🔧 共有グローバル変数（既存のまま）
// ==========================================================
String Termination, SInPoji, Train, Hedder, mTrain;
int Train1, Train2, Train3, Train4;
String Train1s, Train2s, Train3s, Train4s;
volatile int compete = 0;
int Data1; int Data2; int Data3; int Data4;
int FB_Light;
boolean direction = 0;
uint8_t ctr = 0;
uint8_t Data5 = 0;   
uint8_t Data6 = 0;   
uint8_t Data7 = 0;   
uint8_t Data8 = 0;   
uint8_t Send1 = 0; uint8_t Send2 = 0; uint8_t Send3 = 0; uint8_t Send4 = 0;
uint8_t startbutton = 1;
float currentFeedbackVoltage = 0.0; // 最新の電圧を保持する変数

volatile int Train1TimeSetFlag1 = 0; volatile int Train2TimeSetFlag2 = 0;
volatile int Train3TimeSetFlag3 = 0; volatile int Train4TimeSetFlag4 = 0;
volatile int Train1Flag1 = 0; volatile int Train2Flag2 = 0;
volatile int Train3Flag3 = 0; volatile int Train4Flag4 = 0;
volatile int Data5Flag1 = 1; volatile int Data5Flag2 = 1;
volatile int Data5Flag3 = 1; volatile int Data5Flag4 = 1;
volatile int Train1Flag22 = 0; volatile int Train1Flag32 = 0;
volatile int Train2Flag22 = 0; volatile int Train2Flag32 = 0;
volatile int Train3Flag22 = 0; volatile int Train3Flag32 = 0;
volatile int Train4Flag22 = 0; volatile int Train4Flag32 = 0;
int mc;
byte ServoInFlag  = 0; byte ServoOutFlag1 = 0; byte ServoOutFlag2 = 0;
byte startFlag = 0;
volatile int Train1Flag10 = 0; volatile int Train2Flag10 = 0;
volatile int Train3Flag10 = 0; volatile int Train4Flag10 = 0;
volatile int Train1Flag12 = 0; volatile int Train2Flag12 = 0;
volatile int Train3Flag12 = 0; volatile int Train4Flag12 = 0;
volatile int Train1Flag13 = 0; volatile int Train2Flag13 = 0;
volatile int Train3Flag13 = 0; volatile int Train4Flag13 = 0;
volatile int Train1Flag21 = 0; volatile int Train2Flag21 = 0;
volatile int Train3Flag21 = 0; volatile int Train4Flag21 = 0;
volatile int Train1Flag31 = 0; volatile int Train2Flag31 = 0;
volatile int Train3Flag31 = 0; volatile int Train4Flag31 = 0;
volatile int Train1Flag15D1 = 0; volatile int Train1Flag15D2 = 0;
volatile int Train2Flag15D1 = 0; volatile int Train2Flag15D2 = 0;
volatile int Train3Flag15D1 = 0; volatile int Train3Flag15D2 = 0;
volatile int Train4Flag15D1 = 0; volatile int Train4Flag15D2 = 0;
volatile int Train1sesor10Flag1 = 0; volatile int Train2sesor10Flag2 = 0;
volatile int Train3sesor10Flag3 = 0; volatile int Train4sesor10Flag4 = 0;
volatile int Train1sesor12Flag1 = 0; volatile int Train2sesor12Flag2 = 0;
volatile int Train3sesor12Flag3 = 0; volatile int Train4sesor12Flag4 = 0;
volatile int Train1sesor21Flag1 = 0; volatile int Train2sesor21Flag2 = 0;
volatile int Train3sesor21Flag3 = 0; volatile int Train4sesor21Flag4 = 0;
volatile int Train1sesor31Flag1 = 0; volatile int Train2sesor31Flag2 = 0;
volatile int Train3sesor31Flag3 = 0; volatile int Train4sesor31Flag4 = 0;

unsigned long SubSetTime22 = 0; unsigned long MainSetTime32 = 0;
unsigned long Timecompete = 0; unsigned long SubSetTime10 = 0; unsigned long SubSetTime12 = 0;
unsigned long SetTime13 = 0; unsigned long SubSetTime21 = 0;unsigned long MainSetTime31 = 0;
unsigned long SubSetTime31 = 0;
unsigned long SubSetservoTime13 = 0;
unsigned long Time22 = 0; unsigned long Time32 = 0;
unsigned long Time822 = 0; unsigned long Time832 = 0;
unsigned long count22 = 0; unsigned long count32 = 0;
unsigned long count22Flag = 0; unsigned long count32Flag = 0;
unsigned long MainServoTime32; unsigned long SubServoTime22;

#endif