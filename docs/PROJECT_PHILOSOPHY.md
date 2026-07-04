# RuntimeOS Philosophy

## Mission

RuntimeOS is a modular embedded runtime platform.

It is NOT a pentesting firmware.

Pentesting capabilities are implemented as plugins.

---

## Core Principles

The Runtime adapts to the hardware.

The hardware should never dictate the architecture.

---

One Runtime architecture.

Avoid fragmented device-specific firmware forks.

Different hardware targets may require different builds, BSPs, and feature profiles, but they must expose the same RuntimeOS concepts and APIs.


---

Plug & Play first.

The end user should never modify source code.

Configuration should happen through the management interface whenever possible.

---

The management interface is a core feature.

If the hardware supports WiFi AP, RuntimeOS MUST automatically create a management Access Point during boot.

The AP is the primary administration interface.

---

Headless first.

Displays and buttons are optional.

The project must remain fully usable from a phone or laptop.

---

Commercial appliance mindset.

The user experience should resemble products like:

- Home Assistant
- UniFi OS
- pfSense
- Proxmox

Not development boards or hacking scripts.

---

Capabilities over hardware.

Think in capabilities.

Not chips.

Examples:

WiFi

BLE

Storage

SubGHz

NFC

GPIO

Not:

ESP32

CC1101

PN532

---

Services over drivers.

Drivers expose hardware.

Services expose capabilities.

Plugins consume services.

Plugins never access hardware directly.

---

Everything should be discoverable.

The Runtime should detect hardware whenever technically possible.

If automatic detection is impossible, require the minimum user interaction.

---

Incremental development.

Every milestone must produce a working firmware.

The project should never remain broken waiting for future work.

---

Maintainability before features.

A clean architecture is more valuable than adding one more feature.

---

Long-term vision.

RuntimeOS should become a reusable embedded runtime platform capable of running on multiple hardware families while preserving the same user experience.

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