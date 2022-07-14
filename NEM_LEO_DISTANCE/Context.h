/*
  Context.h - Library for wraping the functions controling the Context / enviroment information
  Author - Konstantinos Papageorgiou kp at rei.gr 2022  
*/

#ifndef Context_h
#define Context_h

#include "Arduino.h" 

class Context{
  public:
    Context(byte pin);
    void setup();
    void apply();
    void reflectSensor(float value, byte precission);
    void setGPSTarget(double LAT, double LNG);

    // Enviroment values
    //-----------------------
    // GPS related
    boolean isGPSLocked = false;
    unsigned long GPSLockTime = 0;
    double latlng[2] = {0, 0}; // gps position
    double TARGET_LAT = 37.9584512; //Akropolis
    double TARGET_LNG = 23.7502464;

    float targets[5] = {0, 0, 0, 0, 0}; // heading target, target gps degree, target gps distance meters, x distance, y distance


    byte color = 0;
    // Invoker variables - execution functions frequencies
    int intervals[5] = {10, 52, 104, 506, 1008};
    unsigned long now = millis();
    unsigned long timers[8] = {now, now, now, now};

  private:
    byte _pin;
};

#endif
