# Architectural Decisions

## Firmware

Only one firmware image.

Never create multiple builds for different hardware.

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