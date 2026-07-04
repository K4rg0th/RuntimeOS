# Architectural Decisions

## Decision: Framework independence

RuntimeOS must not depend on a specific vendor SDK.

ESP32 + Arduino is the first reference implementation because it allows fast prototyping.

Hardware-specific SDKs such as ESP-IDF may be used inside BSP implementations,
but the RuntimeOS core should remain framework-independent.

## Firmware

One Runtime architecture.

Avoid fragmented device-specific firmware forks.

Different hardware targets may require different builds, BSPs, and feature profiles, but they must expose the same RuntimeOS concepts and APIs.

---

## Management

If WiFi AP exists:

Always create an AP.

Never ask the user.

---

## Runtime

Plugins

↓

Services

↓

Drivers

↓

Hardware

Plugins never access hardware directly.

---

## Radios

Only one radio active simultaneously.

---

## UI

Headless first.

Responsive.

Mobile first.

---

## Philosophy

RuntimeOS is a runtime platform.

Not a pentesting firmware.


## Decision: Minimal Core and Dynamic Hardware Support

RuntimeOS does not include every possible hardware driver in the base firmware.

The core provides:
- bus discovery
- capability detection
- service interfaces
- driver loading mechanisms

Hardware-specific support is provided through:
- BSPs
- optional drivers
- user-installed modules
- downloadable packages when connectivity exists

The goal is not a firmware containing every driver.

The goal is a runtime capable of understanding and extending itself.