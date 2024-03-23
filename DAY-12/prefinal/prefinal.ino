#define BLYNK_TEMPLATE_ID "TMPL3InVDC1kk"
#define BLYNK_TEMPLATE_NAME "gasSensor"
#define BLYNK_AUTH_TOKEN "lVtOBwim3176gm9TdRucnP5yeZpXWj3P"

//Include the library files
#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

int buzzer = D0;
int sensor = A0;
int relay = D3;
int sensorData;
int sensorThres = 1500;


BlynkTimer timer;
char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "Test1";//Enter your WIFI name
char pass[] = "123456789";//Enter your WIFI password

// //Get the button value
BLYNK_WRITE(V0) {
  digitalWrite(A0, param.asInt());
  int sensorValue= param.asInt();

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
}

  void loop()
  {
    Blynk.run();
    timer.run();

    sensorData = analogRead(sensor); 
    Blynk.virtualWrite(V0, sensorData);
      Serial.print("Sensor Data:");
      Serial.println(sensorData);     
      delay(1000); 

    if(sensorData >= 400){

      digitalWrite(buzzer, HIGH);
      // digitalWrite(relay, LOW);
      // Blynk.email("naoremdiyabarta@gmail.com", "Alert", "Gas Leakage Detected!");
      Blynk.logEvent("gas_alert","Gas Leakage Detected");

      // delay(100);

    } else {
      digitalWrite(buzzer, LOW);
      // digitalWrite(relay, HIGH);
      // delay(5000);
    }
  }





  