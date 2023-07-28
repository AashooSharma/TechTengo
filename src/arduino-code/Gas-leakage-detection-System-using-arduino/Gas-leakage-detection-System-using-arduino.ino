#define LED_COUNT 5
int ledPins[] = {13, 12, 11, 10, 9};
int buzzerPin = 8;

void setup() {
  Serial.begin(9600);
  for (int i = 0; i < LED_COUNT; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  int sensorValue = analogRead(A0);
  Serial.println(sensorValue);

  int mappedValue = map(sensorValue, 0, 1023, 1, LED_COUNT);
  for (int i = 0; i < LED_COUNT; i++) {
    if (i <= mappedValue) {
      digitalWrite(ledPins[i], HIGH);
    } else {
      digitalWrite(ledPins[i], LOW);
    }
  }

  int buzzerValue = map(sensorValue, 0, 1023, 0, 255);
  analogWrite(buzzerPin, buzzerValue);

  delay(1000);
}