/**
 * ! ITEM-7 :: Distinguich between () and {} while creating objects.
 ** Things to Remember
    • Braced initialization is the most widely usable initialization syntax, it prevents
    narrowing conversions, and it’s immune to C++’s most vexing parse.
    • During constructor overload resolution, braced initializers are matched to
    std::initializer_list parameters if at all possible, even if other construc‐
    tors offer seemingly better matches.
    • An example of where the choice between parentheses and braces can make a
    significant difference is creating a std::vector<numeric type> with two
    arguments.
    • Choosing between parentheses and braces for object creation inside templates
    can be challenging.
 */

 #include <iostream>

 class Widget
 {
    public:
    Widget(int i, bool d1) {std::cout << "int, bool\n";};
    Widget(int i, double d2) {std::cout << "int, double\n";};

    //initializer_list parameters
    Widget(std::initializer_list<long double> il) {std::cout << "initializer list\n";};

 };

 int main(int argc, char const *argv[])
 {
    Widget w1(10, true);
    Widget w2{10, true};    //calls initializer_list ctor with conversion of 10 and true to long double.
    Widget w3(10, 5.0);
    Widget w4{10, 5.0};     //same as w2

    return 0;
 }
 