void compete_0(){
    int s1=30;//12/13/21/31
    int m1=30;//3-11
    int f1=15;
    int s2=160;//12/13/21/31
    int m2=150;//3-11
    int f2=7;

    unsigned long nowTime = millis();                // 現在時刻セット
  // *** Start Contlor **********************************   
     //SubSetTime;
  //タイマー
  //SubSetTime = nowTime + TimeSub[cont];  // 経過時間+セット時間
  // ** "22","32" Train1 ###########################################
 //==================0-1=========================================
  if(compete==0){
    Train3=0;
    Train4=0;
  if(Train1==22 && Train1TimeSetFlag1==0 && compete==0){//1
      Send1=0;   // 1号車、消灯　停止
      SubSetTime22= nowTime + 6000; // 経過時間+セット時間
      Train1TimeSetFlag1=1;//22^1
      //Serial.println(SubSetTime22-nowTime);
  };
 if(nowTime > SubSetTime22 && Train1 == 22 && Train1TimeSetFlag1==1 ){
     Data7=1;
    }
  //=========servo===Data7=1============
   if(Train1==22 && Data7==1 && Train1Flag22==0 && (Train2==3 || Train3==3 || Train4==3)){//1
            Send1=0;
          }
   if(Train1==22 && Data7==1 && Train1Flag22==0 && !(Train2==3 || Train3==3 || Train4==3)){//1
         SubServoTime22= nowTime+4000;
         Data6=1;
         Train1Flag22=1;
          }
   if(nowTime > SubServoTime22 && Train1 == 22 && Train1Flag22==1){
           Data6=1;
           Send1=s1;   // 1号車  // 
           SubServoTime22=0;
           SubSetTime22=0; 
           Data7=0;     
          }  
   //=========servo===Data6=1============ 
    //==========="3"====0-1================================== 
        if(Train1==3){
          Train1TimeSetFlag1=0;
          Train1Flag22=0;                                     
        }
        if(Train1==3 && (Train2==4 || Train3==4 || Train4==4)){//4
            Send1=0;
           }
        if(Train1==3 && !(Train2==4 || Train3==4 || Train4==4)){
           Send1=m1;
        }
        /*
      //=========="10"==1-0=====================================
      if(Train1==10 && Train1sesor10Flag1==0){
         Send1=0;
            SubSetTime10= nowTime + random(3000,13000);
           Train1sesor10Flag1=1;
      }
        if(nowTime > SubSetTime10 && Train1 == 10 && Train1sesor10Flag1==1){
           Train1sesor10Flag1=1;
           Train1Flag10=1;
      }
      if(Train1==10 && (Train2==11 || Train3==11 || Train4==11) && Train1Flag10==1){//4
        Send1=0; 
        Train1Flag10=1;  
      }    
      if(Train1 == 10 && !(Train2==11 || Train3==11 || Train4==11) && Train1Flag10==1){ //Sub>>>Sub//1//T1       
        Send1=m1; // 1号車、前照灯、通常走行       
   }  
   */     
   // ** "22","32" Train2 ###########################################
   //===========Train2==start==0-1=========================================
    if(Train2==32 && Train1==3 && Train2TimeSetFlag2==0 && compete==0){//1
      Send2=0;   // 1号車、消灯　停止
      MainSetTime32= nowTime + 1000; // 経過時間+セット時間
      Train2TimeSetFlag2=1;//22^1
     }
     if(nowTime > MainSetTime32 && Train2 == 32 && Train2TimeSetFlag2==1 ){
     //Train2TimeSetFlag2=0;
     Data7=2;
    }
  //=========servo===Data7=2============
    if(Train2==32 && Data7==2 && Train2Flag32==0 && (Train1==3 || Train3==3 || Train4==3)){//1
            Send2=0;
          }
   if(Train2==32 && Data7==2 && Train2Flag32==0 && !(Train1==3 || Train3==3 || Train4==3)){//1
         MainServoTime32= nowTime+4000;
         Data6=2;
         Train2Flag32=1;
          }
   if(nowTime > MainServoTime32 && Train2 == 32 && Train2Flag32==1){
           Data6=2;
           Send2=s2;   // 1号車  //
           MainSetTime32=0;
           MainServoTime32=0;
           Data7=0;
         
           
        }
 
   //=========servo===Data6=1============  
   //==========="3"====0-1================================== 
        if(Train2==3){ 
          Train1TimeSetFlag1=0;
          Train2TimeSetFlag2=0;                 
          Train2Flag32=0;
          compete=1;
          Timecompete=0;     
        }
       if(Train2==3 && (Train1==4 || Train3==4 || Train4==4)){//4
            Send2=0;
           }
       if(Train2==3 && !(Train1==4 || Train3==4 || Train4==4)){
           Send2=m2;
        }

//=========="10"==1-0=====================================
      if(Train1==10 && Train1sesor10Flag1==0){
         Send1=0;
            SubSetTime10= nowTime + 10000;
           Train1sesor10Flag1=1;
      }
        if(nowTime > SubSetTime10 && Train1 == 10 && Train1sesor10Flag1==1){
           Train1sesor10Flag1=1;
           Train1Flag10=1;
      }
      if(Train1==10 && (Train2==11 || Train3==11 || Train4==11) && Train1Flag10==1){//4
        Send1=0; 
        Train1Flag10=1;  
      }    
      if(Train1 == 10 && !(Train2==11 || Train3==11 || Train4==11) && Train1Flag10==1){ //Sub>>>Sub//1//T1       
        Send1=s1; // 1号車、前照灯、通常走行    
   } 
} 
   /*
   //=========="11"==0-1====================================
       if(Train1==11 && (Train2==12 || Train3==12 || Train4==12)){//4
            Send1=0;
            Train1sesor10Flag1=0;
            Train1Flag10=0;
           //SubSetTime11 = nowTime + 5000;  // 経過時間+セット時間//T1
     // Train1TimeSetFlag1=1;
    }
      if(Train1 == 11 && !(Train2==12 || Train3==12 || Train4==12 )){ //Sub>>>Sub//1//T1      
     Send1=s1; // 1号車、前照灯、通常走行
     Train1sesor10Flag1=0;
            Train1Flag10=0;
    //Train1TimeSetFlag1=1;
   }     
    //=========="12"==1-0=====================================
    if(Train1==12 && Train1sesor12Flag1==0){
         Send1=0;
            SubSetTime12= nowTime + 10000;
           Train1sesor12Flag1=1;
      }
    if(nowTime > SubSetTime12 && Train1 == 12 && Train1sesor12Flag1==1){
           Train1sesor12Flag1=1;
           Train1Flag12=1;
      } 
    
    if(Train1==12 && (Train2==13 || Train3==13 || Train4==13) && Train1Flag12==1){//4
        Send1=0; 
        Train1Flag12=1;  
    }
    if(Train1 == 12 && !(Train2==13 || Train3==13 || Train4==13) && Train1Flag12==1){
     Send1=s1; // 1号車、前照灯、通常走行s1 12
     Train1Flag12=0; 
   } */   
}          
