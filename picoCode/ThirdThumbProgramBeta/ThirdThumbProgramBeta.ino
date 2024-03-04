#include "mainH.h"

void setup() {
  tiltServo.attach(tiltServoPin, 1000, 2000);
  openCloseServo.attach(openCloseServoPin, 1000, 2000);

  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);

  onStartup();
}

void loop() {
  debugStart();
  writeServos();
  resetServoPos();
}