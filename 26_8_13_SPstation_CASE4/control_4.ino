//===========control_4=====================================================
void control_4() {
  int s4 = 39; //12/13/21/31
  int m4 = 42; //3-11
  int f4 = 14;
  // *** Start Contlor **********************************
  //SubSetTime;
  //タイマー
  //SubSetTime = nowTime + TimeSub[cont];  // 経過時間+セット時間
  unsigned long nowTime = millis();
  // ** "21","31" Train4 
  //==1-0=======Train4=="21"===1-0===================Main>>>Sub
  //修正
  if (compete == 1) {
    if (Train4 == 21 && (Train1 == 22 || Train2 == 22 || Train3 == 22 )) { //4
      Time822 = 0;
      count22Flag = 0;
      count22 = 0;
      Train4Flag13 = 0;
      Train4Flag15D1 = 0;
      Train4Flag15D2 = 0;
      Train4Flag4 = 0;
      Train4TimeSetFlag4 = 0;
      Send4 = 0; // 3号車、消灯　停止
    }

    if (Train4 == 21 && !(Train1 == 22 || Train2 == 22 || Train3 == 22 )) { //Sub>>>Sub//1//T1
      Time822 = 0;
      count22Flag = 0;
      count22 = 0;
      Train4Flag15D1 = 0;
      Train4Flag15D2 = 0;
      Send4 = s4; //20ok-19ok-18ok-17ok-16ok-15,16nG
      Train4Flag4 = 0;
      Train4TimeSetFlag4 = 0;
      Train4Flag13 = 0;
    }

    //-------------------Train4=="31"===1-0=1>>0--------------------------------------------
    if (Train4 == 31 && (Train1 == 32 || Train2 == 32 || Train3 == 32 )) { //4
      Time832 = 0;
      count32Flag = 0;
      count32 = 0;
      Train4Flag15D1 = 0;
      Train4Flag15D2 = 0;
      Train4Flag13 = 0;
      Train4Flag4 = 0;
      Train4TimeSetFlag4 = 0;
      Send4 = 0;
    }

    if (Train4 == 31 && !(Train1 == 32 || Train2 == 32 || Train3 == 32)) { //Sub>>>Sub//1//T1
      Time832 = 0;
      count32Flag = 0;
      count32 = 0;
      Train4Flag15D1 = 0;
      Train4Flag15D2 = 0;
      Send4 = s4; // 3号車、前照灯    通常走行
      Train4Flag4 = 0;
      Train4TimeSetFlag4 = 0;
      Train4Flag13 = 0;
    }
    //修正
    // ** "22","32" Train4 ###########################################
    //==================0-1=========================================

    if (Train4 == 22 && Train4TimeSetFlag4 == 0 && compete == 1) { //1
      Send4 = 0; // 1号車、消灯　停止
      SubSetTime22 = nowTime + 4000; // 経過時間+セット時間
      Train4TimeSetFlag4 = 1; //22^1
    };
    if (nowTime > (SubSetTime22 + Time822) && Train4 == 22 &&  Train4TimeSetFlag4 == 1 ) {
      Data7 = 1;
    };
    //==Train_4=======servo===Data7=1============
    if (Train4 == 22 && Data7 == 1 && Train4Flag22 == 0 && (Train1 == 3 || Train2 == 3 || Train3 == 3)) { //1
      Send4 = 0;
    }
    if (Train4 == 22 && Data7 == 1 && Train4Flag22 == 0 && !(Train1 == 3 || Train2 == 3 || Train3 == 3) && startFlag == 0) { //1
      startFlag = 1;
      SubServoTime22 = nowTime + 6000;
      Data6 = 1;
      Train4Flag22 = 1;
    }
    if (nowTime > SubServoTime22 && Train4 == 22 && Train4Flag22 == 1 && Data7 == 1) {
      Data6 = 1;
      Send4 = m4; //3号車  //
      Data7 = 0;
      SubServoTime22 = 0; //Train1TimeSetFlag1=0;
      SubSetTime22 = 0;
    }
    //=======servo===Data6=1==================
    //==========servo===Data6=2===========

    //------------------0-1---------------------------------------
    if (Train4 == 32 && Train4TimeSetFlag4 == 0 && compete == 1) { //1
      Send4 = 0; // 1号車、消灯　停止
      MainSetTime32 = nowTime + 4000;  // 経過時間+セット時間
      Train4TimeSetFlag4 = 1;
    }
    if (nowTime > (MainSetTime32 + Time832) && Train4 == 32 && Train4TimeSetFlag4 == 1 ) { //1 Main>>Main
      Data7 = 2;
    }
    //-Servo-----Data7=2--Data6=2----------0-1---------------------------------------
    if (Train4 == 32 && Data7 == 2 && Train4Flag32 == 0 && (Train1 == 3 || Train2 == 3 || Train3 == 3)) { //1
      Send4 = 0;
      //Data7=0;
    }
    if (Train4 == 32 && Data7 == 2 && Train4Flag32 == 0 && !(Train1 == 3 || Train2 == 3 || Train3 == 3) && startFlag == 0) { //1
      startFlag = 1;
      MainServoTime32 = nowTime + 6000;
      Data6 = 2;
      //Data7=0;
      Train4Flag32 = 1;
    }
    if (nowTime > MainServoTime32 && Train4 == 32 && Train4Flag32 == 1 && Data7 == 2) {
      Data6 = 2;
      Send4 = m4; // 1号車  //
      Data7 = 0;
      MainServoTime32 = 0; //Train1TimeSetFlag1=0;
      MainSetTime32 = 0;
    }







    //==========="3"====1-1==================================
    if (Train4 == 3) {
      startFlag = 0;
      Train4Flag22 = 0;
      Train4Flag32 = 0;
      Train4TimeSetFlag4 = 0;
    }
    if (Train4 == 3 && (Train1 == 4 || Train2 == 4 || Train3 == 4)) { //4
      Send4 = 0;
    }
    if (Train4 == 3 && !(Train1 == 4 || Train2 == 4 || Train3 == 4)) {
      Send4 = m4;
    }
    //=========="4"==1-0=====================================
    if (Train4 == 4 && (Train1 == 5 || Train2 == 5 || Train3 == 5)) { //4
      Send4 = 0;
    }
    if (Train4 == 4 && !(Train1 == 5 || Train2 == 5 || Train3 == 5)) {
      Send4 = m4;
    }
    //=========="5"==0-1=====================================
    if (Train4 == 5 && (Train1 == 6 || Train2 == 6 || Train3 == 6)) { //4
      Send4 = 0;
    }
    if (Train4 == 5 && !(Train1 == 6 || Train2 == 6 || Train3 == 6 )) { //Sub>>>Sub//1//T1
      Send4 = m4; // 1号車、前照灯、通常走行
    }
    //=========="6"==1-0=====================================
    if (Train4 == 6 && (Train1 == 7 || Train2 == 7 || Train3 == 7)) { //4
      Send4 = 0;
    }
    if (Train4 == 6 && !(Train1 == 7 || Train2 == 7 || Train3 == 7 )) { //Sub>>>Sub//1//T1
      Send4 = m4; // 1号車、前照灯、通常走行
    }

    //=========="7"==0-1=====================================
    if (Train4 == 7 && (Train1 == 8 || Train2 == 8 || Train3 == 8)) { //4
      Send4 = 0;
    }
    if (Train4 == 7 && !(Train1 == 8 || Train2 == 8 || Train3 == 8 )) { //Sub>>>Sub//1//T1
      Send4 = m4; // 1号車、前照灯、通常走行
    }
    //=========="8"==1-0=====================================
    if (Train4 == 8 && (Train1 == 9 || Train2 == 9 || Train3 == 9)) { //4
      Send4 = 0;
    }
    if (Train4 == 8 && !(Train1 == 9 || Train2 == 9 || Train3 == 9 )) { //Sub>>>Sub//1//T1
      Send4 = m4; // 1号車、前照灯、通常走行
    }
    //=========="9"==0-1=====================================
    if (Train4 == 9 && (Train1 == 10 || Train2 == 10 || Train3 == 10)) { //
      Send4 = 0;
    }
    if (Train4 == 9 && !(Train1 == 10 || Train2 == 10 || Train3 == 10 )) { //Sub>>>Sub//1//T1
      Send4 = m4; // 1号車、前照灯、通常走行
    }
    //=========="10"==1-0=====================================
    if (Train4 == 10 && Train4sesor10Flag4 == 0) {
      Send4 = 0;
      SubSetTime10 = nowTime + random(1000, 1000);
      Train4sesor10Flag4 = 1;
    }
    if (nowTime > SubSetTime10 && Train4 == 10 && Train4sesor10Flag4 == 1) {
      Train4sesor10Flag4 = 1;
      Train4Flag10 = 1;
    }

    if (Train4 == 10 && (Train1 == 11 || Train2 == 11 || Train3 == 11) && Train4Flag10 == 1) { //4
      Send4 = 0;
      Train4Flag10 = 1;
    }
    if (Train4 == 10 && !(Train1 == 11 || Train2 == 11 || Train3 == 11) && Train4Flag10 == 1) { //4
      Send4 = m4; // 1号車、前照灯、通常走行
    }
    //=========="11"==0-1=====================================
    if (Train4 == 11 && (Train1 == 12 || Train2 == 12 || Train3 == 12)) { //
      Send4 = 0;
      Train4sesor10Flag4 = 0;
      Train4Flag10 = 0;
    }
    if (Train4 == 11 && !(Train1 == 12 || Train2 == 12 || Train3 == 12 )) { //Sub>>>Sub//1//T1
      Send4 = m4; // 1号車、前照灯、通常走行
      Train4sesor10Flag4 = 0;
      Train4Flag10 = 0;
    }
    //=========="12"==1-0=====================================
    if (Train4 == 12 && (Train1 == 13 || Train2 == 13 || Train3 == 13)) { //
      Send4 = 0;
    }
    if (Train4 == 12 && !(Train1 == 13 || Train2 == 13 || Train3 == 13 )) { //Sub>>>Sub//1//T1
      Send4 = m4; // 1号車、前照灯、通常走行f4
    }
    //=============必ず==一旦停止=====================================
    //======"13"====0-1=====一旦停止========================
    if (Train4 == 13 && Train4Flag4 == 0) { //3
      Send4 = 0; // 1号車、消灯　停止//ターマーなし
      SetTime13 = nowTime + random(1000, 1000);
      Train4Flag4 = 1;
    }
    if (nowTime > SetTime13 && Train4 == 13 &&  Train4Flag4 == 1 ) {
      Train4Flag4 = 1;

    }
    //===Train4=========13 一旦停止=============
    //================21&&31_ON=================================
    if (Train4 == 13 &&  Train4Flag4 == 1 && Train4TimeSetFlag4 == 0 && (Train1 == 21 || Train2 == 21 || Train3 == 21)
        && (Train1 == 31 || Train2 == 31 || Train3 == 31)) { //4
      Send4 = 0;    //21&&31_ON
      Data5 = 0;
    }
    //=修正==========21_OFF==31_OFF==============================
    if (Train4 == 13 && Train4Flag15D1 == 0 && Train4Flag4 == 1 && Data5Flag4 == 1 && Train4TimeSetFlag4 == 0 && !(Train1 == 21 || Train2 == 21 || Train3 == 21)
        && !(Train1 == 31 || Train2 == 31 || Train3 == 31)) {
      Data5 = 1; // 4号車 //21_off &&31_off
      if (Data5 == 2 && Train4Flag15D2 == 0) {
        Train4Flag15D2 = 1;
        Train4Flag15D1 = 1;
      }
    }
    if (Train4 == 13 && Train4Flag15D2 == 0 && Train4Flag4 == 1 && Data5Flag4 == 2 && Train4TimeSetFlag4 == 0 && !(Train1 == 21 || Train2 == 21 || Train3 == 21)
        && !(Train1 == 31 || Train2 == 31 || Train3 == 31)) {
      Data5 = 2; // 4号車 //21_off &&31_off
      if (Data5 == 2 && Train4Flag15D2 == 0) {
        Train4Flag15D2 = 1;
        Train4Flag15D1 = 1;
      }
    }
    //=====31_ON=====21_ON=============================
    if (Train4 == 13 && Train4Flag15D1 == 0 && Train4Flag4 == 1 && Train4TimeSetFlag4 == 0 && !(Train1 == 21 || Train2 == 21 || Train3 == 21)
        && (Train1 == 31 || Train2 == 31 || Train3 == 31)) {
      Data5 = 1; // 4号車  //31_ON
      if (Data5 == 1 && Train4Flag15D1 == 0) {
        Train4Flag15D1 = 1;
        Train4Flag15D2 = 1;
      }
    }
    if (Train4 == 13 && Train4Flag15D2 == 0 && Train4Flag4 == 1 && Train4TimeSetFlag4 == 0 && (Train1 == 21 || Train2 == 21 || Train3 == 21)
        && !(Train1 == 31 || Train2 == 31 || Train3 == 31)) {
      Data5 = 2; // 4号車  //21_ON
      if (Data5 == 2 && Train4Flag15D2 == 0) {
        Train4Flag15D2 = 1;
        Train4Flag15D1 = 1;
      }
    }
    //修正
    //=========servo===Data5=1============
    if (Train4 == 13 && Train4Flag4 == 1 && Data5 == 1 && Train4Flag13 == 0) {
      Send4 = 0;
      SubSetservoTime13 = nowTime + random(2000, 2000);
      Train4Flag13 = 1;
    }
    if (nowTime > SubSetservoTime13 && Train4 == 13 &&  Train4Flag13 == 1 ) {
      Train4Flag13 = 1;
      Send4 = s4; //4号車  //31_ON
    }

    //=======servo===Data5=2==================
    //==========servo===Data5=2===========
    if (Train4 == 13 && Train4Flag4 == 1 && Data5 == 2 && Train4Flag13 == 0) {
      Send4 = 0;
      SubSetservoTime13 = nowTime + random(2000, 2000);
      Train4Flag13 = 1;
    }
    if (nowTime > SubSetservoTime13 && Train4 == 13 &&  Train4Flag13 == 1 ) {
      Train4Flag13 = 1;
      Send4 = s4; // 1号車  //21_ON
    }

    //=========servo====Data5=2===============
  }
}
