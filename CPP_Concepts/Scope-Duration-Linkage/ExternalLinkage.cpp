/**
 * *External Linkage:
 * ! - An identifier with external linkage can be seen and used both from the file in which it is defined, and from other code files 
 * !(via a forward declaration). In this sense, identifiers with external linkage are truly “global” in that they can be used anywhere 
 * !in your program!
 * ! - Function have external linkage by drfault
 * ! - If you want to define an uninitialized non-const global variable, do not use the extern keyword, otherwise C++ will think 
 * !you’re trying to make a forward declaration for the variable.
 * 
 * Question #1
What’s the difference between a variable’s scope, duration, and linkage? What kind of scope, duration, and linkage do global variables have?

Solution
Scope determines where a variable is accessible. Duration determines when a variable is created and destroyed. Linkage determines whether the
 variable can be exported to another file or not.
Global variables have global scope (a.k.a. file scope), which means they can be accessed from the point of declaration to the end of the file
 in which they are declared.
Global variables have static duration, which means they are created when the program is started, and destroyed when it ends.
Global variables can have either internal or external linkage, via the static and extern keywords respectively.
 */

 #include <iostream>
//-------------summary-------------
// Global variable forward declarations (extern w/ no initializer):
extern int g_y1;                 // forward declaration for non-constant global variable
extern const int g_y2;           // forward declaration for const global variable
//extern constexpr int g_y3;       // not allowed: constexpr variables can't be forward declared

// External global variable definitions (no extern)
int g_x1;                        // defines non-initialized external global variable (zero initialized by default)
int g_x2 { 1 };                  // defines initialized external global variable

// External const global variable definitions (extern w/ initializer)
extern const int g_x3 { 2 };     // defines initialized const external global variable
extern constexpr int g_x4 { 3 }; // defines initialized constexpr external global variable

void sayHi(); // forward declaration for function sayHi, makes sayHi accessible in this file
int main()
{
    sayHi(); // call to function defined in another file, linker will connect this call to the function definition, when this is compiled with another.cpp

    return 0;
}