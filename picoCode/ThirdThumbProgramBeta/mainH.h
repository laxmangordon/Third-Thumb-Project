#include <Servo.h>

#ifndef piPicoHeaderFile
#define piPicoHeaderFile

int rightTiltServoPos = 0;
int leftTiltServoPos = 0;
int openCloseServoPos = 0;

double versionNumber = 0.01;

bool debugMenu = false;

Servo rightTiltServo;
Servo leftTiltServo;
Servo openCloseServo;

void setup();
void loop();

void debugMenuFunction();

#endif