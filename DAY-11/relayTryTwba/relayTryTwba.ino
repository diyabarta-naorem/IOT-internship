#include <ESP8266WiFi.h>

int gas = A0;
// int buzzer = 7;
// int relay = 13;
int relay = D4; 
int buzzer = D0;
int sensorData;
void setup()
{  
  Serial.begin(9600);   
  pinMode(gas,INPUT);                         
  pinMode (buzzer, OUTPUT);
  pinMode (relay, OUTPUT);
 }
void loop()
{
  sensorData = analogRead(gas);       
  Serial.print("Sensor Data:");
  Serial.println(sensorData);
  delay(1000);

  if(sensorData >= 400){
    digitalWrite(buzzer, HIGH);
    // tone(buzzer, 85);
    delay(100);
    digitalWrite(relay, LOW);
  } else {
    digitalWrite(buzzer, LOW);
    delay(100);
    digitalWrite(relay, HIGH);
  }

  delay(1000);                                   
}