// INCLUDES
#include <Stepper.h>

// CONSTANTS
const int X_PIN = A0;
const int Y_PIN = A1;
const int STEPS_PER_REVOLUTION = 200;

// VARIABLES
Stepper myStepper(STEPS_PER_REVOLUTION, 5, 4, 3, 2);
int sensorVal;

void setup() {Serial.begin(9600);}

void loop() {
  int sensorVal = analogRead(X_PIN);

  myStepper.setSpeed(map(sensorVal, 0, 1023, 0, 100));
  myStepper.step(1);

  Serial.println(sensorVal);
}
