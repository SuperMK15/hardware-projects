// CONSTANTS
const int BUTTON_PIN = 12;
const int LED_PINS[7] = {6, 5, 2, 3, 4, 7, 8};
const int delayTime = 750;
const int B[10] = {0b1111110, 0b0110000, 0b1101101, 0b1111001, 0b0110011, 0b1011011, 0b1011111, 0b1110000, 0b1111111, 0b1110011};

void setup() {
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  
  for(int i = 0; i < 7; i++)
    pinMode(LED_PINS[i], OUTPUT);
  
  for(int i = 0; i < 7; i++)
    digitalWrite(LED_PINS[i], LOW);

  Serial.begin(9600);

  for(int i = 0; i < 7; i++) {
    digitalWrite(LED_PINS[i], HIGH);
    delay(400);
    digitalWrite(LED_PINS[i], LOW);
    delay(200);
  }
}

void loop() {
  for(int i = 0; i <= 9; i++) {
    do {delay(1); } while(digitalRead(BUTTON_PIN));
    binaryToDisplay(B[i]);
    do {delay(1); } while(!digitalRead(BUTTON_PIN));
  }

  do {delay(1); } while(digitalRead(BUTTON_PIN));
  binaryToDisplay(0b0000000);
  do {delay(1); } while(!digitalRead(BUTTON_PIN));
}

void binaryToDisplay(int b) {
  for(int i = 0; i < 7; i++) {
    digitalWrite(LED_PINS[i], bitRead(b, 6-i));
  }
}