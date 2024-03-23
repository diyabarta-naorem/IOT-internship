#include <LiquidCrystal.h>
  const int rs=12, en=11, d4=5, d5=4, d6=3, d7=2;
  LiquidCrystal lcd(rs,en,d4,d5,d6,d7);
  int Contrast=65;




  int gas = A0;
  int buzzer = 7;
  int relay = 13;
  int sensorData;

  void setup()
  {  
    Serial.begin(9600);   
                                                                
    analogWrite(6,Contrast);
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
      // tone(buzzer, 1000, 100);
      delay(100);
      digitalWrite(relay, LOW);
      lcd.begin(16,2);
      lcd.setCursor(0,0);
      lcd.print("LPG GAS DETECTED");

    } else {
      digitalWrite(buzzer, LOW);
      delay(100);
      digitalWrite(relay, HIGH);
      lcd.begin(16,2);
      lcd.setCursor(0,0);
      lcd.print("NO GAS DETECTED");
 
    }
  }