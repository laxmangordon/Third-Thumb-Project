#include "mainH.h"

void setLED(int state){
  if (ledState != state){
    switch (state){
      case 0:
        digitalWrite(LED_BUILTIN, LOW);
        break;
      case 1:
        digitalWrite(LED_BUILTIN, HIGH);
        break;
      case 9:
        while(true){
          digitalWrite(LED_BUILTIN, LOW);
          delay(500);
          digitalWrite(LED_BUILTIN, HIGH);
          delay(500);
        }
        break;
    }
  }
}

void resetServoPos(){
  if (digitalRead(resetPosButton) == HIGH){
    int tiltServoPosMiddle = (tiltServoPosMaximum + tiltServoPosMinimum) / 2;
    int openCloseServoPosMiddle = (openCloseServoPosMaximum + openCloseServoPosMinimum) / 2;

    tiltServoPos = tiltServoPosMiddle;
    openCloseServoPos = openCloseServoPosMiddle;

    bounceVeriable1 = false;
    bounceVeriable2 = false;

    tiltServo.write(tiltServoPos);
    openCloseServo.write(openCloseServoPos);

    delay(2000);
  }
}