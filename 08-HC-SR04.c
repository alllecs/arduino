const int echoPin = 9;
const int trigPin = 8;
const int vccPin = 10;

void setup()
{
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  analogWrite(vccPin, 255);
}

void loop() {
  int time, distance;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  time = pulseIn(echoPin, HIGH);
  distance = time / 58;
  Serial.println(distance);
  delay(1000);
}
