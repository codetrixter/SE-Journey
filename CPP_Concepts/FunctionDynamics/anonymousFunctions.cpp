/**
 * @file anonymousFunctions.cpp
 * @author Abhishek
 * @brief Here we discuss the uses and purpose of lambda.
 * 1- example of a program without lambda, but needs one.
 * 2- Syntax of a lambda/closure is :
 * [captureClause](parameters) -> reurn type
 * {
 *      function body
 * }
 * 3- We can name/create variable for a lambda so that we can directly use that name
 * while passing as function parameter.
 * 4- Lambda's can be stored using either auto(type deduction) or std::function.
 * 5- use auto when initializing variable with lambda and use std::function otherwise.
 * 6- Generic lambda(Since C++14):
 *  -> A lambda with one or more auto in there parameter list is called as a generic lambda.
 * 7- A single generic lambda will be generated for each different type that auto resolves to.
 * 8- Return type deductions are done based on the return type of the lambda body, if there are two 
 * return types in the body then, there will be compile time error.
 * @version 0.1
 * @date 2022-06-27
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <iostream>
#include <array>
#include <string_view>
#include <algorithm>
#include <functional>

// Our function will return true if the element matches
// Here (C++17)std::string_view is the class which takes the copy of a string and then if another string is created from it
// the new string will not be copied, instead it will be used as a reference to the original string
// (no new memory allocated)
/* bool containsNut(std::string_view str)
{
    /// std::string.find() returns std::string_view::npos if it doesn't find
    /// the substring. Otherwise it returns the index where the substring occurs
    /// in str.
    return (str.find("nut") != std::string_view::npos);
}

int main()
{
    std::array<std::string_view, 4> arr{ "apple", "banana", "walnut", "lemon" };

    /// Scan our array to see if any elements contain the "nut" substring
    /// Here containsNut() function is only used once and then never again, so it is useless to define it with name.
    /// We can use lambdas here to avoid such single use functions.
    /// auto found{ std::find_if(arr.begin(), arr.end(), containsNut) };

    /// Lambda version, this type of use of lambda right where it is used is also called function literal.
    auto found = std::find_if(arr.begin(), arr.end(), [](std::string_view str) {
        /// body of the nameless function goes here.
        /// return type of this function is deduced automatically by the compiler, by looking at the
        /// last line of the function.
        return (str.find("nut") != std::string_view::npos);
    });

    if (found == arr.end())
    {
        std::cout << "No nuts\n";
    }
    else
    {
        std::cout << "Found " << *found << '\n';
    }

    return 0;
} */

