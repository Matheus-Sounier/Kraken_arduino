#ifndef PID_H
#define PID_H

#include "Arduino.h"
#include "engine.h"

extern float Kp;   
extern float Ki;   
extern float Kd;   

extern int baseSpeed;

void pidSetup();

void pidCalculate(float error);

#endif