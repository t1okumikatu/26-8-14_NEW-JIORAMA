void in_Servo_Contlor(){
  if(Data5==1 && ServoInFlag==0){ // Sub(ServoがMain)
    digitalWrite(PIN_PE0, HIGH);         // Servo In Sub 青
    digitalWrite(PIN_PE1, LOW);          // Servo In Main 橙
    digitalWrite(servoInt, LOW);
    digitalWrite(servoInt, HIGH); 
    ServoInFlag = 0;
  }
  if(Data5==2 && ServoInFlag==0)
  { // Main
    digitalWrite(PIN_PE0,LOW);         // Servo In Sub 青
    digitalWrite(PIN_PE1,HIGH);          // Servo In Main　橙
    digitalWrite(servoInt, LOW);
    delay(1);
    digitalWrite(servoInt, HIGH); 
    ServoInFlag = 0;
  }
}
