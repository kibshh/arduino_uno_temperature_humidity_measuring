#include <Arduino.h>
#include <DHT.h>

#define DHTTYPE DHT11 //type (can be DHT11 or DHT22)
#define DHTPIN 2 //which GPIO pin

DHT dht(DHTPIN, DHTTYPE); //constructor

void setup() {
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  delay(1000); //read sensor every second
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();

  if(isnan(temperature) || isnan(humidity))
  {
    Serial.println("DHT sensor communication failed");
    return;
  }
  else
  {
    Serial.print("Temperature: ");
    Serial.print(temperature);
    Serial.print("°C  Humidity: ");
    Serial.print(humidity);
    Serial.println("%");
  }
}


