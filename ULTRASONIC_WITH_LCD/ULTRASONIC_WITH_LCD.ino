// library includes
#include <LiquidCrystal.h>

// initializing the LCD
const int rs=12, en=11, d4=5, d5=4, d6=3, d7=2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

// CONSTANTS
const int TRIG_PIN = 9;
const int ECHO_PIN = 8;

// VARIABLES
float cm;

void setup() {
  lcd.begin(16, 2);

  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
}

void loop() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  cm = pulseIn(ECHO_PIN, HIGH) / 58.0;
  cm = (int (cm*100))/100;

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("DIST: ");
  lcd.print(cm);
  lcd.print("cm");
  
  delay(200);
}
