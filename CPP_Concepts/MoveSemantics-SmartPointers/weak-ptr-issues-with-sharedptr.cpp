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