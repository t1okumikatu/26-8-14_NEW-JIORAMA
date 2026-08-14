void out_Servo_Contlor(){
    if(Data6==1 ){        // Sub側
      digitalWrite(PIN_PE2, HIGH);    // Servo Out Sub  HIGH_PE2
      digitalWrite(PIN_PE3, LOW);     // Servo Out Main
      digitalWrite(servoInt, LOW);
      digitalWrite(servoInt, HIGH); 
      }
    if(Data6==2  ){   // Main側
      digitalWrite(PIN_PE2, LOW);     // Servo Out Sub
      digitalWrite(PIN_PE3, HIGH);      // Servo Out Main
      digitalWrite(servoInt, LOW);
      digitalWrite(servoInt, HIGH);       
    }
}
  

  
