
#include <Wire.h>
#include <ESP8266WiFi.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x26, 16, 2);


// unsigned long myChannelNumber = 31461;
// const char * myWriteAPIKey = "LD79EOAAWRVYF04Y";

const int gasSensorPin = A0;
const int alcoholThreshold = 500;  // Adjust this value based on your sensor sensitivity
const int redLed = D4;
const int greenLed = D3;


void setup() {
  Serial.begin(115200);
  pinMode(gasSensorPin, INPUT);
  pinMode(redLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
  digitalWrite(redLed, LOW);
  digitalWrite(greenLed, LOW);
  lcd.init();
  lcd.setCursor(0, 0);
  lcd.backlight();
  lcd.print("Alcohol Level:");
}

void loop() {
  int alcoholLevel = analogRead(gasSensorPin);
  if (alcoholLevel <= alcoholThreshold) {
    digitalWrite(greenLed, HIGH);
    digitalWrite(redLed, LOW);
  } else if (alcoholLevel > alcoholThreshold) {
    digitalWrite(greenLed, LOW);
    digitalWrite(redLed, HIGH);
  }
  long MappedAlcoholLevel = map(alcoholLevel, 0, 1000, 0, 100);
  lcd.setCursor(0, 1);
  lcd.print("        ");
  lcd.setCursor(0, 1);
  lcd.print(MappedAlcoholLevel);
  lcd.print("  %");
  delay(500);
}
