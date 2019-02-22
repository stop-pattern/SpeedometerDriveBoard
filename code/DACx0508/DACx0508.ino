#include <SPI.h>

#define MOSI   (12)
#define MISO   (27)
#define CLOCK  (33)
#define SS     (14)

#define SPI_CLOCK_SPEED 1000000
SPIClass * vspi = NULL;

int SPIsend(int senddata) {

  //通信中
  digitalWrite(SS, LOW);
  vspi->transfer(senddata);
  digitalWrite(SS, HIGH);

  //通信終了
  //vspi->endTransaction();
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

  //通信開始
  vspi->beginTransaction(SPISettings(SPI_CLOCK_SPEED, MSBFIRST, SPI_MODE0));
}

void loop() {
  SPIsend(0b000010001111111111111111);
  SPIsend(0b000010011111111111111111);
  delay(1000);
}
