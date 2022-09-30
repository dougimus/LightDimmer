#include <Arduino.h>

// I, Douglas Ward, 000333587, certify that all code submitted is my own work; 
// that I have not copied it from any other source. I also certify that I have not allowed my work to be copied by others.

boolean bState;
boolean bLastState;

void setup() {
  // Set Serial Output Speed
  Serial.begin(115200);

  // set boolean default state
  bState = true;
  bLastState = false;
  
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

  if(iButton == HIGH) { 
    if(bLastState == false) { // check last state so it doesnt repeat
      bLastState = true; //set last state to prevent repeat
      bState = !bState; // toggle boolean
    }
  } else {
    bLastState = false; // unsets last state because button is not pressed
  }

  // read digitized value from the D1 Mini's A/D convertor 
  iResistor = analogRead(A0);

  if(bState == false) {
    digitalWrite(D4, HIGH); //  turn off led
  } else {
    analogWrite(D4, iResistor); // set led to resistor val
  }

  delay(1);
}
