#define IO0 0
#define LED 22

void setup() {
  pinMode(IO0, INPUT);
  pinMode(LED, OUTPUT);
}

void loop() {
  if (IO0 == HIGH) {
    digitalWrite( LED, HIGH);
  }
}
