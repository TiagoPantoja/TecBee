#include <DHT.h>
#include <LiquidCrystal.h>

#define DHTPIN 2
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

#define PIR_PIN 6
#define SOUND_PIN A0

void setup() {
  Serial.begin(9600);
  dht.begin();
  lcd.begin(16, 2);
  pinMode(PIR_PIN, INPUT);
  pinMode(SOUND_PIN, INPUT);
}

void loop() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(t);
  lcd.print((char)223);
  lcd.print("C");

  lcd.setCursor(0, 1);
  lcd.print("Humidity: ");
  lcd.print(h);
  lcd.print("%");

  int presence = digitalRead(PIR_PIN);
  int sound = analogRead(SOUND_PIN);

  Serial.print("Presence: ");
  Serial.println(presence);
  Serial.print("Sound: ");
  Serial.println(sound);

  delay(2000);
}