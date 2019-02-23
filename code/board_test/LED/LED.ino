<<<<<<< HEAD
#define LED 22
#define IO0 0

double light;
String message;

void setup() {
  pinMode(IO0, INPUT);
  pinMode(LED, OUTPUT);
  
  Serial.begin(115200);
  while (!Serial);
  
  Serial.println("");
  Serial.println("Connection completed");
  light = HIGH;
}

void loop() {
  bool stat = false;
  
  if (analogRead(IO0) < 2500) {
    if(light != LOW)stat = true;
  light = LOW;
    message = "ON";
  } else {
    if(light != HIGH)stat = true;
  light = HIGH;
    message = "OFF";
  }
  
  digitalWrite(LED, light);
  
  if(stat == true) Serial.println(message);
  
  delay(1);
}
=======
#define LED 22
#define IO0 0

double light;
String message;

void setup() {
  pinMode(IO0, INPUT);
  pinMode(LED, OUTPUT);
  
  Serial.begin(115200);
  while (!Serial);
  
  Serial.println("");
  Serial.println("Connection completed");
  light = HIGH;
}

void loop() {
  bool stat = false;
  
  if (analogRead(IO0) < 2500) {
    if(light != LOW)stat = true;
  light = LOW;
    message = "ON";
  } else {
    if(light != HIGH)stat = true;
  light = HIGH;
    message = "OFF";
  }
  
  digitalWrite(LED, light);
  
  if(stat == true) Serial.println(message);
  
  delay(1);
}
>>>>>>> acf3d5ac075861e1d6ade95787c2d3ec12d00e4b
