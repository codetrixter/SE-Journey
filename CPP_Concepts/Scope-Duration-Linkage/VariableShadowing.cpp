/**
 * *SHADOWING:
 * - This referes to hiding the local varible when a globale variable is defined with same name
 * 
 * !GCC and Clang support the flag -Wshadow that will generate warnings if a variable is shadowed.
 * !There are several subvariants of this flag (-Wshadow=global, -Wshadow=local, and -Wshadow=compatible-local. Consult the GCC documentation 
 * !for an explanation of the differences.
 */

 #include <iostream>
int value { 5 }; // global variable

int main()
{
    int value { 7 }; // hides the global variable value
    ++value; // increments local value, not global value

    --(::value); // decrements global value, not local value (parenthesis added for readability)

    std::cout << "local variable value: " << value << '\n';
    std::cout << "global variable value: " << ::value << '\n';

    return 0;
} // local value is destroyed