#include "mainH.h"

void debugMenuFunction(int debugValue){
  if (debugValue == true){
    while (Serial.available() > 0){
      switch (Serial.read()){
        case 57: // number 9
          Serial.println(">0: Test openCloseServo");
          Serial.println(">1: Test rightTiltServo");
          Serial.println(">2: Test leftTiltServo");
          Serial.println("");
          Serial.println(">Type \'9\' at any time to open this menu again");
          break;
        
        case 48: // number 0
          for (openCloseServoPos = 0; openCloseServoPos <= 180; openCloseServoPos++){
            digitalWrite(LED_BUILTIN, HIGH);
            Serial.print(">openCloseServo: ");
            Serial.println(openCloseServoPos);
            openCloseServo.write(openCloseServoPos);
            delay(15);
            digitalWrite(LED_BUILTIN, LOW);
          }
          for (openCloseServoPos = 180; openCloseServoPos >= 0; openCloseServoPos--){
            digitalWrite(LED_BUILTIN, HIGH);
            Serial.print(">openCloseServo: ");
            Serial.println(openCloseServoPos);
            openCloseServo.write(openCloseServoPos);
            delay(15);
            digitalWrite(LED_BUILTIN, LOW);
          }
          Serial.println(">Done");
          break;
        
        case 49: // number 1
          for (rightTiltServoPos = 0; rightTiltServoPos <= 180; rightTiltServoPos++){
            digitalWrite(LED_BUILTIN, HIGH);
            Serial.print(">rightServo: ");
            Serial.println(rightTiltServoPos);
            rightTiltServo.write(rightTiltServoPos);
            delay(15);
            digitalWrite(LED_BUILTIN, LOW);
          }
          for (rightTiltServoPos = 180; rightTiltServoPos >= 0; rightTiltServoPos--){
            digitalWrite(LED_BUILTIN, HIGH);
            Serial.print(">rightServo: ");
            Serial.println(rightTiltServoPos);
            rightTiltServo.write(rightTiltServoPos);
            delay(15);
            digitalWrite(LED_BUILTIN, LOW);
          }
          Serial.println(">Done");
          break;
        
        case 50: // number 2
          for (leftTiltServoPos = 0; leftTiltServoPos <= 180; leftTiltServoPos++){
            digitalWrite(LED_BUILTIN, HIGH);
            Serial.print(">leftServo: ");
            Serial.println(leftTiltServoPos);
            leftTiltServo.write(leftTiltServoPos);
            delay(15);
            digitalWrite(LED_BUILTIN, LOW);
          }
          for (leftTiltServoPos = 180; leftTiltServoPos >= 0; leftTiltServoPos--){
            digitalWrite(LED_BUILTIN, HIGH);
            Serial.print(">leftServo: ");
            Serial.println(leftTiltServoPos);
            leftTiltServo.write(leftTiltServoPos);
            delay(15);
            digitalWrite(LED_BUILTIN, LOW);
          }
          Serial.println(">Done");
          break;

        default:
          Serial.println(">");
          break;
      }
    }
  }
}