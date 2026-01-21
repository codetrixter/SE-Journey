/**
 * CHAPTER 25: VIRTUAL FUNCTIONS & POLYMORPHISM SUMMARY
 * 
 * Virtual Functions enable polymorphic behavior - calling the correct derived class
 * function through a base class pointer or reference at runtime (late binding).
 * 
 * Key Concepts:
 * 1. Virtual Functions: Declared with 'virtual' keyword in base class. Allow derived
 *    classes to override the implementation while maintaining the same interface.
 * 
 * 2. Polymorphism: Derived class objects can be treated as base class objects.
 *    Calling a virtual function through base class pointer/reference executes the
 *    appropriate derived class version.
 * 
 * 3. Overriding: A derived class redefines a virtual function inherited from the base.
 *    Use 'override' keyword (C++11) to explicitly mark virtual function overrides.
 * 
 * 4. Virtual Destructor: Always make destructors virtual in base classes to ensure
 *    proper cleanup of derived objects when deleted through base class pointer.
 * 
 * 5. Pure Virtual Functions: Declared with '= 0' make a class abstract and cannot
 *    be instantiated. Derived classes MUST implement pure virtual functions.
 * 
 * 6. Abstract Base Classes: Classes with pure virtual functions. Serve as interfaces.
 *    Cannot be instantiated but can have pointers/references to them.
 * 
 * 7. Virtual Function Cost: Slight runtime overhead due to dynamic dispatch via
 *    virtual function table (vtable). Each object has a vptr to its class's vtable.
 * 
 * 8. VTABLE: Compiler-generated table of function pointers for each virtual function.
 * 
 * Best Practices:
 * - Use virtual functions when designing inheritance hierarchies
 * - Always mark destructors as virtual in base classes
 * - Use 'override' keyword for clarity and compiler checking
 * - Prefer composition over inheritance when polymorphism isn't needed
 * - Consider final keyword to prevent further overriding
 */

 #include <iostream>
//-------------------Quiz 1a---------------

/* class Base
{
protected:
	int m_value;

public:
	Base(int value)
		: m_value{ value }
	{
	}

	const char* getName() const { return "Base"; }
};

class Derived : public Base
{
public:
	Derived(int value)
		: Base{ value }
	{
	}

	const char* getName() const { return "Derived"; }
};

int main()
{
	Derived d{ 5 };
	Base& b{ d };
	std::cout << b.getName() << '\n';

	return 0;
} */
//-----------------Quiz 1b--------------

/* class Base
{
protected:
	int m_value;

public:
	Base(int value)
		: m_value{ value }
	{
	}

	virtual const char* getName() { return "Base"; }
};

class Derived : public Base
{
public:
	Derived(int value)
		: Base{ value }
	{
	}

	virtual const char* getName() const { return "Derived"; }
};

int main()
{
	Derived d{ 5 };
	Base& b{ d };
    //not considered an override since return types are different.
	std::cout << b.getName() << '\n';

	return 0;
} */
//------------------------1c-----------------
 
/* class Base
{
protected:
	int m_value;

public:
	Base(int value)
		: m_value{ value }
	{
	}

	virtual const char* getName() { return "Base"; }
};

class Derived : public Base
{
public:
	Derived(int value)
		: Base{ value }
	{
	}

	const char* getName() override { return "Derived"; }
};

int main()
{
	Derived d{ 5 };
	Base b{ d };    //slicing happened here
	std::cout << b.getName() << '\n';  

	return 0;
} */
//----------------Quiz 1d------------------

/* class Base final
{
protected:
	int m_value;

public:
	Base(int value)
		: m_value{ value }
	{
	}

	virtual const char* getName() { return "Base"; }
};

class Derived : public Base
{
public:
	Derived(int value)
		: Base{ value }
	{
	}

	const char* getName() override { return "Derived"; }
};

int main()
{
	Derived d{ 5 };
	Base& b{ d };
	std::cout << b.getName() << '\n';

	return 0;
} */
//------------Quiz 1e--------------
/* 
class Base
{
protected:
	int m_value;

public:
	Base(int value)
		: m_value{ value }
	{
	}

	virtual const char* getName() { return "Base"; }
};

class Derived : public Base
{
public:
	Derived(int value)
		: Base{ value }
	{
	}

	virtual const char* getName() = 0;
};

const char* Derived::getName()
{
	return "Derived";
}

int main()
{
	Derived d{ 5 }; //cant be instantiated since Derived is an abstract class.
	Base& b{ d };
	std::cout << b.getName() << '\n';

	return 0;
} */
//---------------------------Quiz 1f------------------

