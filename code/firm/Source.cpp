#include <arduino.h>
#include "define.h"
#include "BIDS.h"

void ShiftOut(bool senddata[]) {
  long int out = 0;

  for (int i = 0; i < 48; i++) {
    out |= (senddata[i] << i);
  }
  //Serial.println(out, BIN); //debug
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

void GetData(void) {
  SetNeedle();
  //SetSound();
  SetLamp();
}

void SetNeedle(void) {
  Speed = BIDS::DataGet("I", "E", 1);
  ORP = BIDS::DataGet("I", "P", 135) / 10;
  //DAC
  dacWrite(DAC1, Speed / 120 * 255);
  dacWrite(DAC2, ORP / 120 * 255);
}

void SetSound(void) {
  float ATCbell = BIDS::DataGet("I", "S", 2);
  switch (int(ATCbell)) {
    case 1:
      bell = true;
      shiftregister[43] = bell;
      break;
    default:
      bell = false;
      break;
  }
  if (bell == true) {
    shiftregister[43] = bell;
    //ShiftOut(shiftregister);
    //bell = false;
  }
}

void SetLamp(void) {
  int param;

  X = BIDS::DataGet("I", "P", 101);

  if (X == false) {
    R = BIDS::DataGet("I", "P", 131);
    G = BIDS::DataGet("I", "P", 132);
    notice = BIDS::DataGet("I", "P", 133);
    P = BIDS::DataGet("I", "P", 134);
  } else {
    R = false;
    G = false;
    notice = false;
    P = false;
  }
  BL = BIDS::DataGet("I", "P", 161);
  L15 = BIDS::DataGet("I", "P", 42);
  L60 = BIDS::DataGet("I", "P", 43);
  ATS = BIDS::DataGet("I", "P", 44);

  for (int i = 0; i < 25 ; i++) {
    if (indicator[i] == true) {
      param = i;
      break;
    }
  }
  if (BIDS::DataGet("I", "P", param + 102) == true) {
    bell = false;
  } else {
    for (int i = 0; i < 25 ; i++) {
      indicator[i] = BIDS::DataGet("I", "P", i + 102);  //ATC指示値
      if (indicator[i]) {
        for (i = i + 1; i < 25 ; i++) {
          indicator[i] = 0;
        }
        i = 100;
      }
    }
    bell = true;
  }
}

  void SetData(void) {
    for (int i = 0; i < 25; i++) {
      shiftregister[i] = indicator[i];
    }
    //shink
    shiftregister[25] = R;
    shiftregister[26] = G;
    shiftregister[27] = notice;
    shiftregister[28] = P;
    shiftregister[29] = X;
    shiftregister[30] = 0;
    shiftregister[31] = 0;
    shiftregister[32] = 0;
    shiftregister[33] = 0;
    shiftregister[34] = 0;
    shiftregister[35] = 0;
    shiftregister[36] = 0;
    shiftregister[37] = 0;
    shiftregister[38] = 0;
    shiftregister[39] = 0;

    //source
    shiftregister[40] = L15;
    shiftregister[41] = L60;
    shiftregister[42] = ATS;
    shiftregister[43] = bell;
    shiftregister[44] = 0;//BL;
    shiftregister[45] = 0;
    shiftregister[46] = 0;
    shiftregister[47] = 0;

    ShiftOut(shiftregister);
    bell = false;
  }


  void demo(void) {
    /*
      double B = 255, R = 255;
      while (true) {
        if(analogRead(IO0) == HIGH) break;
        for (int i = 0 ; i < 8; i++) {
        shiftOut(SER, SCK, MSBFIRST, 0b11111111);
        }
        digitalWrite(RCK, LOW);
        digitalWrite(RCK, HIGH);
        dacWrite(DAC1,B);
        dacWrite(DAC2,R);
      }*/
  }
