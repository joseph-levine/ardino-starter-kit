#include <Arduino.h>
const int GREEN_LED_PIN = 9;
const int RED_LED_PIN = 10;
const int BLUE_LED_PIN = 11;

const int RED_SENSOR_PIN = A0;
const int GREEN_SENSOR_PIN = A1;
const int BLUE_SENSOR_PIN = A2;

const int ANALOG_READ_DELAY = 5;

int redSensor = 0;
int greenSensor = 0;
int blueSensor = 0;

void setup() {
  Serial.begin(9600);

  pinMode(GREEN_LED_PIN, OUTPUT);
  pinMode(RED_LED_PIN, OUTPUT);
  pinMode(BLUE_LED_PIN, OUTPUT);
}

void loop() {
  redSensor = analogRead(RED_SENSOR_PIN);
  delay(ANALOG_READ_DELAY);
  greenSensor = analogRead(GREEN_SENSOR_PIN);
  delay(ANALOG_READ_DELAY);
  blueSensor = analogRead(BLUE_SENSOR_PIN);
  delay(ANALOG_READ_DELAY);

  analogWrite(RED_LED_PIN, redSensor / 4);
  analogWrite(GREEN_LED_PIN, greenSensor / 4);
  analogWrite(BLUE_LED_PIN, blueSensor / 4);
}
