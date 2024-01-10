// library includes
#include <LiquidCrystal.h>
#include <DHT11.h>

// initializing the LCD
const int rs=12, en=11, d4=5, d5=4, d6=3, d7=2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

// setting up the DHT11 sensor
const int DHT11_PIN = 7;
DHT11 dht11(DHT11_PIN);

void setup() {
  lcd.begin(16, 2);
}

void loop() {
  int temperature = dht11.readTemperature();
  delay(50);
  int humidity = dht11.readHumidity();

  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(temperature);
  lcd.print(" C");

  delay(100);

  lcd.setCursor(0, 1);
  lcd.print("Humidity: ");
  lcd.print(humidity);
  lcd.print("%");

  delay(5000);
}