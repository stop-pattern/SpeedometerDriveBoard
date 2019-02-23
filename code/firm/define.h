#pragma once

#define IO0 0
#define LED 22
#define DAC1 25
#define DAC2 26

#define SER 12
#define RCK  (27)
#define SCK  (33)
#define OE (14)
#define SCL  (32)

void ShiftOut(bool[]);
void GetData(void);
void SetNeedle(void);
void SetSound(void);
void SetLamp(void);
void SetData(void);
void demo(void);
