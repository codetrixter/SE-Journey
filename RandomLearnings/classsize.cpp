#include <iostream>

class Base
{};
class derived: public Base
{
    int val;
};

int main(int argc, char const *argv[])
{
    std::cout << sizeof(Base) << "\n"
    << sizeof(derived);
    return 0;
}
