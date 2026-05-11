#include <Arduino.h>
#include <pins.h>

#ifndef SENSORS_H
#define SENSORS_H

extern int erroAnterior;

void sensorsSetup();   
int  lerErro();        
bool todosBranco();    
bool todosPreto();     

#endif