// @author : Konstantinos Papageorgiou - 2022 - kp at rei.gr
// @repo: https://github.com/meltoner/NEM_LEO_DISTANCE
//
// # NEM LEO DISTANCE
// 
// NEM GPS FLYSKY DISTANCE SENSOR on Arduino LEONARDO
// 
// Derives and transmits the distance from home to the flysky remote controler screen using a leonardo arduino
// 
// ## Software Features :
// 
// - Software utilises a GPS, remote control on an arduino Leonardo
// - Sensors and accuators are all in classes
// - Impelements five tasks execution frequencies
// - Auto derive home after 10 seconds since first lock
// - Derives distance and degrees from a target gps LAT LOT
// - Transmits distance and degrees of vehicle from target gps
// - RGB Led indicator - no gps red, gps lock - green, home set - blue
// 
// ## Hardware
// 
// Sensors :
// 
// - Gps : OP gps or Ublox M8N with compass
// - Receiver : flysky F9-ia10b
// 
// Main components : 
// - Transmitter : flysky FS-I6X
// - Receiver : [flysky FS-1A10B](https://www.flysky-cn.com/ia10b-canshu)
// - Arduino Leonaro
// 
// Other: 
// 
// - RGB LED
// - 3 Pin Female connectors, ribbon cable, conectors, board, box, battery, etc


#include "Context.h"
#include "Invoker.h"
#include "Gps.h" 
#include "Remote.h"
#include "RGB.h"

Context context(0);
Invoker invoker(0);

Gps gps(0);
Remote remote(0);
RGB rgb(0);

//-----------------------------------------

void setup() {
  context.setup();
  rgb.setup(context);
  remote.setup(context);
  gps.setup(context);
  invoker.setup(context);
}

void apply_very_fast_invoker(){
}

void apply_fast_invoker(){
}

void apply_invoker(){
  gps.apply();
  rgb.apply();
}

void apply_slow_invoker(){
  context.apply(); // every 0.5 second printout / log enviromental variables
  remote.telemetry();
}


void apply_slower_invoker(){
}

void run_invoker(int i){
    switch(i){
      case 0: apply_very_fast_invoker(); break;
      case 1: apply_fast_invoker(); break;
      case 2: apply_invoker(); break;
      case 3: apply_slow_invoker(); break;
      case 4: apply_slower_invoker(); break;
      case 100: break;
    }
}

void loop(){
  int actionIndex = invoker.apply();
  while(actionIndex != 100){
    run_invoker(actionIndex);
    actionIndex = invoker.apply();
  }
}
