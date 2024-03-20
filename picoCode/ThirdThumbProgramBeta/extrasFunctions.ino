#include "mainH.h"

//This function sets the state of the onboard led microcontroller led
//0 = off, 1 = on, 9 = forever blink in half second intervals
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

//This function resets the position of the servos to their mid position.
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