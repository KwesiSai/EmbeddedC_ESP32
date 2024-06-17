#include <DallasTemperature.h>
#include <OneWire.h>

const int potpin = A0;
const int ledpin = 2;

#define ONE_WIRE_BUS 13
OneWire oneWire(ONE_WIRE_BUS);

// Pass our oneWire reference to Dallas Temperature.
DallasTemperature sensors(&oneWire);

void setup() {
  // put your setup code here, to run once:
  pinMode(ledpin, OUTPUT);
  Serial.begin(115200);
  sensors.begin();

}

void loop() {
  int potentvalue = analogRead(potpin);
  int ecgvalue = map(potentvalue,0,1023,0,255);
  int pulse = map(potentvalue,0,1023,60,100);
  int Spo2 =  map(potentvalue, 0,1023,950,1000)/10;
  
  sensors.requestTemperatures();

  float temperatureC = sensors.getTempCByIndex(0);

  // Check if the reading is valid
  if (temperatureC != DEVICE_DISCONNECTED_C) {
    Serial.print("Temperature: ");
    Serial.print(temperatureC);
    Serial.println(" °C");
  } else {
    Serial.println("Error: Could not read temperature data");
  }

  Serial.println("Your Pulse is: ");
  Serial.print(pulse);
  Serial.println(" ");
  Serial.println("Your blood oxygen is: ");
  Serial.print(Spo2);
  Serial.println(" ");
  Serial.println("Simulated ECG value is :");
  Serial.print(ecgvalue);
  Serial.println(" ");

  analogWrite(ledpin, ecgvalue);

  delay(500);

}
