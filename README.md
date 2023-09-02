# Traffic Light Simulator with Arduino

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
9. [Tags](#tags)

## Introduction
The "Traffic Light Simulator with Arduino" project simulates the operation of a traffic light using an Arduino board. It offers an educational and entertaining way to understand the functioning of traffic lights and control systems.

## Project Overview
In this project, we use three LEDs to represent the standard red, yellow, and green lights of a traffic signal. The Arduino board controls these LEDs to mimic the typical sequence of a traffic light. It's a great way to learn about basic programming and digital control with Arduino.

## Components Required
To build this project, you will need the following components:
- Arduino board (e.g., Arduino Uno)
- Three LEDs (Red, Yellow, and Green)
- Three 220Ω resistors (for the LEDs)
- Jumper wires

## Circuit Diagram
![Circuit Diagram](https://your-image-link-here)

## Arduino Sketch
```arduino
int redPin = 2;
int yellowPin = 3;
int greenPin = 4;

void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(yellowPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
}

void loop() {
  // Red light
  digitalWrite(redPin, HIGH);
  delay(2000);  // 2 seconds
  
  // Yellow light
  digitalWrite(redPin, LOW);
  digitalWrite(yellowPin, HIGH);
  delay(1000);  // 1 second
  
  // Green light
  digitalWrite(yellowPin, LOW);
  digitalWrite(greenPin, HIGH);
  delay(2000);  // 2 seconds
  
  // Yellow light again
  digitalWrite(greenPin, LOW);
  digitalWrite(yellowPin, HIGH);
  delay(1000);  // 1 second
}
```

### Source Code Explanation
The provided Arduino sketch demonstrates how to control three LEDs to simulate the operation of a traffic light.

**1. `int ...Pin = ...;`:**
These lines define the pin numbers for the red, yellow, and green LEDs. Make sure to match these pin numbers with your physical connections.

**2. `void setup()`:**
The `setup()` function sets the specified pins as OUTPUT pins, indicating they will be used to control the LEDs.

**3. `void loop()`:**
The `loop()` function defines the sequence of the traffic light simulation. It turns on each LED in the correct sequence, waits for a specified duration, and then turns it off. This loop continues indefinitely, replicating the operation of a traffic light.

## Working Principle
The traffic light simulator operates by sequentially turning on and off the red, yellow, and green LEDs to mimic the standard behavior of a traffic signal. The defined delays create the timing for each signal phase.

## Conclusion
The "Traffic Light Simulator with Arduino" project is an excellent introduction to programming and control systems. It allows you to visualize and understand how a basic traffic light functions. You can further enhance this project by adding pedestrian signals or incorporating a button for manual control.

## Future Enhancements
Consider the following enhancements to make this project more interesting and educational:
- Pedestrian signal with a separate button control.
- Countdown timers for each signal phase.
- Real-time clock integration to simulate different traffic patterns.

## Tags
Arduino, Traffic Light Simulator, LED Control, Traffic Signal, Control Systems, Educational Project, Traffic Light Sequence
