/*
  ACS712.cpp - Library for using ACS712 Hall Effect-Based Linear Current Sensor IC.
  Created by Sakib Ahmed Sumdany, November 8, 2016.
  based on a tutorial found here http://henrysbench.capnfatz.com/henrys-bench/arduino-current-measurements/acs712-arduino-ac-current-tutorial/
  Released into the public domain.
*/

#include "Arduino.h"
#include "ACS712.h"

ACS712::ACS712()
{
  _pin = A0;
  sensorIn = _pin;
  mVperAmp = 66; // use 100 for 20A Module and 66 for 30A Module
  
  
  Voltage = 0;
  VRMS = 0;
  AmpsRMS = 0;

}

ACS712::ACS712(int pin)
{
  _pin = pin;
  sensorIn = _pin;
  mVperAmp = 66; // use 100 for 20A Module and 66 for 30A Module
  
  
  Voltage = 0;
  VRMS = 0;
  AmpsRMS = 0;

}
ACS712::ACS712(int pin, float error)
{
  _pin = pin;
  _error=error;
  sensorIn = _pin;
  mVperAmp = 66; // use 100 for 20A Module and 66 for 30A Module
  
  
  Voltage = 0;
  VRMS = 0;
  AmpsRMS = 0;

}
double ACS712::getACcurrent()
{
   Voltage = getVPP();
   VRMS = (Voltage/2.0) *0.707; 
   AmpsRMS = (VRMS * 1000)/mVperAmp;
   AmpsRMS-=_error;
   if(AmpsRMS<.10) return 0.00f;
   return AmpsRMS;
   
}
void ACS712::getDCcurrent()
{
}

float ACS712::getVPP()
{
  float result;
  
  int readValue;             //value read from the sensor
  int maxValue = 0;          // store max value here
  int minValue = 1024;          // store min value here
  
   uint32_t start_time = millis();
   while((millis()-start_time) < 900) //sample for 1 Sec
   {
       readValue = analogRead(sensorIn);
       // see if you have a new maxValue
       if (readValue > maxValue) 
       {
           /*record the maximum sensor value*/
           maxValue = readValue;
       }
       
       if (readValue < minValue) 
       {
           /*record the maximum sensor value*/
           minValue = readValue;
       }
   }
   
   // Subtract min from max
   result = ((maxValue - minValue) * 5.0)/1024.0;
      
   return result;
 }
  

