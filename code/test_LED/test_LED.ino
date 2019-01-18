bool stat;
double LED;
String light;

void setup() {
  pinMode(0, INPUT);
  pinMode(22, OUTPUT);
  Serial.begin(74880);  //起動メッセージ文字化け防止
  while (!Serial);
  Serial.println("");
  Serial.println("Connection completed");
}

void loop() {
  stat = false;
  if (analogRead(0) < 2000) {
    if(LED != LOW)stat = true;
    LED = LOW;
    light = "ON";
  } else {
    if(LED != HIGH)stat = true;
    LED = HIGH;
    light = "OFF";
  }
  digitalWrite(22, LED);
  if(stat == true) Serial.println(light);
  delay(1);
}
