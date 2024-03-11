const int trigPin = 9;
const int echoPin = 10;
const int buzzer = 3;
const int bulb = 5;

float duration, distance;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(bulb, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = (duration*.0343)/2;
  Serial.print("Distance: ");
  Serial.println(distance);
  delay(500);
  if(distance <= 15)
  {
    digitalWrite(bulb, HIGH);
    digitalWrite(buzzer, HIGH);
  }
  else {
    digitalWrite(bulb, LOW);
    digitalWrite(buzzer, LOW);
  }
}