#define BLYNK_TEMPLATE_ID "TMPL3tlm6BgpQ"
#define BLYNK_TEMPLATE_NAME "gas sensor"
#define BLYNK_AUTH_TOKEN "0Y1Wh84PdSNpu6fDvJBFgKpCFIm9kYG_"

#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

 
char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "Test1";  // type your wifi name
char pass[] = "123456789";  // type your wifi password
int sensor = A0;
int data = 0;
int buzzer = D0;
int sensorThres = 1500;


BlynkTimer timer;

void sendSensor(){
 
 int data = analogRead(sensor);
 Blynk.virtualWrite(V0, data);
  Serial.print("Sensor data: ");
  Serial.println(data);


  if(data <= 400){
    digitalWrite(buzzer, HIGH);
    //Blynk.email("test@gmail.com", "Alert", "Gas Leakage Detected!");
    Blynk.logEvent("gas_alert","Gas Leakage Detected");
  }
}

void setup(){
  pinMode(sensor, INPUT);
   Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);
  //dht.begin();
  timer.setInterval(2500L, sendSensor);
}

void loop(){
  Blynk.run();
  timer.run();
}
