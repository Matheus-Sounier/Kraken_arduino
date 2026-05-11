#ifndef PID_D
#define PID_D

#include "Arduino.h"
#include "engine.h"
#include "sensors.h"

extern float Kp;
extern float Ki;
extern float Kd;

extern int baseSpeed;

void pidSetup();
void pidCalculate(int error);

#endif