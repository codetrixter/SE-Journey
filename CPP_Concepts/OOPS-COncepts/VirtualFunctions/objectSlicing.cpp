/**
 * @file objectSlicing.cpp
 * @author Abhishek
 * @brief Here we discuss about Object Slicing:
 * 1- Whenever we assign a derived instance to a base instance, only the base class part of the object 
 * is copied and the rest is removed, this is called slicing.
 * 2- There are several ways in which object slicing can occur, some of them are:
 *      a. passing arguments to fuctions by value : In order to avoid ths function parameter can have reference 
 * to the object.
 *      b. using vectors of type base class : In order to avoid this you can have pointer as a type of the 
 * vector since keeping it as a reference will not work.
 * 3- The Frankenobject: This is the case where after the slicing is done the resulting object has both 
 * base and derived part of the instance.
 * @version 0.1
 * @date 2022-08-04
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <vector>
#include <functional>   //std::reference_wrapper

/* class Base
{
protected:
    int m_value{};

public:
    Base(int value)
        : m_value{ value }
    {
    }

    virtual const char* getName() const { return "Base"; }
    int getValue() const { return m_value; }
};

class Derived: public Base
{
public:
    Derived(int value)
        : Base{ value }
    {
    }

    const char* getName() const override { return "Derived"; }
};

/// a version of object slicing : using pass by reference to avoid slicing
void printName(Base& base)
{
    std::cout << base.getName() << " " << base.getValue();
}

int main(int argc, char const *argv[])
{
    // Derived der{10};
    // /// Here derived part of the object is sliced off when assigning derived object to base class object.
    // /// Here a copy constructor is called which is initializing base object using derived instance.
    // Base base{der};

    // /// Hence ony base part of the functionality is ran
    // std::cout << base.getName() << " " << base.getValue();

    //-------------------------------------

    // Derived derived{ 5 };
    // printName(derived);

    //-------------------------------------
    /// another version of object slicing
    // Base base{ 10 };
    // Derived der{ 23 };

    // std::vector<Base> v1{};
    // v1.push_back(base);
    // v1.push_back(der);

    // std::cout << "object sliced....\n";
    // for(auto& item : v1)
    // {
    //     std::cout << item.getName() << " " << item.getValue();
    // }
    // /// In order to avoid slicing in above scenario we can use pointer as a type of the vector.
    // /// We are not using reference as they cannot be reassined values and need to be initialized while definition.

    // std::vector<Base*> v2{};
    // v2.push_back(new Base{25});
    // v2.push_back(new Derived{26});

    // std::cout << "\nobject not sliced...\n";
    // for(auto item : v2)
    // {
    //     std::cout << item->getName() << " " << item->getValue();
    // }
    
    //--------------------------------------------------------------

    /// another way to solve the above slicing issue is to use std::reference_wrapper
    std::vector<std::reference_wrapper<Base>> v{}; // a vector of reassignable references to Base

	Base b{ 5 }; // b and d can't be anonymous objects
	Derived d{ 6 };

	v.push_back(b); // add a Base object to our vector
	v.push_back(d); // add a Derived object to our vector

	/// Print out all of the elements in our vector
	/// we use .get() to get our element out of the std::reference_wrapper
	for (const auto& element : v) // element has type const std::reference_wrapper<Base>&
		std::cout << "I am a " << element.get().getName() << " with value " << element.get().getValue() << '\n';

    return 0;
} */
//**************Frankenobject***
class Base
{
public:
    int m_value{};
    char* m_name;

public:
    Base(int value, char* name)
        : m_value{value}, m_name{name}
    {
    }

    virtual ~Base() = default;  // Good practice for polymorphic base

    virtual const char* getName() const { return m_name; }
    virtual int getValue() const { return m_value; }
};

class Derived : public Base
{
    int m_increment{};  // Derived-specific data

public:
    Derived(int value, int increment, char* name)
        : Base(value, name), m_increment{increment}
    {
    }

    const char* getName() const override { return m_name; }

    int getValue() const override 
    { 
        return m_value + m_increment;  // Uses base m_value + derived-specific increment
    }

    int getIncrement() const { return m_increment; }  // For demonstration
};

int main()
{
    Derived d1{10, 100, const_cast<char*>("d1")};  // base value 10, derived adds +100 → visible 110
    Derived d2{20,   1, const_cast<char*>("d2")};  // base value 20, derived adds +1  → visible 21

    Base& base = d2;

    std::cout << "Before assignment:\n";
    std::cout << "  d2.getValue(): " << d2.getValue() << "  (base " << d2.m_value << " + derived increment " << d2.getIncrement() << ")\n\n";

    // This triggers slicing: copies only Base part of d1 into d2's Base part
    base = d1;

    std::cout << "After base = d1 (object slicing occurred):\n";
    std::cout << "  d2.getValue(): " << d2.getValue() << "  (base now " << d2.m_value 
              << " [copied from d1] + derived increment " << d2.getIncrement() 
              << " [still d2's original])\n";
    std::cout << "  base.getValue(): " << base.getValue() << "  (same as above, virtual dispatch)\n";
    std::cout << "  d2.getName(): " << d2.getName() << "  (still original d2 name)\n";

    return 0;
}
//**************Frankenobject***

