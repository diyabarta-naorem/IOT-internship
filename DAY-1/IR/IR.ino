int bulb = 13;
int buzzer = 3;
int ir = 9;

void setup(){
  pinMode(ir, INPUT);
  pinMode(bulb, OUTPUT);
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);
}

void loop (){
  if (digitalRead(ir) == HIGH)
  {
    digitalWrite(bulb, HIGH);
    delay(100);
    digitalWrite(bulb, LOW);
    digitalWrite(buzzer, HIGH);
    Serial.println("Ir is detected");
    tone(buzzer, 10, 500);
    
  }
  else 
  {
    digitalWrite(bulb, HIGH);
    delay(700);
    digitalWrite(bulb, LOW);
    digitalWrite(buzzer, HIGH);
    tone(buzzer, 5, 500);
    Serial.println("Ir is not detected");
    
  }
}

