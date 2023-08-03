#include <ESP8266WiFi.h>
#include <EEPROM.h>
#include <ESP8266WebServer.h>
#include <ThingSpeak.h>
#include <WiFiClient.h>

// Size of EEPROM memory used to store SSID and password
#define EEPROM_SIZE 512

// Pins used to reset the device and put it in programming mode
const int RESET_PIN = 0;
const int PROGRAMMING_PIN = 2;

const char* AP_SSID = "IOTAlcoholProject";
const char* AP_PASSWORD = "iotpassword";

// SSID and password variables
String ssid = "";
String password = "";

ESP8266WebServer server(80);

// Gas sensor setup
const int gasSensorPin = A0;
const int alcoholThreshold = 50; // Adjust this value based on your sensor sensitivity

// ThingSpeak setup
unsigned long thinkSpeakChannelID = 2232310; // Replace with your ThingSpeak Channel ID
const char* thinkSpeakAPIKey = "XF7MW87JB2UZJU9U";      // Replace with your ThingSpeak API Key

// Function to store SSID and password in EEPROM memory
void writeCredentialsToEEPROM() {
  EEPROM.begin(EEPROM_SIZE);
  for (int i = 0; i < ssid.length(); i++) {
    EEPROM.write(i, ssid[i]);
  }
  EEPROM.write(ssid.length(), '\0');
  for (int i = 0; i < password.length(); i++) {
    EEPROM.write(ssid.length() + 1 + i, password[i]);
  }
  EEPROM.write(ssid.length() + 1 + password.length(), '\0');
  EEPROM.commit();
  EEPROM.end();
}

// Function to read SSID and password from EEPROM memory
void readCredentialsFromEEPROM() {
  EEPROM.begin(EEPROM_SIZE);
  char c;
  int i;
  for (i = 0; (c = EEPROM.read(i)) != '\0' && i < EEPROM_SIZE; i++) {
    ssid += c;
  }
  for (i = ssid.length() + 1; (c = EEPROM.read(i)) != '\0' && i < EEPROM_SIZE; i++) {
    password += c;
  }
  EEPROM.end();
}

// Handler for root path, serves web page for configuring WiFi
void handleRoot() {
  server.sendHeader("Content-Type", "text/html");
  server.send(200, "text/html",
    "<html><body><h1>Configure WiFi</h1>" \
    "<form method=\"post\" action=\"/save\">" \
    "SSID: <input type=\"text\" name=\"ssid\" value=\"" + ssid + "\"><br>" \
    "Password: <input type=\"password\" name=\"password\"><br>" \
    "<input type=\"submit\" value=\"Save\">" \
    "</form></body></html>");
}

// Handler for form submission, saves SSID and password to EEPROM
void handleSave() {
  ssid = server.arg("ssid");
  password = server.arg("password");
  
  writeCredentialsToEEPROM();
  server.sendHeader("Location", "/");
  server.send(302);
  delay(500);
  ESP.restart();
}

// Function to send data to ThingSpeak
void sendDataToThinkSpeak(int alcoholLevel) {
  if (WiFi.status() == WL_CONNECTED) {
    WiFiClient client;
    ThingSpeak.begin(client);

    // Set the field value for the ThingSpeak channel
    ThingSpeak.setField(1, alcoholLevel);

    // Write the data to the ThingSpeak channel
    int response = ThingSpeak.writeFields(thinkSpeakChannelID, thinkSpeakAPIKey);

    if (response == 200) {
      Serial.println("Data sent to ThingSpeak successfully.");
    } else {
      Serial.println("Error sending data to ThinkSpeak.");
    }

    // Disconnect the client from the ThingSpeak server
    client.stop();
  } else {
    Serial.println("Not connected to Wi-Fi. Cannot send data to ThinkSpeak.");
  }
}

void setup() {
  Serial.begin(9600);

  // Read saved credentials from EEPROM
  readCredentialsFromEEPROM();
  
  // Try to connect to the saved WiFi network
  WiFi.begin(ssid.c_str(), password.c_str());
  Serial.print("Connecting to saved WiFi network...");

  int i = 0;
  while (WiFi.status() != WL_CONNECTED && i < 20) {
    delay(500);
    Serial.print(".");
    i++;
  }
  
  if (WiFi.status() == WL_CONNECTED) {
    Serial.println("Connected to saved WiFi network.");
    // You can add any additional code here to run when connected to saved WiFi network
  } else {
    // If not connected to saved WiFi network, set up access point and web server
    Serial.println("Failed to connect to saved WiFi network.");
    WiFi.softAP(AP_SSID, AP_PASSWORD);
    IPAddress myIP = WiFi.softAPIP();
    Serial.print("AP IP address: ");
    Serial.println(myIP);
    server.on("/", handleRoot);
    server.on("/save", handleSave);
    server.begin();
  }
}

void loop() {
  server.handleClient();

  // Read gas sensor value and take action based on threshold
  int alcoholLevel = analogRead(gasSensorPin);
  long MappedAlcoholLevel = map(alcoholLevel, 0, 1023, 0, 100); // Assuming the sensor's analog output is in the range of 0-1023

  // Display the alcohol level on the serial monitor
  Serial.print("Alcohol Level: ");
  Serial.print(MappedAlcoholLevel);
  Serial.println("%");

  // Compare alcohol level with threshold
  if (MappedAlcoholLevel > alcoholThreshold) {
    // Perform some action here, for example, send a notification, turn on a warning light, etc.
    // Replace the comment with your desired action.
    Serial.println("High alcohol level detected!");

    // Send data to ThingSpeak
    sendDataToThinkSpeak(MappedAlcoholLevel);
  }

  delay(1000); // Adjust the delay as required for your application
}
