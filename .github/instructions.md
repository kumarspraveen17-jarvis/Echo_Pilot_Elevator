
# Instruction File – C Coding Guidelines
# =====================================
# Purpose:
# This document defines mandatory C coding guidelines
# that the Code Review Agent MUST enforce.
#
# These rules are derived from the official C Style Guide
# and MISRA C:2012 principles.
#
# Priority Order:
# 1. Safety
# 2. Reliability
# 3. Readability
# 4. Maintainability
# 5. Efficiency
#

## 1. General Language & Scope Rules
# ---------------------------------
- This instruction applies ONLY to the C language (C99).
- C++ constructs and C++ style comments (//) are NOT allowed.
- All comments, identifiers, and documentation must be in English.

---

## 2. File Structure & Layout
# ---------------------------

### File Extensions
- Header files must use `.h`
- Source files must use `.c`

### Mandatory File Header
- Every file MUST begin with a structured Doxygen-style comment
- Include:
  - File name
  - Author
  - Copyright
  - Brief description
  - Functional purpose

### Include Rules
- Absolute paths are forbidden
- Include guards using `#ifndef / #define / #endif` are mandatory
- Header file declaring a function must be included in its implementation

### Formatting Rules
- Indentation: exactly **3 spaces**
- TAB characters must NOT be used
- Braces `{}`:
  - Must be on their own lines
  - Opening and closing braces must align vertically

---

## 3. Commenting Rules
# -------------------
- Only `/* */` comments are allowed
- Do not use `//`
- Comments must appear before logical blocks
- Commented‑out code is NOT allowed
  - Use preprocessor directives or delete unused code

---

## 4. Naming Conventions
# ---------------------

### General
- Names must be descriptive and meaningful
- Do NOT use Hungarian notation

### Variables & Functions
- camelCase starting with lowercase
- Example:
  - `currentSpeed`
  - `calculateChecksum`

### Constants, Macros, Enums
- ALL uppercase with underscores
- Enum, struct, and union types must be explicitly named
- Enum values should use a common prefix

---

## 5. Variables & Constants
# ------------------------

### Type Usage
- ONLY company‑defined types are allowed (from `kb_types.h`)
- Examples:
  - `sint8`, `uint8`, `sint32`, `flt32`, `boolean`
- Standard C types are NOT allowed in interfaces

### Declaration Rules
- One variable per declaration line
- Declare variables in the narrowest possible scope
- Local variables must appear at the top of a block
- All variables must be initialized before use
- Static variables require explicit initialization

### Constants
- Magic numbers are NOT allowed (except 0)
- Use `const`, `#define`, or `enum`

---

## 6. Control Structures
# ---------------------

### switch Statements
- Every `case` and `default` must end with `break`
- A `default` case is mandatory
- `switch`, `case`, `default` aligned at same indentation level

### Logical Expressions
- Avoid logical negation of complex expressions
- Assignment inside conditions is NOT allowed

---

## 7. Pointers & References
# ------------------------
- Pointers must be compared against `NULL`, not `0`
- Pointer validity must be checked before dereferencing
- Pointer symbol `*` must be placed with variable name

---

## 8. Memory Management
# --------------------
- Dynamic memory allocation is strictly forbidden
- No use of `malloc`, `calloc`, `free`

---

## 9. Function Definitions
# -----------------------
- Function prototypes must reside in header files
- Function definition order must match declarations
- Explicit return types are mandatory
- Parameter names must match in declaration & definition
- Never return pointers or references to local variables
- Return expressions must be enclosed in parentheses

---

## 10. MISRA Compliance
# --------------------
- MISRA C:2012 rules apply
- Non-decidable rules must be manually evaluated
- Any deviation must be explicitly justified

# End of instruction.md