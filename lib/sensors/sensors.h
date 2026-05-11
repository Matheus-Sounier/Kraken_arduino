// sensors.h
#include <Arduino.h>
#include <pins.h>

#ifndef SENSORS_H
#define SENSORS_H

// Último erro válido — usado pelo PID quando perde a linha
extern int erroAnterior;

void sensorsSetup();   // configura os pinos como INPUT
int  lerErro();        // retorna o erro: -2, -1, 0, +1, +2
bool todosBranco();    // true = todos leram branco (linha tracejada)
bool todosPreto();     // true = todos leram preto  (cruzamento 90°)

#endif