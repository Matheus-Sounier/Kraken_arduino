#include "Arduino.h"
#include "pid.h"

float Kp = 20.0;
float Ki = 0.0;
float Kd = 10.0;

int baseSpeed = 150;

static float integral       = 0;
static float derivative     = 0;
static int currentError     = 0;
static int previousErrorPID = 0;

void pidSetup () {
  integral         = 0;
  derivative       = 0;
  currentError     = 0;
  previousErrorPID = 0;
}

void pidCalculate (int error) {
  currentError = error;

  integral = constrain(integral + currentError, -255, 255);

  derivative = currentError - previousErrorPID;

  float pidWithoutLimit = (Kp * currentError) + (Ki * integral) + (Kd * derivative);
  float pidWithLimit = constrain(pidWithoutLimit, -255, 255);

  int leftSpeed = baseSpeed + pidWithLimit;
  int rightSpeed = baseSpeed - pidWithLimit;

  engineMove(leftSpeed, rightSpeed);

  previousErrorPID = currentError;
} 