#include "mainH.h"

//This function runs on startup. This sets the serial output speed, prints the welcom text, and starts a 5 second delay timer
void onStartup(){
  Serial.begin(115200);

  delay(5000);

  Serial.println(">Welcome");
  Serial.println(">Software made by Harley Smith");
  Serial.print(">Current version: ");
  Serial.println(versionNumber);
  Serial.println("");
  Serial.println(">type \'9\' to enter debug menues");

  //fThis timer can be removed to user discretion
  for(int i = 5; i >= 1; i--){
    Serial.println("");
    Serial.println(">Program starts in: ");
    Serial.print(i);
    delay(1000);
  }
}