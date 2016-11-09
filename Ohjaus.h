  #include"arduino.h"
  #include<Servo.h>
  
	const short int brakeSpeed = 80;          // value for braking 
	const short int parkSpeed = 93;          // value for parking 
	const short int minSpeed = 95;          // value for slow acceleration
	const short int maxSpeed = 100;         // max speed value
	const short int balance = 2;            // angle shift (neutral angle balance)
	const short int maxAnglePos = 33;       // max positive angle value, left turn
	const short int maxAngleNeg = -35;      // max negative angle value, right turn
	const short int startDelay = 3000;      // start delay (ms)
	short int exangle = 90;                 // current state of tire angle

	void accelFast(short int accelSpeed, unsigned short int accelTime);
	void turn(short int angle, short int turnspeed);
	void track();



