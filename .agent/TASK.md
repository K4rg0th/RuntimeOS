# Current Task

## Status

The previous task is complete.

RuntimeOS now has a minimal `RuntimeCore` layer.

`main.cpp` is no longer responsible for RuntimeOS boot logic directly. It now acts as a platform entrypoint that creates a `RuntimeCore` instance and delegates lifecycle calls to it.

## Current implementation state

Implemented:

* ESP32-WROOM-32D reference target
* PlatformIO + Arduino framework
* RuntimeOS WiFi AP
* Web dashboard at `192.168.4.1`
* Web UI separated from `main.cpp`
* Minimal `RuntimeCore`
* `main.cpp` delegates to:

  * `runtime.begin()`
  * `runtime.loop()`

Not implemented yet:

* Capability Registry
* BSP abstraction
* Hardware discovery
* Real driver model
* Plugin loading
* Dynamic modules
* Package installation
* REST API service layer

## Next task

Plan the first minimal Capability model for RuntimeOS.

This is an architecture planning task, not an implementation task.

The goal is to define what a RuntimeOS capability means in v0.1 without creating a fake or overengineered system.

Focus on:

* What information a capability should expose
* Which capabilities are real today
* How capabilities differ from hardware, drivers, and services
* How the Web UI may eventually consume capability information
* What should wait until BSP/discovery exists

Do not implement code yet.

## Current Status

Capability model v0.1 documentation is complete and has been added to docs/ARCHITECTURE.md. No CapabilityRegistry implementation has been done yet.

The CapabilityRegistry is intentionally not implemented at this time, as there are no real consumers for capabilities yet (such as Web UI, API, or plugin/module system).

The next step is to decide when the first real consumer should use capabilities.
