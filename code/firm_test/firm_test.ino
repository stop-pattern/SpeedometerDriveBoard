#include "define.h"
#include "function.h"
int ver = 100;

void setup() {
  SetPin();
  digitalWrite(G, LOW);
  digitalWrite(G, HIGH);
  Serial.begin(19200);
  while (!Serial);
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
}





String patterns[] = {
  "0000000110000000",
  "0000001001000000",
  "0000010000100000",
  "0000100000010000",
  "0001000000001000",
  "0010000000000100",
  "0100000000000010",
  "1000000000000001"
};

void loop() {
  int len = sizeof(patterns);

  for (int j = 0; j < patternLength; j++) {
    //通信中は，latchPinをLOWにする
    digitalWrite(latchPin, LOW);
//    shiftOut(dataPin, clockPin, MSBFIRST, patternToChar(patterns[j])); 
    myShiftOut(dataPin, clockPin, patternToChar(patterns[j]), 16); // 標準のshiftOutではクロックが一つ余計に入るため
    //通信が終了したらlatchPinをHIGHにする
    digitalWrite(latchPin, HIGH);
    delay(30);
  }
}

void myShiftOut(int dataPin, int clockPin, long data, int dataLength) {
  for (int i = 0; i < dataLength; i++ ) {
    digitalWrite(dataPin, !!(data & 1L << i));
    digitalWrite(clockPin, HIGH);
    digitalWrite(clockPin, LOW);
  }
}

long patternToChar(String pattern) {
  int result = 0;
  for (int i = 0; i < pattern.length(); i++) {
    char c = pattern.charAt(i);
    if (c == '1') {
      result += 1 << i;
    }
  }
  return result;
}





/*
void loop() {
  int len = sizeof(patterns);

  for (int j = 0; j < patternLength; j++) {
    //通信中は，latchPinをLOWにする
    digitalWrite(latchPin, LOW);
    //    shiftOut(dataPin, clockPin, MSBFIRST, patternToChar(patterns[j]));
    myShiftOut(dataPin, clockPin, patternToChar(patterns[j]), 16); // 標準のshiftOutではクロックが一つ余計に入るため
    //通信が終了したらlatchPinをHIGHにする
    digitalWrite(latchPin, HIGH);
    delay(30);
  }
}

void myShiftOut(int dataPin, int clockPin, long data, int dataLength) {
  for (int i = 0; i < dataLength; i++ ) {
    digitalWrite(dataPin, !!(data & 1L << i));
    digitalWrite(clockPin, HIGH);
    digitalWrite(clockPin, LOW);
  }
}

long patternToChar(String pattern) {
  int result = 0;
  for (int i = 0; i < pattern.length(); i++) {
    char c = pattern.charAt(i);
    if (c == '1') {
      result += 1 << i;
    }
  }
  return result;
}
*/
