/**
 * *Make sure that the objects are initialized before they are used.
 * 
 * !!IMportant thing to Cover!!
 * !The order of initialization non-local static objects defined in different 
 * !translation units.
 * 
 * *When we have non local static objects in different translation units, it becomes impossible to
 * *make sure that these objects are initialized while they are used in a new object which uses 
 * *prev. non-local static objects.
 * 
 * *One way to make sure that these non-local static objects are initialized before using 
 * *them is by making them part of the a function which returns references to these objects liek below:
 * FileSystem& tfs()
 * {
 *      static FileSystem fs;
 *      return fs;
 * } 
 */
#include <iostream>
#include <list>
using namespace std;

class PhoneNumber
{
};

class ABEntry
{
    // ABEntry = “Address Book Entry”
public:
    ABEntry();
    ABEntry(const std::string &name, const std::string &address,
            const std::list<PhoneNumber> &phones);

private:
    std::string theName;
    std::string theAddress;
    std::list<PhoneNumber> thePhones;
    int numTimesConsulted;
};

ABEntry::ABEntry()
{
    cout << "default ctor..";
}

// A better way to do this would be...
/* ABEntry::ABEntry(const std::string &name, const std::string &address,
                 const std::list<PhoneNumber> &phones)
{
    theName = name;
    // these are all assignments,
    theAddress = address;
    // not initializations
    thePhones = phones;
    numTimesConsulted = 0;
} */

// Here the member variables are initialized and not assigned.
ABEntry::ABEntry(const std::string &name, const std::string &address,
                 const std::list<PhoneNumber> &phones) : theName{name},
                                                         theAddress{address},
                                                         thePhones{phones},
                                                         numTimesConsulted{0}
{
}

int main(int argc, char const *argv[])
{
    string name = "abhi", add = "123";
    list<PhoneNumber> num;

    ABEntry a(name, add, num);
    return 0;
}
