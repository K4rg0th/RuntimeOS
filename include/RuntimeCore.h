#ifndef RUNTIME_CORE_H
#define RUNTIME_CORE_H

#include <WiFi.h>
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>

class RuntimeCore {
private:
    AsyncWebServer server;
    
public:
    RuntimeCore();
    ~RuntimeCore();
    
    void begin();
    void loop();
    
private:
    void setupAPMode();
};

#endif // RUNTIME_CORE_H