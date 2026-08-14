//===========control_3=====================================================
   void control_3(){
   int s3=39;
   int m3=42;
   int f3=22;
    unsigned long nowTime = millis();                // 現在時刻セット
  // *** Start Contlor **********************************   
     //SubSetTime;
  //タイマー
  //SubSetTime = nowTime + TimeSub[cont];  // 経過時間+セット時間
  // ** "21","31" Train3 ###########################################
 //==================1-0=========================================
 //修正
   if(compete==1){
   if(Train3==21 && (Train1==22 || Train2==22 || Train4==22)){//1
      Time822=0;
      count22Flag=0;
      count22=0;
      Train3Flag13=0;
      Train3Flag15D1=0;
      Train3Flag15D2=0;
      Train3Flag3=0;
      Train3TimeSetFlag3=0;
      Send3=0;   // 3号車、消灯　停止     
     }
 if(Train3 == 21 &&  !(Train1==22 || Train2==22 || Train4==22)){
      Time822=0;
      count22Flag=0;
      count22=0;    
      Train3Flag15D1=0;
      Train3Flag15D2=0;
      Send3=s3;//20ok-19ok-18ok-17ok-16ok-15,16nG     
      Train3Flag3=0;
      Train3TimeSetFlag3=0;
      Train3Flag13=0;
   }
 
  //------------------1-0---------------------------------------
 
    
    if(Train3==31 && (Train1==32 || Train2==32 || Train4==32)){//1
      Time832=0;
      count32Flag=0;
      count32=0;    
      Train3Flag15D1=0;
      Train3Flag15D2=0;
      Train3Flag13=0;
      Train3Flag3=0;
      Train3TimeSetFlag3=0;
      Send3=0;
    }
    if(Train3 == 31 && !(Train1==32 || Train2==32 || Train4==32)){//1 Main>>Main
     Time832=0;
     count32Flag=0;
     count32=0;   
     Train3Flag15D1=0;
     Train3Flag15D2=0;
     Send3=s3; // 3号車、前照灯    通常走行       
     Train3Flag3=0;
     Train3TimeSetFlag3=0;
     Train3Flag13=0;
    }
       
   // ** "22","32" Train3 ###########################################
    //==================0-1=========================================
    
  if(Train3==22 && Train3TimeSetFlag3==0 && compete==1){//1
      Send3=0;   // 1号車、消灯　停止
      SubSetTime22= nowTime + 4000; // 経過時間+セット時間
      Train3TimeSetFlag3=1;//22^1
    };
  if(nowTime > (SubSetTime22+Time822) && Train3 == 22 &&  Train3TimeSetFlag3==1 ){      
      Data7=1;
    };
  //==Train_3=======servo===Data7=1============
    if(Train3==22 && Data7==1 && Train3Flag22==0 && (Train1==3 || Train2==3 || Train4==3)){//1
            Send3=0;
          }
    if(Train3==22 && Data7==1 && Train3Flag22==0 && !(Train1==3 || Train2==3 || Train4==3) && startFlag==0){//1
         startFlag=1;
         SubServoTime22= nowTime + 6000;
         Data6=1;
         Train3Flag22=1;
          }
   if(nowTime > SubServoTime22 && Train3 == 22 && Train3Flag22==1 && Data7==1){
           Data6=1;
           Send3=m3;   //3号車  // 
           Data7=0; 
           SubServoTime22=0;//Train1TimeSetFlag1=0;
           SubSetTime22=0;      
          }  
     //=======servo===Data6=1================== 
     //==========servo===Data6=2===========
       
  //------------------0-1---------------------------------------
     if(Train3==32 && Train3TimeSetFlag3==0 && compete==1){//1
      Send3=0; // 1号車、消灯　停止
      MainSetTime32 = nowTime + 4000;  // 経過時間+セット時間
      Train3TimeSetFlag3 = 1;
    }
     if(nowTime > (MainSetTime32+Time832) && Train3 == 32 && Train3TimeSetFlag3==1 ){//1 Main>>Main
      Data7=2;    
       }
  //-Servo-----Data7=2--Data6=2----------0-1---------------------------------------    
         if(Train3==32 && Data7==2 && Train3Flag32==0 && (Train2==3 || Train1==3 || Train4==3)){//1
            Send3=0;
            //Data7=0;
          }
         if(Train3==32 && Data7==2 && Train3Flag32==0 && !(Train2==3 || Train1==3 || Train4==3) && startFlag==0){//1
         startFlag=1;
         MainServoTime32= nowTime+6000;
         Data6=2;
         //Data7=0;
         Train3Flag32=1;
          }
         if(nowTime > MainServoTime32 && Train3 == 32 && Train3Flag32==1 && Data7==2){
           Data6=2;
           Send3=m3;   // 1号車  //
           Data7=0;
           MainServoTime32=0;//Train1TimeSetFlag1=0;
           MainSetTime32=0;
          }   
   
       
     //==========="3"====0-1================================== 
       if(Train3==3){
          startFlag=0;
          Train3Flag22=0;
          Train3Flag32=0;
          Train3TimeSetFlag3=0;   
        }
      if(Train3==3 && (Train1==4 || Train2==4 || Train4==4)){//4
            Send3=0;
           }
      if(Train3==3 && !(Train1==4 || Train2==4 || Train4==4)){
           Send3=m3;
        }  
         
     //=========="4"==1-0=====================================
      if(Train3==4 && (Train1==5 || Train2==5 || Train4==5)){//4
            Send3=0;
    }
      if(Train3 == 4 && !(Train1==5 || Train2==5 || Train4==5 )){ //Sub>>>Sub//1//T1     
     Send3=m3; // 1号車、前照灯、通常走行
   }  
     //=========="5"==0-1=====================================
      if(Train3==5 && (Train1==6 || Train2==6 || Train4==6)){//4
            Send3=0;
           //SubSetTime5 = nowTime + 5000;  // 経過時間+セット時間//T1
     // Train3TimeSetFlag3=1;
    }
      if(Train3 == 5 && !(Train1==6 || Train2==6 || Train4==6 )){ //Sub>>>Sub//1//T1
       
     Send3=m3; // 1号車、前照灯、通常走行
   // Train3TimeSetFlag3=1;
   }  
          //=========="6"==1-0=====================================
      if(Train3==6 && (Train1==7 || Train2==7 || Train4==7)){//4
            Send3=0;
          // SubSetTime6 = nowTime + 5000;  // 経過時間+セット時間//T1
     // Train3TimeSetFlag3=0;
    }
      if(Train3 == 6 && !(Train1==7 || Train2==7 || Train4==7 )){ //Sub>>>Sub//1//T1
       
     Send3=m3; // 1号車、前照灯、通常走行
    //Train3TimeSetFlag3=0;
   }  
         //=========="7"==0-1=====================================
      if(Train3==7 && (Train1==8 || Train2==8 || Train4==8)){//4
            Send3=0;
           //SubSetTime7 = nowTime + 5000;  // 経過時間+セット時間//T1
      //Train3TimeSetFlag3=1;
    }
      if(Train3 == 7 && !(Train1==8 || Train2==8 || Train4==8 )){ //Sub>>>Sub//1//T1
       
     Send3=m3; // 1号車、前照灯、通常走行
    //Train3TimeSetFlag3=1;
   }  
      //=========="8"==1-0=====================================
      if(Train3==8 && (Train1==9 || Train2==9 || Train4==9)){//4
            Send3=0;
          // SubSetTime8 = nowTime + 5000;  // 経過時間+セット時間//T1
      //Train3TimeSetFlag3=0;
    }
      if(Train3 == 8 && !(Train1==9 || Train2==9 || Train4==9 )){ //Sub>>>Sub//1//T1
       
     Send3=m3; // 1号車、前照灯、通常走行
    //Train3TimeSetFlag3=0;
   }  
    //=========="9"==0-1=====================================
      if(Train3==9 && (Train1==10 || Train2==10 || Train4==10)){//4
            Send3=0;
          // SubSetTime9 = nowTime + 5000;  // 経過時間+セット時間//T1
      //Train3TimeSetFlag3=1;
    }
      if(Train3 == 9 && !(Train1==10 || Train2==10 || Train4==10 )){ //Sub>>>Sub//1//T1      
     Send3=m3; // 1号車、前照灯、通常走行
    //Train3TimeSetFlag3=1;
   }  
   //=========="10"==1-0=====================================
      if(Train3==10 && Train3sesor10Flag3==0){
         Send3=0;
            SubSetTime10= nowTime + random(1000,1000);
           Train3sesor10Flag3=1;
      }
        if(nowTime > SubSetTime10 && Train3 == 10 && Train3sesor10Flag3==1){
           Train3sesor10Flag3=1;
           Train3Flag10=1;
      } 
      if(Train3==10 && (Train1==11 || Train2==11 || Train4==11) && Train3Flag10==1){//4
         Send3=0;
         Train3Flag10=1;  
    }
      if(Train3 == 10 && !(Train1==11 || Train2==11 || Train4==11) && Train3Flag10==1){ //Sub>>>Sub//1//T1      
         Send3=m3; // 1号車、前照灯、通常走行  
   }  
   //=========="11"==0-1=====================================
      if(Train3==11 && (Train1==12 || Train2==12 || Train4==12)){//4
         Send3=0;
         Train3sesor10Flag3=0;
         Train3Flag10=0;
    }
      if(Train3 == 11 && !(Train1==12 || Train2==12 || Train4==12 )){ //Sub>>>Sub//1//T1     
     Send3=m3; // 1号車、前照灯、通常走行
     Train3sesor10Flag3=0;
         Train3Flag10=0;
    //Train3TimeSetFlag3=1;
   }     
       //=========="12"==1-0=====================================
      if(Train3==12 && (Train1==13 || Train2==13 || Train4==13)){//4
            Send3=0;
           //SubSetTime12 = nowTime + 5000;  // 経過時間+セット時間//T1
     // Train3TimeSetFlag3=0;
    }
      if(Train3 == 12 && !(Train1==13 || Train2==13 || Train4==13 )){ //Sub>>>Sub//1//T1      
            Send3=m3; // 1号車、前照灯、通常走行
   // Train3TimeSetFlag3=0;
   }     
  //=============必ず==一旦停止=====================================
  //======"13"====0-1=====一旦停止=====Train3===================      
       if(Train3==13 && Train3Flag3==0){//3
         Send3=0;   // 1号車、消灯　停止//ターマーなし
         SetTime13= nowTime + random(1000,1000);
         Train3Flag3=1;
          }
   if(nowTime > SetTime13 && Train3 == 13 &&  Train3Flag3==1 ){
          Train3Flag3=1;
          }
     //======"13"====0-1=====一旦停止=====Train3===================      
     //================21&&31_ON====================
      if(Train3==13 &&  Train3Flag3==1 && Train3TimeSetFlag3==0 && (Train1==21 || Train2==21 || Train4==21) 
          && (Train1==31 || Train2==31 || Train4==31)){//4
          Send3=0;              //21&&31_ON 
          Data5=0;
         }
     //=修正=====21_OFF===31_OFF==========================
       if(Train3==13 && Train3Flag15D1==0 && Train3Flag3==1 && Data5Flag3==1 && Train3TimeSetFlag3==0 && !(Train1==21 || Train2==21 || Train4==21)
          && !(Train1==31 || Train2==31 || Train4==31)){
            Data5=1;  
            if(Data5==1 && Train3Flag15D1==0){
              Train3Flag15D2=1;
              Train3Flag15D1=1;
            }                   
          }
       if(Train3==13 && Train3Flag15D2==0 && Train3Flag3==1 && Data5Flag3==2 && Train3TimeSetFlag3==0 && !(Train1==21 || Train2==21 || Train4==21)
          && !(Train1==31 || Train2==31 || Train4==31)){
            Data5=2;  
            if(Data5==2 && Train3Flag15D2==0){
              Train3Flag15D2=1;
              Train3Flag15D1=1;
            }                    
          }
     //========31_ON===21_ON=============================         
         if(Train3==13 && Train3Flag15D1==0 && Train3Flag3==1 && Train3TimeSetFlag3==0 && !(Train1==21 || Train2==21 || Train4==21)
            && (Train1==31 || Train2==31 || Train4==31)){
            Data5=1;  // 3号車  //31_ON
         if(Data5==1 && Train3Flag15D1==0){
              Train3Flag15D1=1;
              Train3Flag15D2=1;
            }  
          }
         if(Train3==13 && Train3Flag15D2==0 && Train3Flag3==1 && Train3TimeSetFlag3==0 && (Train1==21 || Train2==21 || Train4==21)
            && !(Train1==31 || Train2==31 || Train4==31)){
            Data5=2;    // 3号車  //21_ON
         if(Data5==2 && Train3Flag15D2==0){
              Train3Flag15D2=1;
              Train3Flag15D1=1;
            }          
        
          }
        //修正 
        //=========servo===Data5=1============
         if(Train3==13 && Train3Flag3==1 && Data5==1 && Train3Flag13==0){
         Send3=0;
         SubSetservoTime13= nowTime + random(2000,2000);
         Train3Flag13=1;
          }
   if(nowTime > SubSetservoTime13 && Train3 == 13 &&  Train3Flag13==1 ){
           Train3Flag13=1;
           Send3=s3;   //3号車  //31_ON
          }  
          
            //=======servo===Data5=2==================      
     //==========servo===Data5=2===========
            if(Train3==13 && Train3Flag3==1 && Data5==2 && Train3Flag13==0){
         Send3=0;
         SubSetservoTime13= nowTime + random(2000,2000);
         Train3Flag13=1;
          }
   if(nowTime > SubSetservoTime13 && Train3 == 13 &&  Train3Flag13==1 ){
           Train3Flag13=1;
           Send3=s3;   // 3号車  //21_ON
          }  
          
      //=========servo====Data5=2===============                 
   }
   }   
    
