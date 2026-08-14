/*
void STOP(){
  if(digitalRead(StartSW) == 0){
    while(1){
     if(restart==1){
      break;
     }
      if(data[0] == 99 && data[14] == 88){
    //esp_err_t result = esp_now_send(slave.peer_addr, data, sizeof(data));
      Send1=0;
      Send2=0;
      Send3=0;
      Send4=0;
      
      data[0]  = 99;            // header
      data[1]  = Send1;     // Train5 Speed(0-255)
      data[2]  = Send2;     // Train5 Speed(0-255)
      data[3]  = Send3;     // Train5 Speed(0-255)       
      data[4]  = Send4;     // Train5 Speed(0-255)      
      data[5]  = ctr;       // 
      data[6]  = Train1;   // Train1_poji
      data[7]  = Train2;  // Train2_poji  
      data[8]  = Train3;   // Train3_poji       
      data[9]  = Train4;  // Train4_poji         
      data[10] = Data5;            // SIn
      data[11] = Data6;            // SOut
      data[12] = Data7;            //  SubLed; 
      data[13] = Data7;            // MainLed;
      data[14] = 88;            // ServoOUT position(1:Sub 2:Main)
    
  esp_err_t result = esp_now_send(slave.peer_addr, data, sizeof(data));
      }
     // if(digitalRead(StartSW) == 0){
      //  restart=1;
     // }
}
//ESP.restart();
  }
}
*/
