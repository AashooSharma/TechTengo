#include <SoftwareSerial.h>

SoftwareSerial bluetoothSerial(0, 1); // RX, TX

const int whiteLedPin = 13;
const int yellowLedPin = 12;
const int greenLedPin = 11;
const int blueLedPin = 10;
const int redLedPin = 9;

void setup() {
  Serial.begin(9600);       // Serial monitor for debugging
  bluetoothSerial.begin(9600); // Bluetooth module communication

  pinMode(whiteLedPin, OUTPUT);
  pinMode(yellowLedPin, OUTPUT);
  pinMode(greenLedPin, OUTPUT);
  pinMode(blueLedPin, OUTPUT);
  pinMode(redLedPin, OUTPUT);
  
  // Turn off all LEDs initially
  digitalWrite(whiteLedPin, LOW);
  digitalWrite(yellowLedPin, LOW);
  digitalWrite(greenLedPin, LOW);
  digitalWrite(blueLedPin, LOW);
  digitalWrite(redLedPin, LOW);
}

void loop() {
  if (bluetoothSerial.available()) {
    char receivedChar = bluetoothSerial.read();
    Serial.print("Received: ");
    Serial.println(receivedChar);

    switch (receivedChar) {
      case '1':
        toggleLed(whiteLedPin);
        break;
      case '2':
        toggleLed(yellowLedPin);
        break;
      case '3':
        toggleLed(greenLedPin);
        break;
      case '4':
        toggleLed(blueLedPin);
        break;
      case '5':
        toggleLed(redLedPin);
        break;
      case '6':
        allLeds(true); // Turn on all LEDs
        break;
      case '7':
        allLeds(false); // Turn off all LEDs
        break;
      case '8':
        ledsClockwise(); // Turn on LEDs clockwise
        break;
      case '9':
        ledsAnticlockwise(); // Turn on LEDs anticlockwise
        break;
      case '10':
        danceLeds(); // Simulate dancing LEDs
        break;
      default:
        // Do nothing for unrecognized command
        break;
    }
  }
}

void toggleLed(int ledPin) {
  digitalWrite(ledPin, !digitalRead(ledPin)); // Toggle the LED state
}

void allLeds(bool state) {
  digitalWrite(whiteLedPin, state);
  digitalWrite(yellowLedPin, state);
  digitalWrite(greenLedPin, state);
  digitalWrite(blueLedPin, state);
  digitalWrite(redLedPin, state);
}

void ledsClockwise() {
  for (int i = 0; i < 5; i++) {
    digitalWrite(i + 9, HIGH); // Turn on LED
    delay(300); // Delay for visibility
    digitalWrite(i + 9, LOW);  // Turn off LED
  }
}

void ledsAnticlockwise() {
  for (int i = 4; i >= 0; i--) {
    digitalWrite(i + 9, HIGH); // Turn on LED
    delay(300); // Delay for visibility
    digitalWrite(i + 9, LOW);  // Turn off LED
  }
}

void danceLeds() {
  for (int i = 0; i < 20; i++) {
    randomLeds();
    delay(300);
  }
}

void randomLeds() {
  digitalWrite(whiteLedPin, random(2));
  digitalWrite(yellowLedPin, random(2));
  digitalWrite(greenLedPin, random(2));
  digitalWrite(blueLedPin, random(2));
  digitalWrite(redLedPin, random(2));
}
