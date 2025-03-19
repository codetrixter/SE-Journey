#include <iostream>

class Point
{
    int x;
    public:
    explicit Point(int a): x{a}
    {}

    Point& operator++();
    Point operator++(int);
    friend std::ostream& operator<< (std::ostream& out, const Point& rhs);
};

// Point& Point::operator++ ()
// {
//     ++x;
//     return *this;
// }

Point Point::operator++(int)
{
    Point temp = *this;

    ++x;
    return temp;
}

std::ostream& operator<< (std::ostream& out, const Point& rhs)
{
    out << rhs.x;
    return out;
}

int main(int argc, char const *argv[])
{
    Point p(1);
    std::cout << p++ << p++ << p;
    return 0;
}
