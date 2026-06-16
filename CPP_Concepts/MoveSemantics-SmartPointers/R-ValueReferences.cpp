/**
 * @file R-ValueReferences.cpp
 * @author Abhishek
 * @brief here we discuss about the r-value references in cpp:
 * 1- prior to c++11, only one type of reference existed which was renamed to l-value reference in c++11, which can only be initialized with modifyable
 * l-values.
 * L-Value References Initialization and assignments:
 * -----------------------------------------------------------------------------------
 * L-Value reference            Can be initialized with                 Can modify
 * -----------------------------------------------------------------------------------
 * modifyable l-values          Yes                                     Yes
 * Non-modifyable l-values      No                                      No
 * R-values                     No                                      No
 * 
 * -----------------------------------------------------------------------------------
 * L-Value reference to const           Can be initialized with                 Can modify
 * -----------------------------------------------------------------------------------
 * modifyable l-values                  Yes                                     Yes
 * Non-modifyable l-values              Yes                                     No
 * R-values                             Yes                                     No
 * 
 * **IMPORTANT:L-value references to const objects are particularly useful because they allow us to pass any type of argument (l-value or r-value) into a 
 * function without making a copy of the argument.
 * 
 * 2- c++11 adds a new type of reference called r-value reference which can be initialized with an r-value only.
 * L-Value References Initialization and assignments:
 * -----------------------------------------------------------------------------------
 * R-Value reference            Can be initialized with                 Can modify
 * -----------------------------------------------------------------------------------
 * modifyable l-values          No                                      No
 * Non-modifyable l-values      No                                      No
 * R-values                     Yes                                     Yes
 * 
 * -----------------------------------------------------------------------------------
 * R-Value reference to const           Can be initialized with                 Can modify
 * -----------------------------------------------------------------------------------
 * modifyable l-values                  No                                      No
 * Non-modifyable l-values              No                                      No
 * R-values                             Yes                                     No
 * 
 * **IMPORTANT: R-value references have two properties that are useful. First, r-value references extend the lifespan of the object they are initialized with 
 * to the lifespan of the r-value reference (l-value references to const objects can do this too). Second, non-const r-value references allow you to 
 * modify the r-value!.
 * 
 * **NOTE: You should almost never return an r-value reference, for the same reason you should almost never return an l-value reference. In most cases, 
 * you’ll end up returning a hanging reference when the referenced object goes out of scope at the end of the function.
 * @version 0.1
 * @date 2022-08-30
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
//***********************************R-value references***
/* class Fraction
{
private:
	int m_numerator;
	int m_denominator;

public:
	Fraction(int numerator = 0, int denominator = 1) :
		m_numerator{ numerator }, m_denominator{ denominator }
	{
	}

	friend std::ostream& operator<<(std::ostream& out, const Fraction &f1)
	{
		out << f1.m_numerator << '/' << f1.m_denominator;
		return out;
	}
};

int main()
{
	Fraction&& rref{ Fraction{ 3, 5 } }; // r-value reference to temporary Fraction

	// f1 of operator<< binds to the temporary, no copies are created.
	std::cout << rref << '\n';

	return 0;
} */ // rref (and the temporary Fraction) goes out of scope here
//***********************************R-value references***
//***********************************R-value references as function parameters***
/* void fun(const int &lref) // l-value arguments will select this function
{
	std::cout << "l-value reference to const\n";
}

void fun(int &&rref) // r-value arguments will select this function
{
	std::cout << "r-value reference\n";
}
int main(int argc, char const *argv[])
{
    int x{5};
    int&& ref{16};	//this here is an l-value as it has a name and an address.
    fun(x); // l-value argument calls l-value version of function
	fun(5); // r-value argument calls r-value version of function
    fun(ref);   //calls l-value version of function, since is it passing and l-value.
    return 0;
} */
//***********************************R-value references as function parameters***
//***********************************QUIZ***
int main()
{
	int x{};

	// l-value references
	int &ref1{ x }; // A
	/// int &ref2{ 5 }; // B    error: cannot bind non-const lvalue reference of type ‘int&’ to an rvalue of type ‘int’

	const int &ref3{ x }; // C
	const int &ref4{ 5 }; // D	takeaway from this is that a const l-value reference can be initialized with both l-values and r-values.

	// r-value references
	/// int &&ref5{ x }; // E   error: cannot bind rvalue reference of type ‘int&&’ to lvalue of type ‘int’
	int &&ref6{ 5 }; // F

	/// const int &&ref7{ x }; // G     error: cannot bind rvalue reference of type ‘const int&&’ to lvalue of type ‘int’
	const int &&ref8{ 5 }; // H

	return 0;
}
//***********************************QUIZ***

/*
╔══════════════════════════════════════════════════════════════════════════════╗
║               CONCEPT ANALYSIS — R-ValueReferences.cpp                    ║
╚══════════════════════════════════════════════════════════════════════════════╝

## Concepts

### 1. Rvalue References (`T&&`)
C++11 introduced rvalue references that bind ONLY to rvalues. They allow
modification of temporaries — the foundation of move semantics.

### 2. Reference Binding Rules
| Reference Type       | Binds to lvalue? | Binds to rvalue? | Can modify? |
|---------------------|-----------------|-----------------|-------------|
| `T&`                | Yes             | No              | Yes         |
| `const T&`          | Yes             | Yes             | No          |
| `T&&`               | No              | Yes             | Yes         |
| `const T&&`         | No              | Yes             | No          |

### 3. Rvalue References as Function Parameters
When both `fun(const int&)` and `fun(int&&)` exist, rvalue arguments prefer
the `&&` overload. Named rvalue references (`int&& ref{16}`) are themselves
**lvalues** (they have names and addresses).

**Code walkthrough:**
- `fun(ref)` calls the lvalue overload even though `ref` was declared as `&&`,
  because `ref` is a named entity (lvalue).

**Key Takeaway:** Rvalue references extend temporary lifetimes and enable move
semantics. A named `&&` variable is an lvalue.

#### Alternatives / Idiomatic C++
- Use `std::move(ref)` to cast a named rvalue reference back to an rvalue.
- Forwarding references (`T&&` in templates) use reference collapsing — 
  different from plain rvalue references.

#### Real-World Usage
- **STL containers**: `push_back(T&&)` overloads use rvalue references to
  enable move-insertion of temporaries.
- **Folly**: Move-only types throughout for efficient async programming.

---

## 🔁 Quick Revision
- `T&&` = rvalue reference; binds only to rvalues.
- `const T&` = universal reader; binds to both.
- Named rvalue reference = lvalue (has identity).
- `std::move` casts lvalue to rvalue reference.

### ⚠️ Gotchas
- `T&&` in a template is a **forwarding reference**, not an rvalue reference!
- Never return `T&&` from a function (dangling reference).
*/