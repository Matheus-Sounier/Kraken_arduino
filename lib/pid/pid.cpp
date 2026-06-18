#include "Arduino.h"
#include "pid.h"

float Kp = 18.0;
float Ki = 0.0;
float Kd = 9.0;

int baseSpeed = 130;

static float previousError = 0;
static float integral      = 0;
static float derivative    = 0;

#define INTEGRAL_LIMIT 150.0

void pidSetup() {
  previousError = 0;
  integral      = 0;
  derivative    = 0;
}

void pidCalculate(float error) {
  integral      = constrain(integral + error, -INTEGRAL_LIMIT, INTEGRAL_LIMIT);
  derivative    = error - previousError;
  float pid     = (Kp * error) + (Ki * integral) + (Kd * derivative);
  previousError = error;

  float absError    = fabsf(error); // fabsf = float abs
  float dynamicBase = constrain(baseSpeed - (absError * 0.3f), 80.0f, (float)baseSpeed); // f = float

  float leftSpeed  = constrain(dynamicBase + pid, 30.0f, 220.0f); // f = float
  float rightSpeed = constrain(dynamicBase - pid, 30.0f, 220.0f); // f = float

  engineMove((int)leftSpeed, (int)rightSpeed);
}