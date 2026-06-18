#include "Arduino.h"
#include "sensors.h"
#include "engine.h"
#include "pid.h"

void setup() {
  Serial.begin(9600);

  engineSetup();
  pidSetup();
  sensorsSetup();

  delay(1000);
}

void loop() {
  int error = errorRead();

  if (allWhite()) {
    engineStop();
    return;
  }

  pidCalculate(error);
}