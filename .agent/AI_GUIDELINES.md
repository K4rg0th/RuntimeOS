# RuntimeOS AI Instructions

These files define the architecture.

Do not modify unless explicitly requested:

docs/PROJECT_PHILOSOPHY.md
docs/ARCHITECTURE.md
docs/DECISIONS.md
docs/NAMING.md

These files may be updated during normal development:

TASK.md
TODO.md
CHANGELOG.md

Ignore generated files:

.pio/
.vscode/
build/
sdkconfig.old

## Implementation discipline

Do not implement future architecture layers just because they exist in documentation.

Before adding a new abstraction:

* Identify what problem it solves now.
* Check existing code.
* Prefer moving working code into the correct layer over creating empty frameworks.

RuntimeOS should evolve from working runtime code into clean abstractions.

Avoid:

* unused managers
* placeholder interfaces
* fake plugin systems
* premature driver frameworks
* large rewrites without need

## Firmware verification

After firmware code changes, build verification is not enough.

Cline should perform the technical firmware verification steps when possible:

1. Run `platformio run`.
2. If build succeeds, run `platformio run --target upload`.
3. If upload succeeds, open the serial monitor long enough to confirm expected boot logs.

The user performs the external functional verification manually:

1. Confirm the RuntimeOS AP appears from a phone or computer.
2. Connect to the RuntimeOS AP.
3. Open `http://192.168.4.1`.
4. Confirm the dashboard loads and basic behavior is unchanged.

Do not mark firmware changes as fully validated unless both technical verification and external functional verification are complete.

If only build passed, report:

`Build passed. Flash and hardware verification pending.`

If build and upload passed, but the user has not checked the AP/dashboard yet, report:

`Build and flash passed. External AP/dashboard verification pending.`

