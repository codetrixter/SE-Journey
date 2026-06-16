/**
 * Here we discuss the circular dependency issues with std::shared_ptr and how weak_ptr plays a role 
 * in resolving this issue.
 */

#include <iostream>
#include <memory>
#include <string>

//---------------------circular dependency while using shared pointer-----------
/* class Person
{
	std::string m_name;
	std::shared_ptr<Person> m_partner; // initially created empty

public:

	Person(const std::string &name): m_name(name)
	{
		std::cout << m_name << " created\n";
	}
	~Person()
	{
		std::cout << m_name << " destroyed\n";
	}

	friend bool partnerUp(std::shared_ptr<Person> &p1, std::shared_ptr<Person> &p2)
	{
		if (!p1 || !p2)
			return false;

		p1->m_partner = p2;
		p2->m_partner = p1;
        p1->m_partner = p1; // with this added ricky now has only one use_count and that is ricky's smart pointer, hence it gets deallocated

        std::cout << p1.use_count() << " " << p2.use_count();
		std::cout << p1->m_name << " is now partnered with " << p2->m_name << '\n';

		return true;
	}
};

int main()
{
	auto lucy { std::make_shared<Person>("Lucy") }; // create a Person named "Lucy"
	auto ricky { std::make_shared<Person>("Ricky") }; // create a Person named "Ricky"

	partnerUp(lucy, ricky); // Make "Lucy" point to "Ricky" and vice-versa

    std::cout << lucy.use_count() << " " << ricky.use_count() << '\n';

	return 0;
}  */  //No memory deallocation happens for ricky and lucy shared pointer.

//------------------weak pointer to the rescue---------------

/* class Person
{
	std::string m_name;
	std::weak_ptr<Person> m_partner; // note: This is now a std::weak_ptr

public:

	Person(const std::string &name): m_name(name)
	{
		std::cout << m_name << " created\n";
	}
	~Person()
	{
		std::cout << m_name << " destroyed\n";
	}

	friend bool partnerUp(std::shared_ptr<Person> &p1, std::shared_ptr<Person> &p2)
	{
		if (!p1 || !p2)
			return false;

        // Here since the m_partner is a weak pointer, it does not increments the use_count of shared pointers p1 and p2.
		p1->m_partner = p2;
		p2->m_partner = p1;

        std::cout << p1.use_count() << " " << p2.use_count() << '\n';   // 1 1
		std::cout << p1->m_name << " is now partnered with " << p2->m_name << '\n';

		return true;
	}
    
    std::shared_ptr<Person> getPartner() const { return m_partner.lock(); } // use lock() to convert weak_ptr to shared_ptr
	const std::string& getName() const { return m_name; }
};

int main()
{
	auto lucy { std::make_shared<Person>("Lucy") };
	auto ricky { std::make_shared<Person>("Ricky") };

	partnerUp(lucy, ricky);

    auto partner = ricky->getPartner(); // get shared_ptr to Ricky's partner
	std::cout << ricky->getName() << "'s partner is: " << partner->getName() << '\n';
	return 0;
} */

//----------handling dangling pointers with std::weak_ptr-------

/* class Resource
{
public:
	Resource() { std::cerr << "Resource acquired\n"; }
	~Resource() { std::cerr << "Resource destroyed\n"; }
};

// Returns a std::weak_ptr to an invalid object
std::weak_ptr<Resource> getWeakPtr()
{
	auto ptr{ std::make_shared<Resource>() };
	return std::weak_ptr<Resource>{ ptr };
} // ptr goes out of scope, Resource destroyed

// Returns a dumb pointer to an invalid object
Resource* getDumbPtr()
{
	auto ptr{ std::make_unique<Resource>() };
	return ptr.get();
} // ptr goes out of scope, Resource destroyed

int main()
{
	auto dumb{ getDumbPtr() };
	std::cout << "Our dumb ptr is: " << ((dumb == nullptr) ? "nullptr\n" : "non-null\n");

	auto weak{ getWeakPtr() };
    // If we apply lock on an expired pointer, it will return shared_ptr to nullptr.
	std::cout << "Our weak ptr is: " << ((weak.expired()) ? "expired\n" : "valid\n");

	return 0;
} */

/*
╔══════════════════════════════════════════════════════════════════════════════╗
║          CONCEPT ANALYSIS — weak-ptr-issues-with-sharedptr.cpp            ║
╚══════════════════════════════════════════════════════════════════════════════╝

## Concepts

### 1. Circular Reference Problem with `shared_ptr`
When two objects hold `shared_ptr`s to each other, neither's ref count reaches
zero → memory leak (no destructor called).

**Code walkthrough:** Lucy's `m_partner` → Ricky, Ricky's `m_partner` → Lucy.
Both have use_count 2. When stack shared_ptrs die, counts go to 1 (not 0).

### 2. `std::weak_ptr` — Non-Owning Observer
`weak_ptr` observes a `shared_ptr`-managed object WITHOUT incrementing the ref
count. Breaks circular dependencies.

- `lock()` — returns a `shared_ptr` if the object still exists, else nullptr.
- `expired()` — checks if the managed object has been deleted.

### 3. Detecting Dangling with `weak_ptr`
Unlike raw pointers, `weak_ptr` can detect if the referenced object is gone
(`expired()` returns true). Raw pointers become dangling silently.

**Key Takeaway:** Use `weak_ptr` for back-references in bidirectional
relationships and for caches/observers that shouldn't extend object lifetime.

#### Alternatives / Idiomatic C++
- Design to avoid circular ownership in the first place (e.g., parent owns
  children via `shared_ptr`, children reference parent via raw pointer or
  `weak_ptr`).
- `std::enable_shared_from_this` — allows an object to create a `shared_ptr`
  to itself safely.

#### Real-World Usage
- **Observer pattern**: Observers hold `weak_ptr` to subject.
- **Caches**: Cache holds `weak_ptr`; if object is still alive, reuse it.
- **Asio**: Uses `weak_ptr` + `lock()` pattern in async handlers.

---

## 🔁 Quick Revision
- Circular `shared_ptr` references → memory leak.
- `weak_ptr`: non-owning, doesn't affect ref count.
- `lock()` → `shared_ptr` (or nullptr if expired).
- `expired()` → safe dangling detection.

### ⚠️ Gotchas
- `weak_ptr` alone can't access the object — must `lock()` first.
- Between `expired()` check and `lock()`, object could be destroyed (TOCTOU).
  Always use `lock()` and check the returned `shared_ptr`.
*/