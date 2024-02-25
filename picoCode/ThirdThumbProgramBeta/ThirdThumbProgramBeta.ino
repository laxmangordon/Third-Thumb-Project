#include "mainH.h"

void setup() {
  tiltServo.attach(tiltServoECGSensorPin, 400, 2600);
  openCloseServo.attach(openCloseServoECGSensorPin, 400, 2600);

  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);

  onStartup();
}

void loop() {
  debugStart();
  writeServos();
}