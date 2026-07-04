#include "RuntimeCore.h"
#include "WebUI.h"
#include <Arduino.h>

RuntimeCore::RuntimeCore() : server(80) {
    // Constructor implementation
}

RuntimeCore::~RuntimeCore() {
    // Destructor implementation
}

void RuntimeCore::setupAPMode() {
    // Set AP mode settings
    WiFi.softAP("RuntimeOS-AP", "password123");
    
    IPAddress ip(192, 168, 4, 1);
    IPAddress gateway(192, 168, 4, 1);
    IPAddress subnet(255, 255, 255, 0);

    // Set the static IP address for AP
    WiFi.softAPConfig(ip, gateway, subnet);

    Serial.println("Access Point created successfully");
}

void RuntimeCore::begin() {
    // Setup AP mode
    setupAPMode();
    
    // Setup web server routes
    server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
        // Serve the main dashboard page
        WebUI webui;
        request->send(200, "text/html", webui.getDashboardHtml());
    });
    
    server.begin();
    
    Serial.println("HTTP server started");
}

void RuntimeCore::loop() {
    // Main runtime loop - currently empty as all functionality is handled by the web server
}