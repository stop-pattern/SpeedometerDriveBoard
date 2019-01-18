#pragma once

/*-----Define_default_Value-----*/
//esp32_default
#define IO0 0
#define EN 3
#define DAC_0 25
#define DAC_1 26

/*-----Board_Setup-----*/

//default_pin_assign
#define LED 22

//ShiftRegister_serial
#define SER 12
#define RCK 27
#define G 14
#define SCL 32
#define SCK 33

//DigitalAnalogConvertor_SPI
#define SCK 30
#define MISO 19
#define MOSI 23
#define SS 5


/*-----sumple_sckech-----*/
int latchPin = 32; // SRCLK
int clockPin = 27; // RCLK
int dataPin = 12; // SER
int patternLength = 50;
/*
String patterns[] = {
  "000000000000000000000000000000000000000000000000",
  "100000000000000000000000000000000000000000000000",
  "010000000000000000000000000000000000000000000000",
  "001000000000000000000000000000000000000000000000",
  "000100000000000000000000000000000000000000000000",
  "000010000000000000000000000000000000000000000000",
  "000001000000000000000000000000000000000000000000",
  "000000100000000000000000000000000000000000000000",
  "000000010000000000000000000000000000000000000000",
  "000000001000000000000000000000000000000000000000",
  "000000000100000000000000000000000000000000000000",
  "000000000010000000000000000000000000000000000000",
  "000000000001000000000000000000000000000000000000",
  "000000000000100000000000000000000000000000000000",
  "000000000000010000000000000000000000000000000000",
  "000000000000001000000000000000000000000000000000",
  "000000000000000100000000000000000000000000000000",
  "000000000000000010000000000000000000000000000000",
  "000000000000000001000000000000000000000000000000",
  "000000000000000000100000000000000000000000000000",
  "000000000000000000010000000000000000000000000000",
  "000000000000000000001000000000000000000000000000",
  "000000000000000000000100000000000000000000000000",
  "000000000000000000000010000000000000000000000000",
  "000000000000000000000001000000000000000000000000",
  "000000000000000000000000100000000000000000000000",
  "000000000000000000000000010000000000000000000000",
  "000000000000000000000000001000000000000000000000",
  "000000000000000000000000000100000000000000000000",
  "000000000000000000000000000010000000000000000000",
  "000000000000000000000000000001000000000000000000",
  "000000000000000000000000000000100000000000000000",
  "000000000000000000000000000000010000000000000000",
  "000000000000000000000000000000001000000000000000",
  "000000000000000000000000000000000100000000000000",
  "000000000000000000000000000000000010000000000000",
  "000000000000000000000000000000000001000000000000",
  "000000000000000000000000000000000000100000000000",
  "000000000000000000000000000000000000010000000000",
  "000000000000000000000000000000000000001000000000",
  "000000000000000000000000000000000000000100000000",
  "000000000000000000000000000000000000000010000000",
  "000000000000000000000000000000000000000001000000",
  "000000000000000000000000000000000000000000100000",
  "000000000000000000000000000000000000000000010000",
  "000000000000000000000000000000000000000000001000",
  "000000000000000000000000000000000000000000000100",
  "000000000000000000000000000000000000000000000010",
  "000000000000000000000000000000000000000000000001",
  "111111111111111111111111111111111111111111111111"
};
*/
