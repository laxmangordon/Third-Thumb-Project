#include "mainH.h"

void writeServos(){
  if(analogRead(tiltServoECGSensorPin) >= 700){
    while((analogRead(tiltServoECGSensorPin) >= 700) && bounceVeriable1 == false){
      if(tiltServoPos < tiltServoPosMaximum){
        setLED(1);
        tiltServo.write(tiltServoPos++);
      }
      else{
        setLED(0);
      }
      if(analogRead(tiltServoECGSensorPin) < 700){
        bounceVeriable1 = !bounceVeriable1;
      }
    }
    while((analogRead(tiltServoECGSensorPin) >= 700) && bounceVeriable1 == true){
      if(tiltServoPos > tiltServoPosMinimum){
        setLED(1);
        tiltServo.write(tiltServoPos--);
      }
      else{
        setLED(0);
      }
      if(analogRead(tiltServoECGSensorPin) < 700){
        bounceVeriable1 = !bounceVeriable1;
      }
    }
  }
  if(analogRead(openCloseServoECGSensorPin) >= 700){
    while((analogRead(openCloseServoECGSensorPin) >= 700) && bounceVeriable2 == false){
      if(openCloseServoPos < openCloseServoPosMaximum){
        setLED(1);
        openCloseServo.write(openCloseServoPos++);
      }
      else{
        setLED(0);
      }
      if(analogRead(openCloseServoECGSensorPin) < 700){
        bounceVeriable2 = !bounceVeriable2;
      }
    }
    while((analogRead(openCloseServoECGSensorPin) >= 700) && bounceVeriable2 == true){
      if(openCloseServoPos > openCloseServoPosMinimum){
        setLED(1);
        openCloseServo.write(openCloseServoPos--);
      }
      else{
        setLED(0);
      }
      if(analogRead(openCloseServoECGSensorPin) < 700){
        bounceVeriable2 = !bounceVeriable2;
      }
    }
  }
}