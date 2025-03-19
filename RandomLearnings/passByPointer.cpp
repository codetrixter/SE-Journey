#include <iostream>
struct Name
{
    int size;
};
void function(Name *nickName)
{
    nickName->size = 20;
}
int main(int argc, char const *argv[])
{
    Name *snew = new Name();
    snew->size = 10;
    std::cout << snew->size;

    function(snew);

    std::cout << snew->size;
    return 0;
}
