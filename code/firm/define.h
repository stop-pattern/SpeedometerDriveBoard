#pragma once

#define IO0 0
#define LED 22
#define DAC1 25
#define DAC2 26
#define SW 0

#define SER 12
#define RCK  (27)
#define SCK  (33)
#define OE (14)
#define SCL  (32)

#define MOSI 23
#define MISO 19
#define SCLK 18
#define SS 5

void ShiftOut(bool[]);
void GetData(void);
void SetNeedle(void);
void SetSound(void);
void SetLamp(void);
void SetData(void);
void demo(void);
void interrupt(bool);

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

extern bool isSW;
