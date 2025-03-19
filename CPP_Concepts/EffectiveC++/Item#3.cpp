/**
 * *Use const whenever posiible.
 */
#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

//! Rule to identify the constness of the variable defined:
//! 1- If the const appears to the left of the asterisk->the object pointed by the pointer is constant.
//! 2- If the const appears to the right of the asterisk->the pointer itself is constant.
namespace constants
{
    char greeting[] = "Hello";
    char *p = greeting;
    // non-const pointer, const data
    const char *p1 = greeting;
    // const poiter, non-const data
    char *const p3 = greeting;
    // const pointer and data
    const char *const p2 = greeting;
}

//------------------
void function1(const int *p1); // Here function1 takes a pointer to the constant p1 integer.
void function2(int const *p1); // Here also function2 takes the pointer to the constnt p1 ineteger variable.
//------------------

//----------------const member functions-------------
class TextBlock
{
public:
    TextBlock(const string s) : text{s}
    {
    }
    const char &operator[](std::size_t position) const
    // operator[] for
    {
        return text[position];
    }
    // const objects
    char &operator[](std::size_t position)
    // operator[] for
    {
        return text[position];
    }
    // non-const objects
private:
    std::string text;
};
//----------------const member functions-------------

//-----------constant dillema--------------

//-----------constant dillema--------------

void run()
{
    //------const iterators
    // Here the iterator itself is constant but the object it points can change
    vector<int> vec;
    const vector<int>::iterator iter = vec.begin();
    *iter = 20; // will work
    //++iter; //error

    // Here the iterator is not const but the object pointed by the iterator is constant.
    vector<int>::const_iterator citer = vec.begin();
    //*iter = 20; //error
    ++citer; // will work

    //------const iterators
}
int main(int argc, char const *argv[])
{
    // run();

    //-------const member functions
    TextBlock tb("Hello");
    std::cout << tb[0];
    // calls non-const
    // TextBlock::operator[]
    const TextBlock ctb("World");
    std::cout << ctb[0];
    // calls const TextBlock::operator[]
    //-------const member functions
    return 0;
}
