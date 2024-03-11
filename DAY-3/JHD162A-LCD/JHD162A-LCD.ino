#include <LiquidCrystal.h>
const int rs=12, en=11, d4=5, d5=4, d6=3, d7=2;
LiquidCrystal lcd(rs,en,d4,d5,d6,d7);
int Contrast=65;

void setup() 
 {
  analogWrite(6,Contrast);
 }

void loop() 
 {
  lcd.clear();
  lcd.begin(16,2);
  lcd.setCursor(5,0);
  lcd.print("CUBETEN");
  delay(5000);
  lcd.clear();
  lcd.setCursor(1,1);
  lcd.print("INNOVATION HUB");
  delay(5000);
  lcd.clear();
  lcd.setCursor(1,0);
  lcd.print("MANIPUR, IMPHAL");
  delay(5000);
  lcd.clear();
  }
