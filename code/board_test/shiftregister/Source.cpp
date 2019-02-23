#include <arduino.h>
#include "define.h"

extern bool shiftregister[50];
extern int reg;

void BitShift(bool senddata[]) {
  long int out = 0;

  for (int i = 0; i < 48; i++) {
    out |= (senddata[i] << i);
  }
  ShiftOut(out);
}
void ShiftOut(long int out) {
  if (out != reg) {
    shiftOut(SER, SCK, MSBFIRST, out >> 40);
    shiftOut(SER, SCK, MSBFIRST, out >> 32);
    shiftOut(SER, SCK, MSBFIRST, out >> 24);
    shiftOut(SER, SCK, MSBFIRST, out >> 16);
    shiftOut(SER, SCK, MSBFIRST, out >> 8);
    shiftOut(SER, SCK, MSBFIRST, out >> 0);

    digitalWrite(RCK, LOW);
    digitalWrite(RCK, HIGH);

    reg = out;
  }
}
