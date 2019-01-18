#include "BIDS.h"
#include "define.h"
int ver = 100;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(19200);
  while(!Serial);
  ver = VersionCheck(ver);
  
}

void loop() {

}
