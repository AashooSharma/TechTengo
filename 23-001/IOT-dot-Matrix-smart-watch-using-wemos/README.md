# IoT Smart Watch with MAX7219 using Wemos D1 R2

## Table Of Contents

1. [Introduction](#introduction)
2. [Working](#working)
3. [Components Required](#components-required)
4. [Circuit Diagram](#circuit-diagram)
5. [Arduino Sketch](#arduino-sketch)
6. [Code Explanation](#code-explanation)
7. [Conclusion](#conclusion)

## Introduction <a name="introduction"></a>

Welcome to our exciting IoT project - the IoT Smart Watch using MAX7219 with Wemos D1 R2. In this project, you'll learn how to create a smart watch that displays real-time clock information on a MAX7219 LED matrix module. We'll use the Wemos D1 R2 board to connect to the internet, fetch the time from an NTP server, and display it on the LED matrix.

## Working <a name="working"></a>

The IoT Smart Watch is a wearable device that fetches the current time from an NTP server using the Wemos D1 R2 board's internet connectivity. The time information is then displayed on a MAX7219 LED matrix module. The project utilizes the MD_Parola library to control the LED matrix and the NTPClient library to fetch the time.

## Components Required <a name="components-required"></a>

Before we dive into the details, let's gather the necessary components for this project:

- Wemos D1 R2 board (or any other ESP8266-based board)
- MAX7219 LED matrix module
- Jumper wires

## Circuit Diagram <a name="circuit-diagram"></a>

![Circuit Diagram](https://your-image-link-here)

## Arduino Sketch <a name="arduino-sketch"></a>

Below is the Arduino sketch required for our IoT Smart Watch project. Please upload this code to your Wemos D1 R2 board using the Arduino IDE:

```arduino
// Paste the Arduino sketch here
```

## Code Explanation <a name="code-explanation"></a>

The provided Arduino code does the following:

1. Defines the required libraries for controlling the MAX7219 LED matrix and fetching time from the NTP server.

2. Initializes the pins and settings for the MAX7219 LED matrix and the Wemos D1 R2 board.

3. Reads SSID and password from EEPROM memory if available, or sets up an access point to configure WiFi settings.

4. Handles the web server and web page for configuring WiFi SSID and password.

5. Fetches the time from the NTP server and displays it on the MAX7219 LED matrix.

## Conclusion <a name="conclusion"></a>

Congratulations! You have successfully created your IoT Smart Watch using the MAX7219 LED matrix with the Wemos D1 R2 board. With this project, you can now wear a smart watch that displays real-time clock information. The project demonstrates how IoT devices can be integrated into wearable technologies.

Feel free to explore further and add more features to your IoT Smart Watch, such as weather updates, notifications, or fitness tracking. Happy tinkering!

**Tags:** IoT, Smart Watch, MAX7219, Wemos D1 R2, Wearable, NTP Client, LED Matrix, ESP8266