//*************naming a lambda***
/* /// naming the lambda so that it can be used easily without confusion.
/// instead of auto as a type inference, we can also use function pointer as long as the capture is empty.
bool (*isEven)(int) {
    [] (int n) {
        return ((n%2) == 0);
    }
};

int main(int argc, char const *argv[])
{
    std::vector<int> array{ 2, 4, 6 };
    /// std::all_of is a part of algorithm header, and it iterates through the given data structor and
    /// checks for condition for each element of the structure
    std::cout << std::all_of(array.begin(), array.end(), isEven);
    return 0;
} */
//*************naming a lambda***
//*************storing lambda***
/* int main(int argc, char const *argv[])
{
    /// this version cannot have captures
    int (*addNumbers1)(int, int){
        [](int a, int b)
        {
            return a+b;
        }
    };

    std::cout << addNumbers1(10, 20) << std::endl;

    /// This version can have captures as well
    std::function<int(int,int)> addNumbers2{
        [](int a, int b)
        {
            return a+b;
        }
    };

    std::cout << addNumbers2(20, 30) << std::endl;

    /// This version of lambda can also have captures
    auto addNumbers3{
        [](int a, int b)
        {
            return a+b;
        }
    };

    std::cout << addNumbers1(30, 40) << std::endl;
    return 0;
} */
//*************storing lambda***
//*************using std::function for func param***
// We don't know what fn will be. std::function works with regular functions and lambdas.
// Here auto cannot be used, it is only allowed since c++20.
/* void repeat(int repetitions, const std::function<void(int)>& fn)
{
  for (int i{ 0 }; i < repetitions; ++i)
  {
    fn(i);
  }
}

int main()
{
  repeat(3, [](int i) {
    std::cout << i << '\n';
  });

  return 0;
} */
//*************using std::function for func param***
//*************Generic lambda***
/* /// requires c++17 to build//
int main()
{
    std::array<const char *, 12> months{// pre-C++17 use std::array<const char*, 12>
                                        "January",
                                        "February",
                                        "March",
                                        "April",
                                        "May",
                                        "June",
                                        "July",
                                        "August",
                                        "September",
                                        "October",
                                        "November",
                                        "December"};

    /// search for two months that start with the same letter.
    const auto sameLetter{std::adjacent_find(months.begin(), months.end(),
                                             [](const auto &a, const auto &b)
                                             {
                                                 return (a[0] == b[0]);
                                             })};

    if (sameLetter != months.end())
    {
        /// std::next returns the next iterator after sameLetter.
        std::cout << *sameLetter << " and " << *std::next(sameLetter) << " start with the same letter\n";
    }

    /// c-style strings are not always the first choice, therefore string_view is used whenever string fun are needed 
    const auto stringswithfive{std::count_if(months.begin(), months.end(),
                                             [](std::string_view str)   
                                             {
                                                 return (str.length() == 5);
                                             })};

    std::cout << "There are " << stringswithfive << " five letter months";
} */
//*************Generic lambda***
//*************Generic lambda duplicates***
/* int main(int argc, char const *argv[])
{
    /// Here two version of lambda's are generated one for string and other for integer.
    auto print{
        [](auto value)
        {
            static int callcount = 0;
            std::cout << callcount++ << ": " << value << '\n';
        }
    };

    print("hello");
    print("world");

    print(1);
    print(2);

    print("ding dong");
    return 0;
} */
//*************Generic lambda duplicates***
//*************Return type deductions***
/* int main(int argc, char const *argv[])
{
    /// here we rceieve error: inconsistent types ‘int’ and ‘double’ deduced for lambda return type
    /// In order to fix this we can do two things:
    /// 1- explict casting of the return type to same types.
    /// 2- explicitly define the return type of the lambda.
    auto divide {
        [](int x, int y, bool bInteger) -> double
        {
            if(bInteger)
                return x/y; // will do an implicit conversion to double
            else
                return static_cast<double>(x)/y;
        }
    };

    std::cout << divide(3, 2, true) << '\n';
    std::cout << divide(3, 2, false) << '\n';
    return 0;
} */
//*************Return type deductions***
//*************example of a library lambda***
/* #include <array>

int main(int argc, char const *argv[])
{
    std::array arr{13, 90, 99, 5, 40, 80};
    std::sort(arr.begin(), arr.end(), std::less{}); //curly braces are for instantiating object
    
    for(int i: arr)
    {
        std::cout << i << ' ';
    }
    std::cout << "\n";
    return 0;
} */
//*************example of a library lambda***
//************Quiz-1***
/* struct Student
{
    std::string name;
    int points;
};
int main(int argc, char const *argv[])
{
    std::array<Student, 8> arr{
  { { "Albert", 3 },
    { "Ben", 5 },
    { "Christine", 2 },
    { "Dan", 8 }, // Dan has the most points (8).
    { "Enchilada", 4 },
    { "Francis", 1 },
    { "Greg", 3 },
    { "Hagrid", 5 } }
    };

    auto best = std::max_element(arr.begin(), arr.end(), [](const auto &a, const auto &b)
    {
        return (a.points < b.points);
    });

    std::cout << best->name << " is the best student";
     return 0;
}; */
//************Quiz-1***
//************Quiz-2***
struct Season
{
  std::string_view name{};
  double averageTemperature{};
};

int main()
{
  std::array<Season, 4> seasons{
    { { "Spring", 285.0 },
      { "Summer", 296.0 },
      { "Fall", 288.0 },
      { "Winter", 263.0 } }
  };
  
  std::sort(seasons.begin(), seasons.end(), [](const auto &a, const auto &b)
  {
    return (a.averageTemperature < b.averageTemperature);
  });

  for (const auto& season : seasons)
  {
    std::cout << season.name << '\n';
  }

  return 0;
}
//************Quiz-2***