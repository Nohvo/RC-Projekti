/*
Controlling a servo position using a potentiometer (variable resistor)
by Michal Rinott <http://people.interaction-ivrea.it/m.rinott>

modified on 8 Nov 2013
by Scott Fitzgerald
http://www.arduino.cc/en/Tutorial/Knob
*/

#include"Ohjelmat.h"

Ohjelma device;

void setup() {
	//Serial.begin(115200);

  
  device.attachServos();
	pinMode(startButtonPin, INPUT); // initialize the pushbutton pin as an input
}

void loop() {
	device.track();    // main moving function
}
