// include the library code:
#include  (LiquidCrystal.h)
int Contrast = 70;
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
void setup() {
  analogWrite(6, Contrast);
  // set up the LCD's number of columns and rows:
  Serial.begin(2400);
  lcd.begin(16, 2);
}
void loop()
{
  lcd.setCursor(0, 0);
  lcd.print("Hello Dosto Welcome!!" );
  delay(3000);
  // print the number of seconds since reset:
  lcd.setCursor(0, 1);
  lcd.print("To my Channel ** ");
  delay(3000);
}