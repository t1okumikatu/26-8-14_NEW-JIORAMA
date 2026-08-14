
void setup_servo(){

  digitalWrite(servoInt, HIGH);
  pinMode(PIN_PE0, OUTPUT);   // In 
  pinMode(PIN_PE1, OUTPUT);   // In 
  pinMode(PIN_PE2, OUTPUT);   // Out      
  pinMode(PIN_PE3, OUTPUT);   // Out
  //SubSetTime22=MainSetTime32;
            
 //===servo-1-in   HIGHから立ち上げる
 
  digitalWrite(PIN_PE0, LOW);         // Servo_1-In-Sub 青４
  digitalWrite(PIN_PE1, HIGH);          // Servo_2-In-Main　橙18
  delay(1);
  ServoInFlag = 0;
  //===servo-1-in
   //===servo-1-out 
  digitalWrite(PIN_PE3, HIGH);         // Servo_1-Out-Sub 白23
  digitalWrite(PIN_PE2, LOW);          // Servo_2-Out-Main　緑19
  delay(1);
  ServoOutFlag1 = 0;
  ServoOutFlag2 = 0;
  //===servo-1-out
  //Data5=1;//ServoIn
  Data6=0;//ServoOut
 
  delay(3);
} 
 
   
 
