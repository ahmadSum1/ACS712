
/*
Measuring AC Current Using ACS712
*/

#include "ACS712.h"

ACS712 ac1(A0);

double current=0;

void setup(){ 
 Serial.begin(9600);
}

void loop(){

 current = ac1.getACcurrent();
 Serial.print(current);
 Serial.println(" Amps RMS");

}

