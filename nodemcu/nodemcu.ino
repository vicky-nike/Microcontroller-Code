#define led D7
#define buz D2
#include "DHT.h"

DHT dht;
#define PIR D5
#define BLYNK_PRINT Serial
#include <BlynkSimpleEsp8266.h>
#include <ESP8266WiFi.h>

int state = 0; 
// Your WiFi credentials.
// Set password to "" for open networks.
char auth[] = "APSPK8naCBCNq5D8wlt6zEIg1X1yMhcq";
char ssid[] = "Sreethi S";
char pass[] = "cyclotron5678";

void setup() {
  // put your setup code here, to run once:
pinMode(led, OUTPUT);
pinMode(buz, OUTPUT);
pinMode(PIR, INPUT);
Serial.begin(9600);
Blynk.begin(auth, ssid, pass);
Blynk.syncAll();
dht.setup(D3); // data pin D3
} 

void loop() {
 Blynk.run();
}

BLYNK_WRITE(V0)
 { int i = param.asInt();
   if( i ==1)
   { digitalWrite(led, HIGH);
   }
  else if( i == 0)
  { digitalWrite(led, LOW);
  }
 }

 BLYNK_READ(V1)
 {// Read temperature as Celsius
  delay(dht.getMinimumSamplingPeriod());
  float temperature = dht.getTemperature();
  Serial.print(dht.getStatusString());
  
  Serial.print("\t\t");
  Serial.print(temperature, 1);
  Serial.print("\t\t");
  Blynk.virtualWrite(V1, temperature);
 }

 BLYNK_READ(V2)
 {float sensor_data2 = digitalRead(PIR);
   if (sensor_data2 == HIGH) {           // check if the sensor is HIGH
    digitalWrite(buz, HIGH);   // turn LED ON
    delay(100);                // delay 100 milliseconds 
    
    if (state == '0') {
      Serial.println("Motion detected!");
      Blynk.virtualWrite(V2, state);
      state = 1;       // update variable state to HIGH
    }
  } 
  else {
      digitalWrite(buz, LOW); // turn LED OFF
      delay(200);             // delay 200 milliseconds 
      
      if (state == HIGH){
        Serial.println("Motion stopped!");
        state = LOW;       // update variable state to LOW
    }
  }
  
 }

 BLYNK_READ(V3)
 {delay(dht.getMinimumSamplingPeriod());
  float humidity = dht.getHumidity();
  Serial.print(dht.getStatusString());
  Serial.print("\t");
  Serial.print(humidity, 1);
  Blynk.virtualWrite(V3, humidity);
 }
