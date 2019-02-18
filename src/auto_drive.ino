#include <Servo.h>
Servo servo;

void setup() {
  servo.attach(3);  // attach servo on pin 3 to servo object
  Serial.begin(9600);
  SetupColisionDetection();
  SetupMotors();
  StopMovement();
}

void RepositionToAvoidCollision() {
  int randomNumber = random(1,3);
  Serial.println((String)"Random number selected is " + randomNumber);
  switch (randomNumber) {
    case 1:
      while (ImCloseToAnObject() == true) {
        TurnLeft();
      }
      break;
    case 2:
      while (ImCloseToAnObject() == true) {
        TurnRight();
      }
      break;
  }
}

void loop() {
  if (ImCloseToAnObject() == true) {
    RepositionToAvoidCollision();
  } else {
    MoveForward();
  }
  delay(1000);
}
