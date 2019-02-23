<<<<<<< HEAD
#include "define.h"

int VersionNum = 100;

extern bool shiftregister[50];
extern int reg;

bool light[] = {
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1,
};

void setup() {
  pinMode(IO0, INPUT);

  pinMode(SER, OUTPUT);
  pinMode(RCK, OUTPUT);
  pinMode(SCK, OUTPUT);
  pinMode(OE, OUTPUT);
  pinMode(SCL, OUTPUT);

  Serial.begin(115200);
  while (!Serial);

  digitalWrite(OE, LOW);
  digitalWrite(SCL, HIGH);
  BitShift(light);
}

void loop() {
  if (Serial.available()) {
    String GetData = Serial.readStringUntil('\n');
    GetData.replace("\n", "");
    ShiftOut(GetData.toInt());
  }
  Serial.println(Serial.available());
  delay(1);
}
=======
#include "define.h"

int VersionNum = 100;

extern bool shiftregister[50];
extern int reg;

bool light[] = {
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1,
};

void setup() {
  pinMode(IO0, INPUT);

  pinMode(SER, OUTPUT);
  pinMode(RCK, OUTPUT);
  pinMode(SCK, OUTPUT);
  pinMode(OE, OUTPUT);
  pinMode(SCL, OUTPUT);

  Serial.begin(115200);
  while (!Serial);

  digitalWrite(OE, LOW);
  digitalWrite(SCL, HIGH);
  BitShift(light);
}

void loop() {
  if (Serial.available()) {
    String GetData = Serial.readStringUntil('\n');
    GetData.replace("\n", "");
    ShiftOut(GetData.toInt());
  }
  Serial.println(Serial.available());
  delay(1);
}
>>>>>>> acf3d5ac075861e1d6ade95787c2d3ec12d00e4b
