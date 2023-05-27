#include <stdio.h>
#include <SoftwareSerial.h>
#include "DRA818.h"

#define PD      10  // to the DRA818 PD pin
#define RX      3   // arduino serial RX pin to the DRA818 TX pin
#define TX      4   // arduino serial TX pin to the DRA818 RX pin
SoftwareSerial dra_serial(3,4); // Serial connection to DRA818
//DRA818 *dra;                // the DRA object once instanciated
float freq;                 // the next frequency to scan

void setup() {
  // put your setup code here, to run once:
   Serial.begin(9600); // for logging
   //pinMode( RX , INPUT);
    //pinMode(TX, OUTPUT);
  
  Serial.print("initializing DRA818 ... ");
  
  
  dra_serial.begin(9600);
  dra_serial.listen();
    Serial.print("sending... ");
  dra_serial.write("AT+DMOCONNECT\r\n");
  Serial.println(dra_serial.available());

  while (dra_serial.available()==0);
  //Serial.println("waiting");
   Serial.println(dra_serial.read());


 

}

void loop() {
  // put your main code here, to run repeatedly:

 // if (dra_serial.isListening()) { 
  //      Serial.println("portOne is listening!");
  //  }

}
