#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <ESP8266WiFi.h>
#include <EEPROM.h>
#include <ESP8266WebServer.h>
#include <ThingSpeak.h>

ESP8266WebServer server(80); // Create an instance of the ESP8266WebServer class

const char* ssid; // To store Wi-Fi SSID
const char* password; // To store Wi-Fi password

const int gasSensorPin = A0;
const int alcoholThreshold = 200; // Adjust this value based on your sensor sensitivity

LiquidCrystal_I2C lcd(0x27, 16, 2); // I2C address of the 16x2 LCD

const char* thinkSpeakAPIKey = "YOUR_THINGSPEAK_API_KEY";
const unsigned long thinkSpeakChannelID = YOUR_THINGSPEAK_CHANNEL_ID;

void setupWiFi() {
  String newSSID;
  String newPassword;

  // Read saved network SSID and password from EEPROM memory
  EEPROM.begin(512); // Initialize EEPROM
  newSSID = EEPROM.readString(0); // Read SSID from address 0
  newPassword = EEPROM.readString(50); // Read password from address 50
  EEPROM.end(); // Release EEPROM memory

  // Start the Wi-Fi connection using saved credentials
  if (newSSID.length() > 0 && newPassword.length() > 0) {
    Serial.println("Connecting to saved network...");
    WiFi.begin(newSSID.c_str(), newPassword.c_str());

    // Wait for Wi-Fi connection
    while (WiFi.status() != WL_CONNECTED) {
      delay(100);
    }
  }

  // If not connected to saved network or no saved credentials, create an Access Point (AP)
  if (WiFi.status() != WL_CONNECTED) {
    Serial.println("Failed to connect to saved network. Creating AP...");

    // Set custom AP name and password
    WiFi.softAP("CustomAPName", "CustomAPPassword");

    // Set up the web server
    server.on("/", handleRoot); // Define the root path and the function to handle it
    server.on("/save", handleFormSubmit); // Define the path for form submission
    server.begin(); // Start the web server
  }

  // Display Wi-Fi connection status using LEDs
  pinMode(LED_BUILTIN, OUTPUT); // Green LED
  pinMode(D5, OUTPUT); // Red LED

  if (WiFi.status() == WL_CONNECTED) {
    digitalWrite(LED_BUILTIN, HIGH); // Turn on Green LED
    digitalWrite(D5, LOW); // Turn off Red LED
  } else {
    digitalWrite(LED_BUILTIN, LOW); // Turn off Green LED
    digitalWrite(D5, HIGH); // Turn on Red LED
  }
}

// Function to handle the root path and serve the HTML page
void handleRoot() {
  String htmlPage = "<html><body>";
  htmlPage += "<h1>Enter New Wi-Fi Network Credentials</h1>";
  htmlPage += "<form method='post' action='/save'>";
  htmlPage += "SSID: <input type='text' name='ssid'><br>";
  htmlPage += "Password: <input type='password' name='password'><br>";
  htmlPage += "<input type='submit' value='Submit'>";
  htmlPage += "</form>";
  htmlPage += "</body></html>";
  server.send(200, "text/html", htmlPage);
}

// Function to handle the form submission and save the new SSID and password
void handleFormSubmit() {
  String newSSID = server.arg("ssid");
  String newPassword = server.arg("password");

  if (newSSID.length() > 0 && newPassword.length() > 0) {
    EEPROM.begin(512); // Initialize EEPROM
    EEPROM.writeString(0, newSSID); // Save SSID at address 0
    EEPROM.writeString(50, newPassword); // Save password at address 50
    EEPROM.commit(); // Save data to EEPROM
    EEPROM.end(); // Release EEPROM memory

    server.send(200, "text/html", "Credentials saved. Rebooting...");
    delay(1000);
    ESP.restart();
  } else {
    server.send(400, "text/html", "Invalid input. Please enter both SSID and password.");
  }
}

void sendDataToThinkSpeak(int alcoholLevel) {
  if (WiFi.status() == WL_CONNECTED) {
    ThingSpeak.beginClient();
    ThingSpeak.setField(1, alcoholLevel);
    int response = ThingSpeak.writeFields(thinkSpeakChannelID, thinkSpeakAPIKey);
    if (response == 200) {
      Serial.println("Data sent to ThinkSpeak successfully.");
    } else {
      Serial.println("Error sending data to ThinkSpeak.");
    }
    ThingSpeak.endClient();
  } else {
    Serial.println("Not connected to Wi-Fi. Cannot send data to ThinkSpeak.");
  }
}

void setup() {
  Serial.begin(115200);

  // Initialize LCD
  lcd.begin(16, 2);
  lcd.print("Alcohol Level:");

  // Initialize gas sensor pin and Wi-Fi connection
  pinMode(gasSensorPin, INPUT);
  setupWiFi();
}

void loop() {
  int alcoholLevel = analogRead(gasSensorPin);
  lcd.setCursor(0, 1);
  lcd.print("        ");
  lcd.setCursor(0, 1);
  lcd.print(alcoholLevel);

  // Send data to Thinkspeak
  sendDataToThinkSpeak(alcoholLevel);

  server.handleClient(); // Handle incoming client requests

  delay(1000);
}
