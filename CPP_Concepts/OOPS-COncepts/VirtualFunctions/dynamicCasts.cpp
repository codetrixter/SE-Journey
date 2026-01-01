/**
 * @file dynamicCasts.cpp
 * @author Abhishek
 * @brief Here we discuss about the Dynamic casts:
 * 1- In an inheritance scenario where we want to call derived class non-virtual member using Base pointer.
 *  There are two ways of solving the above problem and call the derived class members"
 *  a. put the member of the derived in the Base class as virtual.
 *  b. downcast the Base pointer to derived pointer, which is the opposite of upcasting (converting derived 
 * to base pointer) which is done implicitly by the compiler. This is done via dynamic_cast
 * NOTE** Always check for the null pointer on the result of the dynamic cast.
 * 
 * Also note that there are several cases where downcasting using dynamic_cast will not work:

    a- With protected or private inheritance.
    b- For classes that do not declare or inherit any virtual functions (and thus don’t have a virtual table).
    c- In certain cases involving virtual base classes (see this page for an example of some of these cases, 
    and how to resolve them).

   2- the static cast works as well where the dynamic casting is used, but there is a caveat,
   the static cast does no runtime type checking to see if the conversion makes any sense or not, hence we 
   might get undefined behaviour or seg fault. 

   3- Dynamic casting works with reference as it worked with pointers, the only difference is when the casting is 
   unsuccessfull an std::bad_cast exception is thrown since there is no such thing as null reference.

   ******************
   Downcasting vs virtual functions::

    In general, using a virtual function should be preferred over downcasting. However, there are times when 
    downcasting is the better choice:

    a.When you can not modify the base class to add a virtual function (e.g. because the base class is part 
    of the standard library)
    b.When you need access to something that is derived-class specific (e.g. an access function that only 
    exists in the derived class)
    c.When adding a virtual function to your base class doesn’t make sense (e.g. there is no appropriate value 
    for the base class to return). Using a pure virtual function may be an option here if you don’t need to 
    instantiate the base class.

   A warning about dynamic_cast and RTTI::

    Run-time type information (RTTI) is a feature of C++ that exposes information about an object’s data type at runtime. This capability is leveraged by dynamic_cast. Because RTTI has a pretty significant space performance cost, some compilers allow you to turn RTTI off as an optimization. Needless to say, if you do this, dynamic_cast won’t function correctly
   ******************
 * @version 0.1
 * @date 2022-08-05
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <string>
//****************point-1***
class Base
{
protected:
	int m_value{};

public:
	Base(int value)
		: m_value{value}
	{
	}

	virtual ~Base() = default;
};

class Derived : public Base
{
protected:
	std::string m_name{};

public:
	Derived(int value, const std::string& name)
		: Base{value}, m_name{name}
	{
	}

	const std::string& getName() const { return m_name; }
};

/// How can we call the drived member here??
Base* getObject(bool returnDerived)
{
	if (returnDerived)
		return new Derived{1, "Apple"};
	else
		return new Base{2};
}

void mainVersionOne()
{
    Base* base = getObject(true);   // how do we print the Derived object's name here, having only a Base pointer?
    //base->getName();  //error: Base has no member getName()
    delete base;
    //return 0;
}

void mainVersionTwo()
{
    Base* base = getObject(true);

    /// static_cast also works here, need to know the difference between the two.
    Derived* derCast = dynamic_cast<Derived*>(base);
    std::cout << derCast->getName();

    delete base;
    return ;
}

int main(int argc, char const *argv[])
{
    /// The above example of dynamic casting worked because the returned derived object was pointed by Base pointer,
    /// what if the returning object was of base type, the the dynamic cast would not have worked
    Base* b{ getObject(true) };

    /// If the dynamic cast fails then the result of the conversion is a null pointer
    /// hence the behaviour will be undefined or segfault.
	Derived* d{ dynamic_cast<Derived*>(b) }; // use dynamic cast to convert Base pointer into Derived pointer

    /// If the getObject() is called with false and no null check is done the program thows seg fault.
	if (d) // make sure d is non-null
		std::cout << "The name of the Derived is: " << d->getName() << '\n';

	delete b;

    return 0;
}
//****************point-1***
//****************point-2***
// Class identifier
/* enum class ClassID
{
	base,
	derived
	/// Others can be added here later
};

class Base
{
protected:
	int m_value{};

public:
	Base(int value)
		: m_value{value}
	{
	}

	virtual ~Base() = default;
	virtual ClassID getClassID() const { return ClassID::base; }
};

class Derived : public Base
{
protected:
	std::string m_name{};

public:
	Derived(int value, const std::string& name)
		: Base{value}, m_name{name}
	{
	}

	const std::string& getName() const { return m_name; }
	virtual ClassID getClassID() const { return ClassID::derived; }

};

Base* getObject(bool bReturnDerived)
{
	if (bReturnDerived)
		return new Derived{1, "Apple"};
	else
		return new Base{2};
}

int main()
{
	Base* b{ getObject(true) };

	if (b->getClassID() == ClassID::derived)
	{
		/// We already proved b is pointing to a Derived object, so this should always succeed
		Derived* d{ static_cast<Derived*>(b) };
		std::cout << "The name of the Derived is: " << d->getName() << '\n';
	}

	delete b;

	return 0;
} */
//****************point-2***
//****************point-3***
/* class Base
{
protected:
	int m_value;

public:
	Base(int value)
		: m_value{value}
	{
	}

	virtual ~Base() = default;
};

class Derived : public Base
{
protected:
	std::string m_name;

public:
	Derived(int value, const std::string& name)
		: Base{value}, m_name{name}
	{
	}

	const std::string& getName() const { return m_name; }
};

int main()
{
	Derived apple{1, "Apple"}; // create an apple
	Base& b{ apple }; // set base reference to object
	Derived& d{ dynamic_cast<Derived&>(b) }; // dynamic cast using a reference instead of a pointer

	std::cout << "The name of the Derived is: " << d.getName() << '\n'; // we can access Derived::getName through d

	return 0;
} */
//****************point-3***

