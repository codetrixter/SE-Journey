/**
 * @file BasicPointersAndReferencetypesInInheritance.cpp
 * @author Abhishek 
 * @brief Here we discuss about the ability to store derived class instance in base 
 * reference/pointer.
 * 1- We can store derived class objects in the reference/pointers for the base type.
 * 2- The above technique is usefult for places where there are lots of derived types and a common functionality needs to be implemented,
 * then that common functionality can be implemented with the Reference to the base type so that this functionality can accept any derived
 * object.
  //TODO:chapter end Quiz
 * @version 0.1
 * @date 2022-07-21
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <string_view>
#include <string>
#include <array>
//*****************point-1***
/* class Base
{
    protected:
    int mValue {};

    public:
    Base(int value)
    : mValue(value)
    {
    }

    std::string_view getName() const 
    {
        return "Base";
    }
    int getValue() const
    {
        return mValue;
    }
};

class Derived: public Base
{
    public:
    Derived(int value)
    : Base(value)
    {
    }

    std::string_view getName() const
    {
        return "Derived";
    }
    int getValueDoubled() const
    {
        return mValue*2;
    }
};

int main(int argc, char const *argv[])
{
    Derived der{ 5 };
    std::cout << "der is " << der.getName() << " and has a value "
              << der.getValue() << std::endl;

    Derived& rDer{ der };
    std::cout << "rDer is " << rDer.getName() << " and has a value "
              << rDer.getValue() << std::endl;

    Derived* pDer{ &der };
    std::cout << "pDer is " << pDer->getName() << " and has a value "
              << pDer->getValue() << std::endl;


    //******************Base pointers and references

    Base& rDerived{der};
    Base* pDerived{&der};

    std::cout << "der is " << der.getName() << " and has a value "
              << der.getValue() << std::endl;
    std::cout << "rDerived is " << rDerived.getName() << " and has a value "
              << rDerived.getValue() << std::endl;
    std::cout << "pDerived is " << pDerived->getName() << " and has a value "
              << pDerived->getValue() << std::endl;
    return 0;
} */
//*****************point-1***
//*****************point-2***
class Animal
{
protected:
    std::string m_name;

    /// We're making this constructor protected because
    /// we don't want people creating Animal objects directly,
    /// but we still want derived classes to be able to use it.
    Animal(std::string_view name)
        : m_name{ name }
    {
    }

    /// To prevent slicing (covered later)
    Animal(const Animal&) = default;
    Animal& operator=(const Animal&) = default;

public:
    std::string_view getName() const { return m_name; }
    std::string_view speak() const { return "???"; }
};

class Cat: public Animal
{
public:
    Cat(std::string_view name)
        : Animal{ name }
    {
    }

    std::string_view speak() const { return "Meow"; }
};

class Dog: public Animal
{
public:
    Dog(std::string_view name)
        : Animal{ name }
    {
    }

    std::string_view speak() const { return "Woof"; }
};

/// without using reference to Base class if we wanted to print each animals name and speak the we would have to overload each function.
void reportAnimal(const Animal* animal)
{
    std::cout << animal->getName() << " says " << animal->speak() << std::endl;
}

// int main()
// {
//     const Cat cat{ "Fred" };
//     std::cout << "cat is named " << cat.getName() << ", and it says " << cat.speak() << '\n';

//     const Dog dog{ "Garbo" };
//     std::cout << "dog is named " << dog.getName() << ", and it says " << dog.speak() << '\n';

//     const Animal* pAnimal{ &cat };
//     std::cout << "pAnimal is named " << pAnimal->getName() << ", and it says " << pAnimal->speak() << '\n';

//     pAnimal = &dog;
//     std::cout << "pAnimal is named " << pAnimal->getName() << ", and it says " << pAnimal->speak() << '\n';

//     /// same method is need for printing name and speak of all the animals, just the underlying object changes.
//     reportAnimal(pAnimal);

//     return 0;
// } 
//--------------Alternatively we can do something like this with pointers/references of Base type.

int main()
{
    const Cat fred{ "Fred" };
    const Cat misty{ "Misty" };
    const Cat zeke{ "Zeke" };

    const Dog garbo{ "Garbo" };
    const Dog pooky{ "Pooky" };
    const Dog truffle{ "Truffle" };

    /// Set up an array of pointers to animals, and set those pointers to our Cat and Dog objects
    /// Note: to_array requires C++20 support (and at the time of writing, Visual Studio 2022 still doesn't support it correctly)
    /// const auto animals{ std::to_array<const Animal*>({&fred, &garbo, &misty, &pooky, &truffle, &zeke }) };

    /// Before C++20, with the array size being explicitly specified
    const std::array<const Animal*, 6> animals{ &fred, &garbo, &misty, &pooky, &truffle, &zeke };

    for (const auto animal : animals)
    {
        std::cout << animal->getName() << " says " << animal->speak() << '\n';
    }

    return 0;
}
//*****************point-2***