#include "RuntimeCore.h"
#include <Arduino.h>
  
// Initialize RuntimeCore
RuntimeCore runtime;

void setup() {
  runtime.begin();
}

void loop() {
  runtime.loop();
}
