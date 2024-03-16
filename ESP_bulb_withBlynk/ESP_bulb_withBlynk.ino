/*New blynk app project
   Home Page
*/
#define BLYNK_TEMPLATE_ID "TMPL3vejE5Ify"
#define BLYNK_TEMPLATE_NAME "First Project"
#define BLYNK_AUTH_TOKEN "MFvxfyvJSz-DxqJ5NGfkRFTi6VDJSTdh"

//Include the library files
#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>


char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "Test1";//Enter your WIFI name
char pass[] = "123456789";//Enter your WIFI password

//Get the button value
BLYNK_WRITE(V0) {
  digitalWrite(D0, param.asInt());
}

void setup() {
  //Set the LED pin as an output pin
  pinMode(D0, OUTPUT);
  //Initialize the Blynk library
  Blynk.begin(auth, ssid, pass, "blynk.cloud", 80);
}

void loop() {
  //Run the Blynk library
  Blynk.run();
}