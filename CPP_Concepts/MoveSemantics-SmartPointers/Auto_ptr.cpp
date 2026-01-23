/**
 * Here we will look into the Auto_ptr introduced in C++98 and why was it depricated in c++17 and new smart pointeres were introduced.
 * 
 */

#include <iostream>

/* template <typename T>
class Auto_ptr1
{
    private:
    // Raw pointer member that will hold the address of the dynamically allocated object
    // This is the actual resource being managed by this smart pointer
    T* m_ptr;

    public:
    // Constructor that takes a raw pointer (defaults to nullptr if no argument provided)
    // 'explicit' would be better here to prevent implicit conversions, but it's omitted
    // The pointer passed in becomes owned by this Auto_ptr1 instance
    Auto_ptr1(T* ptr = nullptr)
    // Member initializer list - initializes m_ptr with the passed pointer
    // More efficient than assignment in constructor body
    : m_ptr{ptr}
    {}

    // Destructor - automatically called when Auto_ptr1 goes out of scope
    // This is the key feature: it automatically deletes the managed resource
    // preventing memory leaks without requiring manual delete calls
    ~Auto_ptr1()
    {
        // Deletes the dynamically allocated object pointed to by m_ptr
        // Note: delete on nullptr is safe and does nothing
        delete m_ptr;
    }
    
    // Dereference operator overload - allows using *ptr syntax
    // Returns a reference to the object being pointed to
    // Example: Auto_ptr1<int> p(new int(5)); int x = *p; // x = 5
    //
    // WHY RETURN BY REFERENCE (T&) instead of by value (T)?
    // 1. EFFICIENCY: Returning by value would create a COPY of the object every time
    //    you dereference. For large objects, this is expensive (memory + CPU).
    // 2. MODIFICATION: Returning by reference allows you to modify the original object.
    //    Example: *ptr = newValue;  // This modifies the actual managed object
    //    If we returned by value, this would only modify a temporary copy!
    // 3. CONSISTENCY: Raw pointers work this way - *rawPtr gives you the actual object,
    //    not a copy. Smart pointers should mimic raw pointer behavior.
    // 4. AVOIDING SLICING: If T is a base class and the actual object is derived,
    //    returning by value would "slice" off the derived part.
    T& operator *()
    {
        // Dereferences m_ptr and returns a reference to the underlying object
        // Warning: No null check - dereferencing nullptr causes undefined behavior
        return *m_ptr;
    }

    // Arrow operator overload - allows using ptr->member syntax
    // Returns the raw pointer so the compiler can apply -> to access members
    // Example: Auto_ptr1<Resource> r(new Resource()); r->someMethod();
    T* operator ->()
    {
        // Returns the raw pointer; compiler will then apply -> to access members
        // This enables natural pointer-like syntax for accessing object members
        return m_ptr;
    }
};
*/

// A sample class to prove the above works
class Resource
{
public:
    Resource() { std::cout << "Resource acquired\n"; }
    ~Resource() { std::cout << "Resource destroyed\n"; }

    void sayHi()
    {
        std::cout << "Hi\n";
    }
};

/* void someFunction()
{
    Auto_ptr1<Resource> ptr(new Resource()); // ptr now owns the Resource

    int x;
    std::cout << "Enter an integer: ";
    std::cin >> x;

    if (x == 0)
        return; // the function returns early

    // do stuff with ptr here
    ptr->sayHi();
}

int main()
{
    someFunction();

    return 0;
} */

//---------------Issues with above smart poiner class--------------------
// It does not have a copy ctor, which enables it to create a copy of the ptr pointing to the same object hence 
// leading to double free.

/* int main(int argc, char const *argv[])
{
    Auto_ptr1<Resource> r = new Resource();
    //Auto_ptr1<Resource> r2 = r; //Here the object pointed by r and r2 is same hence gets freed twice

    return 0;
} */

//-------------Solving double free by implementing move semantics via copy ctr--------------

// Issues with this auto_ptr2 implementation:
// 1. since we implemented move sematics using copy constructor, whenevr we call a function using pass by value
//    the copy ctr is invoked leading to ownership transfer and the original pointer becomes null which may
//    not be the intended behaviour.
// 2. This does not have a feature of eleting arrays (delete[]), so it can only be used for single objects.
// 3. It does not have a way to release ownership without deleting the object (like std::unique_ptr::release).

template <typename T>
class Auto_ptr2
{
    private:
    T* m_ptr;

    public:
    Auto_ptr2(T* ptr = nullptr)
    : m_ptr{ptr}
    {}

    Auto_ptr2(Auto_ptr2& obj)
    {
        m_ptr = obj.m_ptr;
        obj.m_ptr = nullptr;
    }

    Auto_ptr2& operator =(Auto_ptr2& obj)
    {
        if(this == &obj)
            return *this;

        // make sure we deallocate any pointer the destination is already holding first
        delete m_ptr;

        m_ptr = obj.m_ptr;
        obj.m_ptr = nullptr;

        return *this;
    }

    ~Auto_ptr2()
    {
        delete m_ptr;
    }
    
    T& operator *()
    {
        return *m_ptr;
    }

    T* operator ->()
    {
        return m_ptr;
    }

    bool isNull()
    {
        return m_ptr == nullptr;
    }
};

int main(int argc, char const *argv[])
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