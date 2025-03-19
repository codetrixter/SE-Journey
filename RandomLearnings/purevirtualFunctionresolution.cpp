#include <iostream>

class Base
{
    public:
    virtual void getName() = 0;

    virtual void functionName()
    {
        getName();
    }
};
class Derived: public Base
{
    public:
    void getName()
    {
        std::cout << "Derived version";
    }
};
int main(int argc, char const *argv[])
{
    Base* base = new Derived();
    base->functionName();
    return 0;
}
