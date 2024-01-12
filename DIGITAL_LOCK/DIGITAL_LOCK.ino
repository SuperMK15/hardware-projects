// library includes
#include <Keypad.h>
#include <LiquidCrystal.h>

const int PASS = 4056;

const byte ROWS = 4;
const byte COLS = 4;
char keys[ROWS][COLS] = {
  {'1','2','3', 'A'},
  {'4','5','6', 'B'},
  {'7','8','9', 'C'},
  {'*','0','#', 'D'}
};
byte rowPins[ROWS] = {13, 12, 11, 10};
byte colPins[COLS] = {9, 8, 7, 6};

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

const int rs=A0, en=A1, d4=5, d5=4, d6=3, d7=2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  lcd.begin(16, 2);
  lcd.print("Enter Passkey:");
  lcd.setCursor(0, 1);

  Serial.begin(9600);
}

int counter=0, acc=0;

void loop() {
  char key = keypad.getKey();
  
  if (key == '*') {
    reset();
  } else if (key == '#') {
    if (acc == PASS) {
      flashMsg("ACCESS GRANTED", 3);

      lcd.setCursor(0, 0);
      lcd.print("ACCESS GRANTED");
      lcd.setCursor(0, 1);
      lcd.print("Press A to LOCK");
      while(key != 'A') { delay(5); key=keypad.getKey(); }
    } else {
      flashMsg("ACCESS DENIED", 2);
      lcd.setCursor(0, 0);
      if(acc<PASS) lcd.print("HIGHER");
      else lcd.print("LOWER");
      delay(1000);
    }
    reset();
  } else if (key >= '0' && key <= '9' && counter<4) {
    acc*=10;
    acc+=(key-'0');
    counter++;
    lcd.print(key);
  }
  
  delay(50);
}

void reset() {
  acc=0, counter=0;
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Enter Passkey:");
  lcd.setCursor(0, 1);
}

void flashMsg(String msg, int n) {
  lcd.clear();
  for(int i = 0; i < n; i++) {
    lcd.setCursor(0, 0);
    lcd.print(msg);
    delay(1000);
    lcd.clear();
    delay(500);
  }
}
