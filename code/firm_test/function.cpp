#include <Arduino.h>
#include "define.h"

void SetPin(void) {
  pinMode(IO0, INPUT);
  pinMode(DAC_0, OUTPUT);
  pinMode(DAC_1, OUTPUT);
  pinMode(LED, OUTPUT);
}
/*
void DACOut(int num, byte ch) {
  //dh = (ch) ? ch : ch;
  //SPI.send(num, ch);
}

void ShiftOut(int num[]) {
  digitalWrite(SCK, HIGH);
  for (int i = 0; i >= 6; i++) {
    shiftOut(SER, RCK, LSBFIRST, num[i]);
  }
  digitalWrite(SCK, LOW);
}
*/
