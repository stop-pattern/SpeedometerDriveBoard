<<<<<<< HEAD
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
  spi->transfer(Data);  //transfer(Data,24);
  ret = spi->transfer(0b000000000000000000000000,24)
  digitalWrite(SS, HIGH);
  return ret;
}

void DACx050x::Write(int Data) {
  DACx050x::Read(Data);
}



    void Init(void){
      
    }
    void Reset (void){
      //DACx050x::Write(0x1010);
    }

    int GetDevice(void){
      String ret;
      int i = 1;
      ret= DACx050x::Read(i);
      return ret.toInt();
    }
    int GetSync(void){
      
    }
    int GetConfig(void){
      
    }
    int GetGain(int, int){
      
    }
    int GetBrdcast(void){
      
    }
    int GetStatus(void){
      
    }
    int GetValue(int, int){
      
    }


    void SetNop(int){
      DACx050x::Read(0b00);
    }
    void SetSync(int, int){
      
    }
    void SetConfig(int, int, int, int, int, int){
      
    }
    void SetGain(int, int){
      
    }
    void SetTrigger(int, int){
      
    }
    void SetBrdcast(int){
      
    }
    void SetStatus(int){
      
    }
    void SetValue(int, int){
      
    }

    void Pwdwn(void){
      
    }
=======
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
  spi->transfer(Data);  //transfer(Data,24);
  ret = spi->transfer(0b000000000000000000000000,24)
  digitalWrite(SS, HIGH);
  return ret;
}

void DACx050x::Write(int Data) {
  DACx050x::Read(Data);
}



    void Init(void){
      
    }
    void Reset (void){
      //DACx050x::Write(0x1010);
    }

    int GetDevice(void){
      String ret;
      int i = 1;
      ret= DACx050x::Read(i);
      return ret.toInt();
    }
    int GetSync(void){
      
    }
    int GetConfig(void){
      
    }
    int GetGain(int, int){
      
    }
    int GetBrdcast(void){
      
    }
    int GetStatus(void){
      
    }
    int GetValue(int, int){
      
    }


    void SetNop(int){
      DACx050x::Read(0b00);
    }
    void SetSync(int, int){
      
    }
    void SetConfig(int, int, int, int, int, int){
      
    }
    void SetGain(int, int){
      
    }
    void SetTrigger(int, int){
      
    }
    void SetBrdcast(int){
      
    }
    void SetStatus(int){
      
    }
    void SetValue(int, int){
      
    }

    void Pwdwn(void){
      
    }
>>>>>>> acf3d5ac075861e1d6ade95787c2d3ec12d00e4b
