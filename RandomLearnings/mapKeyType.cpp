#include <iostream>
#include <map>

/* struct number
{
    int a;
};

bool operator< (const number& p1, const number& p2)
    {
        return (p1.a < p2.a);
    }

int main(int argc, char const *argv[])
{
    number num;
    std::map<number, int> mm;
    mm[num] = 10;
    return 0;
} */

//--------------user defined in unordered map-----------

#include <unordered_map>

struct Person
{
    int a, b;

    Person(int x, int y)
    {
        a = x;
        b = y;
    }

    //== operator is overloaded to handle collisions
    bool operator==(const Person& p2) const
    {
        return (a == p2.a && b == p2.b);
    }
};

class MyHash
{
    public:

    size_t operator()(const Person& p) const
    {
        return sizeof(p.a)+sizeof(p.b);
    }
};

int main(int argc, char const *argv[])
{
    std::unordered_map<Person, int, MyHash> mm;
    Person p1(10,20);
    mm[p1] = 100;

    return 0;
}




