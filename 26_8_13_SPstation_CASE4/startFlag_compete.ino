void startFlag_compete(){
  unsigned long nowTime = millis();                // 現在時刻セット
   //====T1_T2===========
  //Train1~Train2
     if((Train1==22 || Train2==22) && compete==1 && count22Flag==0){
        count22 = nowTime/1000 ;//count秒                
      count22Flag=1;
     }
      if((Train1==32 || Train2==32) && compete==1 && count32Flag==0){
        count32 = nowTime/1000 ;//count秒                
      count32Flag=1;
     }
   //Train1~Train2
   //====T1_T3===========
   //Train1~Train3
     if((Train1==22 || Train3==22) && compete==1 && count22Flag==0){
        count22 = nowTime/1000 ;//count秒                
      count22Flag=1;
     }
      if((Train1==32 || Train3==32) && compete==1 && count32Flag==0){
        count32 = nowTime/1000 ;//count秒                
      count32Flag=1;
     }
  //Train1~Train3
   //====T1_T4===========
  //Train1~Train4
     if((Train2==22 || Train3==22) && compete==1 && count22Flag==0){
        count22 = nowTime/1000 ;//count秒                
      count22Flag=1;
     }
      if((Train2==32 || Train3==32) && compete==1 && count32Flag==0){
        count32 = nowTime/1000 ;//count秒                
      count32Flag=1;
     }
  //Train1~Train4
  //===T2_T3============
  //Train2~Train3
     if((Train2==22 || Train3==22) && compete==1 && count22Flag==0){
        count22 = nowTime/1000 ;//count秒                
      count22Flag=1;
     }
      if((Train2==32 || Train3==32) && compete==1 && count32Flag==0){
        count32 = nowTime/1000 ;//count秒                
      count32Flag=1;
     }
  //Train2~Train3
   //===T2_T4============
  //Train2~Train4
     if((Train2==22 || Train4==22) && compete==1 && count22Flag==0){
        count22 = nowTime/1000 ;//count秒                
      count22Flag=1;
     }
      if((Train2==32 || Train4==32) && compete==1 && count32Flag==0){
        count32 = nowTime/1000 ;//count秒                
      count32Flag=1;
     }
  //Train2~Train3
   //===T3_T4============
  //Train3~Train4
     if((Train3==22 || Train4==22) && compete==1 && count22Flag==0){
        count22 = nowTime/1000 ;//count秒                
      count22Flag=1;
     }
      if((Train3==32 || Train4==32) && compete==1 && count32Flag==0){
        count32 = nowTime/1000 ;//count秒                
      count32Flag=1;
     }
  //Train3~Train4
    
      //Serial.print("count22---------  ");
      //Serial.println(count22);
      //Serial.print("count32---------  ");
      //Serial.println(count32);
      
      if(count32-count22<10){
        Time832=(count32-count22)*1000;
      }
      if(count32-count22>-10){
        Time822=(count22-count32)*1000;
      }
      
       //Serial.print("Time822---Time832------  ");
      // Serial.print(Time822);
       //Serial.print("  ");
      // Serial.println(Time832);
      }

 

  
 
 
 
    
