#include <Keypad.h>

const int LED_PINS[7] = {5, A2, A4, A3, 4, A1, A0};
const int B[10] = {0b1111110, 0b0110000, 0b1101101, 0b1111001, 0b0110011, 0b1011011, 0b1011111, 0b1110000, 0b1111111, 0b1110011};

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

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

void setup(){
  Serial.begin(9600);

  for(int i = 0; i < 7; i++)
    pinMode(LED_PINS[i], OUTPUT);
  
  for(int i = 0; i < 7; i++)
    digitalWrite(LED_PINS[i], LOW);

  Serial.begin(9600);

  for(int i = 0; i < 7; i++) {
    digitalWrite(LED_PINS[i], HIGH);
    delay(200);
    digitalWrite(LED_PINS[i], LOW);
    delay(100);
  }
}
  
void loop(){
  char key = keypad.getKey();
  
  if(key) {
    if(key>='0' && key<='9')
      binaryToDisplay(B[key-'0']);
    else
      binaryToDisplay(0b0000000);
  }
}


void binaryToDisplay(int b) {
  for(int i = 0; i < 7; i++) {
    digitalWrite(LED_PINS[i], bitRead(b, 6-i));
  }
}