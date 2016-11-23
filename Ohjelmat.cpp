#include"Ohjelmat.h">

short int startButtonState = 0;         // variable for reading the pushbutton status

Ohjelma::Ohjelma(){}
Ohjelma::~Ohjelma(){}

void Ohjelma::start(){
  // Setup sonars
  NewPing sonar1(TRIGGER_PIN, ECHO_PIN1, MAX_DISTANCE); // NewPing setup of pins and maximum distance.
  NewPing sonar2(TRIGGER_PIN, ECHO_PIN2, MAX_DISTANCE); // NewPing setup of pins and maximum distance.
  NewPing sonar3(TRIGGER_PIN, ECHO_PIN3, MAX_DISTANCE); // NewPing setup of pins and maximum distance.

  //Ohjaus::attachServos();
 
	Ohjaus::turn(1, 5);
	int rightSonar;
	int leftSonar;
	int frontSonar;
	int brake = 0;
	Serial.println("Start");
	Ohjaus::accelerate(84);
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
			Ohjaus::turn(25, 5);
			delay(300);
			Ohjaus::turn(0, 5);
			delay(800);
			Ohjaus::turn(-25, 5);
			delay(300);
			Ohjaus::turn(0, 5);
			delay(400);
			Ohjaus::turn(-25, 5);
			delay(120);
			Ohjaus::turn(0, 5);
			delay(700);
			Ohjaus::turn(25, 5);
			delay(120);
			Ohjaus::turn(0, 5);
			delay(50);
			Ohjaus::accelerate(95);
			Ohjaus::accelerate(90);
			delay(70000);
		}
	}
}

