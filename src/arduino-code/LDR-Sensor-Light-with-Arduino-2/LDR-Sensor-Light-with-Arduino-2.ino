const int ldrPin = 8;      // Digital pin connected to LDR
const int ledPin = 13;     // Digital pin connected to LED
const int darkThreshold = HIGH; // Digital value when it's dark

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(ldrPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  int ldrValue = digitalRead(ldrPin);
  Serial.println("LDR Value: " + String(ldrValue));

  if (ldrValue == darkThreshold) {  // LDR value indicates it's dark
    digitalWrite(ledPin, HIGH);  // Turn on the LED
  } else {
    digitalWrite(ledPin, LOW);   // Turn off the LED
  }
  
  delay(1000); // Delay between readings
}
