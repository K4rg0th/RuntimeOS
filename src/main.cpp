#include "HAL.h"
#include "PowerManager.h"
#include "StorageManager.h"
#include "PluginManager.h"
#include "WebUI.h"
#include <WiFi.h>
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>
 
// Initialize ESPAsyncWebServer
AsyncWebServer server(80);

void setupAPMode() {
  // Set AP mode settings
  WiFi.softAP("RuntimeOS-AP", "password123");
  
  IPAddress ip(192, 168, 4, 1);
  IPAddress gateway(192, 168, 4, 1);
  IPAddress subnet(255, 255, 255, 0);

  // Set the static IP address for AP
  WiFi.softAPConfig(ip, gateway, subnet);

  Serial.println("Access Point created successfully");
}

void setup() {
  HAL hal;
  StorageManager storageManager;
  PluginManager pluginManager;
  WebUI webUI;
  PowerManager powerManager;
  
  hal.init();
  storageManager.init();
  pluginManager.init();
  webUI.init();
  powerManager.init();

  // Start AP mode
  setupAPMode();
  
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/plain", "RuntimeOS Access Point");
  });

  server.begin();

  Serial.println("HTTP server started");
}

void loop() {
  // Main application loop
  // Placeholder for actual runtime tasks
}
