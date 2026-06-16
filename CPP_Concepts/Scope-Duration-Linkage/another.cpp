/**
 * ! This file just acts as an example for testing external linkages
 */
#include <iostream>

void sayHi() // this function has external linkage, and can be seen by other files
{
    std::cout << "Hi!\n";
}

/*
╔══════════════════════════════════════════════════════════════════════════════╗
║                      CONCEPT ANALYSIS — another.cpp                        ║
╚══════════════════════════════════════════════════════════════════════════════╝

## Concepts

### 1. Functions with External Linkage
`sayHi()` has **external linkage** by default (no `static` keyword). It can be
called from other TUs (like ExternalLinkage.cpp) via a forward declaration.

**Key Takeaway:** This file exists solely to demonstrate cross-TU linking. When
compiled together with ExternalLinkage.cpp, the linker resolves `sayHi()`.

#### Alternatives / Idiomatic C++
- In modern C++, prefer placing shared declarations in a header file rather
  than relying on manual forward declarations in each source file.

---

## 🔁 Quick Revision
- Functions are externally linked by default.
- Forward declarations in other TUs allow cross-file function calls.
- The linker resolves symbols across object files.
*/