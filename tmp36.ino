void setup() {
  Serial.begin(9600);
  pinMode(A0, INPUT);
}

void loop() {
  int tmp = analogRead(A0);
  float volt = (tmp * 5.0)/1024;
  float milliVolt = volt * 1000;
  float tempC = (milliVolt - 500)/10;

  Serial.print(tempC);
  Serial.println(" Celcius");
  delay(1000);
}
