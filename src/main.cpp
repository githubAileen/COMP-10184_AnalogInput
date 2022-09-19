#include <Arduino.h>
// I Aileen Velasco, 000805966 certify that this material is my original work. 
//No other person's work has been used without due acknowledgement. 
//I have not made my work available to anyone else.

void setup() {
  // configure the USB serial monitor
  Serial.begin(115200);
}

void loop() {
  int iVal;

  // read digitized value from the D1 Mini's A/D converter
  iVal = analogRead(A0);
  float voltage = (iVal*(3.3/1024));
  float temp = (50/3.3)*voltage;
  String judgement = "";

  if (temp < 10){
    judgement = "Cold!";
  } else if (temp >= 10 && temp < 15){
    judgement = "Cool";
  } else if (temp >= 15 && temp < 25){
    judgement = "Perfect";
  } else if (temp >= 25 && temp < 30){
    judgement = "Warm";
  } else if (temp >= 30 && temp < 35){
    judgement = "Hot";
  } else {
    judgement = "Too Hot!";
  }

  // print value to the USB port
  //Serial.println("Digitized Value of " + String(iVal) + 
  //" is equivalent to an Analog Voltage = " + voltage + "V");

  Serial.println("Digitized output of " + String(iVal) + 
  " is equivalent to a temperature input of " + temp + " deg. C, which is " +
  judgement);

  // wait 0.5 seconds (500ms)
  delay(500);
}