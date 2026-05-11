#include "Arduino.h"
#include "sensors.h"
#include "engine.h"
#include "pid.h"

void setup () {
  Serial.begin(9600);

  sensorsSetup();
  engineSetup();
  pidSetup();

  delay(3000);
}

void loop () {
  int error = errorRead();
  pidCalculate(error);
}