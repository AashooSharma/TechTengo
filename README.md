# Security Alarm System using PIR Sensor with Arduino

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
The "Security Alarm System using PIR Sensor with Arduino" is a DIY project that helps to detect human motion in its surroundings and triggers a buzzer to alert for potential security breaches. We will use a PIR (Passive Infrared) sensor to detect human motion, and when motion is detected, the buzzer will be activated to signal the presence of human activity.

## Project Overview
This project aims to create a simple and effective security alarm system using the PIR sensor. The Arduino board reads the state of the PIR sensor and activates the buzzer whenever human motion is detected within its range. It can be used to enhance the security of homes, offices, or any area where human activity needs to be monitored.

## Components Required
To build the Security Alarm System, you will need the following components:
- Arduino Uno board
- PIR sensor module
- Buzzer
- Jumper wires

## Circuit Diagram
![Circuit Diagram](https://github.com/Automatic-lly/IOTs-Robotics-Projects/blob/2ff5657f2a837e772b362fbb438b0f72d4edb3dd/src/circuit-files/Screenshot%202023-07-28%20152929.png)

## Arduino Sketch
```arduino
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
```

### Source Code Explanation
The source code is relatively straightforward. Let's go through it step-by-step.

**1. `const int pirSensorPin = 2;`:**
The `pirSensorPin` variable is set to 2, representing the signal pin of the PIR sensor connected to Digital Pin 2 on the Arduino.

**2. `const int buzzerPin = 12;`:**
The `buzzerPin` variable is set to 12, representing the digital output pin for controlling the buzzer.

**3. `void setup()`:**
The `setup()` function is called when the Arduino board is powered up or reset. It configures the PIR sensor and buzzer pins as input and output, respectively, and initializes the Serial Monitor (optional).

**4. `Serial.begin(9600);`:**
The `Serial.begin()` function is used to initialize the Serial Monitor at a baud rate of 9600 bps for optional debugging.

**5. `void loop()`:**
The `loop()` function is the main execution loop that continuously checks for human motion.

**6. `int pirState = digitalRead(pirSensorPin);`:**
The `digitalRead()` function reads the state of the PIR sensor connected to the `pirSensorPin`.

**7. `if (pirState == HIGH) { ... }`:**
If the PIR sensor state is HIGH (motion detected), the buzzer is turned on.

**8. `digitalWrite(buzzerPin, HIGH);`:**
The `digitalWrite()` function is used to turn on the buzzer (set the `buzzerPin` to HIGH) when human motion is detected.

**9. `Serial.println("Human detected!");`:**
If human motion is detected, this line prints a message "Human detected!" to the Serial Monitor (optional).

**10. `else { ... }`:**
If no human motion is detected, the buzzer is turned off.

**11. `digitalWrite(buzzerPin, LOW);`:**
The `digitalWrite()` function is used to turn off the buzzer (set the `buzzerPin` to LOW) when no human motion is detected.

## Conclusion
Congratulations! You have successfully created a Security Alarm System using the PIR sensor and Arduino. The system can detect human motion and activate the buzzer, alerting for potential security breaches.

## Future Enhancements
To further enhance this project, you can add features such as integrating the alarm system with a security camera, sending notifications to a smartphone or email, or even integrating it with home automation platforms for more comprehensive security monitoring.

Feel free to explore and customize the project to suit your specific security needs and preferences.

**Tags:** IoT, PIR Sensor, Security Alarm System, Arduino, Home Security, DIY Project
