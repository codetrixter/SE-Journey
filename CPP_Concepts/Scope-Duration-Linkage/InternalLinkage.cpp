/**
 * *Internal Linkage
 * ! - Global varibales nad function identifiers can either have internal or external linkage.
 * ! - An identifier with internal linkage can be seen and used within a single translation unit, but it is not accessible from other translation units. 
 * !   This means that if two source files have identically named identifiers with internal linkage, those identifiers will be treated as independent 
 * !   (and do not result in an ODR violation for having duplicate definitions).
 * ! - Global variables with internal linkage are called internal varibales
 * ! - Functions can also be made to have internal linkage by adding static to their declaration
 * ! - Typically internal linkage is used fro following 2 reasons:
 *      1- Avoid naming collisions
 *      2- Restrict th euse of an identifier
 * 
 * NOTE: The C++11 standard (appendix C) provides the rationale for why const variables have internal linkage by default: “Because const objects can be
 *  used as compile-time values in C++, this feature urges programmers to provide explicit initializer values for each const. This feature allows the
 *  user to put const objects in header files that are included in many compilation units.”

The designers of C++ intended two things:

Const objects should be usable in constant expressions. In order to be usable in a constant expression, the compiler must have seen a definition 
(not a declaration) so it be evaluated at compile-time.
Const objects should be able to be propagated via header files.
Objects with external linkage can only be defined in a single translation unit without violating the ODR -- other translation units must access those
 objects via a forward declaration. If const objects had external linkage by default, they would only be usable in constant expressions in the 
 single translation unit containing the definition, and they could not be effectively propagated via header files, as #including the header into
 more than one source file would result in an ODR violation.

Objects with internal linkage can have a definition in each translation unit where they are needed without violating the ODR. This allows const objects
 to be placed in a header file and #included into as many translation units as desired without violating the ODR. And since each translation unit
 has a definition rather than a declaration, this ensures that those constants can be used in constant expressions within the translation unit.

Inline variables (which can have external linkage without causing ODR violations) weren’t introduced until C++17.
 */

 #include <iostream>

// static int g_x{}; // non-constant globals have external linkage by default, but can be given internal linkage via the static keyword

// const int g_y{ 1 }; // const globals have internal linkage by default
// constexpr int g_z{ 2 }; // constexpr globals have internal linkage by default

// int main()
// {
//     std::cout << g_x << ' ' << g_y << ' ' << g_z << '\n';
//     return 0;
// }

//---------------------------------------------------------------------

// This function is declared as static, and can now be used only within this file
// Attempts to access it from another file via a function forward declaration will fail
// In ADD.cpp file:
[[maybe_unused]] static int add(int x, int y)
{
    return x + y;
}

//in main.cpp:

#include <iostream>

int add(int x, int y); // forward declaration for function add

int main()
{
    std::cout << add(3, 4) << '\n';

    return 0;
}   //ERROR: add is outside main's scope