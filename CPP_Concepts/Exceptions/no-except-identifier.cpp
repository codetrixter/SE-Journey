/**
 * Here we are going to discuss about the no-except identifier and why and when it should be used.
 * 
 * //! List of non-throwing functions
 * //! Functions that are implicitly non-throwing:
   //! 1- Destructors
   
   //! Functions that are non-throwing by default for implicitly-declared or defaulted functions:
   //! 1- Constructors: default, copy, move
   //! 2- Assignments: copy, move
   //! 3- Comparison operators (as of C++20)

   //! Functions that are potentially throwing (if not implicitly-declared or defaulted):
   //! 1- Normal functions
   //! 2- User-defined constructors
   //! 3- User-defined operators
 * 
 */

#include <iostream>

class Doomed
{
public:
    ~Doomed()
    {
        std::cout << "Doomed destructed\n";
    }
};

void thrower()
{
    std::cout << "Throwing exception\n";
    throw 1;
}

void pt()
{
    std::cout << "pt (potentally throwing) called\n";
    //This object will be destroyed during stack unwinding (if it occurs)
    Doomed doomed{};
    thrower();
    std::cout << "This never prints\n";
}

void nt() noexcept
{
    std::cout << "nt (noexcept) called\n";
    //This object will be destroyed during stack unwinding (if it occurs)
    Doomed doomed{};
    thrower();
    // since the thrown exception by the thrower() is not handled here, hence the propagation will try to go 
    // to caller of nt, which is tester, but since nt() is noexcept, it will not allow such propagation
    // and will call std::terminate.
    std::cout << "this never prints\n";
}

void tester(int c) noexcept
{
    std::cout << "tester (noexcept) case " << c << " called\n";
    try
    {
        (c == 1) ? pt() : nt();
    }
    catch (...)
    {
        std::cout << "tester caught exception\n";
    }
}

int main()
{
    std::cout << std::unitbuf; // flush buffer after each insertion
    std::cout << std::boolalpha; // print boolean as true/false
    tester(1);
    std::cout << "Test successful\n\n";
    tester(2);
    std::cout << "Test successful\n";

    return 0;
}