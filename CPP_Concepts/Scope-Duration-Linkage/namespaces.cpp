/**
 * *Purpose: namespaces were originally introduced to prevent naming collisions in a huge project using vast nukber of 3rd party libraries
 * - Nested namespaces
 * - namespace aliasing
 * - same namespace can be used in multip[le files or multiple places in a file
 * 
 * !namespaces are heavily used by standard library as in, most of the header files of the standard library is using namespace std
 * !this allows them to ditribute the std code into different header files
 */

 /**********nested namespace ************/
 #include <iostream>

 // In c++17 this can also be written as namespace Foo::Goo{ } in a single line
// namespace Foo
// {
//     namespace Goo // Goo is a namespace inside the Foo namespace
//     {
//         int add(int x, int y)
//         {
//             return x + y;
//         }
//     }
// }

// int main1()
// {
//     std::cout << Foo::Goo::add(1, 2) << '\n';
//     return 0;
// }
 /**********nested namespace ************/

 /**********namespaxce aliasing **********/

namespace Foo::Goo
{
    int add(int x, int y)
    {
        return x + y;
    }
}

int main2()
{
    namespace Active = Foo::Goo; // active now refers to Foo::Goo

    std::cout << Active::add(1, 2) << '\n'; // This is really Foo::Goo::add()

    return 0;
} // The Active alias ends here
 /**********namespaxce aliasing **********/
