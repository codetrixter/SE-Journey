/**
 * !- L value expressions evaluate to an idetifible object.
 * !- R value expressions evaluate to a temporary object or a value not associated with an identifiable object.
 * !- An lvalue expression can be converted to an rvalue expression.
 * !- An rvalue expression cannot be converted to an lvalue expression.
 */

 int main() 
 {
    int x = 10; // x is an lvalue
    int y = x;  // x is converted to an rvalue to assign to y

    int* p = &x; // &x is an rvalue (address of x)
    // int& r = 20; // Error: cannot bind non-const lvalue reference to an rvalue
    const int& r = 20; // OK: can bind const lvalue reference to an rvalue

    int z = x + 5; // (x + 5) is an rvalue, sice it resolves to  temporary value, which immidiately looses scope bwyond this expression


    /*********Lvalue to Rvalue coversion */

    int a{ 1 };
    int b{ 2 };

    a = b; // y is not an rvalue, but this is legal. Here conversion is happenening and b is evaluated to 2 by the compiler.

    a = a + 3; //Here the + overloaded operator operates on the converted rvalue of a (which is 1) and r value 
    3, producing a new rvalue (which is 4). This new rvalue is then assigned to a.
    /*********************************** */

    return 0;
 }