# MQ-2 Sensor Alarm with Arduino - Gas Leakage Detector

Hello fellow makers and Arduino enthusiasts! Welcome to our exciting project - the MQ-2 Sensor Alarm using Arduino. In this project, you'll learn how to create your very own gas leakage detector and alarm system using simple components and Arduino programming.

## Introduction

Gas leakage is a serious safety concern in various environments. Whether it's at home, in a workshop, or in industrial settings, detecting gas leaks early can prevent potential disasters. The MQ-2 gas sensor is an affordable and widely available component that can detect various gases, including methane, propane, butane, and alcohol.

## Project Description

In this project, we will be using an MQ-2 gas sensor with an Arduino to detect gas concentration levels and provide visual and auditory alerts when gas leakage is detected. We will use LEDs to indicate the gas concentration level and a buzzer to sound an alarm when the gas concentration exceeds a certain threshold.

## Components Required

To get started, you'll need the following components:

1. Arduino board (e.g., Arduino Uno)
2. MQ-2 gas sensor module
3. 5x LEDs (any color you prefer)
4. 5x 220-ohm resistors (for the LEDs)
5. Buzzer
6. Breadboard and jumper wires

## Circuit Diagram

Before we dive into the code, let's take a look at the circuit diagram for our gas leakage detector:

![Circuit Diagram](https://i.imgur.com/your-image-link-here.png)

## Arduino Sketch

Now, let's move on to the Arduino code. Upload the provided sketch to your Arduino board using the Arduino IDE:

```arduino
#define LED_COUNT 5
int ledPins[] = {13, 12, 11, 10, 9};
int buzzerPin = 8;

void setup() {
  Serial.begin(9600);
  for (int i = 0; i < LED_COUNT; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  int sensorValue = analogRead(A0);
  Serial.println(sensorValue);

  int mappedValue = map(sensorValue, 0, 1023, 1, LED_COUNT);
  for (int i = 0; i < LED_COUNT; i++) {
    if (i <= mappedValue) {
      digitalWrite(ledPins[i], HIGH);
    } else {
      digitalWrite(ledPins[i], LOW);
    }
  }

  int buzzerValue = map(sensorValue, 0, 1023, 0, 255);
  analogWrite(buzzerPin, buzzerValue);

  delay(1000);
}
```

## Code Explanation

The provided Arduino code does the following:

1. Defines `LED_COUNT` as 5 since we are using 5 LEDs to indicate gas concentration levels.
2. In the `setup()` function, it initializes the serial communication for debugging and sets the LED pins and buzzer pin as outputs.
3. The `loop()` function reads the analog value from the MQ-2 gas sensor connected to pin A0.
4. The sensor value is mapped to a range suitable for our 5 LEDs (1 to 5), and the corresponding LEDs are set to light up according to the gas concentration level.
5. Additionally, the buzzer's intensity is adjusted based on the gas concentration to create an alarm effect.

## Testing the Gas Leakage Detector

To test your gas leakage detector, follow these steps:

1. Power up your Arduino board and upload the sketch.
2. Make sure the MQ-2 sensor is properly connected to the A0 pin.
3. Provide the sensor with a suitable gas source, such as alcohol or butane.
4. Observe the LEDs lighting up and the buzzer sounding when gas concentration increases.
5. Move the gas source away to see the LEDs turn off and the buzzer silence.

## Safety Precautions

While testing the gas leakage detector, ensure you do so in a well-ventilated area and with caution. Do not expose yourself to harmful gases in the process.

## Conclusion

Congratulations! You have successfully created an MQ-2 Sensor Alarm with Arduino gas leakage detector. This project can serve as a crucial safety tool in various settings, providing an early warning system for potential gas leaks.

Feel free to experiment and enhance the project further. You could add a display to show gas concentration values or even connect the detector to an IoT platform to receive alerts remotely.

Remember, safety always comes first, and we hope this project helps you in creating a safer environment. Happy tinkering!

**Tags:** Arduino, Gas Leakage Detector, MQ2 Sensor, Safety First, DIY Project
