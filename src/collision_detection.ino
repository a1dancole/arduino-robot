const int ECHO = A4, TRIG = A5;

int GetDistanceToNearestObject() {
  digitalWrite(TRIG, LOW);
  delayMicroseconds(4);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(4);
  digitalWrite(TRIG, LOW);
  return (int)pulseIn(ECHO, HIGH);
}

boolean ImCloseToAnObject() {
  int distance = GetDistanceToNearestObject();
  Serial.println((String)"Distance from object is " + distance);
  return distance <= 1000;
}

void SetupColisionDetection() {
  pinMode(ECHO, INPUT);
  pinMode(TRIG, OUTPUT);
}
