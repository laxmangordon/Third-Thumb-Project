#include "mainH.h"

void debugStart(){
  if (Serial.available() > 0) {
    if ((int)Serial.read() == 57) {
      debugMenu = true;
      Serial.println("");
      Serial.println(">0: Test openCloseServo");
      Serial.println(">1: Test tiltServo");
      Serial.println(">2: Show tiltServoSensor output values");
      Serial.println(">3: Show openCloseServoSensor output values");
      Serial.println("");
      Serial.println(">Type \'9\' at any time to open this menu again");
      debugMenuFunction();
    }
  }
  resetServoPos();
}

void debugMenuFunction() {
  while (true) {
    while (Serial.available() > 0) {
      switch (Serial.read()) {
        case 57:  // number 9
          Serial.println(">0: Test openCloseServo");
          Serial.println(">1: Test tiltServo");
          Serial.println(">2: Show tiltServoSensor output values");
          Serial.println(">3: Show openCloseServoSensor output values");
          Serial.println(">Type \'9\' at any time to open this menu again");
          break;

        case 48:  // number 0
          for (openCloseServoPos = 0; openCloseServoPos <= 180; openCloseServoPos++) {
            digitalWrite(LED_BUILTIN, HIGH);
            Serial.print(">openCloseServo: ");
            Serial.println(openCloseServoPos);
            openCloseServo.write(openCloseServoPos);
            delay(15);
            digitalWrite(LED_BUILTIN, LOW);
          }
          for (openCloseServoPos = 180; openCloseServoPos >= 0; openCloseServoPos--) {
            digitalWrite(LED_BUILTIN, HIGH);
            Serial.print(">openCloseServo: ");
            Serial.println(openCloseServoPos);
            openCloseServo.write(openCloseServoPos);
            delay(15);
            digitalWrite(LED_BUILTIN, LOW);
          }
          Serial.println(">Done");
          break;

        case 49:  // number 1
          for (tiltServoPos = 0; tiltServoPos <= 180; tiltServoPos++) {
            digitalWrite(LED_BUILTIN, HIGH);
            Serial.print(">tiltServo: ");
            Serial.println(tiltServoPos);
            tiltServo.write(tiltServoPos);
            delay(15);
            digitalWrite(LED_BUILTIN, LOW);
          }
          for (tiltServoPos = 180; tiltServoPos >= 0; tiltServoPos--) {
            digitalWrite(LED_BUILTIN, HIGH);
            Serial.print(">tiltServo: ");
            Serial.println(tiltServoPos);
            tiltServo.write(tiltServoPos);
            delay(15);
            digitalWrite(LED_BUILTIN, LOW);
          }
          Serial.println(">Done");
          break;
        
        case 50:    //number 2
          while (true){
            Serial.println(analogRead(tiltServoECGSensorPin));

            if (Serial.available() > 0){
              if(((int)Serial.read() == 99) || ((int)Serial.read() == 67)){ //99 = c 67 = C
                break;
              }
            }

            delay(15);
          }

        case 51:    //number 3
          while (true){
            Serial.println(analogRead(openCloseServoECGSensorPin));

            if (Serial.available() > 0){
              if(((int)Serial.read() == 99) || ((int)Serial.read() == 67)){ //99 = c 67 = C
                break;
              }
            }

            delay(15);
          }

        default:
          Serial.println(">");
          break;
      }
    }
  }
}