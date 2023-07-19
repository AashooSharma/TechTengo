#include <ESP8266WiFi.h>
#include <WiFiUdp.h>
#include <NTPClient.h>
#include <MD_Parola.h>
#include <MD_MAX72xx.h>
#include <time.h>
#include <TimeLib.h>
#include <EEPROM.h>
#include <ESP8266WebServer.h>

// Size of EEPROM memory used to store SSID and password
#define EEPROM_SIZE 512

// Pins used to reset the device and put it in programming mode
const int RESET_PIN = 0;
const int PROGRAMMING_PIN = 2;

const char* AP_SSID = "MyAccessPoint";
const char* AP_PASSWORD = "myPassword";

// SSID and password variables
String ssid = "";
String password = "";

ESP8266WebServer server(80);

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

const long gmtOffset_sec = 19800; // Indian Standard Time (IST) - GMT + 5:30
#define HARDWARE_TYPE MD_MAX72XX::GENERIC_HW
#define MAX_DEVICES 4
#define CLK_PIN D5
#define DATA_PIN D7
#define CS_PIN D6

MD_Parola P = MD_Parola(HARDWARE_TYPE, DATA_PIN, CLK_PIN, CS_PIN, MAX_DEVICES);
WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "pool.ntp.org");

void setup() {
  P.begin();
  Serial.begin(9600);
  
  readCredentialsFromEEPROM();
  
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
    
    P.setIntensity(8);
    P.setInvert(false);
    // WiFi.begin(AP_SSID, AP_PASSWORD);
    // Serial.print("Connecting to ");
    // Serial.print(ssid);
    // while (WiFi.status() != WL_CONNECTED) {
    //   delay(1000);
    //   Serial.print(".");
    // }
    Serial.println("");
    Serial.println("WiFi connected");
    timeClient.begin();
    timeClient.setTimeOffset(19800); // Indian Standard Time (IST) - GMT + 5:30
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
  timeClient.update();
  // Display the current time
  Serial.println(timeClient.getFormattedTime());
  unsigned long epochTime = timeClient.getEpochTime();
  setTime(epochTime);
  int currentHour = hour();
  int currentMinute = minute();
  int currentSecond = second();
  P.setTextAlignment(PA_LEFT);
  P.print(timeClient.getFormattedTime());
  delay(1000);
}
