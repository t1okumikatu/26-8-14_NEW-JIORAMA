#include <esp_now.h>
#include <WiFi.h>
#include <ESPAsyncWebServer.h>
#include "esp_wifi.h"

const char* ssid = "Train5_Monitor";
const char* password = "password123";

AsyncWebServer server(80);
AsyncWebSocket ws("/ws");

// ブロードキャスト用ピア設定
uint8_t broadcastAddress[] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};

// 各データ保持用変数（トレイン1用）
float lastKnownVoltage = 0.0;
float lastKnownDelay = 0.0; 
float lastKnownCurrent = 0.0;

struct __attribute__((packed)) CombinedPayload {
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
  uint8_t data88;       // data[19]  (88:電圧, 85:電流, 77/66:遅延, 99:STOP命令, 1:START命令)
  
  float voltage;        
};

CombinedPayload incomingPack; 
CombinedPayload stationData; 

// =================================================================
// 📱 スマホ用 HTML / JavaScript 画面データ（トレイン1対応版）
// =================================================================
const char index_html[] PROGMEM = R"rawliteral(
<!DOCTYPE html>
<html>
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Train5 Monitor 電流実測対応版 (Train1)</title>
    <style>
        body { font-family: Arial, sans-serif; background: #222; color: #fff; margin: 20px; }
        h1 { text-align: center; color: #00ffcc; font-size: 24px; }
        .container { max-width: 500px; margin: 0 auto; background: #333; padding: 15px; border-radius: 10px; box-shadow: 0 4px 10px rgba(0,0,0,0.5); }
        .data-row { display: flex; justify-content: space-between; padding: 12px 0; border-bottom: 1px solid #444; font-size: 16px; }
        .label { color: #aaa; }
        .value { font-weight: bold; color: #ffeb3b; font-family: monospace; }
        .space-above { margin-top: 15px; }
        
        .voltage-box { background: #111; border: 1px solid #00ffcc; padding: 12px; border-radius: 8px; margin-bottom: 10px; display: flex; justify-content: space-between; align-items: center; }
        .voltage-label { color: #00ffcc; font-weight: bold; font-size: 16px; }
        .voltage-value { font-size: 22px; color: #00ffcc; font-weight: bold; font-family: monospace; }

        .current-box { background: #111; border: 1px solid #e91e63; padding: 12px; border-radius: 8px; margin-bottom: 10px; display: flex; justify-content: space-between; align-items: center; }
        .current-label { color: #e91e63; font-weight: bold; font-size: 16px; }
        .current-value { font-size: 22px; color: #e91e63; font-weight: bold; font-family: monospace; }
        
        .delay-box { background: #111; border: 1px solid #ff9800; padding: 12px; border-radius: 8px; margin-bottom: 15px; display: flex; justify-content: space-between; align-items: center; }
        .delay-label { color: #ff9800; font-weight: bold; font-size: 16px; }
        .delay-value { font-size: 22px; color: #ff9800; font-weight: bold; font-family: monospace; }

        /* 🚨 サイクリック操作ボタン用スタイル */
        .toggle-btn {
            width: 100%;
            font-size: 22px;
            font-weight: bold;
            padding: 15px 0;
            border: none;
            border-radius: 8px;
            cursor: pointer;
            margin-bottom: 15px;
            transition: background 0.2s, box-shadow 0.2s;
        }
        /* STOP状態（赤） */
        .btn-stop {
            background: #f44336;
            color: white;
            box-shadow: 0 4px #b71c1c;
        }
        .btn-stop:active {
            background: #d32f2f;
            box-shadow: 0 2px #b71c1c;
            transform: translateY(2px);
        }
        /* START状態（緑） */
        .btn-start {
            background: #4caf50;
            color: white;
            box-shadow: 0 4px #1b5e20;
        }
        .btn-start:active {
            background: #388e3c;
            box-shadow: 0 2px #1b5e20;
            transform: translateY(2px);
        }
    </style>
</head>
<body>
    <div class="container">
        <h1>Train5 運行モニター</h1>
        
        <!-- 🔄 1つのボタンでSTOP / STARTを切り替え -->
        <button id="actionBtn" class="toggle-btn btn-stop" onclick="toggleAction()">🛑 MODULE STOP</button>

        <div class="voltage-box">
            <span class="voltage-label">🔋 トレイン1 バッテリー電圧:</span>
            <span class="voltage-value"><span id="voltage_val">0.00</span> V</span>
        </div>

        <div class="current-box">
            <span class="current-label">🔌 トレイン1 消費電流:</span>
            <span class="current-value"><span id="current_val">0.0</span> mA</span>
        </div>

        <div class="delay-box">
            <span class="delay-label">⏳ 最終ストップ時の片道飛行時間:</span>
            <span class="delay-value"><span id="delay_val">0.0</span> ms</span>
        </div>

        <div class="data-row"><span class="label">Train Spd1:</span><span class="value" id="d1">-</span></div>
        <div class="data-row"><span class="label">Train Spd2:</span><span class="value" id="d3">-</span></div>
        <div class="data-row"><span class="label">Train Spd3:</span><span class="value" id="d5">-</span></div>
        <div class="data-row"><span class="label">Train Spd4:</span><span class="value" id="d7">-</span></div>
        
        <div class="data-row space-above"><span class="label">Train1 / 2 位置:</span><span class="value"><span id="d9">-</span> / <span id="d10">-</span></span></div>
        <div class="data-row"><span class="label">Train3 / 4 位置:</span><span class="value"><span id="d11">-</span> / <span id="d12">-</span></span></div>
        
        <div class="data-row"><span class="label">SIn / SOut:</span><span class="value" id="custom_status">- / -</span></div>
        
        <div class="data-row space-above"><span class="label">Counter / StartBtn:</span><span class="value"><span id="d17">-</span> / <span id="d18">-</span></span></div>
    </div>

    <script>
        var gateway = `ws://${window.location.hostname}/ws`;
        var websocket;
        var isStopped = false; // ボタンの状態フラグ (false: STOP準備状態, true: START準備状態)

        function initWebSocket() {
            websocket = new WebSocket(gateway);
            websocket.onmessage = onMessage;
            websocket.onclose = function() { setTimeout(initWebSocket, 2000); };
        }

        // 🔄 STOP/STARTのサイクリック切り替え送信関数
        function toggleAction() {
            if (websocket && websocket.readyState === WebSocket.OPEN) {
                var btn = document.getElementById('actionBtn');
                
                if (!isStopped) {
                    // STOP命令を送信して、見た目をSTARTボタンへ変更
                    websocket.send("STOP");
                    btn.innerText = "▶️ MODULE START";
                    btn.className = "toggle-btn btn-start";
                    isStopped = true;
                } else {
                    // START命令を送信して、見た目をSTOPボタンへ変更
                    websocket.send("START");
                    btn.innerText = "🛑 MODULE STOP";
                    btn.className = "toggle-btn btn-stop";
                    isStopped = false;
                }
            }
        }

        function onMessage(event) {
            var data = event.data.trim().split(',');
            
            if(data.length >= 23) {
                document.getElementById('d1').innerText  = data[1];
                document.getElementById('d3').innerText  = data[3];
                document.getElementById('d5').innerText  = data[5];
                document.getElementById('d7').innerText  = data[7];
                document.getElementById('d9').innerText  = data[9];
                document.getElementById('d10').innerText = data[10];
                document.getElementById('d11').innerText = data[11];
                document.getElementById('d12').innerText = data[12];
                document.getElementById('d17').innerText = data[17];
                document.getElementById('d18').innerText = data[18];
                
                var sinVal = data[13];
                var soutVal = data[14];
                if (sinVal == "1") sinVal = "SUB"; else if (sinVal == "2" || sinVal == "0") sinVal = "MAIN";
                if (soutVal == "1") soutVal = "SUB"; else if (soutVal == "2" || soutVal == "0") soutVal = "MAIN";

                var statusEl = document.getElementById('custom_status');
                if (statusEl) statusEl.innerText = sinVal + " / " + soutVal;
                
                var rawVolt = parseInt(data[20]);
                if (rawVolt > 0) {
                    var voltVal = rawVolt / 50.0;
                    var voltEl = document.getElementById('voltage_val');
                    if (voltEl) voltEl.innerText = voltVal.toFixed(2);
                }

                var delayVal = parseFloat(data[21]);
                var delayEl = document.getElementById('delay_val');
                if (delayEl) delayEl.innerText = delayVal.toFixed(1);

                var currentVal = parseFloat(data[22]);
                var currentEl = document.getElementById('current_val');
                if (currentEl) currentEl.innerText = currentVal.toFixed(1);
            }
        }
        window.addEventListener('load', initWebSocket);
    </script>
</body>
</html>
)rawliteral";

// === 📱 スマホからのボタン操作（WebSocket受信）処理 ===
void onWsEvent(AsyncWebSocket *server, AsyncWebSocketClient *client, AwsEventType type, void *arg, uint8_t *data, size_t len) {
  if (type == WS_EVT_DATA) {
    AwsFrameInfo *info = (AwsFrameInfo*)arg;
    if (info->final && info->index == 0 && info->len == len && info->opcode == WS_TEXT) {
      data[len] = 0;
      String msg = String((char*)data);
      
      if (msg == "STOP") {
        Serial.println("🚨 スマホからSTOP命令を受信！ESP-NOWで全送信します。");
        CombinedPayload stopPack;
        memset(&stopPack, 0, sizeof(stopPack));
        stopPack.header = 99;
        stopPack.data88 = 99; // 💡 99 = STOPフラグ
        
        esp_now_send(broadcastAddress, (uint8_t *)&stopPack, sizeof(stopPack));
      } 
      else if (msg == "START") {
        Serial.println("▶️ スマホからSTART命令を受信！ESP-NOWで全送信します。");
        CombinedPayload startPack;
        memset(&startPack, 0, sizeof(startPack));
        startPack.header = 99;
        startPack.data88 = 1;  // 💡 1 = STARTフラグ
        
        esp_now_send(broadcastAddress, (uint8_t *)&startPack, sizeof(startPack));
      }
    }
  }
}

// === ESP-NOW 受信コールバック ===
void OnDataRecv(const esp_now_recv_info *info, const uint8_t *incomingData, int len) {
  if (len >= sizeof(CombinedPayload)) {
    memcpy(&incomingPack, incomingData, sizeof(CombinedPayload));
    
    if (incomingPack.header == 99 && 
       (incomingPack.data88 == 88 || incomingPack.data88 == 85 || incomingPack.data88 == 77 || incomingPack.data88 == 66)) {
      
      stationData = incomingPack;

      if (stationData.data88 == 77 || stationData.data88 == 66) {
        lastKnownDelay = stationData.voltage;
      } else if (stationData.data88 == 88) {
        if (stationData.voltage > 0.01) {
          lastKnownVoltage = stationData.voltage;
        }
      } else if (stationData.data88 == 85) {
        lastKnownCurrent = stationData.voltage;
      }

      String csvStr = "";
      for(int i = 0; i < 20; i++) {
        csvStr += String(((uint8_t*)&stationData)[i]) + ",";
      }
      
      uint8_t packedVolt = (uint8_t)(lastKnownVoltage * 50.0 + 0.5);
      csvStr += String(packedVolt) + ","; 
      csvStr += String(lastKnownDelay, 1) + ",";
      csvStr += String(lastKnownCurrent, 1);

      ws.textAll(csvStr); 
    } 
  }
}

void setup() {
  Serial.begin(115200);
  
  WiFi.mode(WIFI_AP_STA);
  //--
  // 💡 APの固定IP設定 (IP, ゲートウェイ, サブネットマスク)
  IPAddress local_ip(192, 168, 5, 1);
  IPAddress gateway(192, 168, 5, 1);
  IPAddress subnet(255, 255, 255, 0);
  
  WiFi.softAPConfig(local_ip, gateway, subnet); // AP設定を適用
  WiFi.softAP(ssid, password, 1); 
  esp_wifi_set_channel(1, WIFI_SECOND_CHAN_NONE);
  //----
  if (esp_now_init() != ESP_OK) {
    return;
  }
  
  // 💡 ピア登録（ブロードキャスト用）
  esp_now_peer_info_t peerInfo = {};
  memcpy(peerInfo.peer_addr, broadcastAddress, 6);
  peerInfo.channel = 1;
  peerInfo.encrypt = false;
  esp_now_add_peer(&peerInfo);

  esp_now_register_recv_cb(OnDataRecv);

  ws.onEvent(onWsEvent);
  server.addHandler(&ws);

  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(200, "text/html", index_html);
  });

  server.begin();
  Serial.println("Train5 Monitor（トレイン1テレメトリ対応版）稼働しました！");
}

void loop() {
  ws.cleanupClients();
  delay(50);
}