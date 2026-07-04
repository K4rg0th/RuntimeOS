# TODO


## Current priority

* [ ] Define RuntimeOS Capability model v0.1
* [ ] Decide which capabilities are real in the current ESP32 reference build
* [ ] Decide what capability metadata is safe to expose now
* [ ] Decide how Capability Registry should be introduced incrementally
* [ ] Avoid fake discovery or fake plugin systems

## Recently completed

* [x] Introduced minimal `RuntimeCore`
* [x] Simplified `main.cpp` into platform entrypoint
* [x] Preserved WiFi AP behavior
* [x] Preserved Web dashboard behavior
* [x] Avoided wiring placeholder managers into runtime core
* [x] Document Capability model v0.1



- Capability Registry
- Hardware Discovery
- Driver Manager
- Module Installer
- BSP Manager
- Device Tree
- Resource Manager

Future ideas

- OTA

- Bluetooth provisioning

- MQTT

- Event Bus

- Plugin Marketplace

- Dark Theme

- Theme Engine

- Metrics

- Automation Engine

- Scheduler

- CLI

- WebSocket API

- Authentication

- [ ] Implement CapabilityRegistry only when Web UI, API, or plugin/module system consumes it
