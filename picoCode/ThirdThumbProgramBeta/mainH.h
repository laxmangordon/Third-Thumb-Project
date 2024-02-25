#include <Servo.h>

#ifndef piPicoHeaderFile
#define piPicoHeaderFile

double versionNumber = 0.01;

#define tiltServoECGSensorPin 2
#define openCloseServoECGSensorPin 3

bool tiltServoDirection = false;
bool openCloseServoDirection = false;

int ledState = 0;

int tiltServoPos = 0;
int openCloseServoPos = 0;

bool debugMenu = false;
bool debugMenuBlock = false;

Servo tiltServo;
Servo openCloseServo;

void setup();
void loop();

void onStartup();

void debugStart();
void debugMenuFunction();

void setLED();
void writeServos();

#endif