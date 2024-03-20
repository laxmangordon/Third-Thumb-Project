#include "mainH.h"

//define the writeServo() function
//The way that this function works is that it checks if the output of the EMG/ECG sensors have reached a threshold written below. If this is done, it will move the
//corresponding servo in one direction. This then triggers a latch and the next time the threshold is reached, the servo will move in the opposit direction. This 
//loops forever.
void writeServos(){
  //starts checking the tilt sensor and servo
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

  //starts checking the open and close sensor and servo
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