#include <Arduino.h>

boolean bState;

void setup() {
  // Set Serial Output Speed
  Serial.begin(115200);

  // set boolean default state
  bState = true;
  
  // configure pin D4 as a digital output
  pinMode(D4, OUTPUT); 

  // configure pin D5 as digital input
  pinMode(D5, INPUT_PULLUP);
 
  // set default PWM range 
  analogWriteRange(1023);
}

void loop() {
  int iResistor;
  int iButton;
 
  // read digital value from button
  iButton = digitalRead(D5);

  if(iButton == 0) {
    bState = !bState; // toggle boolean
  }

  // read digitized value from the D1 Mini's A/D convertor 
  iResistor = analogRead(A0);

  if(bState == false) {
    iResistor = 0; //turn off led
  }

  analogWrite(D4, iResistor);

  delay(1);
}