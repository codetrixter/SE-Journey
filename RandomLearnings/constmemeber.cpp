#include <iostream>

class Base
{
    public:
    static int value;
    const int a = 10;

    Base()
    {

    }
};

int Base::value = 20;
int main(int argc, char const *argv[])
{
    Base b;
    std::cout << b.a << b.value;
    return 0;
}
