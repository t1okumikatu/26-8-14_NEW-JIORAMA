//===========control_1=====================================================
 void control_1(){
    int s1=30;//12/13/21/31
    int m1=30;//3-11
    int f1=15;
    unsigned long nowTime = millis();                // 現在時刻セット
  // *** Start Contlor **********************************   
     //SubSetTime;
  //タイマー
  //SubSetTime = nowTime + TimeSub[cont];  // 経過時間+セット時間
  // ** "22","32" Train1 ###########################################
 //==================0-1=========================================
  if(compete==1){
  if(Train1==22 && Train1TimeSetFlag1==0 && compete==1 ){//1
      //SubSetTime21=0;
      //startFlag21=0;
      Send1=0;   // 1号車、消灯　停止
      SubSetTime22= nowTime+4000; // 経過時間+セット時間
      Train1TimeSetFlag1=1;//22^1
      
  }
 if(nowTime > SubSetTime22+(Time822) && Train1 == 22 && Train1TimeSetFlag1==1){
     Data7=1;
     //SubSetTime22=0;
    }
  
  //=========servo===Data7=1============
   if(Train1==22 && Data7==1 && Train1Flag22==0 && (Train2==3 || Train3==3 || Train4==3)){//1
            Send1=0;
            //Data7=0;
          }
   if(Train1==22 && Data7==1 && Train1Flag22==0 && !(Train2==3 || Train3==3 || Train4==3) && startFlag==0){//1
         startFlag=1;
         SubServoTime22= nowTime+6000;
         Data6=1;
         //Data7=0;
         Train1Flag22=1;
          }
   if(nowTime > SubServoTime22 && Train1 == 22 && Train1Flag22==1 && Data7==1){
           Data6=1;
           Send1=s1;   // 1号車  //
           Data7=0;
           SubServoTime22=0;//Train1TimeSetFlag1=0;
           SubSetTime22=0;
           
          }  
   //=========servo===Data6=1============       
  //------Data7=2--Data6=2----------0-1---------------------------------------
         if(Train1==32 && Train1TimeSetFlag1==0 && compete==1 ){//1
         Send1=0;   // 1号車、消灯　停止
         MainSetTime32= nowTime+4000; // 経過時間+セット時間
         Train1TimeSetFlag1=1;//22^1      
          }
         if(nowTime > MainSetTime32+(Time832) && Train1 == 32 && Train1TimeSetFlag1==1){
         Data7=2;
         //MainSetTime32=0;
          }
  //-Servo-----Data7=2--Data6=2----------0-1---------------------------------------    
         if(Train1==32 && Data7==2 && Train1Flag32==0 && (Train2==3 || Train3==3 || Train4==3)){//1
            Send1=0;
            //Data7=0;
          }
         if(Train1==32 && Data7==2 && Train1Flag32==0 && !(Train2==3 || Train3==3 || Train4==3) && startFlag==0){//1
         startFlag=1;
         MainServoTime32= nowTime+6000;
         Data6=2;
         //Data7=0;
         Train1Flag32=1;
          }
         if(nowTime > MainServoTime32 && Train1 == 32 && Train1Flag32==1 && Data7==2){
           Data6=2;
           Send1=s1;   // 1号車  //
           Data7=0;
           MainServoTime32=0;//Train1TimeSetFlag1=0;
           MainSetTime32=0;
          }   
  
       
        //==========="3"====0-1================================== 
        if(Train1==3){
          startFlag=0;
          Train1Flag22=0;
          Train1Flag32=0;
          Train1TimeSetFlag1=0;              
        }
        if(Train1==3 && (Train2==4 || Train3==4 || Train4==4)){//4
            Send1=0;
           }
        if(Train1==3 && !(Train2==4 || Train3==4 || Train4==4)){
           Send1=m1;
        }
        
     //=========="4"==1-0=====================================
      if(Train1==4 && (Train2==5 || Train3==5 || Train4==5)){//4
            Send1=0;
    }
      if(Train1 == 4 && !(Train2==5 || Train3==5 || Train4==5 )){ //Sub>>>Sub//1//T1       
     Send1=m1; // 1号車、前照灯、通常走行
   }  
     //=========="5"==0-1=====================================
      if(Train1==5 && (Train2==6 || Train3==6 || Train4==6)){//4
            Send1=0;
          // SubSetTime5 = nowTime + 5000;  // 経過時間+セット時間//T1
     // Train1TimeSetFlag1=1;
    }
      if(Train1 == 5 && !(Train2==6 || Train3==6 || Train4==6 )){ //Sub>>>Sub//1//T1
       
     Send1=m1; // 1号車、前照灯、通常走行
    //Train1TimeSetFlag1=1;
   }  
          //=========="6"==1-0=====================================
      if(Train1==6 && (Train2==7 || Train3==7 || Train4==7)){//4
            Send1=0;
           //SubSetTime6 = nowTime + 5000;  // 経過時間+セット時間//T1
      //Train1TimeSetFlag1=0;
    }
      if(Train1 == 6 && !(Train2==7 || Train3==7 || Train4==7 )){ //Sub>>>Sub//1//T1
       
     Send1=m1; // 1号車、前照灯、通常走行
   // Train1TimeSetFlag1=0;
   }  
         //=========="7"==0-1=====================================
      if(Train1==7 && (Train2==8 || Train3==8 || Train4==8)){//4
            Send1=0;
           //SubSetTime7 = nowTime + 5000;  // 経過時間+セット時間//T1
      //Train1TimeSetFlag1=1;
    }
      if(Train1 == 7 && !(Train2==8 || Train3==8 || Train4==8 )){ //Sub>>>Sub//1//T1
       
     Send1=m1; // 1号車、前照灯、通常走行
    //Train1TimeSetFlag1=1;
   }  
      //=========="8"==1-0=====================================
      if(Train1==8 && (Train2==9 || Train3==9 || Train4==9)){//4
            Send1=0;
           //SubSetTime8 = nowTime + 5000;  // 経過時間+セット時間//T1
      //Train1TimeSetFlag1=0;
    }
      if(Train1 == 8 && !(Train2==9 || Train3==9 || Train4==9 )){ //Sub>>>Sub//1//T1
       
     Send1=m1; // 1号車、前照灯、通常走行
    //Train1TimeSetFlag1=0;
   }  
    //=========="9"==0-1=====================================
      if(Train1==9 && (Train2==10 || Train3==10 || Train4==10)){//4
            Send1=0;
           //SubSetTime9 = nowTime + 5000;  // 経過時間+セット時間//T1
     // Train1TimeSetFlag1=1;
    }
      if(Train1 == 9 && !(Train2==10 || Train3==10 || Train4==10 )){ //Sub>>>Sub//1//T1
       
     Send1=s1; // 1号車、前照灯、通常走行
    //Train1TimeSetFlag1=1;
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
   //=========="11"==0-1=====================================
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
   }     
 //================Sub>>Main==0-1===============================
 //=a===========13 一旦停止=============
   if(Train1==13 && Train1Flag1==0){//3
         Send1=0;   // 1号車、消灯　停止//ターマーなし
         SetTime13= nowTime + 3000;
         Train1Flag1=1;
         Train1Flag12=0;
         Train1sesor12Flag1=0;
          }
   if(nowTime > SetTime13 && Train1 == 13 &&  Train1Flag1==1 ){
          Train1Flag1=1;
          }           
  //==b=Train1=========13 一旦停止=============
  //=========================================
         if(Train1==13 &&  Train1Flag1==1 && Train1TimeSetFlag1==0 && (Train2==21 || Train3==21 || Train4==21) && (Train2==31 || Train3==31 || Train4==31)){//4
         Send1=0;                 //21&&31_ON
         Data5=0; 
         }
         //修正=========
         //========21_OFF=====31_OFF======================
         if(Train1==13 && Train1Flag15D1==0 && Train1Flag1==1 && Data5Flag1==1 && Train1TimeSetFlag1==0 && !(Train2==21 || Train3==21 || Train4==21) 
          && !(Train2==31 || Train3==31 || Train4==31)){
            Data5=1;  // 1号車 //21_OFF &&31_OFF  
             if(Data5==1 && Train1Flag15D1==0){// 1号車  //31_ON
              Train1Flag15D1=1;
              Train1Flag15D2=1;
            }            
          }
          if(Train1==13 && Train1Flag15D2==0 && Train1Flag1==1 && Data5Flag1==2 && Train1TimeSetFlag1==0 && !(Train2==21 || Train3==21 || Train4==21) 
          && !(Train2==31 || Train3==31 || Train4==31)){//2
            Data5=2;    // 1号車 //21_OFF &&31_OFF  
             if(Data5==2 && Train1Flag15D2==0){// 1号車  //21_ON//1
              Train1Flag15D2=1;
              Train1Flag15D1=1;
            }      
          }
          //=====================================
         if(Train1==13 && Train1Flag15D1==0 && Train1Flag1==1 && Train1TimeSetFlag1==0 && !(Train2==21 || Train3==21 || Train4==21)
           && (Train2==31 || Train3==31 || Train4==31)){//31_ON
            Data5=1;
             if(Data5==1 && Train1Flag15D1==0){// 1号車  //31_ON
              Train1Flag15D1=1;
              Train1Flag15D2=1;
            }                          
          }                 
         if(Train1==13 && Train1Flag15D2==0 && Train1Flag1==1 && Train1TimeSetFlag1==0 && (Train2==21 || Train3==21 || Train4==21)
           && !(Train2==31 || Train3==31 || Train4==31)){//21_ON
            Data5=2;
            if(Data5==2 && Train1Flag15D2==0){// 1号車  //21_ON//1
              Train1Flag15D2=1;
              Train1Flag15D1=1;
            }     
          }
        //修正=====================
//=c========servo===Data5=1============
            if(Train1==13 && Train1Flag1==1 && Data5==1 && Train1Flag13==0){
         Send1=0;
         SubSetservoTime13= nowTime + 3000;
         Train1Flag13=1;
          }
   if(nowTime > SubSetservoTime13 && Train1 == 13 &&  Train1Flag13==1 ){
           Train1Flag13=1;
           Send1=s1;   // 1号車  //31_ON
           SubSetTime21=0;
          }  
          
            //=======servo===Data5=1==================      
     //==========servo===Data5=2===========
            if(Train1==13 && Train1Flag1==1 && Data5==2 && Train1Flag13==0){
         Send1=0;
         SubSetservoTime13= nowTime + 3000;
         Train1Flag13=1;
          }
   if(nowTime > SubSetservoTime13 && Train1 == 13 &&  Train1Flag13==1 ){
           Train1Flag13=1;
           Send1=s1;   // 1号車  //21_ON
           SubSetTime21=0;
          }  
          
      //=========servo====Data5=2===============       
       
       
  
 //修正
 //====Train1==21===============Main>>Sub==============================
   
  //------------------1-0---------------------------------------
    if(Train1==21 && Train1sesor21Flag1==0){
         Send1=0;
            SubSetTime21= nowTime + 2000;
           Train1sesor21Flag1=1;
      }
        if(nowTime > SubSetTime21 && Train1 == 21 && Train1sesor21Flag1==1){
           Train1sesor21Flag1=1;
           Train1Flag21=1;
      } 
    
    if(Train1==21 && (Train3==22 || Train2==22 || Train4==22) && Train1Flag21==1){//1
      Time822=0;
      count22Flag=0;
      count22=0;    
      Train1Flag15D1=0;
      Train1Flag15D2=0;
      Train1Flag13=0;
      Train1Flag1=0;
      Train1TimeSetFlag1=0;
      Send1=0;
    }
    if(Train1 == 21 && !(Train3==22 || Train2==22 || Train4==22) && Train1Flag21==1){//1 Main>>Main
     Time822=0;
     count22Flag=0;
     count22=0;   
     Train1Flag15D1=0;
     Train1Flag15D2=0;
     Send1=s1; // 3号車、前照灯    通常走行       
     Train1Flag1=0;
     Train1TimeSetFlag1=0;
     Train1Flag13=0;
    }
   //---Train1-----31------1>>0---------------------------------------
      if(Train1==31 && Train1sesor31Flag1==0){
         Send1=0;
            MainSetTime31= nowTime + 2000;
           Train1sesor31Flag1=1;
      }
        if(nowTime > MainSetTime31 && Train1 == 31 && Train1sesor31Flag1==1){
           Train1sesor31Flag1=1;
           Train1Flag31=1;
      } 
      if(Train1==31 && (Train2==32 || Train3==32 || Train4==32 )){//4
       Time832=0;
      count32Flag=0;
      count32=0;
      Train1Flag15D1=0;
      Train1Flag15D2=0;
      Train1Flag13=0;
      Train1Flag1=0;
      Train1TimeSetFlag1=0;
      Send1=0;   // 1号車、消灯　停止//タイマーなし
       //MainSetTime31 = nowTime + random(3000,10000);  // 経過時間+セット時間//T1
      //Train1TimeSetFlag1=0;
      } 
      
      if(Train1 == 31 && !(Train2==32 || Train3==32 || Train4==32 )){ //Sub>>>Sub//1//T1
       Time832=0;
      count32Flag=0;
      count32=0;
      Train1Flag15D1=0;
      Train1Flag15D2=0;
      Send1=s1; // 1号車、前照灯、通常走行
      Train1Flag1=0;
      Train1TimeSetFlag1=0;
      Train1Flag13=0;
   }
 }
   //修正
 }
