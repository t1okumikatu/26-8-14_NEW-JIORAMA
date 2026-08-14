#define EXTERN_MAIN
#include "constant.h"

// 定期的にコマンド送信する関数
void SendV() {
  // 💡 理由：
  // 送信処理はすべてメインスケッチの「PackAndSendStationData()」が一括して、
  // しゃくり・タイムラグが出ないように完璧なタイミングで管理・送信しています。
  // そのため、このSendV()の中で二重に送信処理を行う必要はなくなりました。
  
  // もしシリアルモニタ等で定期的に電圧を確認したい場合は、
  // 以下のデバッグログだけを残しておきます。不要なら関数ごと空っぽでもOKです！
  
  static unsigned long prevMillis = 0;
  if (millis() - prevMillis > 500) { // 500msごとにシリアル確認
    prevMillis = millis();
    
    Serial.print("【現在の共有電圧】: ");
    Serial.print(currentFeedbackVoltage, 2);
    Serial.println(" V");
  }
}