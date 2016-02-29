/*
Written by Steve Lovejoy aka lovejoy777
This code is for the use with  rf receiver relays
to be controlled by ethernet/rf base station.
*/

#include <RCSwitch.h>
#define relay1 5
RCSwitch mySwitch = RCSwitch();

void setup() {
  Serial.begin(9600);
  pinMode(relay1, OUTPUT);
  pinMode(7, OUTPUT);
  digitalWrite(7, HIGH);
  digitalWrite(5, LOW);
  mySwitch.enableReceive(0);  // Receiver on interrupt 0 => that is pin #2
}

void loop() {
  if (mySwitch.available()) {
    int value = mySwitch.getReceivedValue();
    if (value == 0) {
    } else {
     if (value == 5394) {
       digitalWrite(relay1,LOW); // off
     }
     else if (value == 5395) {
       digitalWrite(relay1,HIGH); // on
     }
    }
    mySwitch.resetAvailable();
  }
}
