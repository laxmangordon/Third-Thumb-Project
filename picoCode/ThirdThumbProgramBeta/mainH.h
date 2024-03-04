#include <Servo.h>

#ifndef piPicoHeaderFile
#define piPicoHeaderFile

double versionNumber = 0.01;

#define tiltServoECGSensorPin 26
#define openCloseServoECGSensorPin 27
#define openCloseServoPin 6
#define tiltServoPin 7

#define resetPosButton 10 //idk the actual value yet, figure it out!

bool tiltServoDirection = false;
bool openCloseServoDirection = false;

int ledState = 0;

int tiltServoPos = 0;
int openCloseServoPos = 0;

int tiltServoPosMinimum = 20;
int tiltServoPosMaximum = 160;
int openCloseServoPosMinimum = 20;
int openCloseServoPosMaximum = 160;

bool bounceVeriable1 = false;
bool bounceVeriable2 = false;

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
void resetServoPos();

void writeServos();

#endif