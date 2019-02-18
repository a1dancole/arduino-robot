const int ENB = 5, ENA = 6, PIN_1 = 7, PIN_2 = 8, PIN_3 = 9, PIN_4 = 11, HIGH_SPEED = 220, MED_SPEED = 180, LOW_SPEED = 120, TURN_SPEED = 180;

void SetupMotors() {
  pinMode(PIN_1, OUTPUT);
  pinMode(PIN_2, OUTPUT);
  pinMode(PIN_3, OUTPUT);
  pinMode(PIN_4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
}

int GetCalculatedSpeedBasedOnDistanceToObject() {
  int distanceToNearestObject = GetDistanceToNearestObject();
  if (distanceToNearestObject >= 5000) {
    return HIGH_SPEED;
  }
  if (distanceToNearestObject >= 2000 && distanceToNearestObject < 5000) {
    return MED_SPEED;
  }
  return LOW_SPEED;
}

void MoveForward() {
  int moveSpeed = GetCalculatedSpeedBasedOnDistanceToObject();
  Serial.println((String)"Speed is " + moveSpeed);
  Serial.println("Moving forward");
  analogWrite(ENA, moveSpeed);
  analogWrite(ENB, moveSpeed);
  digitalWrite(PIN_1, HIGH);
  digitalWrite(PIN_2, LOW);
  digitalWrite(PIN_3, LOW);
  digitalWrite(PIN_4, HIGH);
  delay(100);
}

void MoveBack() {
  analogWrite(ENA, LOW_SPEED);
  analogWrite(ENB, LOW_SPEED);
  digitalWrite(PIN_1, LOW);
  digitalWrite(PIN_2, HIGH);
  digitalWrite(PIN_3, HIGH);
  digitalWrite(PIN_4, LOW);
  delay(200);
}

void TurnLeft() {
  analogWrite(ENA, TURN_SPEED);
  analogWrite(ENB, TURN_SPEED);
  Serial.println("Turning left");
  digitalWrite(PIN_1, LOW);
  digitalWrite(PIN_2, HIGH);
  digitalWrite(PIN_3, LOW);
  digitalWrite(PIN_4, HIGH);
  delay(400);
}

void TurnRight() {
  analogWrite(ENA, TURN_SPEED);
  analogWrite(ENB, TURN_SPEED);
  Serial.println("Turning right");
  digitalWrite(PIN_1, HIGH);
  digitalWrite(PIN_2, LOW);
  digitalWrite(PIN_3, HIGH);
  digitalWrite(PIN_4, LOW);
  delay(400);
}

void StopMovement() {
  digitalWrite(ENA, LOW);
  digitalWrite(ENB, LOW);
  delay(100);
}
