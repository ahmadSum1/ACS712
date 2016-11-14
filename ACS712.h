/*
  ACS712.h - Library for using ACS712 Hall Effect-Based Linear Current Sensor IC.
  Created by Sakib Ahmed Sumdany, November 8, 2016.
  based on a tutorial found here: http://henrysbench.capnfatz.com/henrys-bench/arduino-current-measurements/acs712-arduino-ac-current-tutorial/
  Released into the public domain.
*/
#ifndef ACS712_h
#define ACS712_h

#include "Arduino.h"


class ACS712
{
  public:
    ACS712();
    ACS712(int pin);
    ACS712(int pin, float error);
    double getACcurrent();
    void getDCcurrent();
  private:
    int _pin;
    float _error;
    int sensorIn;
    int mVperAmp;
    
    double Voltage;
    double VRMS;
    double AmpsRMS;

    float getVPP();

};

#endif
