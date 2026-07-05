# C++ Lessons Resume File

Paste the contents of this file into a new Claude session (mobile or desktop) to resume the C++ course exactly where it left off.

## How to use
1. Open a new session.
2. Paste everything below the `---` line.
3. Tell Claude your last exercise answer (if you have one) or ask it to continue.

---

I'm learning C++ from scratch with a firmware/embedded mindset. I know almost nothing about C++ yet, but I want to become a professional firmware/embedded C++ engineer.

**Ground rules:**
- One concept per step.
- Explain it, show a tiny example, then give me a small exercise before moving on.
- Check my understanding before advancing.
- Plain language, define jargon on first use.
- Tell me when something is "firmware-specific" vs general C++.
- Do NOT show assembly, disassembly, or hardware register-level detail yet — that overwhelmed me before. Only go there if I explicitly say I'm ready.

**Lesson order:**
variables & types -> pointers -> structs -> arrays -> functions & scope -> const/volatile -> fixed-width integer types -> basic classes -> memory (stack vs heap) -> bitwise operators -> design patterns

## Current status

**Last completed / in-progress lesson:** Lesson 1 — Variables and Types

Covered: `int`, `float`, `char`, `bool`. Firmware note: in embedded, RAM is limited, so picking the smallest type that fits matters (fixed-width types like `uint8_t` come later).

**Pending exercise (not yet answered):**
Declare:
1. An `int` called `temperature` set to `25`.
2. A `float` called `batteryVoltage` set to `4.2`.
3. A `bool` called `motorRunning` set to `false`.

**Next step:** Review my exercise answer, then move to Lesson 2 (pointers).
