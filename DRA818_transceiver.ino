#include <stdio.h>
#include <SoftwareSerial.h>
#include "DRA818.h"

#define PD      10  // to the DRA818 PD pin
#define RX      3   // arduino serial RX pin to the DRA818 TX pin
#define TX      4   // arduino serial TX pin to the DRA818 RX pin
SoftwareSerial dra_serial(3,4); // Serial connection to DRA818
//DRA818 *dra;                // the DRA object once instanciated
float freq;                 // the next frequency to scan


int  read_response() {
  char ack[3];
  ack[0] = ack[1] = ack[2] = '\0';  // Just to quiet some warnings.

  
  ack[2]=0;
  long start = millis();
  do {
    if (dra_serial.available()) {
      ack[0] = ack[1];
      ack[1] = ack[2];
      ack[2] =dra_serial.read();
      Serial.println("reading");
    }
  } while (ack[2] != 0xa && (millis() - start) <   2000);
 

   return (ack[0] == '0');
}


void setup() {
  // put your setup code here, to run once:
   Serial.begin(9600); // for logging
   //pinMode( RX , INPUT);
    //pinMode(TX, OUTPUT);
  
  Serial.print("initializing DRA818 ... ");
  
  
  dra_serial.begin(9600);
  
    Serial.print("sending... ");
     char i = 3;


  while (i-- > 0) {
   
   Serial.println("trying... ");
  dra_serial.write("AT+DMOCONNECT\r\n");
 Serial.print(read_response());

  }
 dra_serial.write("S+146.520\r\n"); 
 Serial.print(read_response());
dra_serial.write("AT+VERSION\r\n"); 
 Serial.print(read_response());
}

void loop() {
  // put your main code here, to run repeatedly:

 // if (dra_serial.isListening()) { 
  //      Serial.println("portOne is listening!");
  //  }

}
