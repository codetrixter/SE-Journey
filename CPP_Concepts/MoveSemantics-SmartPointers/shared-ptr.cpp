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

/*
╔══════════════════════════════════════════════════════════════════════════════╗
║                   CONCEPT ANALYSIS — shared-ptr.cpp                        ║
╚══════════════════════════════════════════════════════════════════════════════╝

## Concepts

### 1. `std::shared_ptr` — Reference-Counted Ownership
Multiple `shared_ptr`s can own the same resource. An internal reference count
tracks owners; resource is deleted when count reaches zero.

### 2. The Control Block
`shared_ptr` allocates a **control block** containing: reference count, weak
count, deleter, and allocator. `make_shared` combines object + control block
in a single allocation (more cache-friendly).

### 3. The Aliasing Anti-Pattern (Double Ownership)
```cpp
Resource* res = new Resource;
shared_ptr<Resource> ptr1{res};
shared_ptr<Resource> ptr2{res}; // BAD: independent control blocks!
```
Two independent shared_ptrs each think they exclusively own `res` → double free.

**Fix:** Always copy/assign from an existing shared_ptr:
`shared_ptr<Resource> ptr2{ptr1};`

### 4. `std::make_shared` — Best Practice
- Single allocation for object + control block.
- Exception-safe.
- Cannot use custom deleter (use shared_ptr constructor for that).

**Key Takeaway:** Always create shared_ptrs via `make_shared` or copy from
existing shared_ptr. Never create independent shared_ptrs from raw pointers.

#### Alternatives / Idiomatic C++
- Prefer `unique_ptr` unless shared ownership is genuinely needed.
- C++20: `std::atomic<std::shared_ptr<T>>` for thread-safe pointer updates.
- `weak_ptr` breaks circular references (see weak-ptr file).

#### Real-World Usage
- **Asio**: Shared ownership of connection objects across async handlers.
- **ROS2** (Robot OS): Shared pointers for message passing between nodes.
- **Unreal Engine**: Uses its own `TSharedPtr` (similar concept).

---

## 🔁 Quick Revision
- `shared_ptr`: ref-counted, last owner deletes resource.
- `make_shared`: single allocation, exception-safe, preferred.
- Never create two shared_ptrs from the same raw pointer.
- Control block = ref count + weak count + deleter.

### ⚠️ Gotchas
- `make_shared` delays memory deallocation if `weak_ptr`s exist (control block
  stays alive).
- Thread-safe ref count but NOT thread-safe access to the pointed object.
- Circular references → memory leak (use `weak_ptr`).
*/