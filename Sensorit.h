#include"arduino.h"
#include<NewPing.h>

#define TRIGGER_PIN  11  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN1    12  // Arduino pin tied to echo pin on the ultrasonic sensor..
#define ECHO_PIN2    13  // Arduino pin tied to echo pin on the ultrasonic sensor.
#define ECHO_PIN3    7  // Arduino pin tied to echo pin on the ultrasonic sensor.
#define MAX_DISTANCE 400 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.
