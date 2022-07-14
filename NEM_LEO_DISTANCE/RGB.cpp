/*
  RGB.h - Library for wraping the functions controling the RGB led
  Author - Konstantinos Papageorgiou kp at rei.gr 2022
*/

#include "Arduino.h"
#include "RGB.h" 
#include "Context.h"

RGB::RGB(byte pin){}

void RGB::setup(Context &_context){
  context = &_context;
  pinMode(9 , OUTPUT); // red
  pinMode(10, OUTPUT); // green
  pinMode(11, OUTPUT); // blue
  apply();
}

void RGB::apply(){
  analogWrite(9 , R[context->color]);
  analogWrite(10, G[context->color]);
  analogWrite(11, B[context->color]);
}
