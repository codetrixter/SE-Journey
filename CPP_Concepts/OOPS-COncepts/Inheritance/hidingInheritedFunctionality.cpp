/**
 * @file hidingInheritedFunctionality.cpp
 * @author Abhishek
 * @brief Here we discuss how we can modify the properties of the inherited members:
 * 1- We can change the access specifier of the inherited memebers.
 * 2- We can hide the members of the Base class in derived class by various ways:
 * -- by making public data members as private in derived class.
 * -- by making members functions as delete in derived class.
 * @version 0.1
 * @date 2022-06-16
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>

//*************point - 1***
/* class Base
{
private:
    int m_value {};

public:
    Base(int value)
        : m_value { value }
    {
    }

protected:
    void printValue() const { std::cout << m_value; }
};

class Derived: public Base
{
    public:
    Derived(int val): Base{val}
    {}

    //printValue was protected member but we changed it to public by using 
    using Base::printValue;  
};

int main(int argc, char const *argv[])
{
    Derived d{ 10};
    //This code works since the printValue is public.
    d.printValue();
    return 0;
} */

//*************point - 1***

//*************point - 2 -- a ***
/* class Base
{
    private:
    int m_value {};
};

class Derived: public Base
{
    private:
    //make Base classes m_value public as private in derived class
    using Base::m_value;

    public::
    Derived(int value)
    //we can't initialize base class memeber 
    {
        //But we can assign value to it
        m_value = value;
    }
};

int main(int argc, char const *argv[])
{
    Derived d{10};
    //won't work since this is converted to private in derived class
    //std::cout << d.m_value << std::endl;
    return 0;
} */

//*************point - 2 -- a ***

//*************point - 2 -- b ***
class Base
{
private:
	int m_value {};

public:
	Base(int value)
		: m_value { value }
	{
	}

	int getValue() const { return m_value; }
};

class Derived : public Base
{
public:
	Derived(int value)
		: Base { value }
	{
	}


	int getValue() = delete; // mark this function as inaccessible
};

int main()
{
	Derived derived { 7 };

	// The following won't work because getValue() has been deleted!
	//std::cout << derived.getValue();

    //base version of the getValue can be called like below
    std::cout << derived.Base::getValue() << std::endl;

    //another way to call Vase version of getValue
    std::cout << static_cast<Base&>(derived).getValue() << std::endl;

	return 0;
}
//*************point - 2 -- b ***
