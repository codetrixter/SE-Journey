/**
 * @file polimorphism.cpp
 * @author Abhishek
 * @brief Here we discuss the usage of virtual functions and polymorphism.
 * 1- Using virtual functions we can rename a base reference holding the derived object to call derived version of the members.
 * 2- Never call virtual functions from constructors and destructors:
 *      a. Reason is in virtual inheritance the base class is created and then the derived versions, so whe we call virtual functions from the 
 * base class constructor the derived version has not even been created yet, so the base version will be called.
 * @version 0.1
 * @date 2022-07-29
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <string_view>
#include <string>
#include <array>
//*************Point-1***
/* class Base
{
public:
    virtual std::string_view getName() const 
    { 
        return "Base"; 
    }
};

class Derived: public Base
{
public:
    virtual std::string_view getName() const 
    { 
        return "Derived"; 
    }
};

int main()
{
    Derived derived;
    Base& rBase{ derived };
    /// calls the derived version of the getName()
    std::cout << "rBase is a " << rBase.getName() << '\n';

    return 0;
} */
//-----------------------Alternate
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
    /// only base class function needs to be specified as virtual rest all derived version of the functions are optional
    virtual std::string_view speak() const { return "???"; }
};

class Cat: public Animal
{
public:
    Cat(std::string_view name)
        : Animal{ name }
    {
    }

    virtual std::string_view speak() const { return "Meow"; }
};

class Dog: public Animal
{
public:
    Dog(std::string_view name)
        : Animal{ name }
    {
    }

    virtual std::string_view speak() const { return "Woof"; }
};

/// without using reference to Base class if we wanted to print each animals name and speak the we would have to overload each function.
void reportAnimal(const Animal* animal)
{
    std::cout << animal->getName() << " says " << animal->speak() << std::endl;
}
int main(int argc, char const *argv[])
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

    /// all the speak functions are called properly since we used virtual keyword.
    for (const auto animal : animals)
    {
        std::cout << animal->getName() << " says " << animal->speak() << '\n';
    }
    return 0;
}
//*************Point-1***
//*************QUIZ-1***
/* class A
{
public:
    virtual std::string_view getName() const { return "A"; }
};

class B: public A
{
public:
    virtual std::string_view getName() const { return "B"; }
};

class C: public B
{
public:
/// Note: no getName() function here
};

class D: public C
{
public:
    virtual std::string_view getName() const { return "D"; }
};

int main()
{
    C c;
    A& rBase{ c };
    /// prints B since that is the most derived version of getName() available.
    std::cout << rBase.getName() << '\n';

    return 0;
} */
//*************QUIZ-1***
//*************QUIZ-2***
/* class A
{
    public:
    A()
    {
        std::cout << "A ctor called";
    }
public:
    virtual std::string_view getName() const { return "A"; }
};

class B: public A
{
public:
    virtual std::string_view getName() const { return "B"; }
};

class C: public B
{
public:
    virtual std::string_view getName() const { return "C"; }
};

class D: public C
{
public:
    virtual std::string_view getName() const { return "D"; }
};

int main()
{
    C c;
    B& rBase{ c }; // note: rBase is a B this time
    std::cout << rBase.getName() << '\n';

    return 0;
} */
//*************QUIZ-2***
//*************QUIZ-3***
/* class A
{
public:
    /// note: no virtual keyword
    std::string_view getName() const { return "A"; }
};

class B: public A
{
public:
    virtual std::string_view getName() const { return "B"; }
};

class C: public B
{
public:
    virtual std::string_view getName() const { return "C"; }
};

class D: public C
{
public:
    virtual std::string_view getName() const { return "D"; }
};

int main()
{
    C c;
    A& rBase{ c };
    /// Since A has no virtual function so A's version of teh function get called hence A.
    std::cout << rBase.getName() << '\n';

    return 0;
} */
//*************QUIZ-3***
//*************QUIZ-4***
/* class A
{
public:
    virtual std::string_view getName() const { return "A"; }
};

class B: public A
{
public:
    /// note: no virtual keyword in B, C, and D
    std::string_view getName() const { return "B"; }
};

class C: public B
{
public:
    std::string_view getName() const { return "C"; }
};

class D: public C
{
public:
    std::string_view getName() const { return "D"; }
};

int main()
{
    C c;
    B& rBase{ c }; // note: rBase is a B this time
    /// C will be printed, reason: Base class has virtual function, hence all subclasses with same function became virtual by default.
    std::cout << rBase.getName() << '\n';

    return 0;
} */
//*************QUIZ-4***
//*************QUIZ-5***
/* class A
{
public:
    virtual std::string_view getName() const { return "A"; }
};

class B: public A
{
public:
    /// Note: Functions in B, C, and D are non-const.
    virtual std::string_view getName() { return "B"; }
};

class C: public B
{
public:
    virtual std::string_view getName() { return "C"; }
};

class D: public C
{
public:
    virtual std::string_view getName() { return "D"; }
};

int main()
{
    C c;
    A& rBase{ c };
    /// A is printed,reason:-> Since A is teh reference storing C's object hence A's version of getName will be called, and when found virtual
    /// compiler will look for most derived version, only to see that there is no derived version of A.getName since others are const, hence not 
    /// considered overriding.
    std::cout << rBase.getName() << '\n';

    return 0;
} */
//*************QUIZ-5***
//*************QUIZ-5***
/* class A
{
public:
	A() { std::cout << getName(); } // note addition of constructor

	virtual std::string_view getName() const { return "A"; }
};

class B : public A
{
public:
	virtual std::string_view getName() const { return "B"; }
};

class C : public B
{
public:
	virtual std::string_view getName() const { return "C"; }
};

class D : public C
{
public:
	virtual std::string_view getName() const { return "D"; }
};

int main()
{
    /// A is printed, reason: when C is created, A is created first due to ctor chaining, and inside A's ctor getName is called which at the time,
    /// cannot llok for derived versions since derived class are not created yet, hence A.getName() is called
	C c;

	return 0;
} */
//*************QUIZ-5***
