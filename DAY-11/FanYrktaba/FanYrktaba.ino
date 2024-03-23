// /*New blynk app project
//    Home Page
// */
// #define BLYNK_TEMPLATE_ID "TMPL3_3XS4gPO"
// #define BLYNK_TEMPLATE_NAME "Gas sensor"
// #define BLYNK_AUTH_TOKEN "H3AwrE31D-IT8Cg1wosxOPH59ZC6HHXU"

// //Include the library files
// #define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
// #include <BlynkSimpleEsp8266.h>

int buzzer = D0;
int sensor = A0;
int relay = D3; 
int sensorData;

// char auth[] = BLYNK_AUTH_TOKEN;
// // char ssid[] = "Rickyrick";//Enter your WIFI name
// // char pass[] = "12345678";//Enter your WIFI password



// // char ssid[] = "Test1";//Enter your WIFI name
// // char pass[] = "123456789";//Enter your WIFI password

// char ssid[] = "Redmi Note 9 Pro Max";//Enter your WIFI name
// char pass[] = "Pink2003";//Enter your WIFI password

// //Get the button value
// BLYNK_WRITE(V0) {
//   digitalWrite(A0, param.asInt());
//   // int sensorValue= param.asInt();

// }
// BLYNK_WRITE(V1) {
//   digitalWrite(D3, param.asInt());
// }

void setup() {
  //Set the LED pin as an output pin
  pinMode(D0, OUTPUT);
  pinMode(A0, INPUT);
  pinMode(D3, OUTPUT);
  Serial.begin(9600);   

  //Initialize the Blynk library
  // Blynk.begin(auth, ssid, pass, "blynk.cloud", 80);
}

  void loop()
  {
    // Blynk.run();
    sensorData = analogRead(sensor); 
      Serial.print("Sensor Data:");
      Serial.println(sensorData);     
      delay(1000); 

    if(sensorData >= 200){
      digitalWrite(buzzer, HIGH);
      // tone(buzzer, 85);
      digitalWrite(relay, HIGH);
      delay(100);

    } else {
      digitalWrite(buzzer, LOW);
      digitalWrite(relay, LOW );
      delay(100);
    }
  
  }





  