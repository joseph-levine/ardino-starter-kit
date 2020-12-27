#include <Arduino.h>

#ifndef MAX_VOLTS
#define MAX_VOLTS 5.f
#endif

#ifndef SENSOR_TO_VOLTS
#define SENSOR_TO_VOLTS(rawVal) ((float)rawVal / 1024.f) * MAX_VOLTS
#endif

#ifndef SENSOR_TO_TEMP
#define SENSOR_TO_TEMP(rawVal) (SENSOR_TO_VOLTS(rawVal) - .5f) * 100.f
#endif

const int sensorPin = A0;
const float baselineTemp = 20.f;

void printInfo(int sensorVal) {
  Serial.print("Sensor Value: ");
  Serial.print(sensorVal);
  Serial.print(", Volts: ");
  Serial.print(SENSOR_TO_VOLTS(sensorVal));
  Serial.print(", ");
  Serial.print(SENSOR_TO_TEMP(sensorVal));
  Serial.println("˚C");
}

void setup() {
  Serial.begin(9600);
  for (int pinNumber = 2; pinNumber < 5; ++pinNumber) {
    pinMode(pinNumber, OUTPUT);
    digitalWrite(pinNumber, LOW);
  }
}

void loop() {
  int sensorVal = analogRead(sensorPin);
  printInfo(sensorVal);
  int display_level = (int)(SENSOR_TO_TEMP(sensorVal) - baselineTemp);
  for (int pinNumber = 2; pinNumber < 5; ++pinNumber) {
    digitalWrite(pinNumber, display_level > (pinNumber - 1) * 2 ? HIGH : LOW);
  }
  delay(300);
}
