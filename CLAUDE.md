# CLAUDE.md

Guidance for Claude Code (and other AI assistants) working in this repository.

## What this repo is

This is a personal learning repo, not a product codebase. It has two parts:

1. **`CPP_LESSONS.md`** — a resume/session-state file for an ongoing, tutor-style
   C++ course the user is taking from Claude, aimed at becoming a firmware/embedded
   C++ engineer. It tracks exactly which lesson and exercise the user last stopped at.
2. **`stm32g0-nucleo/`** — a PlatformIO project targeting an STM32 Nucleo-G071RB
   board (Arduino framework), containing numbered example sketches that correspond
   to lessons in the course (GPIO, UART, PWM, ADC, interrupts, I2C, SPI, ...).

There is no build pipeline, test suite, package.json, or CI in this repo. "Development"
here means: continuing the C++ course, writing/adjusting lesson example firmware, and
keeping `CPP_LESSONS.md` in sync with progress.

## Repository layout

```
CPP_LESSONS.md                     Resume file: course rules + current lesson/exercise state
stm32g0-nucleo/
  platformio.ini                   PlatformIO config: env:nucleo_g071rb, ststm32 platform, arduino framework
  src/main.cpp                     The "active" sketch PlatformIO actually builds/uploads
  examples/NN_topic.cpp            Numbered, standalone lesson examples (not compiled directly)
  include/README                   Stock PlatformIO placeholder (no project headers yet)
  lib/README                       Stock PlatformIO placeholder (no private libraries yet)
```

Key thing to know: **PlatformIO only compiles `src/main.cpp`.** The files under
`examples/` are reference copies of each lesson's sketch, kept for the user to look
back on — they are not part of the active build. When a new lesson's example is
finished, its content is generally copied into `src/main.cpp` to actually run on
hardware (see `git log` — e.g. lesson 8's SPI example was duplicated into `main.cpp`).

## The C++ course workflow (`CPP_LESSONS.md`)

This file is the source of truth for where the user is in the curriculum. Read it
before assuming context about what the user already knows.

Ground rules baked into the course (respect these when teaching/continuing):
- One concept per step; explain, show a tiny example, then give a small exercise
  before moving on. Check understanding before advancing.
- Plain language; define jargon on first use.
- Explicitly flag what's "firmware-specific" vs. general C++.
- Do **not** show assembly, disassembly, or hardware register-level detail unless
  the user explicitly says they're ready for it.
- Lesson order: variables & types -> pointers -> structs -> arrays -> functions &
  scope -> const/volatile -> fixed-width integer types -> basic classes -> memory
  (stack vs heap) -> bitwise operators -> design patterns.

When resuming or advancing the course:
- Update the "Current status" section in `CPP_LESSONS.md` (last completed/in-progress
  lesson, what was covered, any pending unanswered exercise, and next step) so the
  file keeps working as a cross-device resume point.
- If a lesson maps to a hardware concept already covered by the STM32 examples
  (GPIO, UART, PWM, ADC, interrupts, I2C, SPI), prefer wiring the C++ concept to
  that existing example rather than inventing an unrelated one.

## Firmware example conventions (`stm32g0-nucleo/`)

Follow the style already established in `examples/*.cpp` and `src/main.cpp`:

- Each example starts with a one-line header comment: `// Lesson N: Topic - short description`.
- Uses the Arduino framework API (`pinMode`, `digitalWrite`, `analogRead`, `Serial`,
  `Wire`, `SPI`, etc.), not bare STM32 HAL/LL register access — this is intentional,
  matching the "no register-level detail yet" course rule.
- Board pin names use Nucleo/Arduino aliases (`PA5`, `PC13`, `A0`, ...), not raw
  peripheral/pin numbers.
- Comments explain *why*, not *what* (e.g. why a pin idles HIGH, why `volatile` is
  needed for an ISR-shared variable) — keep this pattern, don't over-comment obvious
  API calls.
- Files are numbered by lesson order (`01_`, `02_`, ...) and should stay in sync
  with the lesson sequence in `CPP_LESSONS.md`.

Board target: Nucleo-G071RB (`nucleo_g071rb`), STM32 platform, Arduino framework —
see `stm32g0-nucleo/platformio.ini`. If adding a new example that needs a library
(e.g. a sensor driver), add it via `lib_deps` in `platformio.ini` rather than vendoring
code into `lib/`.

## Working conventions

- No test suite or CI exists; there's nothing to run automatically after a change.
  If asked to verify firmware code, check it compiles conceptually against the
  Arduino/STM32 API used elsewhere in the repo — actual build/upload requires
  PlatformIO and physical hardware, which this environment does not have.
- Don't introduce a build system, test framework, or restructure the two top-level
  areas (course docs vs. firmware project) unless explicitly asked — this repo is
  intentionally minimal.
- When editing `src/main.cpp`, remember it reflects "whatever lesson is currently
  being run on real hardware" — don't leave it in a broken/half-written state.
