/**
 * @file smartPointers.cpp
 * @author Abhishek
 * @brief Here we discuss the usefullness of smart pointers(Composition Class):
 * 1- These help prevent memory leaks, as can be seen in someFunction(), as it terminates the local variable Auto_ptr's destructor is called which 
 * deallocates the memory.
 * 2- For supporting copy ctor and assignment operators, we implemented move semantics for the objects which only allows one object of Auto_ptr
 * to have valid values at a time, which helps avoid double free error that we saw in above case.
 * 
 * The Auto_ptr2 represents std::auto_ptr which was depricated in c++11 and removed in c++17, following were its flaws:
 * 1- Because std::auto_ptr implements move semantics through the copy constructor and assignment operator, passing 
 * a std::auto_ptr by value to a function will cause your resource to get moved to the function parameter (and be destroyed at the end of the 
 * function when the function parameters go out of scope). Then when you go to access your auto_ptr argument from the caller (not realizing it was 
 * transferred and deleted), you’re suddenly dereferencing a null pointer. Crash!
 * 2- std::auto_ptr always deletes its contents using non-array delete. This means auto_ptr won’t work correctly with dynamically allocated 
 * arrays, because it uses the wrong kind of deallocation. Worse, it won’t prevent you from passing it a dynamic array, which it will then mismanage, 
 * leading to memory leaks.
 * 3- auto_ptr doesn’t play nice with a lot of the other classes in the standard library, including most of the containers and algorithms. 
 * This occurs because those standard library classes assume that when they copy an item, it actually makes a copy, not a move.
 * @version 0.1
 * @date 2022-08-29
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <iostream>
//***********************************smart pointer***
/* template <typename T>
class Auto_ptr1
{
    T *m_ptr;

public:
    // Pass in a pointer to "own" via the constructor
    Auto_ptr1(T *ptr = nullptr)
        : m_ptr(ptr)
    {
    }

    // The destructor will make sure it gets deallocated
    ~Auto_ptr1()
    {
        delete m_ptr;
    }

    // Overload dereference and operator-> so we can use Auto_ptr1 like m_ptr.
    T &operator*() const { return *m_ptr; }
    T *operator->() const { return m_ptr; }
};

// A sample class to prove the above works
class Resource
{
public:
    Resource() { std::cout << "Resource acquired\n"; }
    ~Resource() { std::cout << "Resource destroyed\n"; }
    void sayHi() { std::cout << "Hi!\n"; }
};

//Here in this function if the Auti_ptr was not smart then the function would have returned after receiving x as 0 and ptr would be left dangling.
void someFunction()
{
    Auto_ptr1<Resource> ptr(new Resource()); // ptr now owns the Resource

    int x;
    std::cout << "Enter an integer: ";
    std::cin >> x;

    if (x == 0)
        return; // the function returns early

    // do stuff with ptr here
    ptr->sayHi();
}   //The destructor of Auto_ptr will be invoked at the end of this function, no matter how this function terminates.

int main()
{
    Auto_ptr1<Resource> res(new Resource()); // Note the allocation of memory here
    //!< double free will occur here, since copy constructir will shallow copy the pointer and res2 will also point to object pointed by res, hence
    //!< when main terminates and the res object is deleted, res2 will be pointing to nothing and will try to delete that at the end of main.
    Auto_ptr1<Resource> res2{res};  

    // ... but no explicit delete needed

    // Also note that the Resource in angled braces doesn't need a * symbol, since that's supplied by the template
    someFunction();

    return 0;
} */ // variable "res" goes out of scope here, and destroys the allocated Resource for us.
//***********************************smart pointer***
//***********************************smart pointer supporting copy and assignment operations***
template <typename T>
class Auto_ptr2
{
	T* m_ptr;
public:
	Auto_ptr2(T* ptr=nullptr)
		:m_ptr(ptr)
	{
	}

	~Auto_ptr2()
	{
		delete m_ptr;
	}

	// A copy constructor that implements move semantics
	Auto_ptr2(Auto_ptr2& a) // note: not const
	{
		m_ptr = a.m_ptr; // transfer our dumb pointer from the source to our local object
		a.m_ptr = nullptr; // make sure the source no longer owns the pointer
	}

	// An assignment operator that implements move semantics
	Auto_ptr2& operator=(Auto_ptr2& a) // note: not const
	{
		if (&a == this)
			return *this;

		delete m_ptr; // make sure we deallocate any pointer the destination is already holding first
		m_ptr = a.m_ptr; // then transfer our dumb pointer from the source to the local object
		a.m_ptr = nullptr; // make sure the source no longer owns the pointer
		return *this;
	}

    //!< explore about these operators more here:https://stackoverflow.com/questions/8777845/overloading-member-access-operators/8778050#8778050
    //!< Since these are special operators.
	T& operator*() const { return *m_ptr; }
	T* operator->() const { return m_ptr; }
	bool isNull() const { return m_ptr == nullptr; }
};

class Resource
{
public:
	Resource() { std::cout << "Resource acquired\n"; }
	~Resource() { std::cout << "Resource destroyed\n"; }
};

int main()
{
	Auto_ptr2<Resource> res1(new Resource());
	Auto_ptr2<Resource> res2; // Start as nullptr

	std::cout << "res1 is " << (res1.isNull() ? "null\n" : "not null\n");
	std::cout << "res2 is " << (res2.isNull() ? "null\n" : "not null\n");

	res2 = res1; // res2 assumes ownership, res1 is set to null

	std::cout << "Ownership transferred\n";

	std::cout << "res1 is " << (res1.isNull() ? "null\n" : "not null\n");
	std::cout << "res2 is " << (res2.isNull() ? "null\n" : "not null\n");

	return 0;
}
//***********************************smart pointer supporting copy and assignment operations***