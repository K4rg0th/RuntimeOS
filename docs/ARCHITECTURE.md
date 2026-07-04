# RuntimeOS Architecture

## Vision

RuntimeOS is not a pentesting firmware.

RuntimeOS is a modular embedded runtime platform.

Pentesting capabilities are implemented through plugins.

The Runtime should remain generic enough to support any embedded application based on hardware capabilities.

---

## Architecture status

The architecture described in this document represents the intended RuntimeOS design direction.

Not every layer exists as code yet.

RuntimeOS development follows an incremental approach:

1. Implement the smallest working runtime.
2. Extract real abstractions only when required.
3. Keep hardware-specific code isolated.
4. Avoid placeholder architecture with empty managers/classes.

A documented component does not mean the component already exists.

Current implementation status must always be verified from the source tree.

# Design Goals

- Plug & Play
- Single firmware image
- Hardware agnostic architecture
- Modular
- Extensible
- Maintainable
- Headless-first
- Mobile-friendly

---

# Runtime Layers

Hardware

↓

Board Support Package (BSP)

↓

Hardware Discovery

↓

Drivers

↓

Runtime Core

↓

Services

↓

Plugins

↓

REST API

↓

Web UI

---

# Capabilities

Capabilities describe what hardware is able to do.

Examples

- WiFi
- BLE
- NFC
- SubGHz
- 2.4GHz Radio
- Ethernet
- Storage
- USB
- GPIO
- SPI
- I2C
- UART
- Battery

## Capability Model v0.1 (Documentation-only)

The RuntimeOS capability model v0.1 is documentation-only for now.

A capability is working runtime functionality exposed by RuntimeOS, not hardware discovery or placeholder architecture.

Static capability declarations may be used in the future, but are not implemented yet.

Current real capabilities are:
- wifi.ap
- management.http
- management.web_ui

Placeholder components that must not be declared as capabilities:
- HAL
- StorageManager
- PowerManager
- PluginManager
- RESTAPI

CapabilityRegistry should be implemented only when there is a real consumer such as Web UI, API, or plugin/module system.

---

# Services

Capabilities create Services.

Example

WiFi Capability

↓

WiFi Service

↓

Scan

Connect

Access Point

Monitor

Packet Capture

Plugins consume Services.

Plugins never access hardware directly.

---

# Plugins

Plugins implement features.

Examples

WiFi

BLE

CC1101

NRF24

PN532

OTA

Storage

Automation

Future pentesting plugins

Plugins should remain independent.

---

# Boot Process

1. BSP initialization
2. Driver initialization
3. Capability discovery
4. Runtime initialization
5. Service registration
6. Management Interface
7. Plugin loading
8. Runtime ready

---

# Management Interface

If WiFi AP capability exists:

Always create an Access Point.

Default address:

192.168.4.1

This AP is the primary management interface.

Ethernet, if available, should expose the same interface without disabling the AP.

---

# Radio Policy

Only one radio module may be active at a time.

Future hardware revisions may implement hardware power switching.

---

# User Experience

The user should never need to modify firmware.

The Runtime should automatically adapt itself to the available hardware.

---

# UI

Inspired by

- Home Assistant
- UniFi OS
- Proxmox
- pfSense

The UI should look like a commercial embedded appliance.

Not like a hacking tool.

---

# Current Milestone

WiFi AP

Embedded HTTP Server

Placeholder Dashboard

Placeholder Navigation

Nothing else.

## Hardware Agnostic Philosophy

RuntimeOS does not aim to include every possible hardware driver inside the firmware.

The core firmware must remain minimal and portable.

RuntimeOS provides:

- hardware capability discovery
- bus scanning
- device identification when possible
- standardized service interfaces
- dynamic extension through drivers and plugins

A device does not need to be fully supported at boot time.

The expected flow is:

1. Detect available hardware interfaces
2. Identify connected devices when possible
3. Expose known capabilities automatically
4. Request or load additional drivers when required

Drivers may come from:

- built-in minimal support
- user uploaded packages
- removable storage
- network download when available
- custom development

The goal is not:

"Firmware containing every driver"

The goal is:

"A small runtime capable of understanding its environment and expanding itself."