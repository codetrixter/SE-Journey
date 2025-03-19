/**
 * @file friendClassesAnsFunctions.cpp
 * @author Abhishek
 * @brief Here we discuss the details and intricacies of the friend keyword:
 * 1- friend functions can access private members of a class as though it was a member of that class, it doesn't matter which section of the class you
 * declare the friend function(private/public).
 * 2- A friend function can be friends to multiple classes.
 * 3- Friend classes: by making one classes friend of another, we can access all the members of the base class.
 *      a- Even though the befriended class can access the members of the base class, still it needs the object of that class and does 
 *      not have access ot the *this pointer of that class.
 *      b- Friendness is not transitive in nature, if A is a friend of B then B does not becomes the friend of A automatically.
 * 4- making friend member function: we can make a member function of another class a friend of another class.
 *      a- Note that making a specific member function a friend requires the full definition for the class of the member function to have been seen first.
 * 
 * This feature of C++ is used for operator overloading.
 * @version 0.1
 * @date 2022-06-11
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>

//**************1***
/* class Value
{
    private:
    int m_value { 0 };

    //make reset the friend of this class
    friend bool equality(const Value &v1, const Value &v2);

    public:
    Value(int val): m_value{val}
    {}
};

bool equality(const Value &v1, const Value &v2)
{
    return (v1.m_value == v2.m_value);
}

int main(int argc, char const *argv[])
{
    Value v1{5};
    Value v2{6};

    std::cout << std::boolalpha << equality(v1, v2);    
    return 0;
} */
//**************1***

//**************2***
/* class Humidity;

class Temperature
{
private:
    int m_temp {};

public:
    Temperature(int temp=0)
        : m_temp { temp }
    {
    }

    friend void printWeather(const Temperature& temperature, const Humidity& humidity);
};

class Humidity
{
private:
    int m_humidity {};

public:
    Humidity(int humidity=0)
        : m_humidity { humidity }
    {
    }

    friend void printWeather(const Temperature& temperature, const Humidity& humidity);
};

//this functions cann access private members from both the classes.
void printWeather(const Temperature& temperature, const Humidity& humidity)
{
    std::cout << "The temperature is " << temperature.m_temp <<
       " and the humidity is " << humidity.m_humidity << '\n';
}

int main()
{
    Humidity hum{10};
    Temperature temp{12};

    printWeather(temp, hum);

    return 0;
} */
//**************2***

//**************3***
/* class Storage
{
private:
    int m_nValue {};
    double m_dValue {};
public:
    Storage(int nValue, double dValue)
       : m_nValue { nValue }, m_dValue { dValue }
    {
    }

    // Make the Display class a friend of Storage
    friend class Display;
};

class Display
{
private:
    bool m_displayIntFirst;

public:
    Display(bool displayIntFirst)
         : m_displayIntFirst { displayIntFirst }
    {
    }

    void displayItem(const Storage& storage)
    {
        if (m_displayIntFirst)
            std::cout << storage.m_nValue << ' ' << storage.m_dValue << '\n';
        else // display double first
            std::cout << storage.m_dValue << ' ' << storage.m_nValue << '\n';
    }
};

int main()
{
    Storage storage{5, 6.7};
    Display display{false};

    display.displayItem(storage);

    return 0;
} */
//**************3***

//**************4***
/* class Storage; // forward declaration for class Storage

class Display
{
private:
	bool m_displayIntFirst {};

public:
	Display(bool displayIntFirst)
		: m_displayIntFirst { displayIntFirst }
	{
	}

	void displayItem(const Storage& storage); // forward declaration above needed for this declaration line
};

class Storage // full definition of Storage class
{
private:
	int m_nValue {};
	double m_dValue {};
public:
	Storage(int nValue, double dValue)
		: m_nValue { nValue }, m_dValue { dValue }
	{
	}

	// Make the Display::displayItem member function a friend of the Storage class (requires seeing the full declaration of class Display, as above)
	friend void Display::displayItem(const Storage& storage);
};

// Now we can define Display::displayItem, which needs to have seen the full definition of class Storage
void Display::displayItem(const Storage& storage)
{
	if (m_displayIntFirst)
		std::cout << storage.m_nValue << ' ' << storage.m_dValue << '\n';
	else // display double first
		std::cout << storage.m_dValue << ' ' << storage.m_nValue << '\n';
}

int main()
{
    Storage storage(5, 6.7);
    Display display(false);

    display.displayItem(storage);

    return 0;
} */
//**************4***

//**************QUIZ***

class Vector3d;

class Point3d
{
private:
	double m_x{};
	double m_y{};
	double m_z{};

public:
	Point3d(double x = 0.0, double y = 0.0, double z = 0.0)
		: m_x{x}, m_y{y}, m_z{z}
	{

	}

	void print() const
	{
		std::cout << "Point(" << m_x << " , " << m_y << " , " << m_z << ")\n";
	}

	void moveByVector(const Vector3d& v);
};

class Vector3d
{
private:
	double m_x{};
	double m_y{};
	double m_z{};

public:
	Vector3d(double x = 0.0, double y = 0.0, double z = 0.0)
		: m_x{x}, m_y{y}, m_z{z}
	{

	}

	void print() const
	{
		std::cout << "Vector(" << m_x << " , " << m_y << " , " << m_z << ")\n";
	}

    friend void Point3d::moveByVector(const Vector3d& v);
};

void Point3d::moveByVector(const Vector3d& v)
{
    m_x += v.m_x;
    m_y += v.m_y;
    m_z += v.m_z;
}

int main()
{
	Point3d p{1.0, 2.0, 3.0};
	Vector3d v{2.0, 2.0, -3.0};

	p.print();
	p.moveByVector(v);
	p.print();

	return 0;
}
//**************QUIZ***