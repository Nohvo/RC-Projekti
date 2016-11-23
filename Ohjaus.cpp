#include"Ohjaus.h"
  
 short int exangle = 90; // current state of tire angle
Ohjaus::Ohjaus(){
  attachServos();
  }
Ohjaus::~Ohjaus(){}
void Ohjaus::turn(short int angle, short int turnspeed){
   //servoturn.attach(9);            // attaches the turning servo on pin to the servo object
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
		turnServo(angle);
	}
	else if (angle == exangle){
	}
	else if (angle < exangle){
		for (int i = exangle; i > angle; i--){
			turnServo(i);
			delay(turnspeed);
		}
	}
	else {
		for (int i = exangle; i < angle; i++){
			turnServo(i);
			delay(turnspeed);
		}
	}
	exangle = angle;
} 

void Ohjaus::accelFast(short int accelSpeed, unsigned short int accelTime){
   
   //servoaccel.attach(10);          // attaches the acceleration servo on pin to the servo object
	if (accelSpeed <= maxSpeed && accelSpeed >= minSpeed){
		accelerate(accelSpeed);
		delay(accelTime);
	}
	else if (accelSpeed < minSpeed && accelSpeed > 0){
		accelerate(accelSpeed);
		delay(accelTime);
	}
	else if (accelSpeed > maxSpeed){
		accelerate(maxSpeed);
		delay(accelTime);
	}
	else {
		accelerate(parkSpeed);
		delay(accelTime);
	}
}

/*void accelerate(int accelAmount){
  servoaccel.attach(10);
  
}*/

void Ohjaus::track(){
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

void Ohjaus::accelerate(int accelAmount){
  servoaccel.write(accelAmount);  
}

void Ohjaus::turnServo(int turnAmount){
  servoturn.write(turnAmount);
  }

void Ohjaus::attachServos(){
  servoaccel.attach(10); 
  servoturn.attach(9);
}
void Ohjaus::turnAngled(short int tireAngle, short int targetAngle) // Turn function that uses compass to turn desired angle (real angle).
 {    
   int lastAngle = exangle; // Save tire angle to turn afterwards
   int pingDelay = 100; // Delay for reading compass module
   int realAngle = 0; // 0 is placeholder for compass read!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
   int startingAngle = realAngle; // save starting angle (real compass angle) to memory
   boolean overflowPos = false; // Overflow if targetAngle > 359
   boolean overflowNeg = false; // Overflow if targetAngle < 0
   
   // Set targetAngle to "real" angle
   targetAngle = realAngle + targetAngle;
   
   if (targetAngle < 0) // Check if there is negative overflow in turning angle (example. targetAngle is -30 and real angle is 20 wich leads to targetAngle being -10, this changes it to 269)
   {
     targetAngle = 359 + targetAngle;
     overflowNeg = true;
   }
    else if (targetAngle > 359) // Check if there is positive overflow in turning angle
   {
     targetAngle = targetAngle - 359;
     overflowPos = true;
   }
   
   if (realAngle != targetAngle) // Check if angle is not already magically right
   {  
     // Turn tires to wanted turning angle angle
     turn(tireAngle, 5);
     
     if (realAngle > targetAngle || overflowNeg==true) // Check turning direction
     {
       while (realAngle > targetAngle || overflowNeg==true && realAngle < startingAngle) // delay loop wich checks if car is turning in allowed angles
       {
         delay(pingDelay);
         realAngle = 0; //0 is placeholder for compass read!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
       }  
     }
     else 
     {
       while (realAngle < targetAngle || overflowPos==true && realAngle > startingAngle) // same as above but to other directon
       {
         delay(pingDelay);
         realAngle = 0; //0 is placeholder for compass read!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
       }
     }
     turn(lastAngle, 5); // turn tires back to las angle
   }
 }


