#include <Arduino.h>

#ifndef SWITCH_PIN
#define SWITCH_PIN 8
#endif
#ifndef FIRST_LED_PIN
#define FIRST_LED_PIN 2
#endif
#ifndef LAST_LED_PIN
#define LAST_LED_PIN 7
#endif
// INTERVAL is 60 seconds
const uint16_t interval = 6000;

unsigned long previousTime = 0;
int previousSwitchState = 0;
uint8_t next_pin_to_light = FIRST_LED_PIN;

void setup() {
  for (int8_t pin = FIRST_LED_PIN; pin <= LAST_LED_PIN; ++pin) {
    pinMode(pin, OUTPUT);
  }
  pinMode(SWITCH_PIN, INPUT);
}

void reset() {
  for (int8_t pin = FIRST_LED_PIN; pin <= LAST_LED_PIN; ++pin) {
    digitalWrite(pin, LOW);
  }
  next_pin_to_light = FIRST_LED_PIN;
}

void loop() {
  unsigned long now = millis();
  if (now - previousTime > interval && next_pin_to_light <= LAST_LED_PIN) {
    previousTime = now;
    digitalWrite(next_pin_to_light, HIGH);
    ++next_pin_to_light;
  }
  int switchState = digitalRead(SWITCH_PIN);
  if (switchState != previousSwitchState) {
    previousTime = now;
    reset();
  }
  previousSwitchState = switchState;
}
