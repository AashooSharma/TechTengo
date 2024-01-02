# Clap Switch with Arduino

## Table Of Contents

1. [Introduction](#introduction)
2. [Project Overview](#project-overview)
3. [Components Required](#components-required)
4. [Circuit Diagram](#circuit-diagram)
5. [Arduino Sketch](#arduino-sketch)
   - [Source Code Explanation](#source-code-explanation)
6. [Working Principle](#working-principle)
7. [Conclusion](#conclusion)
8. [Future Enhancements](#future-enhancements)

## Introduction
The "Clap Switch with Arduino" project allows you to control an LED by clapping your hands. This is achieved by using a sound sensor connected to an Arduino board, making it a fun and interactive way to explore sound-based control systems.

## Project Overview
In this project, a sound sensor is employed to detect clapping sounds. When a clap is detected, the Arduino triggers an LED to turn on or off. This concept can be extended to control other electronic devices based on sound inputs.

## Components Required
To build this project, you will need the following components:
- Arduino board (e.g., Arduino Uno)
- Sound sensor module
- LED
- Resistor (around 220Ω)
- Jumper wires

## Circuit Diagram
![Circuit Diagram](https://your-image-link-here)

## Arduino Sketch
```arduino
int sensor_pin = 9;
int led = 13;
int val = 0;
int new_val = 0;

void setup() {
  pinMode(sensor_pin, INPUT);
  pinMode(led, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int new_val = digitalRead(sensor_pin);
  Serial.println(new_val);

  if (new_val == 1) {
    if (val == 0) {
      val = 1;
      digitalWrite(led, HIGH);
      delay(2000);
    } else {
      val = 0;
      digitalWrite(led, LOW);
      delay(2000);
    }
  }
}
```

### Source Code Explanation
- **`sensor_pin`**: The pin to which the sound sensor is connected.
- **`led`**: The pin to which the LED is connected.
- **`val` and `new_val`**: Variables to store the previous and current states of the sound sensor.
- **`setup()`**: Initializes the pins for input and output and starts serial communication for debugging.
- **`loop()`**: Checks for changes in the sound sensor's state. If a clap is detected, it toggles the LED.

## Working Principle
The sound sensor detects changes in sound intensity. When a clap is detected, the Arduino interprets this change and toggles the LED. This project illustrates a simple form of sound-controlled interaction.

## Conclusion
The "Clap Switch with Arduino" is a hands-on project that introduces the concept of sound-based control. It's a great starting point for exploring more advanced sound recognition and automation systems.

## Future Enhancements
Consider these enhancements to extend the project:
- Adjust sensitivity for different sound levels.
- Implement multi-clap patterns for different actions.
- Connect additional output devices for a more comprehensive sound-controlled system.
