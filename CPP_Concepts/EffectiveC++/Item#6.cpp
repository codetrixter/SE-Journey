/**
 * *Explicitly disallow the use of compiler generated functions you do not want.
*/

#include <iostream>
using namespace std;
//------------------------------Case 1 and 2-----
/* class HomeForSale
{
    public:
    HomeForSale() = default;
    void createCopies();

    private:
    HomeForSale(const HomeForSale& hfs);
    HomeForSale& operator=(const HomeForSale& lhs);
};

void HomeForSale::createCopies()
{
    HomeForSale obj2;
    *this = obj2;   //linker error : undefined reference to 'HomeForSale& operator=(const HomeForSale& lhs)'
}

// Here we can create copy as well as assigne the object to one another, since there is defaukt versions 
// of copy ctor and copy assignment operator defined by the compiler.
void runCase1()
{
    HomeForSale hfs1;
    // HomeForSale hfs2(hfs1);  //error:copy ctor is private within this context.
    //hfs2 = hfs1;    //copy assignement operator invoked.
}

// In order to prevent the case 1, we can define copy ctor. and copy ass. opera. as private, which will
// prevent outside users from creating copies and assinments, but still friends and teh members of the
// class itself can create copies and assinmnets.
// In order to prevent even that we can declare copy ctor. and copy ass. oper. as private memebrs of the
// class but will not define them, which will basically not allow even friends and own memebres of the 
// class to create copies and ass. since they will get linker errors.
void runCase2()
{
    HomeForSale hfs1;
    HomeForSale hfs2;
    //hfs2 = hfs1;    //copy assignement operator invoked, error: private within this context.

    // Take a look, for example, at the definitions of 
    // !ios_base, basic_ios, and sentry 
    // in your standard library implementation, which use the same technique of declaration
    // but not definition.
    hfs1.createCopies();    //gives linker error.
} */
//------------------------------Case 1 and 2-----
class Uncopyable
{
    protected:
    Uncopyable(){}
    ~Uncopyable(){}

    private:
    Uncopyable(const Uncopyable& hfs);
    Uncopyable& operator=(const Uncopyable& lhs);
};

class HomeForSale: private Uncopyable
{
    public:
    void createCopyAss()
    {
        HomeForSale temp;
        // copy ass. oper. is deleted within this context since the base class has private copy ass. oper.
        // !Boost uses this to prevent copy and assnments.
        *this = temp;
    }
};
// We can move from link time error to compile time error, moving private copy ctor and copy ass. oper.
// in the base class, and implement that base class in the HomeForSale class.
void runCase3()
{
    HomeForSale hfs1;
    hfs1.createCopyAss();
}

int main(int argc, char const *argv[])
{
    //runCase1();
    //runCase2();
    runCase3();
    return 0;
}
