/**
 * @file typeDeductionForObjectsAuto.cpp
 * @author Abhishek 
 * @brief Here we discuss the type deduction using the auto keyword for objects:
 * 1- type deduction works with the initialized variables only.
 * 2- type deduction drops the const qualifier from the deduced types.
 * 3- type deduction of string literals works when added a suffix of s and sv for 
 * string and strin_view.
 * 
 * @version 0.1
 * @date 2022-07-11
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#include <string>
#include <string_view>

int main(int argc, char const *argv[])
{
    auto d{5.0};
    auto i{5};

    std::cout << typeid(d).name() << " " << typeid(i).name();
    //auto x; //error: declaration of ‘auto x’ has no initializer

    //const is droped after type deduction
    const int val{10};
    auto xx{val};   //const is dropped from val, it is of type int now.
    
    std::cout << typeid(val).name() << " " << typeid(xx).name();

    //string type deductions
    auto str{"abhishek"};
    using namespace std::literals;
    auto str1{ "mishra"s };
    auto str2{ "kumar"sv };
    std::cout << typeid(str).name() << " " << typeid(str1).name() << " " << typeid(str2).name();
    return 0;

    //********Type deduction and constexpr */
    {
        constexpr int val{10};
        auto xx{val};   //xx is of type int, const is dropped

        const l_c {val}; //l_c is of type const int, where val's constness is dropped and reapplied to l_c.
        std::cout << typeid(val).name() << " " << typeid(xx).name();    
    }
}
