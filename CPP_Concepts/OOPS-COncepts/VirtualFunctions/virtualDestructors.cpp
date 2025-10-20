/**
 * @file virtualDestructors.cpp
 * @author Abhishek
 * @brief Here we discuss the usage of following:
 * 1- Virtual Destructors: This is necessary for avoiding memory leaks since the derived class objects will not be deallocated properly since 
 * the detructor of only base class is called as it is not virtual.
 * 2- Ignoring Virtualization: In cases when you want to call a base class version of the function which is virtual, you can do so by using  :: 
 * "scope resolution operator".
 * @version 0.1
 * @date 2022-07-31
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>

//******************point-1***
class Base
{
public:
    /// by making this virtual we ensure that derived class detructor is also called while deleting base class objects.
    virtual ~Base() 
    {
        std::cout << "Calling ~Base()\n";
    }
};

class Derived: public Base
{
private:
    int* m_array;

public:
    Derived(int length)
      : m_array{ new int[length] }
    {
    }

    ~Derived() // note: not virtual (your compiler may warn you about this)
    {
        std::cout << "Calling ~Derived()\n";
        delete[] m_array;
    }
};

int main()
{
    Derived *derived { new Derived(5) };
    Base *base { derived };

    delete base;

    return 0;
}
//******************point-1***
//******************point-2***
/* class Base
{
public:
    virtual ~Base() = default;
    virtual const char* getName() const { return "Base"; }
};

class Derived: public Base
{
public:
    virtual const char* getName() const { return "Derived"; }
};

/// How can we call the base version of the getName() in this case.
int main(int argc, char const *argv[])
{
    Derived der;
    Base* base{&der};

    //like this using scope resolution operator.
    std::cout << base->Base::getName();    
    return 0;
} */
//******************point-2***
//******************Herb Stutters Wisdome***
/*
//-----------------------------------------------Question------------------------------------------------------------------------------
This is a common question asked by new programmers. As noted in the top example, if the base class destructor isn’t marked as virtual, 
then the program is at risk for leaking memory if a programmer later deletes a base class pointer that is pointing to a derived object. 
One way to avoid this is to mark all your destructors as virtual. But should you?
//-----------------------------------------------Question------------------------------------------------------------------------------
//-----------------------------------------------Answer------------------------------------------------------------------------------
It’s easy to say yes, so that way you can later use any class as a base class -- but there’s a performance penalty for doing so 
(a virtual pointer added to every instance of your class). So you have to balance that cost, as well as your intent.

Conventional wisdom (as initially put forth by Herb Sutter, a highly regarded C++ guru) has suggested avoiding the non-virtual destructor 
memory leak situation as follows, “A base class destructor should be either public and virtual, or protected and nonvirtual.” A class with a 
protected destructor can’t be deleted via a pointer, thus preventing the accidental deleting of a derived class through a base pointer when 
the base class has a non-virtual destructor. Unfortunately, this also means the base class can’t be deleted through a base class pointer, 
which essentially means the class can’t be dynamically allocated or deleted except by a derived class. This also precludes using smart pointers 
(such as std::unique_ptr and std::shared_ptr) for such classes, which limits the usefulness of that rule (we cover smart pointers in a later chapter). 
It also means the base class can’t be allocated on the stack. That’s a pretty heavy set of penalties.
//-----------------------------------------------Answer------------------------------------------------------------------------------
Now that the final specifier has been introduced into the language, our recommendations are as follows:

If you intend your class to be inherited from, make sure your destructor is virtual.
If you do not intend your class to be inherited from, mark your class as final. This will prevent other classes from inheriting from it in the 
first place, without imposing any other use restrictions on the class itself. */
//******************Herb Stutters Wisdome***