#include "mainH.h"

void setup() {
  Serial.begin(115200);

  delay(5000);

  rightTiltServo.attach(10, 400, 2600);
  leftTiltServo.attach(11, 400, 2600);
  openCloseServo.attach(12, 400, 2600);

  pinMode(LED_BUILTIN, OUTPUT);

  Serial.println(">Welcome");
  Serial.println(">Software made by Harley Smith");
  Serial.print(">Current version: ");
  Serial.println(versionNumber);

  Serial.println("");

  Serial.println(">type \'9\' to enter debug menues");

  delay(5000);
}

void loop(){
  if (!debugMenu){
    if(Serial.available() > 0){
      if ((int)Serial.read() == 57){
        debugMenu = true;
        Serial.println(">0: Test openCloseServo");
        Serial.println(">1: Test rightTiltServo");
        Serial.println(">2: Test leftTiltServo");
        Serial.println("");
        Serial.println(">Type \'9\' at any time to open this menu again");
      }
    }
  }
  else{
    debugMenuFunction(debugMenu);
  }
}
