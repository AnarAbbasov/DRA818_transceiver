#include <stdio.h>
#include <SoftwareSerial.h>
#include "DRA818.h"

#define PD      10  // to the DRA818 PD pin
#define RX      3   // arduino serial RX pin to the DRA818 TX pin
#define TX      4   // arduino serial TX pin to the DRA818 RX pin
#define SQ_PIN  12 
SoftwareSerial *dra_serial; // Serial connection to DRA818
DRA818 *dra;                // the DRA object once instanciated
float freq;                 // the next frequency to scan
boolean SQ_ON=false;

void setup() {
  // put your setup code here, to run once:
   Serial.begin(9600); // for logging

  Serial.println("Booting ...");

  Serial.print("initializing I/O ... ");  
  dra_serial = new SoftwareSerial(RX, TX); // Instantiate the Software Serial Object.
  pinMode(PD, OUTPUT);                     // Power control of the DRA818
  pinMode(SQ_PIN, INPUT);     
  digitalWrite(PD,HIGH);                    // start at low power
  Serial.println("done");

  Serial.print("initializing DRA818 ... ");
  /*
   * Configure DRA818V using 145.500 MHz, squelch 4, volume 8, no ctcss, 12.5 kHz bandwidth, all filters activated
   *
   * Alternative call:
   *  dra = new DRA818(dra_serial, DRA818_VHF);
   *  dra->handshake();
   *  dra->group(DRA818_12K5, 145.500, 145.500, 0, 4, 0); SQ
   *  dra->volume(8);
   *  dra->filters(true, true, true);
   */
  dra = DRA818::configure(dra_serial, DRA818_VHF, 145.490, 145.490, 1, 2, 0, 0, DRA818_12K5, true, true, true);
 
  if (!dra) {
    Serial.println("\nError while configuring DRA818");
  }
  freq = DRA818_VHF_MIN;

  Serial.println("done");

  Serial.println("Starting ... ");

}


void loop() {
  // put your main code here, to run repeatedly:
if (digitalRead(SQ_PIN)==HIGH && SQ_ON==false)
   {

     dra = DRA818::configure(dra_serial, DRA818_VHF, 146.520, 146.520, 0, 2, 0, 0, DRA818_12K5, true, true, true);
     SQ_ON=true;
      Serial.println("current freq 146.520");
     
    
   }
   if (digitalRead(SQ_PIN)==LOW &&SQ_ON==true)
    {
   dra = DRA818::configure(dra_serial, DRA818_VHF, 145.490, 145.490, 1, 2, 0, 0, DRA818_12K5, true, true, true);
   SQ_ON=false;
      Serial.println("current freq 145.490");
      }

}
