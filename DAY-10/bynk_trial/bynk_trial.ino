/*New blynk app project
   Home Page
*/
#define BLYNK_TEMPLATE_ID "TMPL3_3XS4gPO"
#define BLYNK_TEMPLATE_NAME "Gas sensor"
#define BLYNK_AUTH_TOKEN "H3AwrE31D-IT8Cg1wosxOPH59ZC6HHXU"
// #include <LiquidCrystal_I2C.h>

//Include the library files
#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

int buzzer = D0;
int sensor = A0;
int relay = D3; 
int sensorData;

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "Rickyrick";//Enter your WIFI name
char pass[] = "12345678";//Enter your WIFI password

// char ssid[] = "Test1";//Enter your WIFI name
// char pass[] = "123456789";//Enter your WIFI password

BlynkTimer timer;
int pinValue = 0;

//Get the button value
BLYNK_WRITE(V0) {
  // digitalWrite(A0, param.asInt());
  pinValue = param.asInt();

}
BLYNK_WRITE(V1) {
  digitalWrite(D3, param.asInt());
}

void setup() {
  //Set the LED pin as an output pin
  pinMode(D0, OUTPUT);
  pinMode(A0, INPUT);
  pinMode(D3, OUTPUT);
  Serial.begin(9600);   

  //Initialize the Blynk library
  Blynk.begin(auth, ssid, pass, "blynk.cloud", 80);
    timer.setInterval(100L, notifiaction);
}

void notifiaction() {
    sensorData = analogRead(sensor); 
      Serial.print("Sensor Data:");
      Serial.println(sensorData);     
      delay(1000); 
  sensorData = map(sensorData, 0, 1024, 0, 100);
  if (pinValue == 1) {
    if (sensor <= 300) {
      // lcd.setCursor(0, 1);
      // lcd.print("Gas value:Normal");
      digitalWrite(buzzer, LOW);

    } else if (sensor > 400) {
      // Blynk.notify("Warning! Gas leak detected");
      // lcd.setCursor(0, 1);
      // lcd.print("Gas value:High  ");
      digitalWrite(buzzer, HIGH);
    }
    // lcd.setCursor(0, 0);
    // lcd.print("Value : ");
    // lcd.print(sensorData);
    Blynk.virtualWrite(V1, sensorData);
    digitalWrite(buzzer, HIGH);
  } else {
    // lcd.clear();
  }
}

void loop() {
  Blynk.run();
  timer.run();
}

//   /*GAS detector security system.
//  * https://srituhobby.com
//  */
 
// #include <LiquidCrystal_I2C.h>
// #define BLYNK_PRINT Serial
// #include <ESP8266WiFi.h>
// #include <BlynkSimpleEsp8266.h>
// LiquidCrystal_I2C lcd(0x27, 16, 2);

// char auth[] = " ";// Enter your Auth token
// char ssid[] = " ";//Enter your WIFI SSIS
// char pass[] = " ";//Enter your WIFI password
// BlynkTimer timer;
// int pinValue = 0;


// void setup() {
//   Serial.begin(9600);
//   lcd.backlight();
//   lcd.init();
//   pinMode(Green, OUTPUT);
//   pinMode(Red, OUTPUT);
//   pinMode(Buzzer, OUTPUT);
//   pinMode(Sensor, INPUT);
//   Blynk.begin(auth, ssid, pass);
//   timer.setInterval(100L, notifiaction);
// }
// BLYNK_WRITE(V0) {
//   pinValue = param.asInt();
// }



// void loop() {
//   Blynk.run();
//   timer.run();
// }





  