// ===== 従来の配列形式でシリアル表示する関数（ステーション側専用） =====
void printStationData() {
  // 1. 構造体 StationPayload の実際のサイズ（20バイト）に合わせてバッファを用意
  int dataSize = sizeof(sendData); // ぴったり20になります
  uint8_t buffer[dataSize];
  
  // 2. 構造体のデータを一瞬で生配列（バイト列）に変換してコピー
  memcpy(buffer, &sendData, dataSize);
  
  // 3. シリアルモニターに従来の「data[0]=XX...」の形式で出力
  Serial.print("【送信生データ配列】: ");
  for (int i = 0; i < dataSize; i++) { // data[0] 〜 data[19] までを自動でループ
    Serial.print("data[");
    Serial.print(i);
    Serial.print("]:");
    Serial.print(buffer[i]);
    
    if (i < dataSize - 1) {
      Serial.print(",  "); // 見やすくするための区切り文字
    }
  }
  Serial.println(); // 改行
}