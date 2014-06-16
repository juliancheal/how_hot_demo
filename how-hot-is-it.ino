int temperature = 0;
float voltage = 0;
int reading = 0;
int lastTime = 0;
char howHawt[4];

void setup() {
  Spark.variable("temperature", &temperature, INT);
  pinMode(A7, INPUT);
}

void reportTheData() {
  reading = analogRead(A7);
  voltage = (reading * 3.3)/4095;
  temperature = (voltage - 0.5) * 100;
  sprintf(howHawt, "%d", temperature);
  Spark.publish("geek-hq/temperature", howHawt);
}

void loop() {
  unsigned long now = millis();
  
  if(now-lastTime>5000UL) {
    lastTime = now;
    reportTheData();
  }
}
