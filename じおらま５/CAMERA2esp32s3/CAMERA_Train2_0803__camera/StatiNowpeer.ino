#include "constant.h"
#include <esp_now.h>

// 💡 メイン側にある受信・送信関数を外部参照
extern void OnDataRecv(const esp_now_recv_info *info, const uint8_t *incomingData, int len);
extern void OnDataSent(const wifi_tx_info_t *info, esp_now_send_status_t status);

void StatiNowpeer(){
  if (esp_now_init() != ESP_OK) {
    Serial.println("ESP-NOW init failed!");
    return;
  }

  esp_now_register_recv_cb(OnDataRecv);
  esp_now_register_send_cb(OnDataSent);

  esp_now_peer_info_t peerInfo = {};
  // broadcastAddress (0xFF) をコピーして登録
  memcpy(peerInfo.peer_addr, broadcastAddress, 6);
  peerInfo.channel = 1;
  peerInfo.encrypt = false;
  
  if (esp_now_add_peer(&peerInfo) != ESP_OK) {
    Serial.println("peer失敗");
    return;
  }
}