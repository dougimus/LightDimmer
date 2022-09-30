#include <Arduino.h>

void setup() {
  // Set Serial Output Speed
  Serial.begin(115200);
  
  // configure pin D4 as a digital output
  pinMode(D4, OUTPUT); 
 
  // set default PWM range 
  analogWriteRange(1023);
}

void loop() {
  int iVal; 
 
  // read digitized value from the D1 Mini's A/D convertor 
  iVal = analogRead(A0);

  analogWrite(D4, iVal);

  delay(1);
}