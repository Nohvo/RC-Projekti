#include"Ohjelmat.h"
#include<Servo.h>
#include<NewPing.h>

const short int startButtonPin = 2;        // the number of the pushbutton pin
short int startButtonState = 0;         // variable for reading the pushbutton status

void start(){
	turn(1, 5);
	int rightSonar;
	int leftSonar;
	int frontSonar;
	int brake = 0;
	Serial.println("Start");
	servoaccel.write(84);
	while (1){
		delay(32);
		rightSonar = sonar1.ping_cm();
		delay(32);
		leftSonar = sonar2.ping_cm();
		delay(32);
		frontSonar = sonar3.ping_cm();
		if (rightSonar == 0){
			rightSonar = 400;
		}
		if (leftSonar == 0){
			leftSonar = 400;
		}
		if (frontSonar == 0){
			frontSonar = 400;
		}
		Serial.print(leftSonar);
		Serial.print(" <-vasen eteen = ");
		Serial.print(frontSonar);
		Serial.print(" oikea-> ");
		Serial.println(rightSonar);
		if (frontSonar < 300) {
			turn(25, 5);
			delay(300);
			turn(0, 5);
			delay(800);
			turn(-25, 5);
			delay(300);
			turn(0, 5);
			delay(400);
			turn(-25, 5);
			delay(120);
			turn(0, 5);
			delay(700);
			turn(25, 5);
			delay(120);
			turn(0, 5);
			delay(50);
			servoaccel.write(95);
			servoaccel.write(90);
			delay(70000);
		}
	}
}
