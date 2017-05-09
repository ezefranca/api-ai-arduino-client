/*
  APIAIArduino.h - Library for flashing APIAIArduino code.
  Created by Ezequiel Franca, May 9, 2017.
  Released into the public domain.
*/

#include "Arduino.h"
#include "APIAIArduino.h"

APIAIArduino::APIAIArduino(int pin)
{
  pinMode(pin, OUTPUT);
  _pin = pin;
}

void APIAIArduino::dot()
{
  digitalWrite(_pin, HIGH);
  delay(250);
  digitalWrite(_pin, LOW);
  delay(250);  
}

void APIAIArduino::dash()
{
  digitalWrite(_pin, HIGH);
  delay(1000);
  digitalWrite(_pin, LOW);
  delay(250);
}

