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

One firmware.

Never multiple firmware builds.

If different hardware requires different behavior, solve it through BSPs, drivers or runtime detection.

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