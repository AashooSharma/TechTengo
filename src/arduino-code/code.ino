const int ldrSensorPin = A0;  // LDR sensor analog input pin
const int lightPin = 13;      // Digital output pin for the light
const int thresholdValue = 500;  // Adjust this value based on your ambient light conditions

void setup() {
  pinMode(lightPin, OUTPUT);
  Serial.begin(9600);  // Initialize serial communication (optional)
}

void loop() {
  int ldrValue = analogRead(ldrSensorPin);  // Read the analog value from the LDR sensor
  Serial.println(ldrValue);  // Print the LDR value (optional)

  if (ldrValue < thresholdValue) {
    // It's dark, turn on the light
    digitalWrite(lightPin, HIGH);
    Serial.println("Light ON");  // Print a message to the serial monitor (optional)
  } else {
    // It's bright, turn off the light
    digitalWrite(lightPin, LOW);
    Serial.println("Light OFF");  // Print a message to the serial monitor (optional)
  }

  delay(500);  // A short delay to avoid rapid changes in light readings
}
