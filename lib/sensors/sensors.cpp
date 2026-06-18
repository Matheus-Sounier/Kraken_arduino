#include "Arduino.h"
#include "sensors.h"

int sensorMin[NUM_SENSORS];
int sensorMax[NUM_SENSORS];

float previousError = 0;

static int readNormalized(int i) {
  int raw = analogRead(SENSOR_PINS[i]);

  if (sensorMax[i] == sensorMin[i]) return 0;

  int normalized = map(raw, sensorMin[i], sensorMax[i], 0, 100);
  return constrain(normalized, 0, 100);
}

void sensorsSetup() {
  for (int i = 0; i < NUM_SENSORS; i++) {
    pinMode(SENSOR_PINS[i], INPUT);
    sensorMin[i] = 1023;
    sensorMax[i] = 0;
  }

  pinMode(CALIBRATION_LED, OUTPUT);
  unsigned long start = millis();

  while (millis() - start < CALIBRATION_TIME_MS) {
    digitalWrite(CALIBRATION_LED, (millis() / 100) % 2);

    for (int i = 0; i < NUM_SENSORS; i++) {
      int raw = analogRead(SENSOR_PINS[i]);
      if (raw < sensorMin[i]) sensorMin[i] = raw;
      if (raw > sensorMax[i]) sensorMax[i] = raw;
    }
  }

  digitalWrite(CALIBRATION_LED, LOW);
}

bool allWhite() {
  for (int i = 0; i < NUM_SENSORS; i++) {
    if (readNormalized(i) > 20) return false;
  }
  return true;
}

bool allBlack() {
  for (int i = 0; i < NUM_SENSORS; i++) {
    if (readNormalized(i) < 80) return false;
  }
  return true;
}

float getLastError() {
  return previousError;
}

float errorRead() {
  if (allBlack()) return 0;
  if (allWhite()) return previousError;

  const int weights[NUM_SENSORS] = { -200, -100, 0, 100, 200 };

  long weightedSum = 0;
  int  activeSum   = 0;

  for (int i = 0; i < NUM_SENSORS; i++) {
    int val = readNormalized(i);
    weightedSum += (long)val * weights[i];
    activeSum   += val;
  }

  if (activeSum == 0) return previousError;

  float error = (float)(weightedSum / activeSum);

  previousError = error;
  return error;
}