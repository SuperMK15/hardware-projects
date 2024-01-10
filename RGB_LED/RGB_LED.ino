// CONSTANTS
const int X_PIN = A0;
const int Y_PIN = A1;
const int KEY_PIN = 8;
const int POTENTIO_1 = A2;
const int POTENTIO_2 = A3;
const int RED_PIN = 6;
const int GREEN_PIN = 5;
const int BLUE_PIN = 3;

void setup() {
  // configure KEY_PIN as INPUT_PULLUP
  pinMode(KEY_PIN, INPUT_PULLUP);
  digitalWrite(KEY_PIN, HIGH);

  // configure baud rate for Serial Monitor
  Serial.begin(9600);

  setColor(0, 0, 255);
}

void loop() {
  // print all relevant values
  int red = map(analogRead(POTENTIO_1), 0, 1023, 0, 255);
  int green = map(analogRead(POTENTIO_2), 0, 1023, 0, 255);
  int blue = map(analogRead(X_PIN), 0, 1023, 0, 255);

  Serial.print(red);
  Serial.print(" ");
  Serial.print(green);
  Serial.print(" ");
  Serial.print(blue);
  Serial.println(" ");

  setColor(red/2, green/2, blue/2);

  delay(500); // delay by 500ms
}

void setColor(int red, int green, int blue) {
  analogWrite(RED_PIN, red);
  analogWrite(GREEN_PIN, green);
  analogWrite(BLUE_PIN, blue);
}
