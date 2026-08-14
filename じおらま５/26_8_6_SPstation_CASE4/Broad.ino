/*void Broad(){
      Receive();
      data[0]  = 99;            // header
      data[1]  = Send1*1.4;     // Train5 Speed(0-255)
      data[2]  = FB_LIght;     // Train5 Speed(0-255)
      data[3]  = Send2*4.5;     // Train5 Speed(0-255)       
      data[4]  = FB_LIght;     // Train5 Speed(0-255) 
      data[5]  = Send3;     // Train5 Speed(0-255)
      data[6]  = FB_LIght;     // Train5 Speed(0-255)
      data[7]  = Send4*2;     // Train5 Speed(0-255)       
      data[8]  = FB_LIght;     // Train5 Speed(0-255)      
      data[9]  = Train1;   // Train1_poji
      data[10]  = Train2;  // Train2_poji  
      data[11]  = Train3;   // Train3_poji       
      data[12]  = Train4;  // Train4_poji         
      data[13] = Data5;            // SIn
      data[14] = Data6;            // SOut
      data[15] = Data7;            //  SubLed; 
      data[16] = Data7;            // MainLed;
      data[17]  = ctr;       //
      data[18] = startbutton;  
      data[19] = 88;           
      
      if(compete==1){
         control_1();
         control_2();
         control_3();
         control_4();
      }
      if(compete==0){
        compete_0();
      }
       if(data[0] == 99 && data[19] == 88){
      esp_err_t result = esp_now_send(slave.peer_addr, data, sizeof(data));
   } 
      }
*/
 
