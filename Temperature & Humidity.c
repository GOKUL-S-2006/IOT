#include <dht.h>

dht DHT;

#define DHT11_PIN 7

void setup(){
  Serial.begin(9600);
}

void loop(){
  int chk = DHT.read11(DHT11_PIN);

  float tempC = DHT.temperature;
  float tempF = tempC * 9.0 / 5.0 + 32;

  Serial.print("Temperature = ");
  Serial.print(tempC);
  Serial.print(" °C | ");
  Serial.print(tempF);
  Serial.println(" °F");

  Serial.print("Humidity = ");
  Serial.print(DHT.humidity);
  Serial.println(" %");

  delay(1000);
}
