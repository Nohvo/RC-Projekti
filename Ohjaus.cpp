#include"Ohjaus.h"
#include <Servo.h>

Servo servoturn;  // create servo object to control turning servo
Servo servoaccel;  // create servo object to control acceleration servo

void turn(short int angle, short int turnspeed){

	// checks that turning angles are within safe limits
	if (angle > maxAnglePos && angle > 0){
		angle = maxAnglePos;
	}
	else if (angle < maxAngleNeg && angle < 0){
		angle = maxAngleNeg;
	}

	angle = angle + balance + 90;     // scale

	// sets turning angle
	if (angle == 90 + balance){
		servoturn.write(angle);
	}
	else if (angle == exangle){
	}
	else if (angle < exangle){
		for (int i = exangle; i > angle; i--){
			servoturn.write(i);
			delay(turnspeed);
		}
	}
	else {
		for (int i = exangle; i < angle; i++){
			servoturn.write(i);
			delay(turnspeed);
		}
	}
	exangle = angle;
}

void accelFast(short int accelSpeed, unsigned short int accelTime){

	if (accelSpeed <= maxSpeed && accelSpeed >= minSpeed){
		servoaccel.write(accelSpeed);
		delay(accelTime);
	}
	else if (accelSpeed < minSpeed && accelSpeed > 0){
		servoaccel.write(accelSpeed);
		delay(accelTime);
	}
	else if (accelSpeed > maxSpeed){
		servoaccel.write(maxSpeed);
		delay(accelTime);
	}
	else {
		servoaccel.write(parkSpeed);
		delay(accelTime);
	}
}


void track(){
	accelFast(parkSpeed, 500);
	turn(0, 2);
	delay(20);

	accelFast(minSpeed, 2000);
	turn(30, 5);
	accelFast(minSpeed, 3300);
	turn(0, 5);
	accelFast(minSpeed, 1000);
	turn(30, 5);
	accelFast(minSpeed, 3300);
	turn(0, 5);
	accelFast(minSpeed, 1000);

	accelFast(parkSpeed, 500);

}