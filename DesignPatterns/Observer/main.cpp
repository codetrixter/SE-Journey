/**
 * @brief Here we discuss about the observer design pattern:
 * * Definition: An observer is an object that wishes to be informed about the events happenning in 
 * * the system. The entity generating the events is called observable. 
*/
#include <iostream>
#include "observer.hpp"
#include "observable.hpp"

class Person : public Observable<Person>
{
    int age;

    public:

    Person(int a): age{a} {

    }

    int getAge()
    {
        return age;
    }

    void setAge(int x)
    {
        if(age == x) return;
        age = x;
        notify(*this, "age");
    }
};

class ConsolePersonObserver : public Observer<Person>
{
    private:
    void field_changed(Person& source, const std::string& field_name) override
    {
        std::cout << "Person's" << field_name << "has changed to :";
        if(field_name == "age")
            std::cout << source.getAge() << std::endl;

    }
};

int main(int argc, char const *argv[])
{
    Person p{5};
    ConsolePersonObserver cpo;
    p.subscribe(cpo);
    p.setAge(20);
    p.setAge(30);
    p.unsubscribe(cpo);
    p.setAge(20);
    return 0;
}
