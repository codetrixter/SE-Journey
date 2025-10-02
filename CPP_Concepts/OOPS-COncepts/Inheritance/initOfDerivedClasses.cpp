/**
 * @file initOfDerivedClasses.cpp
 * @author Abhishek
 * @brief Here we define when the Base and Derived class members are initialized:
 * ->  When creating a derived class constructor, we should initialize the base class members using the base class
 * constructor.
 * @version 0.1
 * @date 2022-06-13
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#include <string>

class Person
{
private:
    std::string m_name;
    int m_age {};

public:
    Person(const std::string& name = "", int age = 0)
        : m_name{ name }, m_age{ age }
    {
    }

    const std::string& getName() const { return m_name; }
    int getAge() const { return m_age; }

};

/// BaseballPlayer publicly inheriting Person
class BaseballPlayer : public Person
{
private:
    double m_battingAverage {};
    int m_homeRuns {};

public:
    BaseballPlayer(const std::string& name = "", int age = 0,
        double battingAverage = 0.0, int homeRuns = 0)
        : Person{ name, age } // call Person(const std::string&, int) to initialize these fields
        , m_battingAverage{ battingAverage }, m_homeRuns{ homeRuns }
    {
    }

    double getBattingAverage() const { return m_battingAverage; }
    int getHomeRuns() const { return m_homeRuns; }
};

int main(int argc, char const *argv[])
{
    BaseballPlayer bp{"Pedro", 32, 0.342, 43};

    std::cout << "Name of the player is : " << bp.getName() << std::endl;
    std::cout << "Age of the player is : "<< bp.getAge() << std::endl;
    std::cout << "Batting average of the player is : " << bp.getBattingAverage() << std::endl;
    std::cout << "Number of Home runs made by the player : " << bp.getHomeRuns() << std::endl;

    return 0;
}

//***********Simple quiz***
/* class Fruit
{
    private: 
    std::string m_Name;
    std::string m_Color;

    public:
    Fruit(const std::string& name, const std::string& color):
    m_Name{name},
    m_Color{color}
    {}

    const std::string& getName() const
    {
        return m_Name;
    }

    const std::string& getColor() const
    {
        return m_Color;
    }

};

class Apple: public Fruit
{
    private:
    double m_Fiber;

    public:
    Apple(const std::string& name, const std::string& color, double fiber): m_Fiber{fiber}, Fruit{name, color}
    {}

    double getFiber() const
    {
        return m_Fiber;
    }

};

std::ostream& operator<<(std::ostream& out, const Apple& a)
{
    out << "Apple(" << a.getName() << ", " << a.getColor() << ", " << a.getFiber() << ')';
    return out;
}

class Banana: public Fruit
{
    public:
    Banana(const std::string& name, const std::string& color):
    Fruit{name, color}
    {}
};

std::ostream& operator<<(std::ostream& out, const Banana& b)
{
    out << "Banana(" << b.getName() << ", " << b.getColor() << ')';
    return out;
}

int main(int argc, char const *argv[])
{
    const Apple a{ "Red delicious", "red", 4.2 };
	std::cout << a << '\n';

	const Banana b{ "Cavendish", "yellow" };
	std::cout << b << '\n';

    return 0;
} */

//***********Simple quiz***
