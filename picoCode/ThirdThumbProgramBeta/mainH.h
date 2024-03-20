#include <Servo.h>

#ifndef piPicoHeaderFile
#define piPicoHeaderFile

double versionNumber = 0.01;

//depending on you setup, change these values below to match the wiring of the microcontroller
#define tiltServoECGSensorPin 26 //tilt sensor pin # / user set
#define openCloseServoECGSensorPin 27 //open and close sensor pin # / user set
#define openCloseServoPin 6 //open and close servo pin # / user set
#define tiltServoPin 7 //open and close pin # / user set

#define resetPosButton 10 //reset button pin # / user set


int ledState = 0; //used to determine the power state of the led / changes within the code

int tiltServoPos = 0; //used to deterine the current position of the tilt servo / changes within the code
int openCloseServoPos = 0; //used to determine the current positon of the open and close servo / changes within the code

int tiltServoPosMinimum = 20; //tilt servo minimum position / user set
int tiltServoPosMaximum = 160; //tilt servo maximum position / user set
int openCloseServoPosMinimum = 20; //open and close servo minimum position / user set
int openCloseServoPosMaximum = 160; //open and close servo maximum position / user set

bool bounceVeriable1 = false; //used to change the movement direction of the servos / changes within the code
bool bounceVeriable2 = false; //used to change the movement direction of the servos / changes within the code

bool debugMenu = false; //used to determine if the debug menu should be displayed or not / changes within the codes
bool debugMenuBlock = false; //used to determine if the debug menu should be displayed or not / changes within the codes


//define the servos
Servo tiltServo; //defines the tilt servo
Servo openCloseServo; //defines the open and close servo

//define the functions
void setup();
void loop();

void onStartup();

void debugStart();
void debugMenuFunction();

void setLED();
void resetServoPos();

void writeServos();

#endif