# Heart Pulse Rate Sensor with Arduino

## Table Of Contents
1. [Introduction](#introduction)
2. [Project Overview](#project-overview)
3. [Components Required](#components-required)
4. [Circuit Diagram](#circuit-diagram)
5. [Arduino Sketch](#arduino-sketch)
6. [Source Code Explanation](#source-code-explanation)
7. [Conclusion](#conclusion)
8. [Future Enhancements](#future-enhancements)

## Introduction
The Heart Pulse Rate Sensor with Arduino is a DIY project that allows you to monitor and display your live heart rate (BPM - Beats Per Minute) using the PulseSensor Playground Library. In this post, we will guide you through the process of building this heart rate monitoring system using an Arduino Uno.

## Project Overview
This project displays your real-time BPM in the Arduino Serial Monitor and blinks the built-in LED with each heartbeat. By connecting a pulse sensor module to the Arduino, you can easily measure your heart rate and visualize it in the Serial Monitor.

## Components Required
To build the Heart Pulse Rate Sensor, you will need the following components:
- Arduino Uno board
- Pulse sensor module
- Jumper wires
- Breadboard

## Circuit Diagram
![Circuit Diagram](https://your-image-link-here)

## Arduino Sketch
```arduino
// Getting_BPM_to_Monitor prints the BPM to the Serial Monitor, using the least lines of code and PulseSensor Library.

#define USE_ARDUINO_INTERRUPTS true
#include <PulseSensorPlayground.h>

const int PulseWire = 0; // PulseSensor PURPLE WIRE connected to ANALOG PIN 0
const int LED = 13; // The on-board Arduino LED, close to PIN 13.
int Threshold = 550; // Determine which Signal to "count as a beat" and which to ignore.

PulseSensorPlayground pulseSensor;

void setup() {
  Serial.begin(9600);

  // Configure the PulseSensor object, by assigning our variables to it.
  pulseSensor.analogInput(PulseWire);
  pulseSensor.blinkOnPulse(LED);
  pulseSensor.setThreshold(Threshold);

  if (pulseSensor.begin()) {
    Serial.println("We created a pulseSensor Object !");
  }
}

void loop() {
  if (pulseSensor.sawStartOfBeat()) {
    int myBPM = pulseSensor.getBeatsPerMinute();
    Serial.println("♥️  A HeartBeat Happened !");
    Serial.print("BPM: ");
    Serial.println(myBPM);
  }

  delay(20);
}
```

## Source Code Explanation

**1. `#define USE_ARDUINO_INTERRUPTS true`:**
This line enables low-level interrupts to ensure accurate BPM (Beats Per Minute) calculation.

**2. `#include <PulseSensorPlayground.h>`:**
The PulseSensorPlayground Library is included in the sketch to simplify the heart rate monitoring process.

**3. `const int PulseWire = 0;`:**
The `PulseWire` variable is set to 0, representing the pulse sensor's connection to ANALOG PIN 0 on the Arduino.

**4. `const int LED = 13;`:**
The `LED` variable is set to 13, representing the built-in LED on the Arduino board.

**5. `int Threshold = 550;`:**
The `Threshold` variable determines the signal value to count as a heartbeat and which values to ignore. You can fine-tune this value using the Getting Started Project.

**6. `PulseSensorPlayground pulseSensor;`:**
An instance of the PulseSensorPlayground object called `pulseSensor` is created.

**7. `void setup()`:**
The `setup()` function is called when the Arduino board is powered up or reset. It configures the Serial Monitor, the PulseSensor object, and checks if the pulse sensor is initialized correctly.

**8. `Serial.begin(9600);`:**
The `Serial.begin()` function is used to initialize the Serial Monitor at a baud rate of 9600 bps.

**9. `pulseSensor.analogInput(PulseWire);`:**
The `analogInput()` function assigns the pulse sensor's analog input to the `PulseWire` variable.

**10. `pulseSensor.blinkOnPulse(LED);`:**
The `blinkOnPulse()` function automatically blinks the Arduino's LED with each heartbeat detected.

**11. `pulseSensor.setThreshold(Threshold);`:**
The `setThreshold()` function sets the threshold value for detecting heartbeats.

**12. `if (pulseSensor.begin()) { ... }`:**
This block of code checks if the `pulseSensor` object is initialized correctly. If successful, it prints a message in the Serial Monitor.

**13. `void loop()`:**
The `loop()` function is the main execution loop that continuously runs the heart rate monitoring process.

**14. `if (pulseSensor.sawStartOfBeat()) { ... }`:**
The `sawStartOfBeat()` function constantly tests if a heartbeat occurred.

**15. `int myBPM = pulseSensor.getBeatsPerMinute();`:**
The `getBeatsPerMinute()` function returns the BPM value as an integer and stores it in the `myBPM` variable.

**16. `Serial.println("♥️  A HeartBeat Happened !");`:**
If a heartbeat is detected, this line prints the message "A HeartBeat Happened !" in the Serial Monitor.

**17. `Serial.print("BPM: ");`:**
This line prints the phrase "BPM: " in the Serial Monitor.

**18. `Serial.println(myBPM);`:**
This line prints the BPM value inside the `myBPM` variable in the Serial Monitor.

**19. `delay(20);`:**
A small delay of 20 milliseconds is added to the loop to ensure accurate BPM calculations and prevent unnecessary processing.

## Conclusion
Congratulations! You have successfully created a Heart Pulse Rate Sensor using Arduino. The system displays your live BPM and blinks the built-in LED with each heartbeat.

## Future Enhancements
There are several possibilities for enhancing this project. You could integrate it into a health monitoring system, add an LCD display to visualize the heart rate, or even create a data logging system to store and analyze heart rate data.

Feel free to explore further and customize the project according to your preferences and requirements.

**Tags:** IoT, Pulse Sensor, Heart Rate Monitor, Arduino, Health Monitoring, DIY Project
