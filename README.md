# Smart Soil Moisture Monitor with Arduino Uno

## Table Of Contents

1. [Introduction](#introduction)
2. [Project Overview](#project-overview)
3. [Components Required](#components-required)
4. [Circuit Diagram](#circuit-diagram)
5. [Arduino Sketch](#arduino-sketch)
   - [Source Code Explanation](#source-code-explanation)
6. [Conclusion](#conclusion)
7. [Future Enhancements](#future-enhancements)

## Introduction <a name="introduction"></a>

Welcome to our exciting project - the Smart Soil Moisture Monitor with Arduino Uno. In this project, we'll create a smart gardening system that monitors the soil moisture level and provides visual feedback through LEDs. The system utilizes an Arduino Uno, a soil moisture sensor, and simple LED indicators to indicate the moisture level.

## Project Overview <a name="project-overview"></a>

The goal of this project is to develop a soil moisture monitoring system that helps gardeners keep track of their plants' water needs. The system will continuously monitor the soil moisture using a soil moisture sensor connected to an Arduino Uno. Depending on the moisture level, the system will activate specific LEDs to indicate whether the soil is too dry, adequately moist, or too wet.

## Components Required <a name="components-required"></a>

To build the Smart Soil Moisture Monitor system, you'll need the following components:

1. Arduino Uno board
2. Soil moisture sensor module
3. Water pump
4. Jumper wires and breadboard
5. Garden pots or containers for testing

## Circuit Diagram <a name="circuit-diagram"></a>

Below is the circuit diagram for our Smart Soil Moisture Monitor system:

![Circuit Diagram](https://your-image-link-here)

## Arduino Sketch <a name="arduino-sketch"></a>

```arduino
int water; //random variable  
void setup() { 
  pinMode(3, OUTPUT); //output pin for relay board, this will send signal to the relay 
  pinMode(6, INPUT); //input pin coming from the soil sensor 
} 
 
void loop() {  
  water = digitalRead(6);  // reading the coming signal from the soil sensor 
  if (water == HIGH) // if the water level is full then cut the relay  
  { 
    digitalWrite(3, LOW); // low is to cut the relay 
  } 
  else 
  { 
    digitalWrite(3, HIGH); //high to continue providing signal and water supply 
  } 
  delay(400);  
}
```

### Source Code Explanation <a name="source-code-explanation"></a>

The Arduino sketch for the Smart Soil Moisture Monitor is relatively simple. Let's go through the code step by step:

1. We define a variable `water` to store the soil moisture sensor's readings.

2. In the `setup()` function, we set the `pinMode` for pin 3 as OUTPUT, which will control the relay board and pin 6 as INPUT, which will receive the signal from the soil sensor.

3. The `loop()` function continuously reads the signal from the soil moisture sensor using the `digitalRead(6)` function.

4. If the `water` value is `HIGH`, it means the water level is full, and the relay is cut off by setting `digitalWrite(3, LOW)`, thus stopping the water supply.

5. If the `water` value is `LOW`, it means the soil is not fully saturated, and the relay is activated by setting `digitalWrite(3, HIGH)`, allowing water supply to continue.

6. We add a `delay(400)` to avoid rapid switching of the relay, providing some stability to the system.

## Conclusion <a name="conclusion"></a>

Congratulations! You have successfully created a Smart Soil Moisture Monitor using Arduino Uno. This system will help you keep track of your plants' water needs and take appropriate actions to maintain their health.

## Future Enhancements <a name="future-enhancements"></a>

This project can be further enhanced with additional features and functionalities:

1. Implement a real-time clock (RTC) module to log moisture levels at specific intervals.
2. Add a display to show the precise moisture level readings.
3. Integrate the system with a water pump to automate the watering process based on moisture levels.

Feel free to experiment and expand the capabilities of your Smart Soil Moisture Monitor to create a more sophisticated gardening solution.

Happy gardening and happy tinkering!

**Tags:** IoT, Smart Gardening, Soil Moisture Sensor, Arduino Uno, Gardening, Soil Moisture Monitor, DIY Project