/* class Base
{
protected:
	int m_value;

public:
	Base(int value)
		: m_value{ value }
	{
	}

	virtual const char* getName() { return "Base"; }
};

class Derived : public Base
{
public:
	Derived(int value)
		: Base{ value }
	{
	}

	virtual const char* getName() { return "Derived"; }
};

int main()
{
	auto* d{ new Derived(5) };
	Base* b{ d };
	std::cout << b->getName() << '\n';
	delete b;

	return 0;
} */

//-------------------Quiz 2(a, b)----------------

#include <ostream>
#include <vector>
#include <algorithm>
#include <memory>

class Point
{
private:
	int m_x{};
	int m_y{};

public:
	Point(int x, int y)
		: m_x{ x }, m_y{ y }
	{

	}

	friend std::ostream& operator<<(std::ostream& out, const Point& p)
	{
		return out << "Point(" << p.m_x << ", " << p.m_y << ')';
	}
};

class Shape
{
    public:
    virtual std::ostream& print(std::ostream& out) const = 0;
    friend std::ostream& operator <<(std::ostream& out, const Shape& rhs)
    {
        return rhs.print(out);
    }
    virtual ~Shape() = default;
};

class Triangle: public Shape
{
    private:
    Point m_p1;
    Point m_p2;
    Point m_p3;

    public:
    Triangle(const Point& p1, const Point& p2, const Point& p3)
    : m_p1{p1}, m_p2{p2}, m_p3{p3}
    {

    }
    
    std::ostream& print(std::ostream& out) const override
    {
        return out << "Triangle(" << m_p1 << ", " << m_p2 << ", " << m_p3 << ")";
    }
};

class Circle: public Shape
{
    private:
    Point m_center;
    int radius;

    public:
    Circle(const Point& p, int r)
    : m_center{p}, radius{r}
    {

    }

	int getRadius() const 
	{
		return radius;
	}

    std::ostream& print(std::ostream& out) const override
    {
        return out << "Circle(" << m_center << ", " << "radius " << radius << ")";
    }
};

/* int main(int argc, char const *argv[])
{
    Circle c{ Point{ 1, 2 }, 7 };   //Circle(Point(1, 2), radius 7)
    std::cout << c << '\n';

    Triangle t{Point{ 1, 2 }, Point{ 3, 4 }, Point{ 5, 6 }};    //Triangle(Point(1, 2), Point(3, 4), Point(5, 6))
    std::cout << t << '\n';

    return 0;
} */

//----------------Quiz 2c-------------

/* int getLargestRadius(const std::vector<Shape*>& shapes)
{
	int largestRadius{};

	for(const auto* i : shapes)
	{
		if( auto* c {dynamic_cast<const Circle*>(i)} )
		{
			largestRadius = std::max(largestRadius, c->getRadius());
		}
	}
	return largestRadius;
}

int main()
{
	std::vector<Shape*> v{
	  new Circle{Point{ 1, 2 }, 7},
	  new Triangle{Point{ 1, 2 }, Point{ 3, 4 }, Point{ 5, 6 }},
	  new Circle{Point{ 7, 8 }, 3}
	};

	// print each shape in vector v on its own line here
    // Circle(Point(1, 2), radius 7)
    // Triangle(Point(1, 2), Point(3, 4), Point(5, 6))
    // Circle(Point(7, 8), radius 3)

	for(const auto* i : v)
	{
		std::cout << *i << "\n";
	}


	std::cout << "The largest radius is: " << getLargestRadius(v) << '\n'; // write this function

	// delete each element in the vector here
	for(const auto* item : v)
    	delete item;

	return 0;
} */

//-------------Quiz 2d-use std::unique_ptr-------------------

int getLargestRadius(const std::vector<std::unique_ptr<Shape>>& shapes)
{
	int largestRadius{};

	for(const auto& i : shapes)
	{
		if( auto* c {dynamic_cast<const Circle*>(i.get())} )
		{
			largestRadius = std::max(largestRadius, c->getRadius());
		}
	}
	return largestRadius;
}

int main()
{
	std::vector<std::unique_ptr<Shape>> v;
	v.reserve(3);
	v.push_back(std::make_unique<Circle>(Point{ 1, 2 }, 7)); 
	v.push_back(std::make_unique<Triangle>(Point{ 1, 2 }, Point{ 3, 4 }, Point{ 5, 6 }));
	v.push_back(std::make_unique<Circle>(Point{ 7, 8 }, 3));

	// print each shape in vector v on its own line here
    // Circle(Point(1, 2), radius 7)
    // Triangle(Point(1, 2), Point(3, 4), Point(5, 6))
    // Circle(Point(7, 8), radius 3)                                        

	for(const auto& i : v)
	{
		std::cout << *i << "\n";
	}


	std::cout << "The largest radius is: " << getLargestRadius(v) << '\n'; // write this function

	// delete each element in the vector here
	// for(const auto* item : v)
    // 	delete item;

	return 0;
} 