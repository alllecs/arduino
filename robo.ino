const int echoPin = 9;
const int trigPin = 8;
const int vccPin = 10;
const int dvig1 = 7;
const int dvig2 = 6;
const int dvig3 = 5;
const int dvig4 = 4;

void setup()
{
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  analogWrite(vccPin, 255);

  pinMode(dvig1, OUTPUT);
  pinMode(dvig2, OUTPUT);
  pinMode(dvig3, OUTPUT);
  pinMode(dvig4, OUTPUT);
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
  if(distance < 50 && distance > 10) {
    digitalWrite(dvig4, LOW);
    digitalWrite(dvig3, LOW);
    digitalWrite(dvig2, LOW);
    digitalWrite(dvig1, HIGH);
  } else if(distance < 10) {
    digitalWrite(dvig1, LOW);
    digitalWrite(dvig2, HIGH);
    digitalWrite(dvig3, LOW);
    digitalWrite(dvig4, HIGH);
    delay(10);
  } else {
    digitalWrite(dvig4, LOW);
    digitalWrite(dvig3, HIGH);
    digitalWrite(dvig2, LOW);
    digitalWrite(dvig1, HIGH);
  }
}
