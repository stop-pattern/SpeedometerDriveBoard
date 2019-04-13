#include "define.h"
#include "BIDS.h"
#include <SPI.h>

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
  pinMode(SW, INPUT);
  pinMode(LED, OUTPUT);
  pinMode(DAC1, OUTPUT);
  pinMode(DAC2, OUTPUT);

  pinMode(SER, OUTPUT);
  pinMode(RCK, OUTPUT);
  pinMode(SCK, OUTPUT);
  pinMode(OE, OUTPUT);
  pinMode(SCL, OUTPUT);

  pinMode(MOSI, OUTPUT);
  pinMode(MISO, OUTPUT);
  pinMode(SCLK, OUTPUT);
  pinMode(SS, OUTPUT);

  attachInterrupt(SW, interrupt, CHANGE); //スイッチ割込み

  cnt = 0;

  digitalWrite(LED, HIGH);
  digitalWrite(SS, HIGH);

  Serial.begin(115200);
  while (!Serial);
  VersionNum = BIDS::VersionCheck(VersionNum);

  SPI.beginTransaction(SPISettings(50000000, MSBFIRST, SPI_MODE1));
  SPI.begin();
  SPI.transfer(0b000000101111111100000000);

  digitalWrite(LED, HIGH);

  digitalWrite(OE, LOW);
  digitalWrite(SCL, HIGH);
}

void loop() {

  GetData();

  SetData();

  if (isSW) {
    if (analogRead(SW) == HIGH) {
      BIDS::DataGet("K", "P", 0);
    } else  {
      BIDS::DataGet("K", "R", 0);
    }
    isSW = false;
  }

  delay(1);
}

//スイッチ割込み
void interrupt(void) {
  isSW = true;
}
