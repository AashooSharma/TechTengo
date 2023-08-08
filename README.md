# LDR Sensor Light with Arduino

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
The "LDR Sensor Light with Arduino" is a simple project that automatically controls a light source based on the ambient light conditions. We will use an LDR (Light-Dependent Resistor) sensor to detect the surrounding light intensity. When it gets dark, the Arduino will turn on the light, and when it's bright, the Arduino will turn off the light.

## Project Overview
This project demonstrates how an LDR sensor can be used to control a light source automatically. The Arduino reads the analog value from the LDR sensor, and based on a predefined threshold value, it decides whether to turn on or off the light. It can be used for applications like streetlights, automatic night lamps, or any scenario where automatic light control is needed.

## Components Required
To build the LDR Sensor Light, you will need the following components:
- Arduino Uno board
- LDR sensor
- Light source (LED, lamp, etc.)
- Relay module
- Jumper wires

## Circuit Diagram
![Circuit Diagram](src/circuit-files/Screenshot%202023-07-28%20155010.png)

## Arduino Sketch
```arduino
const int ldrSensorPin = A0;  // LDR sensor analog input pin
const int lightPin = 13;      // Digital output pin for the light
const int thresholdValue = 500;  // Adjust this value based on your ambient light conditions

void setup() {
  pinMode(lightPin, OUTPUT);
  Serial.begin(9600);  // Initialize serial communication (optional)
}

void loop() {
  int ldrValue = analogRead(ldrSensorPin);  // Read the analog value from the LDR sensor
  Serial.println(ldrValue);  // Print the LDR value (optional)

  if (ldrValue < thresholdValue) {
    // It's dark, turn on the light
    digitalWrite(lightPin, HIGH);
    Serial.println("Light ON");  // Print a message to the serial monitor (optional)
  } else {
    // It's bright, turn off the light
    digitalWrite(lightPin, LOW);
    Serial.println("Light OFF");  // Print a message to the serial monitor (optional)
  }

  delay(500);  // A short delay to avoid rapid changes in light readings
}
```

### Source Code Explanation
The source code is relatively straightforward. Let's go through it step-by-step.

**1. `const int ldrSensorPin = A0;`:**
The `ldrSensorPin` variable is set to A0, representing the analog input pin connected to the LDR sensor.

**2. `const int lightPin = 13;`:**
The `lightPin` variable is set to 13, representing the digital output pin for controlling the light.

**3. `const int thresholdValue = 500;`:**
The `thresholdValue` variable is used to define the LDR value threshold for determining whether it's dark or bright. You can adjust this value based on your ambient light conditions.

**4. `void setup()`:**
The `setup()` function is called when the Arduino board is powered up or reset. It configures the lightPin as an output and initializes the Serial Monitor (optional).

**5. `Serial.begin(9600);`:**
The `Serial.begin()` function is used to initialize the Serial Monitor at a baud rate of 9600 bps for optional debugging.

**6. `void loop()`:**
The `loop()` function is the main execution loop that continuously reads the LDR sensor value and controls the light.

**7. `int ldrValue = analogRead(ldrSensorPin);`:**
The `analogRead()` function reads the analog value from the LDR sensor connected to the `ldrSensorPin`.

**8. `Serial.println(ldrValue);`:**
This line prints the LDR value to the Serial Monitor (optional) for monitoring the light intensity.

**9. `if (ldrValue < thresholdValue) { ... }`:**
If the LDR value is less than the threshold value (it's dark), the light is turned on.

**10. `digitalWrite(lightPin, HIGH);`:**
The `digitalWrite()` function is used to turn on the light (set the `lightPin` to HIGH) when it's dark.

**11. `else { ... }`:**
If the LDR value is greater than or equal to the threshold value (it's bright), the light is turned off.

**12. `digitalWrite(lightPin, LOW);`:**
The `digitalWrite()` function is used to turn off the light (set the `lightPin` to LOW) when it's bright.

**13. `delay(500);`:**
A short delay of 500 milliseconds is added to avoid rapid changes in light readings.

## Conclusion
Congratulations! You have successfully created an LDR Sensor Light with Arduino. The system automatically controls the light based on the surrounding light conditions.

## Future Enhancements
You can further enhance this project by adding additional features like adjusting the threshold value based on the time of day, integrating it with home automation systems, or implementing more complex light control algorithms for specific applications.

Feel free to explore and customize the project to suit your specific light control requirements.

**Tags:** IoT, LDR Sensor, Automatic Light Control, Arduino, Home Automation, DIY Project
