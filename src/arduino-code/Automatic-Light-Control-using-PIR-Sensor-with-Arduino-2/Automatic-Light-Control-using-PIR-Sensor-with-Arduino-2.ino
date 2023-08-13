const int pirSensorPin = 2;   // PIR sensor signal pin
const int ledPin = 13;        // Digital output pin for the LED

void setup() {
  pinMode(pirSensorPin, INPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);  // Initialize serial communication (optional)
}

void loop() {
  int pirState = digitalRead(pirSensorPin);  // Read the state of the PIR sensor

  if (pirState == HIGH) {
    // Motion detected, turn on the LED
    digitalWrite(ledPin, HIGH);
    Serial.println("Motion detected!");  // Print a message to the serial monitor (optional)
  } else {
    // No motion detected, turn off the LED
    digitalWrite(ledPin, LOW);
  }
}
