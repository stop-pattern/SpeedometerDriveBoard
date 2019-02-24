#include "define.h"
#include "BIDS.h"

int VersionNum = 100;


/*----------variants---------*/
extern double Speed;
extern double ORP;
extern int indicator[25];
extern int R, G, notice, P, X, BL;
extern int bell;
extern int L15, L60, ATS;
extern int cnt;
extern bool shiftregister[50];
extern int reg;


bool light_on[] = {
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1,
};
bool light_off[] = {
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0,
};

void setup() {
  pinMode(IO0, INPUT);
  pinMode(LED, OUTPUT);
  pinMode(DAC1, OUTPUT);
  pinMode(DAC2, OUTPUT);

  pinMode(SER, OUTPUT);
  pinMode(RCK, OUTPUT);
  pinMode(SCK, OUTPUT);
  pinMode(OE, OUTPUT);
  pinMode(SCL, OUTPUT);

  cnt = 0;

  digitalWrite(LED, HIGH);

  Serial.begin(115200);
  while (!Serial);
  VersionNum = BIDS::VersionCheck(VersionNum);

  digitalWrite(LED, HIGH);

  digitalWrite(OE, LOW);
  digitalWrite(SCL, HIGH);
}

void loop() {

  GetData();

  SetData();

  delayMicroseconds(5);
}
