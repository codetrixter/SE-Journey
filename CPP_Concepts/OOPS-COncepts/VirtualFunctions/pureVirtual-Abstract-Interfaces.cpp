/**
 * @file pureVirtual-Abstract-Interfaces.cpp
 * @author Abhishek
 * @brief Here we discuss about following:
 * 1- Pure virtual functions: These functions are the functions that are required to be redefined 
 * in the derived classes. These functions are maked by 0 suffixed at the end of the function signature.
 * 2- Abstract classes: These classes conatin one or more puer virtual functions and cannot be instantiated. Hence it is
 * necessary to extend/implemet these classes and override their pure virtual functions.
 * 3- Interface classes: These classes are the ones that do not have any function bodies, meaning all the functions 
 * are pure in nature.
 * 4- pure virtual functions can have bodies but they still need to be redefined/implemented in the derived classes
 * 
 * Important Note::**
 * Pure virtual functions and the virtual table
    Abstract classes still have virtual tables, as these can still be used if you have a pointer or reference to 
    the abstract class. The virtual table entry for a class with a pure virtual function will generally either 
    contain a null pointer, or point to a generic function that prints an error 
    (sometimes this function is named __purecall).
 * @version 0.1
 * @date 2022-08-01
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <string_view>
#include <string>

//*************Point-1/2***
/* class Animal // This Animal is an abstract base class
{
protected:
    std::string m_name;

public:
    Animal(const std::string& name)
        : m_name{ name }
    {
    }

    const std::string& getName() const { return m_name; }
    virtual const char* speak() const = 0; // note that speak is now a pure virtual function

    virtual ~Animal() = default;
};

class Cat: public Animal
{
public:
    Cat(const std::string& name)
        : Animal{ name }
    {
    }

    const char* speak() const override { return "Meow"; }
};

class Dog: public Animal
{
public:
    Dog(const std::string& name)
        : Animal{ name }
    {
    }

    const char* speak() const override { return "Woof"; }
};

class Cow: public Animal
{
public:
    Cow(const std::string& name)
        : Animal{ name }
    {
    }

    // We forgot to redefine speak
    const char* speak() const override { return "Moo"; }
};

int main()
{
    Cow cow{ "Betsy" };
    std::cout << cow.getName() << " says " << cow.speak() << '\n';

    return 0;
} */
//*************Point-1/2***
//*************Point-4***
/* class Animal // This Animal is an abstract base class
{
protected:
    std::string m_name;

public:
    Animal(const std::string& name)
        : m_name{ name }
    {
    }

    std::string getName() { return m_name; }
    virtual const char* speak() const = 0; // The = 0 means this function is pure virtual

    virtual ~Animal() = default;
};

const char* Animal::speak() const  // even though it has a body
{
    return "buzz";
}

class Dragonfly: public Animal
{

public:
    Dragonfly(const std::string& name)
        : Animal{name}
    {
    }

    const char* speak() const override// this class is no longer abstract because we defined this function
    {
        return Animal::speak(); // use Animal's default implementation
    }
};

int main()
{
    Dragonfly dfly{"Sally"};
    std::cout << dfly.getName() << " says " << dfly.speak() << '\n';

    return 0;
} */
//*************Point-4***
//*************Point-3***
#include <cmath>
class IErrorLog
{
public:
    virtual bool openLog(const char *filename) = 0;
    virtual bool closeLog() = 0;

    virtual bool writeError(const char *errorMessage) = 0;

    virtual ~IErrorLog() {} // make a virtual destructor in case we delete an IErrorLog pointer, so the proper derived destructor is called
};

//passing the log interface instance is beneficial, since any class derived from this iterface can be passed here.
//so this function can take error messages that needs to printed on console or file or some browser etc.
double mySqrt(double value, IErrorLog& log)
{
    if (value < 0.0)
    {
        log.writeError("Tried to take square root of value less than 0");
        return 0.0;
    }
    else
    {
        return std::sqrt(value);
    }
}
//*************Point-3***