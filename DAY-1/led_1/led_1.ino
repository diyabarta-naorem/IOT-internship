int delay_duration = 300;
int LED_1 = 12;
int LED_2 = 13;
void setup() {
  pinMode(LED_1, OUTPUT);
  pinMode(LED_2, OUTPUT);
}

void loop() {
  digitalWrite(LED_1, HIGH);
  delay(delay_duration);
  digitalWrite(LED_1, LOW);     
  digitalWrite(LED_1, HIGH);
  delay(delay_duration);
  digitalWrite(LED_1, LOW);   

  digitalWrite(LED_2, HIGH);                       
  delay(delay_duration);
  digitalWrite(LED_2, LOW);                       
}