#ifndef PINS_H
#define PINS_H

#include <Arduino.h>

#define NUM_SENSORS 5

const uint8_t SENSOR_PINS[NUM_SENSORS] = { A0, A1, A2, A3, A4 };

#define CALIBRATION_TIME_MS 3000
#define CALIBRATION_LED LED_BUILTIN

extern int sensorMin[NUM_SENSORS];
extern int sensorMax[NUM_SENSORS];

#define ENA 5 
#define ENB 6 

#define IN1 8 
#define IN2 9
#define IN3 10
#define IN4 11

#endif