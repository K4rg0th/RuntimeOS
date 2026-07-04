#include "WebServer.h"
#include "WebUI.h"
#include <Arduino.h>
#include <ESPAsyncWebServer.h>

// Global server instance
static AsyncWebServer server(80);

void WebServerStart() {
    // Route for the root page
    server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
        WebUI webui;
        request->send(200, "text/html", webui.getDashboardHtml());
    });
    
    // Start server
    server.begin();
}
