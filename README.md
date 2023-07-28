# Automatic Light Control using PIR Sensor with Arduino

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
The "Automatic Light Control using PIR Sensor with Arduino" is a simple DIY project that automatically controls the light based on motion detection. We will use a PIR (Passive Infrared) sensor to detect motion, and when motion is detected, the light will be turned on. After a specific delay time without any motion, the light will automatically turn off.

## Project Overview
In this project, we will be using a PIR sensor to detect motion in its surroundings. The Arduino board will process the sensor data and control the light based on motion detection. It offers a convenient and energy-efficient way to automatically turn on the light when someone enters the sensor's range and turn it off after a specific delay when there is no motion.

## Components Required
To build the Automatic Light Control system, you will need the following components:
- Arduino Uno board
- PIR sensor module
- Light (LED or bulb)
- Jumper wires

## Circuit Diagram
![Circuit Diagram](https://github.com/Automatic-lly/IOTs-Robotics-Projects/blob/9021c4cd3758b1d7075545f2fc08f3b80f139206/src/circuit-files/Screenshot%202023-07-28%20161208.png)

## Arduino Sketch
```arduino
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
```

### Source Code Explanation

**1. `const int pirSensorPin = 2;`:**
The `pirSensorPin` variable is set to 2, representing the signal pin of the PIR sensor connected to Digital Pin 2 on the Arduino.

**2. `const int lightPin = 13;`:**
The `lightPin` variable is set to 13, representing the digital output pin for controlling the light (LED or bulb).

**3. `const int delayTime = 5000;`:**
The `delayTime` variable is set to 5000 milliseconds (5 seconds), which determines how long the light stays on after no motion is detected.

**4. `boolean motionDetected = false;`:**
The `motionDetected` variable is a boolean that stores the motion detection status. It is initialized as false.

**5. `unsigned long lastMotionTime = 0;`:**
The `lastMotionTime` variable is of type `unsigned long` and stores the time when motion was last detected. It is initialized as 0.

**6. `void setup()`:**
The `setup()` function is called when the Arduino board is powered up or reset. It configures the PIR sensor and light pins as input and output, respectively, and initializes the Serial Monitor (optional).

**7. `Serial.begin(9600);`:**
The `Serial.begin()` function is used to initialize the Serial Monitor at a baud rate of 9600 bps for optional debugging.

**8. `void loop()`:**
The `loop()` function is the main execution loop that continuously runs the automatic light control process.

**9. `checkMotion();`:**
The `checkMotion()` function is called to check for motion using the PIR sensor.

**10. `if (motionDetected) { ... }`:**
If motion is detected (the `motionDetected` variable is true), the light is turned on, and the `lastMotionTime` variable is updated with the current time.

**11. `digitalWrite(lightPin, HIGH);`:**
The `digitalWrite()` function is used to turn on the light (set the `lightPin` to HIGH) when motion is detected.

**12. `lastMotionTime = millis();`:**
The `millis()` function returns the number of milliseconds since the Arduino board started running. It records the time when motion was last detected.

**13. `motionDetected = false;`:**
After turning on the light, the `motionDetected` variable is reset to false, indicating no motion is currently detected.

**14. `else { ... }`:**
If no motion is detected, this block of code checks if the light should be turned off after the delay time.

**15. `if (millis() - lastMotionTime >= delayTime) { ... }`:**
This line calculates the time difference between the current time and the time when motion was last detected. If the time difference is greater than or equal to the `delayTime`, it means no motion has been detected for the specified delay period.

**16. `digitalWrite(lightPin, LOW);`:**
The `digitalWrite()` function is used to turn off the light (set the `lightPin` to LOW) after the delay time.

**17. `void checkMotion() { ... }`:**
The `checkMotion()` function is responsible for reading the state of the PIR sensor and updating the `motionDetected` variable accordingly.

**18. `int pirState = digitalRead(pirSensorPin);`:**
The `digitalRead()` function reads the state of the PIR sensor connected to the `pirSensorPin`.

**19. `if (pirState == HIGH) { ... }`:**
If the PIR sensor state is HIGH (motion detected), the `motionDetected` variable is set to true, indicating motion is detected.

**20. `Serial.println("Motion detected!");`:**
If motion is detected, this line prints a message "Motion detected!" to the Serial Monitor (optional).

## Conclusion
Congratulations! You have successfully created an Automatic Light Control system using the PIR sensor and Arduino. The light will automatically turn on

 when motion is detected and turn off after a specified delay when no motion is detected.

## Future Enhancements
You can enhance this project further by adding additional features, such as adjusting the delay time, integrating it into a home automation system, or using multiple PIR sensors for more comprehensive coverage.

Feel free to explore and customize the project to suit your specific requirements and preferences.

**Tags:** IoT, PIR Sensor, Automatic Light Control, Arduino, Home Automation, DIY Project
