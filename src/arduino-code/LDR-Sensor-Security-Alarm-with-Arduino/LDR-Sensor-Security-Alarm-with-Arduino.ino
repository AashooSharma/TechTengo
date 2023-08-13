const int ldrPin = 8;       // Digital pin connected to LDR
const int buzzerPin = 9;    // Digital pin connected to the buzzer
const int laserPin = 7;     // Digital pin connected to the laser module
const int threshold = 500;  // Threshold value to trigger the alarm

void setup() {
  pinMode(buzzerPin, OUTPUT);
  pinMode(laserPin, OUTPUT);
  pinMode(ldrPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  setupLaser();
  int ldrValue = digitalRead(ldrPin);
  Serial.println("LDR Value: " + String(ldrValue));

  if (ldrValue == HIGH) {  // LDR will be HIGH when laser is interrupted
    activateAlarm();
  } else {
    deactivateAlarm();
  }
  
  delay(1000); // Delay between readings
}

void activateAlarm() {
  digitalWrite(buzzerPin, HIGH);
  Serial.println("Intruder detected! Alarm activated.");
}

void deactivateAlarm() {
  digitalWrite(buzzerPin, LOW);
}

void setupLaser() {
  digitalWrite(laserPin, HIGH); // Turn on laser
}

void turnOffLaser() {
  digitalWrite(laserPin, LOW); // Turn off laser
}
