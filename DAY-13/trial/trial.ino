#define BLYNK_TEMPLATE_ID "TMPL3InVDC1kk"
#define BLYNK_TEMPLATE_NAME "gasSensor"
#define BLYNK_AUTH_TOKEN "lVtOBwim3176gm9TdRucnP5yeZpXWj3P"

#define buzzer D0
#define sensor A0
#define relay D3

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

int sensorThres = 400; // Adjust threshold as needed
bool manualFanControl = false; // Flag for manual fan control

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "Test1"; //Enter your WIFI name
char pass[] = "123456789"; //Enter your WIFI password

BlynkTimer timer;

void checkGasSensor() {
  int sensorData = analogRead(sensor);
  Blynk.virtualWrite(V0, sensorData);

  if (!manualFanControl) {
    if (sensorData <= sensorThres) {
      digitalWrite(buzzer, HIGH);
      Blynk.logEvent("gas_alert", "Gas Leakage Detected");
      digitalWrite(relay, HIGH); // Turn on the fan automatically
    } else {
      digitalWrite(buzzer, LOW);
      digitalWrite(relay, LOW); // Turn off the fan automatically
    }
  }
}

BLYNK_WRITE(V1) {
  int fanState = param.asInt();
  if (fanState == 1) {
    manualFanControl = true; // Enable manual control
    digitalWrite(relay, HIGH); // Turn on the fan
  } else {
    manualFanControl = false; // Disable manual control
    digitalWrite(relay, LOW); // Turn off the fan
  }
}

void setup() {
  pinMode(buzzer, OUTPUT);
  pinMode(sensor, INPUT);
  pinMode(relay, OUTPUT);
  Serial.begin(9600);

  Blynk.begin(auth, ssid, pass, "blynk.cloud", 80);
  timer.setInterval(1000L, checkGasSensor); // Check gas sensor every second
}

void loop() {
  Blynk.run();
  timer.run();
}
