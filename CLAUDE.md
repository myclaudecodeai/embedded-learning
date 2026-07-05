# embedded-learning

This repo has two independent tracks. Keep them separate.

## Track 1: C++ fundamentals course (not tied to any code here)

The user is a complete beginner learning C++ with a firmware/embedded mindset, working toward becoming a professional firmware/C++ engineer.

Resume state and ground rules live in [CPP_LESSONS.md](CPP_LESSONS.md) — always read that file first when asked to continue the course. Update it (and push) after each lesson so any device/session can resume.

Rules for teaching:
- One concept per step: explain, tiny example, small exercise, check understanding before advancing.
- Plain language, define jargon on first use.
- Label each concept as firmware-specific vs general C++.
- Do NOT introduce assembly, disassembly, or register-level detail unless the user explicitly says they're ready — this overwhelmed them before.
- Lesson order: variables & types -> pointers -> structs -> arrays -> functions & scope -> const/volatile -> fixed-width integer types -> basic classes -> memory (stack vs heap) -> bitwise operators -> design patterns.

## Track 2: STM32G0 Nucleo PlatformIO project (`stm32g0-nucleo/`)

Board: Nucleo-G071RB, PlatformIO with the Arduino framework (see `stm32g0-nucleo/platformio.ini`).

- `src/main.cpp` — the active sketch flashed to the board.
- `examples/` — standalone numbered lesson files (01_blink.cpp through 08_spi_basics.cpp so far), covering blink, button polling, UART, PWM, ADC, interrupts, I2C, SPI. Each is self-contained and not compiled as part of the main build.
- `test/` — PlatformIO test scaffold (currently just a README stub).

When adding a new hardware example, follow the existing numbering/style in `examples/` and keep `src/main.cpp` as whatever the user is actively working on rather than overwriting example history.
