#include "mainH.h"

void setup() {

  //attaches the tilt servo to the number assigned to the tiltServoPin variable and assign the min/max pwm of the servo to 1000/2000
  tiltServo.attach(tiltServoPin, 1000, 2000);
  //attaches the open and close servo to the number assigned to the openCloseServoPin variable and assign the min/max pwm of the servo to 1000/2000
  openCloseServo.attach(openCloseServoPin, 1000, 2000);

  //Sets the pin assigned to the builtin led to the microcontroller as an output
  pinMode(LED_BUILTIN, OUTPUT);
  //sets the builtin led pin to low
  digitalWrite(LED_BUILTIN, LOW);

  //runs the startup function
  onStartup();
}

void loop() {
  //start the debugging segment of code
  debugStart();

  //start the main code functions
  writeServos();

  //start the code that resets the servos' positions
  resetServoPos();
}