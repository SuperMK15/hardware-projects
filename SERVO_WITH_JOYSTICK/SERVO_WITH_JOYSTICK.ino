// library includes
#include <LiquidCrystal.h>
#include <Servo.h>

// initializing the LCD
const int rs=12, en=11, d4=5, d5=4, d6=3, d7=2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

// creating the servo
Servo servo;

// CONSTANTS
const int X_PIN = A0;
const int SERVO_PIN = 6;

void setup() {
  lcd.begin(16, 2);
  servo.attach(SERVO_PIN);
}

void loop() {
  int xInput = analogRead(X_PIN);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Position: ");
  lcd.print(xInput);

  servo.write(map(xInput, 0, 1023, 0, 200));

  delay(500);
}
