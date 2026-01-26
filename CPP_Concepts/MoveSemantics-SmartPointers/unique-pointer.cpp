/**
 * Here we cover the ins and outs of the smart pointer class called std::unique_ptr.
 *
 * //!IMPORTANT POINTS
 * //!1- unique_ptr class also manages array of objects passed to it, but it is almost always a better choice to use std::vector
 * //!std:array, instead of using fixed/dynamic/c-style array with unique_ptr.
 *
 */

#include <iostream>
#include <memory>
#include <utility> //although it is included for "std::move", but we also get "std::move" from <memory> hence not really need to add this here.

/* class Resource
{
public:
    Resource()
    {
        std::cout << "Resource allocated...\n";
    }

    ~Resource()
    {
        std::cout << "Resource deallocated...\n";
    }

    friend std::ostream &operator<<(std::ostream &out, const Resource &)
    {
        return out << "I am a resource";
    }
}; */
/*
int main(int argc, char const *argv[])
{
    // Resource object is allocated memory on the heap here.
    std::unique_ptr<Resource> pointer{new Resource};

    return 0;
}   */
// memory is deallocated here.

//-------------Proof that unique_ptr manages objects via move semantics--------------

/* int main(int argc, char const *argv[])
{
    std::unique_ptr<Resource> res1{new Resource{}}; // Resource created here
    std::unique_ptr<Resource> res2{};               // Start as nullptr

    std::cout << "res1 is " << (res1 ? "not null\n" : "null\n");
    std::cout << "res2 is " << (res2 ? "not null\n" : "null\n");

    // res2 = res1; // Won't compile: copy assignment is disabled
    res2 = std::move(res1); // res2 assumes ownership, res1 is set to null

    std::cout << "Ownership transferred\n";

    std::cout << "res1 is " << (res1 ? "not null\n" : "null\n");
    std::cout << "res2 is " << (res2 ? "not null\n" : "null\n");

    if(res2)    //use implicit cast to bool to ensure res contains a Resource.
        std::cout << *res2 << "\n";
    return 0;
} */

//---------------std::make_unique()-------------------------------------------------
/// Benefits of using std::make_unique:
/// 1- Ease fo use.
/// 2- It also resolves and exception safety issue that was preset in C++14.
/// Consider an expression like this one:
/// some_function(std::unique_ptr<T>(new T), function_that_can_throw_exception());
/// The compiler is given a lot of flexibility in terms of how it handles this call. It could create a new T, then call
/// function_that_can_throw_exception(), then create the std::unique_ptr that manages the dynamically allocated T. If function_that_can_throw_exception()
/// throws an exception, then the T that was allocated will not be deallocated, because the smart pointer to do the deallocation
/// hasn’t been created yet. This leads to T being leaked.
/// std::make_unique() doesn’t suffer from this problem because the creation of the object T and the creation of the std::unique_ptr
/// happen inside the std::make_unique() function, where there’s no ambiguity about order of execution.
/// This issue was fixed in C++17, as evaluation of function arguments can no longer be interleaved.
#include <vector>

/* class Fraction
{
private:
    int m_numerator{ 0 };
    int m_denominator{ 1 };

public:
    Fraction(int numerator = 0, int denominator = 1) :
        m_numerator{ numerator }, m_denominator{ denominator }
    {
    }

    friend std::ostream& operator<<(std::ostream& out, const Fraction &f1)
    {
        out << f1.m_numerator << '/' << f1.m_denominator;
        return out;
    }
};


int main()
{
    // Create a single dynamically allocated Fraction with numerator 3 and denominator 5
    // We can also use automatic type deduction to good effect here
    auto f1{ std::make_unique<Fraction>(3, 5) };
    std::cout << *f1 << '\n';

    // Create a dynamically allocated array of Fractions of length 4
    auto f2{ std::make_unique<Fraction[]>(4) };
    std::cout << f2[0] << '\n';

    // This is the preferred way to achieve what we did in line 96.
    // std::vector<Fraction> vec(4);
    // std::cout << vec[0] << '\n';

    return 0;
} */

//--------Returing std::unique_ptr from a function---------------

/// In this function one should avoid returning by reference or pointer like this:
/// std::unique_ptr<Resource>*/std::unique_ptr<Resource>&, this is because when returning like this
/// the exclusive ownership and Return value optimization wont be available on the reference or pointer
/// to the unique poinetr object.
/* std::unique_ptr<Resource> createResource()
{
    std::unique_ptr<Resource> pp = std::make_unique<Resource>();
    return pp;
}

int main()
{
    // in c++14 or earlier the temp Resource pointer would have been move assigned to ptr.
    // In c++17 and above this move assignmenet is ellided.
    auto ptr{createResource()};

    // do whatever

    return 0;
} */

//-----------passing std::unique_ptr to a function----------

// This function takes ownership of the Resource, which isn't what we want
/* void takeOwnership(std::unique_ptr<Resource> res)
{
     if (res)
          std::cout << *res << '\n';
} // the Resource is destroyed here

// The function only uses the resource, so we'll accept a pointer to the resource, 
// not a reference to the whole std::unique_ptr<Resource>
// This is done when we want the unique_ptr to persist out of the function body as well.
void useResource(const Resource* res)
{
	if (res)
		std::cout << *res << '\n';
	else
		std::cout << "No resource\n";
}

int main()
{
    auto ptr{ std::make_unique<Resource>() };

    // takeOwnership(ptr); // This doesn't work, need to use move semantics
    takeOwnership(std::move(ptr)); // ok: use move semantics

    useResource(ptr.get()); //get() used here to get a pointer to the Resource

    std::cout << "Ending program\n";

    return 0;
} */

//--------------Misusing unique_ptr-------
/* int main(int argc, char const *argv[])
{
    // *****This way we can create 2 smart pointers that are pointing to same object, hence,
    // while deallocation undefined behavior occurs, and double free.
    // Resource* res{new Resource};
    // std::unique_ptr<Resource> res1 {res};
    // std::unique_ptr<Resource> res2 {res};

    // ******Here if we try to delete smart pointer manually then double free can occur 
    // Resource* res{new Resource};
    // std::unique_ptr<Resource> res1{res};
    // delete res;
    // return 0;

    //!NOTE - Both the above use cases can be avoided using std::make_unique.
} */

//--------------------QUIZ------------------------

class Fraction
{
private:
	int m_numerator{ 0 };
	int m_denominator{ 1 };

public:
	Fraction(int numerator = 0, int denominator = 1) :
		m_numerator{ numerator }, m_denominator{ denominator }
	{
	}

	friend std::ostream& operator<<(std::ostream& out, const Fraction &f1)
	{
		out << f1.m_numerator << '/' << f1.m_denominator;
		return out;
	}
};

void printFraction(const Fraction* ptr)
{
	if (ptr)
		std::cout << *ptr << '\n';
	else
		std::cout << "No fraction\n";
}

int main()
{
	std::unique_ptr<Fraction> ptr{ std::make_unique<Fraction>(3, 5) };

	printFraction(ptr.get());

	return 0;
}