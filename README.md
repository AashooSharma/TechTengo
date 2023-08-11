# LEDs Control by Voice with Smartphone

## Table Of Contents

1. [Introduction](#introduction)
2. [Project Overview](#project-overview)
3. [Components Required](#components-required)
4. [Circuit Diagram](#circuit-diagram)
5. [Arduino Sketch](#arduino-sketch)
   - [Source Code Explanation](#source-code-explanation)
6. [Conclusion](#conclusion)
7. [Future Enhancements](#future-enhancements)

## Introduction
The "LEDs Control by Voice with Smartphone" project brings together the power of Arduino and Bluetooth communication to create a fun and interactive LED control system. This project enables you to control LEDs using voice commands sent from a smartphone via Bluetooth.

## Project Overview
This project uses Bluetooth communication to receive voice commands from a smartphone and controls a set of LEDs accordingly. By sending specific command codes from a smartphone app, you can toggle individual LEDs, turn on/off all LEDs, create dynamic LED patterns, and even simulate dancing LEDs.

## Components Required
To create the LEDs Control by Voice project, you will need the following components:
- Arduino board (e.g., Arduino Uno)
- HC-05 Bluetooth module
- LEDs (White, Yellow, Green, Blue, Red)
- Resistors (220Ω, for each LED)
- Jumper wires

## Circuit Diagram
![Circuit Diagram](https://your-image-link-here)

## Arduino Sketch
```arduino
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
      // Cases for controlling LEDs based on received commands
      // Implement your own commands here
    }
  }
}

// Other functions for controlling LEDs based on received commands
// Toggle LED, Turn on/off all LEDs, LED patterns, etc.
```

### Source Code Explanation
The source code provided is a foundation for controlling LEDs using voice commands from a smartphone app via Bluetooth.

**1. `SoftwareSerial bluetoothSerial(0, 1);`:**
This line initializes a software serial communication object named `bluetoothSerial` on digital pins 0 (RX) and 1 (TX). This object will handle Bluetooth communication.

**2. `const int ...LedPin = ...;`:**
These lines define the pin numbers for each LED. Adjust these pin numbers based on your circuit connections.

**3. `void setup()`:**
This function initializes serial communication for debugging, initializes the Bluetooth communication, sets LED pins as outputs, and turns off all LEDs.

**4. `void loop()`:**
This loop listens for data available from the Bluetooth module. If data is available, it reads a character and processes it using a `switch` statement.

**5. `switch (receivedChar) { ... }`:**
In this `switch` statement, you can define cases for various voice commands received from the smartphone app. For example, you can create cases to toggle individual LEDs, turn on/off all LEDs, and activate LED patterns.

**6. Other Functions for LED Control:** 
The code provides placeholders for functions that implement specific LED control actions, such as toggling LEDs, turning on/off all LEDs, creating LED patterns, and simulating dancing LEDs. You can customize these functions to suit your desired LED control actions.

## Conclusion
The LEDs Control by Voice with Smartphone project showcases the integration of Arduino and Bluetooth technology for interactive LED control. This project opens up opportunities to create custom voice-controlled applications, making your LED display dynamic and engaging.

## Future Enhancements
As you explore this project further, consider adding more voice commands and creating complex LED patterns. You can integrate additional sensors to trigger LED patterns based on external conditions or expand this concept into a home automation system with voice-controlled lighting.

## Tags
Arduino, Bluetooth, Voice Control, LED Control, Smartphone Integration, Electronics, DIY Project
