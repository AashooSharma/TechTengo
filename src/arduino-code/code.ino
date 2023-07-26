const int pirSensorPin = 2;   // PIR sensor signal pin
const int buzzerPin = 12;    // Digital output pin for the buzzer

void setup() {
  pinMode(pirSensorPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600);  // Initialize serial communication (optional)
}

void loop() {
  int pirState = digitalRead(pirSensorPin);  // Read the state of the PIR sensor

  if (pirState == HIGH) {
    // Human motion detected, turn on the buzzer
    digitalWrite(buzzerPin, HIGH);
    Serial.println("Human detected!");  // Print a message to the serial monitor (optional)
  } else {
    // No human motion detected, turn off the buzzer
    digitalWrite(buzzerPin, LOW);
  }
}
