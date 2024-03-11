int sensorPin=A0;
int buzzer = 8;
int sensorData;
int relay = 7;
void setup()
{  
  Serial.begin(9600);   
  pinMode(sensorPin,INPUT);                         
  pinMode (buzzer, OUTPUT);
 }
void loop()
{
  sensorData = analogRead(sensorPin);       
  Serial.print("Sensor Data:");
  Serial.println(sensorData);

  if(sensorData >= 400){
    digitalWrite(buzzer, HIGH);
    delay(100);
  } else {
    digitalWrite(buzzer, LOW);
    delay(100);

  }

  delay(1000);                                   
}