#include "mainH.h"

/*void writeServos() {
  if ((analogRead(26) >= 700) && (tiltServoDirection == false)) {
    if (tiltServoPos >= 150) {
      tiltServoDirection = true;
    }
    while ((analogRead(26) >= 700) && (tiltServoPos <= 150)) {
      tiltServo.write(tiltServoPos);
      tiltServoPos += 1;
      delay(10);
    }
  } 
  
  if ((analogRead(26) >= 700) && (tiltServoDirection == true)) {
    if (tiltServoPos <= 40) {
      tiltServoDirection = false;
    }
    while ((analogRead(26) >= 700) && (tiltServoPos >= 40)) {
      tiltServo.write(tiltServoPos);
      tiltServoPos -= 1;
      delay(10);
    }
  } else {
    ;;
  }
  if ((analogRead(27) >= 700) && (openCloseServoDirection == false)) {
    if (openCloseServoPos >= 150) {
      openCloseServoDirection = true;
    }
    while ((analogRead(27) >= 700) && (openCloseServoPos <= 150)) {
      openCloseServo.write(tiltServoPos);
      openCloseServoPos += 1;
      delay(10);
    }
  } else if ((analogRead(27) >= 700) && (openCloseServoDirection == true)) {
    if (openCloseServoPos <= 40) {
      openCloseServoDirection = false;
    }
    while ((analogRead(27) >= 700) && (openCloseServoPos >= 40)) {
      openCloseServo.write(tiltServoPos);
      openCloseServoPos -= 1;
      delay(10);
    }
  } else {
    ;;
  }
}*/

bool bounceVeriable1 = false;
bool bounceVeriable2 = false;

void writeServos(){
  if(analogRead(26) >= 700){
    while((analogRead(26) >= 700) && bounceVeriable1 == false){
      if(tiltServoPos < 100){
        setLED(1);
        tiltServo.write(tiltServoPos++);
      }
      else{
        setLED(0);
      }
      if(analogRead(26) < 700){
        bounceVeriable1 = !bounceVeriable1;
      }
    }
    while((analogRead(26) >= 700) && bounceVeriable1 == true){
      if(tiltServoPos > 20){
        setLED(1);
        tiltServo.write(tiltServoPos--);
      }
      else{
        setLED(0);
      }
      if(analogRead(26) < 700){
        bounceVeriable1 = !bounceVeriable1;
      }
    }
  }
  if(analogRead(27) >= 700){
    while((analogRead(27) >= 700) && bounceVeriable2 == false){
      if(openCloseServoPos < 100){
        setLED(1);
        openCloseServo.write(openCloseServoPos++);
      }
      else{
        setLED(0);
      }
      if(analogRead(27) < 700){
        bounceVeriable2 = !bounceVeriable2;
      }
    }
    while((analogRead(27) >= 700) && bounceVeriable2 == true){
      if(openCloseServoPos > 20){
        setLED(1);
        openCloseServo.write(openCloseServoPos--);
      }
      else{
        setLED(0);
      }
      if(analogRead(27) < 700){
        bounceVeriable2 = !bounceVeriable2;
      }
    }
  }
}

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