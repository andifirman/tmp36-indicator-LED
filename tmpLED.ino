int ledMerah = 7;
int ledKuning = 9;
int ledHijau = 13;

void setup(){
  Serial.begin(9600);
  pinMode(ledMerah, OUTPUT);
  pinMode(ledKuning, OUTPUT);
  pinMode(ledHijau, OUTPUT);
  pinMode(A0, INPUT);
}

void loop(){
  int tmp = analogRead(A0); //Membaca nilai awal dari tmp36. Dari nilai ini, nantinya akan dilakukan perhitungan
  float volt = (tmp * 5.0)/1024; //Untuk menghitung perhitungan dari nilai inputan awal tmp36
  float milliVolt = volt * 1000; //Dari volt di atas, dilakukan konversi ke milivolt dengan cara dikalikan dengan 1000
  float tempC = (milliVolt - 500)/10; //Dari data yang didapatkan di atas, maka dilakukan lagi perhitungan agar mendapatkan nilai yang sebenarnya dari Celcius
  
  if(tempC <= 0){
    digitalWrite(ledHijau, HIGH);
    digitalWrite(ledKuning, LOW);
    digitalWrite(ledMerah, LOW);
    Serial.print(tempC);
    Serial.println(" Celcius");
    delay(1000);
  }else if(tempC <= 50){
    digitalWrite(ledHijau, LOW);
    digitalWrite(ledKuning, HIGH);
    digitalWrite(ledMerah, LOW);
    Serial.print(tempC);
    Serial.println(" Celcius");
    delay(1000);
  }else{
    digitalWrite(ledHijau, LOW);
    digitalWrite(ledKuning, LOW);
    digitalWrite(ledMerah, HIGH);
    Serial.print(tempC);
    Serial.println(" Celcius");
    delay(1000);
  }
}
