/*Adicionando display de LCD */
/* Adicionando sensor de temperatura e umidade DHT modelo 11 */
#include "DHT.h"
#include <dht11.h>
#include <LiquidCrystal.h>


dht11 DHT11;

// Configura o display LCD
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  // Configura a velocidade de transmissão da porta serial
  Serial.begin(9600);
  lcd.begin(16, 2);
}

void loop() {
  // Lê a temperatura e a umidade do sensor
  int chk = DHT11.read(7);
  
  // Exibe a temperatura e a umidade no monitor serial
  Serial.print("Temperatura: ");
  Serial.print(DHT11.temperature);
  Serial.print(" °C, Umidade: ");
  Serial.print(DHT11.humidity);
  Serial.println(" %");

  // Exibe a temperatura e a umidade no display LCD
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Temperatura: ");
  lcd.print(DHT11.temperature);
  lcd.print("C");
  lcd.setCursor(0,1);
  lcd.print("Umidade: ");
  lcd.print(DHT11.humidity);
  lcd.print("%");
  
  delay(2000);
}
