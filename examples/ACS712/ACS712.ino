
/*
Measuring AC Current Using ACS712
put ACS712.cpp and ACS712.h files in the same folder
*/

#include "ACS712.h"

float error=0.05f;
int sensorPin=A0;
ACS712 ac1(sensorPin, error);

double current=0;

void setup(){ 
 Serial.begin(9600);
}

void loop(){

 current = ac1.getACcurrent();
 Serial.print(current);
 Serial.println(" Amps RMS");

}

