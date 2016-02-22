/*
Written by Steve Lovejoy aka lovejoy777
This code is for the use with  rf receiver relays
to be controlled by ethernet/rf base station.
*/

#include <RCSwitch.h>

#define relay1 5 // define pin 5 for relay1

RCSwitch mySwitch = RCSwitch();

void setup() {
  Serial.begin(9600);
  pinMode(relay1, OUTPUT);
  pinMode(7, OUTPUT); // 5v power for relay
  digitalWrite(7, HIGH);
  mySwitch.enableReceive(0);  // Receiver on interrupt 0 => that is pin #2
}

void loop() {
  if (mySwitch.available()) {
    
    int value = mySwitch.getReceivedValue();
    
    if (value == 0) {
      Serial.print("No Data");
    } else {
     // Serial.print("Received ");
     if (value == 5392) { // if 5392 is received turn relay1 on
       digitalWrite(relay1,HIGH); // ON
     }
     else if (value == 5393) { // if 5393 is received turn relay1 off
       digitalWrite(relay1,LOW); // OFF
     }
     // Serial.println(value);
    }
    mySwitch.resetAvailable();
  }
}
