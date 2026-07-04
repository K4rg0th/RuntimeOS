# Changelog

## 0.0.1

Initial project

ESP-IDF

WiFi AP

HTTP Server

Placeholder UI

## 0.0.2

Validate initial RuntimeOS ESP32 AP milestone

## 0.0.3

Create first visible RuntimeOS web UI
- Replace plain text response with lightweight responsive dashboard
- Implement dashboard, modules, logs, settings, and about sections
- Inspired by Home Assistant, Tabler, UniFi, and router dashboards
- Responsive mobile + desktop design
- No external CDN or assets
- Placeholder data allowed

## Unreleased

### Added

* Added minimal `RuntimeCore` layer.
* Added `RuntimeCore.begin()` and `RuntimeCore.loop()` lifecycle entrypoints.
* Added RuntimeOS-owned management interface bootstrap for the current ESP32 reference build.

### Changed

* Simplified `main.cpp` into a platform entrypoint.
* Moved current WiFi AP and HTTP dashboard lifecycle responsibility out of `main.cpp`.
* Preserved existing AP and dashboard behavior while improving runtime structure.

### Notes

* `RuntimeCore` currently owns WiFi AP and HTTP dashboard bootstrap as a temporary v0.1 architecture step.
* Placeholder managers are intentionally not wired into `RuntimeCore`.
* Capability Registry, BSP abstraction, hardware discovery, plugins, and dynamic drivers are not implemented yet.



