#include <stdio.h>
#include <SoftwareSerial.h>


#define PD      10  // to the DRA818 PD pin
#define RX      3   // arduino serial RX pin to the DRA818 TX pin
#define TX      4   // arduino serial TX pin to the DRA818 RX pin
SoftwareSerial dra_serial(3,4); // Serial connection to DRA818
              // the DRA object once instanciated
float freq;                 // the next frequency to scan



void setup() {
  pinMode(PD, OUTPUT);                     // Power control of the DRA818
  digitalWrite(PD,HIGH);  
  // put your setup code here, to run once:
   Serial.begin(9600); // for logging
   //pinMode( RX , INPUT);
    //pinMode(TX, OUTPUT);
  
  Serial.println("initializing DRA818 ... ");
  
  
  dra_serial.begin(9600);
  
    Serial.println("sending... ");
  delay(3000);
  dra_serial.println("AT+DMOCONNECT");
  
 Serial.println(dra_serial.readString());
   dra_serial.println("S+146.520");
 Serial.println(dra_serial.readString());
 
   dra_serial.println("AT+SETTAIL=1");
   Serial.println(dra_serial.readString());
  dra_serial.println("AT+DMOSETGROUP=0,146.5200,146.5200,0,4, 0");
   Serial.println(dra_serial.readString());
    
}

void loop() {
 

}
