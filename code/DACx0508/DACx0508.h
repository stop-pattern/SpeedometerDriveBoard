#pragma once
#ifndef _DACx050x_
#define _DACx050x_


#include <SPI.h>

class DACx050x {
  public:
    DACx050x(SPIClass *, int);
    ~DACx050x();


    void Init(void);
    void Reset(void);

    int GetDevice(void);
    int GetSync(void);
    int GetConfig(void);
    int GetGain(int, int);
    int GetGain(int, int);
    int GetBrdcast(void);
    int GetStatus(void);
    int GetValue(int, int);

    void SetNop(int);
    void SetSync(int, int);
    void SetConfig(int, int, int, int, int, int);
    void SetGain(int, int);
    void SetTrigger(int, int);
    void SetBrdcast(int);
    void SetStatus(int);
    void SetValue(int, int);

    void Pwdwn(void);

  private:
    int SS; //CS
    int channel;  //number of DAC cannnel
    int gain; //value of DAC gain range
    int divider;  //number of DAC divider
    String Read(int);
    void Write(int);
    SPIClass * spi;
    enum DACmode {
      A,
      B,
    };
};

/*
  #define SPI_CLOCK_SPEED 1000000
  SPIClass * vspi = NULL;

  int SPIsend(int senddata) {
  //通信開始
  vspi->beginTransaction(SPISettings(SPI_CLOCK_SPEED, MSBFIRST, SPI_MODE0));

  //通信中
  digitalWrite(SS, LOW);
  vspi->transfer(senddata);
  digitalWrite(SS, HIGH);

  //通信終了
  vspi->endTransaction();
  }

  void setup()
  {
  //SPIのインスタンス作成
  vspi = new SPIClass(VSPI);
  vspi->begin();

  //pin初期化
  pinMode(SS, OUTPUT);

  //シリアル開始
  Serial.begin(19200);
  while (!Serial); //接続待機

  SPI.begin(CLOCK, MISO, MOSI, SS);
  }

  void loop() {
  SPIsend(0b000010001111111111111111);
  delay(1000);
  }

*/

#endif  //_DACx050x_
