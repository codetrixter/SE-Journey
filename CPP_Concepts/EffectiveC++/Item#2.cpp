/**
 * *Prefer consts, enums and inlines to #defines.
 * !1- For simple constants, prefer const objects or enums to #defines.
 * !2- For function-like macros, prefer inline functions to #defines.
*/

#include <iostream>
//instead of this, use globbal constants
//#define ASPECT_RATIO 1.653
const double ASPECT_RATIO = 1.653;

//------------------------------------------------
//Two special cases while defining constants.
//1- Make pointers as const in addition to the const object that the pointer points to.
const char* const authorName = "Abhishek Mishra";

//2- FOr class specific constants make them static so that they can only be initialized once.
class GamePlayer
{
    private:
    //Not valid for old compilers.
    static const int NumTurn = 5;
    int scores[NumTurn];
};
//initialization for old compilers which did not allow in place static member initialization like above.
//const int GamePlayer::NumTurn = 5;
//------------------------------------------------

//-----------enum hack------------
class GamePlayerOne
{
    //Since old compilers incorrectly prohibited in-class init for static constants.
    //1- It prohibits the user to get pointer or reference of the constant members.(Item#18-further explore)
    //2- It provides ease in identification.
    enum { NumTurn = 5};
    int scores[NumTurn];
};
//-----------enum hack------------

//----------inline uses-----------
// call f with the maximum of a and b
//#define CALL_WITH_MAX(a, b) f((a) > (b) ? (a) : (b))

template<typename T>
// because we don’t
inline void callWithMax(const T& a, const T& b)
// know what T is, we
{
// pass by reference-to-
f(a > b ? a : b);
// const — see Item 20
}

//----------inline uses-----------

int main(int argc, char const *argv[])
{
    int a = 5, b = 0;
    callWithMax(++a, b);
    std::cout << a << ", " << b << "\n";
    callWithMax(++a, b+10);
    std::cout << a << ", " << b << "\n";

    return 0;
}
