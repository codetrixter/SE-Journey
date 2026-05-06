/**
 * @file dependency.cpp
 * @author Abhishek
 * @brief Here we discuss about the dependency relationship:
 * 1- Dependency is different than association in a way that in a dependency, the dependent object/class instantiates the dependency on the fly 
 * whenever needed.
 * @version 0.1
 * @date 2022-08-28
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>

//Dependent class
class Point
{
private:
    double m_x{};
    double m_y{};
    double m_z{};

public:
    Point(double x=0.0, double y=0.0, double z=0.0): m_x{x}, m_y{y}, m_z{z}
    {
    }

    friend std::ostream& operator<< (std::ostream& out, const Point& point); // Point has a dependency on std::ostream here
};

//Dependency implementation
std::ostream& operator<< (std::ostream& out, const Point& point)
{
    // Since operator<< is a friend of the Point class, we can access Point's members directly.
    out << "Point(" << point.m_x << ", " << point.m_y << ", " << point.m_z << ')';

    return out;
}

int main()
{
    Point point1 { 2.0, 3.0, 4.0 };

    std::cout << point1; // the program has a dependency on std::cout here

    return 0;
}

/*
## 📝 CONCEPT ANALYSIS

### 🔑 Core Concepts Demonstrated:
| # | Concept | Where Used |
|---|---------|-----------|
| 1 | **Dependency relationship** | Point depends on `std::ostream` (uses-a) |
| 2 | **Transient usage** | ostream used only during function call, not stored |
| 3 | **Friend function for dependency** | `operator<<` accesses private members |

### 🏭 Real-World Usage:
- Most function parameters represent dependencies
- Dependency injection: pass interfaces as params for testability

### ⚡ Quick Revision:
- Dependency = "uses-a" — weakest relationship
- Object is used transiently (not stored as member)
- Typically via function parameter or local instantiation
*/