#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// CONSTANTS
const int X_PIN = A0;
const int Y_PIN = A1;
const int KEY_PIN = 7;

// VARIABLES
int xVal, yVal;
bool pressed;

void setup() {
  pinMode(KEY_PIN, INPUT_PULLUP);

  lcd.begin(16, 2);

  lcd.setCursor(0, 0);
  lcd.print("Turning ON...");
  delay(500);

  lcd.setCursor(0, 1);
  lcd.print("Loading.");
  delay(500);
  lcd.setCursor(0, 1);
  lcd.print("Loading..");
  delay(500);
  lcd.setCursor(0, 1);
  lcd.print("Loading...");
  delay(500);
  lcd.setCursor(0, 1);
  lcd.print("Loading....");
  delay(500);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("READY!");
  delay(500);
}

void loop() {
  xVal = analogRead(X_PIN);
  yVal = analogRead(Y_PIN);
  pressed = !digitalRead(KEY_PIN);

  Serial.print(xVal);
  Serial.print(" ");
  Serial.print(yVal);

  lcd.clear();
  lcd.setCursor(0, 0);
  if(pressed) lcd.print("SECRET MESSAGE!!");
  else if(xVal<=20) lcd.print("DOWN");
  else if(xVal>=1000) lcd.print("UP");
  else if(yVal>=1000) lcd.print("RIGHT");
  else if(yVal<=20) lcd.print("LEFT");
  else lcd.print("NOTHING!!");

  lcd.setCursor(0, 1);
  lcd.print("X: ");
  lcd.print(xVal);
  lcd.print(", Y: ");
  lcd.print(yVal);

  delay(500);
}