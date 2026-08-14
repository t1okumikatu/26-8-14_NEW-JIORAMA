//===========control_2=====================================================
void control_2(){
     int s2=160;//39      *4...*3
     int m2=150;
     int f2=7;
       // *** Start Contlor **********************************
     //SubSetTime;
  //タイマー
  //SubSetTime = nowTime + TimeSub[cont];  // 経過時間+セット時間
   unsigned long nowTime = millis();
   // ** "22","32" Train2 ###########################################
   //===========Train2==start==0-1=========================================
          if(compete==1){
          if(Train2==22 && Train2TimeSetFlag2==0 && compete==1 ){//1
          Send2=0;   // 1号車、消灯　停止
          SubSetTime22= nowTime+4000; // 経過時間+セット時間
          Train2TimeSetFlag2=1;
     
          }
          if(nowTime > SubSetTime22+(Time822) && Train2 == 22 && Train2TimeSetFlag2==1){
          Data7=1;
          //SubSetTime22=0;
           }
 
  //=========servo===Data7=2============
   if(Train2==22 && Data7==1 && Train2Flag22==0 && (Train1==3 || Train3==3 || Train4==3)){//1
            Send2=0;
            //Data6=1;
          }
   if(Train2==22 && Data7==1 && Train2Flag22==0 && !(Train1==3 || Train3==3 || Train4==3) &&  startFlag==0){//1
          startFlag=1;
         SubServoTime22=nowTime+6000;
         Data6=1;
         //Data7=0;
         Train2Flag22=1;
          }
   if(nowTime > SubServoTime22 && Train2 == 22 && Train2Flag22==1){
           Data6=1;
           Send2=s2;   // 2号車  //
           Data7=0;
           SubServoTime22=0;// Train2TimeSetFlag2=0;
           SubSetTime22=0;
          }  
   //=========servo===Data6=1============     

 
  //---------------0>>1---------------------------------
 if(Train2==32 && Train2TimeSetFlag2==0 && compete==1 ){//1
      Send2=0;   // 1号車、消灯　停止
      MainSetTime32= nowTime+4000; // 経過時間+セット時間
      Train2TimeSetFlag2=1;
     
  };
 if(nowTime > MainSetTime32+(Time832) && Train2 == 32 && Train2TimeSetFlag2==1){
     Data7=2;
     //MainSetTime32=0;
    };
 
  //=========servo===Data7=2============
   if(Train2==32 && Data7==2 && Train2Flag32==0 && (Train1==3 || Train3==3 || Train4==3)){//1
            Send2=0;
          }
   if(Train2==32 && Data7==2 && Train2Flag32==0 && !(Train1==3 || Train3==3 || Train4==3) && startFlag==0){//1
         startFlag=1;
         MainServoTime32=nowTime+6000;
         Data6=2;
         //Data7=0;
         Train2Flag32=1;
          }
   if(nowTime > MainServoTime32 && Train2 == 32 && Train2Flag32==1){
           Data6=2;
           Send2=s2;   // 1号車  //
           Data7=0;
           MainServoTime32=0;// Train2TimeSetFlag2=0;
           MainSetTime32=0;
          }  
   //=========servo===Data6=1============     
          
//==========="3"====0-1================================== 
        if(Train2==3){  
          startFlag=0;                
          Train2Flag22=0;
          Train2Flag32=0;
          Train2TimeSetFlag2=0; 
        }
       if(Train2==3 && (Train1==4 || Train3==4 || Train4==4)){//4
            Send2=0;
           }
       if(Train2==3 && !(Train1==4 || Train3==4 || Train4==4)){
           Send2=s2;
        }
        
 //=========="4"==1-0=====================================
      if(Train2==4 && (Train1==5 || Train3==5 || Train4==5)){//4
            Send2=0;
    }
      if(Train2 == 4 && !(Train1==5 || Train3==5 || Train4==5 )){ //Sub>>>Sub//1//T1    
     Send2=s2; // 1号車、前照灯、通常走行
   }  
    
//=========="5"==0-1=====================================
      if(Train2==5 && (Train1==6 || Train3==6 || Train4==6)){//4
            Send2=0;
          // SubSetTime5 = nowTime + 5000;  // 経過時間+セット時間//T1
     // Train2TimeSetFlag2=1;
    }
      if(Train2 == 5 && !(Train1==6 || Train3==6 || Train4==6 )){ //Sub>>>Sub//1//T1
       
     Send2=s2; // 1号車、前照灯、通常走行
    //Train2TimeSetFlag2=1;
   }  
       
//=========="6"==1-0=====================================
      if(Train2==6 && (Train1==7 || Train3==7 || Train4==7)){//4
            Send2=0;
          // SubSetTime6 = nowTime + 5000;  // 経過時間+セット時間//T1
     // Train2TimeSetFlag2=0;
    }
      if(Train2 == 6 && !(Train1==7 || Train3==7 || Train4==7 )){ //Sub>>>Sub//1//T1
       
     Send2=s2; // 1号車、前照灯、通常走行
    //Train2TimeSetFlag2=0;
   }  
      
//=========="7"==0-1=====================================
      if(Train2==7 && (Train1==8 || Train3==8 || Train4==8)){//4
            Send2=0;
           //SubSetTime7 = nowTime + 5000;  // 経過時間+セット時間//T1
      //Train2TimeSetFlag2=1;
    }
      if(Train2 == 7 && !(Train1==8 || Train3==8 || Train4==8 )){ //Sub>>>Sub//1//T1
       
     Send2=s2; // 1号車、前照灯、通常走行
    //Train2TimeSetFlag2=1;
   } 
//=========="8"==1-0=====================================
      if(Train2==8 && (Train1==9 || Train3==9 || Train4==9)){//4
            Send2=0;
           //SubSetTime8 = nowTime + 5000;  // 経過時間+セット時間//T1
      //Train2TimeSetFlag2=0;
    }
      if(Train2 == 8 && !(Train1==9 || Train3==9 || Train4==9 )){ //Sub>>>Sub//1//T1
       
     Send2=s2; // 1号車、前照灯、通常走行
    //Train2TimeSetFlag2=0;
   }    
//=========="9"==0-1=====================================
      if(Train2==9 && (Train1==10 || Train3==10 || Train4==10)){//4
            Send2=0;
           //SubSetTime9 = nowTime + 5000;  // 経過時間+セット時間//T1
      //Train2TimeSetFlag2=1;
    }
      if(Train2 == 9 && !(Train1==10 || Train3==10 || Train4==10 )){ //Sub>>>Sub//1//T1
       
     Send2=s2; // 1号車、前照灯、通常走行
    //Train2TimeSetFlag2=1;
   }         
//=========="10"==1-0=====================================
       if(Train2==10 && Train2sesor10Flag2==0){
         Send2=0;
            SubSetTime10= nowTime + 3000;
           Train2sesor10Flag2=1;
      }
        if(nowTime > SubSetTime10 && Train2 == 10 && Train2sesor10Flag2==1){
           Train2sesor10Flag2=1;
           Train2Flag10=1;
      }
      if(Train2==10 && (Train1==11 || Train3==11 || Train4==11) && Train2Flag10==1){//4
        Send2=0;
        Train2Flag10=1;  
    }
      if(Train2 == 10 && !(Train1==11 || Train3==11 || Train4==11 ) && Train2Flag10==1){ //Sub>>>Sub//1//T1
       
     Send2=s2; // 1号車、前照灯、通常走行
   
   }      
//=========="11"==0-1=====================================
      if(Train2==11 && (Train1==12 || Train3==12 || Train4==12)){//4
            Send2=0;
          Train2sesor10Flag2=0;
            Train2Flag10=0;  
    }
      if(Train2 == 11 && !(Train1==12 || Train3==12 || Train4==12 )){ //Sub>>>Sub//1//T1       
     Send2=s2; // 1号車、前照灯、通常走行
     Train2sesor10Flag2=0;
            Train2Flag10=0;  
    //Train2TimeSetFlag2=1;
   }           
   //=========="12"==1-0=====================================
  //==1-0=======Train2=="12"===1-0===================Main>>>Sub
  if(Train2==12 && Train2sesor12Flag2==0){
         Send2=0;
            SubSetTime12= nowTime + 10000;
           Train2sesor12Flag2=1;
      }
    if(nowTime > SubSetTime12 && Train2 == 12 && Train2sesor12Flag2==1){
           Train2sesor12Flag2=1;
           Train2Flag12=1;
      }    
    if(Train2==12 && (Train1==13 || Train3==13 || Train4==13) && Train2Flag12==1){//4
        Send2=0; 
        Train2Flag12=1;  
    }
    if(Train2 == 12 && !(Train1==13 || Train3==13 || Train4==13) && Train2Flag12==1){
     Send2=s2; // 1号車、前照灯、通常走行s1 12
     Train2Flag12=0;
     Train2Flag2=0;
   }       
  //================Sub>>Main==0-1===============================
   //=a====="13"====0-1=====一旦停止========================
         if(Train2==13 && Train2Flag2==0){//3
         Send2=0;   // 1号車、消灯　停止//ターマーなし
         SetTime13= nowTime + 3000;
         Train2Flag2=1;
         Train2Flag12=0;
         Train2sesor12Flag2=0;
          }
   if(nowTime > SetTime13 && Train2 == 13 &&  Train2Flag2==1 ){
         Train2Flag2=1;
          }
      //=b==Train2=========13 一旦停止=============  
      //=========================================          
       if(Train2==13 &&  Train2Flag2==1 && Train2TimeSetFlag2==0 && (Train1==21 || Train3==21 || Train4==21) 
          && (Train1==31 || Train3==31 || Train4==31)){//4
          Send2=0;              //21&&31_ON
          Data5=0;
         }
         //=修正========21_OFF=31_OFF===============================
       if(Train2==13 && Train2Flag15D1==0 && Train2Flag2==1 && Data5Flag2==1 && Train2TimeSetFlag2==0 && !(Train1==21 || Train3==21 || Train4==21)
          && !(Train1==31 || Train3==31 || Train4==31)){
         Data5=1;   // 2号車 //21_off &&31_off  
             if(Data5==1 && Train2Flag15D1==0){
              Train2Flag15D1=1;
              Train2Flag15D2=1;
            }       
          }
        if(Train2==13 && Train2Flag15D2==0 && Train2Flag2==1 && Data5Flag2==2 && Train2TimeSetFlag2==0 && !(Train1==21 || Train3==21 || Train4==21)
          && !(Train1==31 || Train3==31 || Train4==31)){
            Data5=2;  // 2号車 //21_off &&31_off   
             if(Data5==2 && Train2Flag15D2==0){
              Train2Flag15D2=1;
              Train2Flag15D1=1;
            }             
          }
          //=============================================
          
         if(Train2==13 && Train2Flag15D1==0 && Train2Flag2==1 && Train2TimeSetFlag2==0 && !(Train1==21 || Train3==21 || Train4==21)
           && (Train1==31 || Train3==31 || Train4==31)){
            Data5=1;    // 1号車  //31_ON
            if(Data5==1 && Train2Flag15D1==0){
              Train2Flag15D1=1;
              Train2Flag15D2=1;
            }  
          }
         if(Train2==13 && Train2Flag15D2==0 && Train2Flag2==1 && Train2TimeSetFlag2==0 && (Train1==21 || Train3==21 || Train4==21)
            && !(Train1==31 || Train3==31 || Train4==31)){
            Data5=2;    // 1号車  //21_ON
              if(Data5==2 && Train2Flag15D2==0){
              Train2Flag15D2=1;
              Train2Flag15D1=1;
            }     
          }
          //修正
//=c========servo===Data5=1============
            if(Train2==13 && Train2Flag2==1 && Data5==1 && Train2Flag13==0){
         Send2=0;
         SubSetservoTime13= nowTime + 3000;
         Train2Flag13=1;
          }
   if(nowTime > SubSetservoTime13 && Train2 == 13 &&  Train2Flag13==1 ){
           Train2Flag13=1;
           Send2=s2;   // 2号車  //31_ON         
          }           
            //=======servo===Data5=1==================      
     //==========servo===Data5=2===========
            if(Train2==13 && Train2Flag2==1 && Data5==2 && Train2Flag13==0){
         Send2=0;
         SubSetservoTime13= nowTime + 3000;
         Train2Flag13=1;
          }
   if(nowTime > SubSetservoTime13 && Train2 == 13 &&  Train2Flag13==1 ){
           Train2Flag13=1;
           Send2=s2;   // 2号車  //21_ON
           
          }  
          
      //=========servo====Data5=2===============          
     //===修正
     //==1-0=======Train2=="21"===1-0===================Main>>>Sub
     //==1-0=======Train2=="21"===1-0===================Main>>>Sub 
   //=========Train2 pattern2========================Main>>>Sub
     if(Train2==21 && Train2sesor21Flag2==0){
         Send2=0;
         Train2Flag13=0;
            SubSetTime21= nowTime + 2000;
           Train2sesor21Flag2=1;
      }
        if(nowTime > SubSetTime21 && Train2 == 21 && Train2sesor21Flag2==1){
           Train2sesor21Flag2=1;
           Train2Flag21=1;
      } 
    
    if(Train2==21 && (Train3==22 || Train1==22 || Train4==22) && Train2Flag21==1){//1
      Train2Flag2=0;
      Time822=0;
      count22Flag=0;
      count22=0;    
      Train2Flag15D1=0;
      Train2Flag15D2=0;
      Train2Flag13=0;
      Train2TimeSetFlag2=0;
      Send2=0;
    }
    if(Train2 == 21 && !(Train3==22 || Train1==22 || Train4==22) && Train2Flag21==1){//1 Main>>Main
     Train2Flag2=0;
     Time822=0;
     count22Flag=0;
     count22=0;   
     Train2Flag15D1=0;
     Train2Flag15D2=0;
     Send2=s2; // 3号車、前照灯    通常走行       
     Train2TimeSetFlag2=0;
     Train2Flag13=0;
    }
 //-----Train2----31----------1>>0--------------------------------------------
     if(Train2==31 && Train2sesor31Flag2==0){
         Send2=0;
         Train2Flag13=0;
        Train2Flag2=0;
            SubSetTime31= nowTime + 2000;
           Train2sesor31Flag2=1;
      }
        if(nowTime > SubSetTime31 && Train2 == 31 && Train2sesor31Flag2==1){
           Train2sesor31Flag2=1;
           Train2Flag31=1;
      } 

     if(Train2==31 && (Train1==32 || Train3==32 || Train4==32 ) && Train2Flag31==1){//4
       Train2Flag2=0;
       Time832=0;
       count32Flag=0;
       count32=0;
       Send2=0;   // 2号車、
       Train2Flag13=0;
       Train2Flag15D1=0;
       Train2Flag15D2=0;
       Train2TimeSetFlag2=0;
      } 
    if(Train2 == 31 && !(Train1==32 || Train3==32 || Train4==32 ) && Train2Flag31==1){ //Sub>>>Sub//1//T1
        Train2Flag13=0;
        Train2Flag2=0;
        Time832=0;
        count32Flag=0;
        count32=0;
        Train2Flag15D1=0;
        Train2Flag15D2=0;
        Send2=s2; // 3号車、前照灯    通常走行       
        Train2TimeSetFlag2=0;
        Train2Flag31=0;  
          }
          }
}