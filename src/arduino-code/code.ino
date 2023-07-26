const int pirSensorPin = 2;   // PIR sensor signal pin
const int lightPin = 13;      // Digital output pin for the light
const int delayTime = 5000;   // Time in milliseconds for how long the light stays on after no motion is detected

boolean motionDetected = false;  // Variable to store motion detection status
unsigned long lastMotionTime = 0;  // Variable to store the time when motion was last detected

void setup() {
  pinMode(pirSensorPin, INPUT);
  pinMode(lightPin, OUTPUT);
  Serial.begin(9600);  // Initialize serial communication (optional)
}

void loop() {
  checkMotion();  // Call the function to check for motion

  if (motionDetected) {
    digitalWrite(lightPin, HIGH);  // Turn on the light if motion is detected
    lastMotionTime = millis();  // Record the time when motion was detected
    motionDetected = false;  // Reset the motion detection status
  } else {
    // Check if the light should be turned off after the delay time
    if (millis() - lastMotionTime >= delayTime) {
      digitalWrite(lightPin, LOW);  // Turn off the light after the delay
    }
  }
}

void checkMotion() {
  // Read the state of the PIR sensor
  int pirState = digitalRead(pirSensorPin);
  
  // If motion is detected, set the motionDetected variable to true
  if (pirState == HIGH) {
    motionDetected = true;
    Serial.println("Motion detected!");  // Print a message to the serial monitor (optional)
  }
}
