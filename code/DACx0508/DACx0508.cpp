#include <arduino.h>
#include <SPI.h>
#include "DACx0508.h"

DACx050x::DACx050x(SPIClass * c_spi, int CS) {//, int clockspeed, int bitorder, int spimode) {
  this->spi = &c_spi;
  this->SS = CS;
  //this->spi->beginTransaction(SPISettings(clockspeed, bitorder, spimodev));
}

DACx050x::~DACx050x() {

}

String DACx050x::Read(int Data) {
  String ret;
  digitalWrite(SS, LOW);
  ret = spi->transfer(Data, 24)
        digitalWrite(SS, HIGH);
  return ret;
}

void DACx050x::Write(int Data) {
  DACx050x::Read(Data);
}



void DACx050x::Init(void) {
    this->GetDevice(void);
    this->GetSync(void);
    this->GetConfig(void);
    this->GetGain(int, int);
}
void DACx050x::Reset (void) {
  //DACx050x::Write(0x1010);
}

int DACx050x::GetDevice(void) {
  String ret;
  int i = 1;
  ret = this->Read(i);
  return ret.toInt();
}
int DACx050x::GetSync(void) {

}
int DACx050x::GetConfig(void) {

}
int DACx050x::GetGain(int, int) {

}
int DACx050x::GetGain(void) {
//全スキャン
}
int DACx050x::GetBrdcast(void) {

}
int DACx050x::GetStatus(void) {

}
int DACx050x::GetValue(int, int) {

}


void DACx050x::SetNop(int) {
  this->Read(0b00);
}
void DACx050x::SetSync(int, int) {

}
void DACx050x::SetConfig(int, int, int, int, int, int) {

}
void DACx050x::SetGain(int, int) {

}
void DACx050x::SetTrigger(int, int) {

}
void DACx050x::SetBrdcast(int) {

}
void DACx050x::SetStatus(int) {

}
void DACx050x::SetValue(int, int) {

}

void DACx050x::Pwdwn(void) {

}
