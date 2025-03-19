/**
 * *Know what functions C++ silently writes and calls.
 *
 * *IMPORTANT::When a class is given empty then compiler by default creates following functions.
 * 1. Default Ctor
 * 2. Copy Ctor
 * 3. Copy assignment operator.
 * 4. Move Ctor.
 * 5. Move assignement operator.
 * 6. destructor.
 *
 * *IMPORTANT::Once you define your own versions of the above default functions, compiler no longer creates
 * them for you.
 * 
 * *If a Base class has copy assignement operator as private, then derived class will not create default 
 * copy assignment operator.
 *
 */
#include <iostream>
#include <string>
using namespace std;

// case 1*****
/* template <typename T>
class NamedObject
{
public:
    NamedObject(const char *name, const T &value):
    nameValue{name},
    objectValue{value}
    {};
    NamedObject(const std::string &name, const T &value):
    nameValue{name},
    objectValue{value}
    {};

private:
    std::string nameValue;
    T objectValue;
}; */

// case 2*****
template <typename T>
class NamedObject
{
public:
    NamedObject(const std::string &name, const T &value) : nameValue{name},
                                                           objectValue{value} {};

    // private:
    std::string &nameValue;
    const T objectValue;
};

void runCase1()
{
    NamedObject<int> ob1("Smallest Prime Number", 2);
    NamedObject<int> ob2(ob1); // calls copy ctor.

    cout << ob2.nameValue << " " << ob2.objectValue;
}

void runCase2()
{
    std::string newDog("Persephone");
    std::string oldDog("Satch");

    NamedObject<int> p(newDog, 2);
    NamedObject<int> s(oldDog, 36);
    p = s;
}

int main(int argc, char const *argv[])
{
    // Here neither copy ctor nor copy ass. operatirs were created by the compiler.
    //runCase1();

    // Here since the memebre variables are of type reference and constant, the compiler does not knows
    // how to write a default copy ctor/copy ass. oper. function, since references cannot be made to refere 
    // to a different object and constant member variables cannot be assigned values just like that.
    runCase2();
    return 0;
}
