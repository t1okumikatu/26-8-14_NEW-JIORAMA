 void GUIDE_train(){
  
  while(digitalRead(guide1) == LOW){//1-0
    //ESP.restart();    
    switch (digitalRead(GPIO36)){   
    case 0 : Serial.println("GPIO36=OFF");
    Data5=1;
    Send1=42;
    Serialprint2();
    Broad();
    in_Servo_Contlor();
    continue;   
    default : Serial.println("GPIO36=ON"); 
    Send1=0;     
    Serialprint2();
    Broad();
    in_Servo_Contlor();
    //Data5=2; 
    break;    
    }
    break;
    }
    
  while(digitalRead(guide2) == LOW){//1-0 
    switch (digitalRead(GPIO34)){   
    case 0 : Serial.println("GPIO34=OFF");
    Data5=2;
    Send2=42;
    Serialprint2();
    Broad();
    in_Servo_Contlor();
    continue;      
    case 1 : Serial.println("GPIO34=ON"); 
    Send2=0;     
    Serialprint2();
    Broad();
    in_Servo_Contlor();
    break;
    } 
    break;   
  }
  
  
   while(digitalRead(guide3) == LOW){//1-0    
    switch (digitalRead(GPIO39)){   
    case 0 : Serial.println("GPIO39=OFF");
    Data5=1;
    Send3=42;
    Serialprint2();
    Broad();
    in_Servo_Contlor();
    continue;   
    case 1 : Serial.println("GPIO39=ON"); 
    Send3=0;     
    Serialprint2();
    Broad();
    in_Servo_Contlor();
    break;     
    }
    break;
    }
  while(digitalRead(guide4) == LOW){//1-0 
    switch (digitalRead(GPIO35)){   
    case 0 : Serial.println("GPIO35=OFF");
    Data5=2;
    Send4=42;
    Serialprint2();
    Broad();
    in_Servo_Contlor();
    continue;     
    case 1 : Serial.println("GPIO35=ON"); 
    Send4=0;     
    Serialprint2();
    Broad();
    in_Servo_Contlor();
    break;
    }
   break;
  }
 }

  //======================================
