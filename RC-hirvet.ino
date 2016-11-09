/*
Controlling a servo position using a potentiometer (variable resistor)
by Michal Rinott <http://people.interaction-ivrea.it/m.rinott>

modified on 8 Nov 2013
by Scott Fitzgerald
http://www.arduino.cc/en/Tutorial/Knob
*/

#include"Ohjelmat.h"
#include<Servo.h>

void setup() {
	Serial.begin(115200);
  servoturn.attach(9);            // attaches the turning servo on pin to the servo object
  servoaccel.attach(10);          // attaches the acceleration servo on pin to the servo object
	pinMode(startButtonPin, INPUT); // initialize the pushbutton pin as an input
}

void loop() {


	track();    // main moving function


}
