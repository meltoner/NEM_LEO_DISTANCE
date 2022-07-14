/*
  Remote.h - Library for wraping the functions Remote control i/o
  Author - Konstantinos Papageorgiou kp at rei.gr 2022
*/

#include "Arduino.h"
#include "Remote.h"
#include <IBusBM.h>

 
#define EXT_SENSORS 10

Remote::Remote(byte pin){
}

void Remote::setup(Context &_context){
  context = &_context;
  IBusSensor.begin(Serial1);
  IBusSensor.addSensor(0x00); // voltage fake - consistency with nem mega uvrc
  IBusSensor.addSensor(0x02); // GPS from home // shown as 3
  //IBusSensor.addSensor(0x14); // GPS degrees from home
  delay(200); 
}

void Remote::apply(){
}

void Remote::telemetry(){
  IBusSensor.setSensorMeasurement(1, 100); 
  IBusSensor.setSensorMeasurement(2, context->targets[2]);
  //IBusSensor.setSensorMeasurement(3, (uint16_t)abs(context->targets[1]));
}
