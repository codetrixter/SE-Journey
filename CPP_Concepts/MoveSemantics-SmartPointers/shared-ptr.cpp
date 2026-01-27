/**
 * Here we explore how a shared_ptr is implemented and what are its use cases.
 * //!IMPORTANT POINTS OF SHARED POINTERS
 * //! 1-unlike unique pointer shared pointer not only has an internal pointyer for the object it is managing, but another 
 * //! pointer is also created for managing the lifecycle of the "managed object" aka "control block".
 * //! 2-Shared pointers can be created from unique poinetr but other way is not possible.
 * //! 3-C++17 and earlier shared pointyer class did not have proper support for arrays.
 */

#include <iostream>
#include <string>
#include <memory>
#include <algorithm>

class Resource
{
public:
	Resource() { std::cout << "Resource acquired\n"; }
	~Resource() { std::cout << "Resource destroyed\n"; }
};

/* int main()
{
	Resource* res { new Resource };
    /// Here since ptr1 and ptr2 are two different shared pointers hence they own res separatly, hence when ptr2
    /// goes out of scope at line:27, res is deallocated and at line:32 double free occurs as ptr1 is trying to deallocate res as well.
	std::shared_ptr<Resource> ptr1 { res };
	{
		std::shared_ptr<Resource> ptr2 { res }; // create ptr2 directly from res (instead of ptr1)

		std::cout << "Killing one shared pointer\n";
	} // ptr2 goes out of scope here, and the allocated Resource is destroyed

	std::cout << "Killing another shared pointer\n";

	return 0;
} // ptr1 goes out of scope here, and the allocated Resource is destroyed again */

//------------fix for above double free issue------------------

int main()
{
	std::shared_ptr<Resource> ptr1 { std::make_shared<Resource>() };
	{
		std::shared_ptr<Resource> ptr2 { ptr1 }; // created a copy from ptr1

		std::cout << "Killing one shared pointer\n";
	} // ptr2 goes out of scope here and, counter is reduced to 1

	std::cout << "Killing another shared pointer\n";

	return 0;
} // ptr1 goes out of scope here, and the allocated Resource is destroyed since counter goes to 0.