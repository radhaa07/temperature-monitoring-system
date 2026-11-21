#include <DHT.h>

#define DHTPIN 2
#define DHTTYPE DHT22
#define LED_PIN 8
#define BUZZER_PIN 9
#define THRESHOLD 35.0   // alert above 35 °C

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  dht.begin();
}

void loop() {
  float temp = dht.readTemperature();

  if (isnan(temp)) {                 // handle failed sensor read
    Serial.println("Sensor read failed");
    delay(2000);
    return;
  }

  Serial.print("Temperature: ");
  Serial.print(temp);
  Serial.println(" C");

  if (temp > THRESHOLD) {
    digitalWrite(LED_PIN, HIGH);
    tone(BUZZER_PIN, 1000);          // 1 kHz alarm
  } else {
    digitalWrite(LED_PIN, LOW);
    noTone(BUZZER_PIN);
  }
  delay(2000);                       // DHT22 reads at most every 2 s
}
