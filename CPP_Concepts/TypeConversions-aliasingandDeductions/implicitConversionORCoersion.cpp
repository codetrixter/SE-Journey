/**
 * @file implicitConversionORCoersion.cpp
 * @author Abhishek 
 * @brief Here we see the imlicit conversion dynamics:
 * 1- Implicit type conversion cases.
 * 2- C++ defines how different fundamental types are converted called as "standard conversions".
 * These standard conversions are divided into 4 categories:
 * a- Numeric promotions.
 * b- Numeric conversions.
 * c- Arithmetic conversions.
 * d- Other conversions.
 * 
 * When a type conversion is needed, the compiler will see if there are standard conversion that it can 
 * use to convert the value to the desired type. The compiler might use 0 or more standard conversion in 
 * the conversion process.
 * !For full list of supported conversion in C++23 here is the list which can be referred from the image typeconversions.png
 * @version 0.1
 * @date 2022-06-30
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
//****************IMplicit type conversions***
 
void doSomething(long ld)
{}

//Here integert type 7 is converted into float
float foo()
{
    return 7;
}

int main(int argc, char const *argv[])
{
    //here integer type 3 is converted to type double.
    double d{3};
    d = 9;

    //Here integer type 4 is converted to double
    double division{3.0/4};

    //Here integer type 5 is converted to boolean
    if(5)

    //Here passed integer value is converted to long
    doSomething(5);

    //narrowing conversion are not allowed during brace initialization
    //int x{2.9}; //error

    return 0;
}
//****************IMplicit type conversions***
/*
╔══════════════════════════════════════════════════════════════════════════════╗
║          CONCEPT ANALYSIS — implicitConversionORCoersion.cpp               ║
╚══════════════════════════════════════════════════════════════════════════════╝

## Concepts

### 1. Implicit Type Conversion (Coercion)
The compiler automatically converts one type to another when needed. Four
categories: numeric promotions, numeric conversions, arithmetic conversions,
and other conversions.

**Code walkthrough:**
- `double d{3};` — int 3 promoted to double 3.0 (safe, no data loss).
- `double division{3.0/4}` — int 4 converted to double for mixed arithmetic.
- `if(5)` — int 5 converted to bool `true`.
- `doSomething(5)` — int 5 converted to `long`.

### 2. Narrowing Conversions and Brace Initialization
`int x{2.9};` — brace init PREVENTS narrowing conversions (compile error).
This is one of the key advantages of uniform initialization.

**Key Takeaway:** Implicit conversions happen silently. Brace initialization
protects against accidental narrowing. Use `static_cast` for intentional
narrowing.

#### Alternatives / Idiomatic C++
- Use `static_cast<int>(d)` to make narrowing explicit.
- C++20 `std::in_range<T>(value)` checks if a value fits in a type safely.
- `gsl::narrow_cast` / `gsl::narrow` from the Guidelines Support Library.

#### Real-World Usage
- **Chromium**: Uses `base::checked_cast<>` to catch narrowing at runtime.
- **LLVM**: Extensive use of `static_cast` with explicit comments for intent.

## 🔁 Quick Revision
- Implicit conversion: compiler converts types automatically when needed.
- Brace init `{}` prevents narrowing; `()` and `=` allow it.
- Four categories: promotions, conversions, arithmetic conversions, other.

### 💡 Remember
- "What's the difference between promotion and conversion?" → Promotions are
  always safe (no data loss); conversions may lose data.

### ⚠️ Gotchas
- `int x = 3.9;` silently truncates to 3. Use `int x{3.9};` to catch this.
- Signed/unsigned conversions can produce unexpected large values.
*/
