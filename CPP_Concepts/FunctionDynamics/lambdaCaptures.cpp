/**
 * @file lambdaCaptures.cpp
 * @author Abhishek
 * @brief Here we discuss about the usage of captures in lambda:
 * 1- These are used to give access to the surrounding variables of the lambda to to the lambda.
 * 2- The default values captured by the lambda are of constant type and cannot be changed. "mutable" keyword can be used to make the captured
 * variables modifyable.
 * 3- capture by reference, once the lambda captures the variables by reference, they are no longer const.
 * 4- captures can be used to atke multiple captures or default captures, which takes all the member variables and feeds to the lambda either
 * by value or by reference.
 * 5- We can define new variables inside the capture of the lambda.
 * 6- We should always be carefull while handling Dangling variables in lambdas.
 * 7- unintended copies of lambda.
 * @version 0.1
 * @date 2022-07-24
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <iostream>
#include <array>
#include <string_view>
#include <string>
#include <algorithm>
//************ point-1***
/* int main(int argc, char const *argv[])
{
    std::array<std::string_view, 4> arr{"apple", "banana", "walnut", "lemon"};

    /// Ask the user what to search for.
    std::cout << "search for: ";

    std::string search{};
    std::cin >> search;

    auto found{std::find_if(arr.begin(), arr.end(), [search](std::string_view str)
                            {
                                /// Search for @search rather than "nut".
                                return (str.find(search) != std::string_view::npos); // Error: search not accessible in this scope
                            }
                        )};

    if (found == arr.end())
    {
        std::cout << "Not found\n";
    }
    else
    {
        std::cout << "Found " << *found << '\n';
    }

    return 0;
} */
//************ point-1***
//************ point-2***
/* int main(int argc, char const *argv[])
{
    int  ammo{ 10 };

    auto shoot
    {
        /// when we captue ammo a new const version is copied which cannot be updated hence the error.
        /// If we want to update.modify the captured variables then we need to mark the lambda with the mutable keyword like below.
        /// Since captured variables are the members of the lambda object hence they persist across the multiple calls to the lambda.
        [ammo]() mutable
        {
            --ammo;     //error: decrement of read-only variable ‘ammo’
            std::cout << "Pew ! " << ammo << "shots left. \n";
        }
    };

    shoot();    //lambda called once.

    std::cout << ammo << "shots left\n";

    return 0;
} */
//************ point-2***
//************ point-3***
/* int main(int argc, char const *argv[])
{
    int  ammo{ 10 };

    auto shoot
    {
        /// variable ammo is captured by reference, hence does not needs mutable keyword.
        [&ammo]()
        {
            --ammo;     //error: decrement of read-only variable ‘ammo’
            std::cout << "Pew ! " << ammo << "shots left. \n";
        }
    };

    shoot();    //lambda called once.

    std::cout << ammo << "shots left\n";

    return 0;
} */
//-----------------------------------
/* struct Car
{
  std::string make{};
  std::string model{};
};

int main()
{
  std::array<Car, 3> cars{ { { "Volkswagen", "Golf" },
                             { "Toyota", "Corolla" },
                             { "Honda", "Civic" } } };

  int comparisons{ 0 };

  std::sort(cars.begin(), cars.end(),
    /// Capture @comparisons by reference.
    [&comparisons](const auto& a, const auto& b) {
      /// We captured comparisons by reference. We can modify it without "mutable".
      ++comparisons;

      /// Sort the cars by their make.
      return (a.make < b.make);
  });

  std::cout << "Comparisons: " << comparisons << '\n';

  for (const auto& car : cars)
  {
    std::cout << car.make << ' ' << car.model << '\n';
  }

  return 0;
} */
//************ point-3***
//************ point-4***
/* int main()
{
    std::array<int, 5> areas = {100, 25, 121, 40, 56};

    int width{};
    int height{};
    int length{};

    std::cout << "Enter width and height and length: ";
    std::cin >> width >> height >> length;

    auto found{ std::find_if(areas.begin(), areas.end(),
                               [=](int knownArea) { // will default capture width and height by value
                                 return (width * height == knownArea); // because they're mentioned here
                               }) };

    /// auto found{std::find_if(areas.begin(), areas.end(),
    ///                         [width, height, &length](int knownArea) { // captures width and height by value and length by reference
    ///                             ++length;
    ///                             return (width * height == knownArea);
    ///                         })};

    /// auto found{std::find_if(areas.begin(), areas.end(),
    ///                         [=, &length](int knownArea) { // captures length by reference and everything else by value.
    ///                             ++length;
    ///                             return (width * height == knownArea);
    ///                         })};

    /// auto found{std::find_if(areas.begin(), areas.end(),
    ///                         [&, length](int knownArea) { // captures length by value and everything else by reference
    ///                             ++length;
    ///                             return (width * height == knownArea);
    ///                         })};

    /// auto found{std::find_if(areas.begin(), areas.end(),
    ///                         [&, &length](int knownArea) { // error
    ///                             ++length;
    ///                             return (width * height == knownArea);
    ///                        })};

    /// auto found{std::find_if(areas.begin(), areas.end(),
    ///                         [=, length](int knownArea) { // error
    ///                             ++length;
    ///                             return (width * height == knownArea);
    ///                         })};

    /// auto found{std::find_if(areas.begin(), areas.end(),
    ///                         [width, height, &width](int knownArea) { // error since width appears twice
    ///                             ++length;
    ///                            return (width * height == knownArea);
    ///                        })};

    /// error: expected identifier before ‘]’ token
    /// auto found{std::find_if(areas.begin(), areas.end(),
    ///                         [width, height, &](int knownArea) { // error since default capture needs to the first element in the capture.
    ///                             return (width * height == knownArea);
    ///                         })};

    if (found == areas.end())
    {
        std::cout << "I don't know this area :(\n";
    }
    else
    {
        std::cout << "Area found :)\n";
    }

    return 0;
} */
//************ point-4***
//************ point-5***
/* int main()
{
  std::array<int, 5> areas{ 100, 25, 121, 40, 56 };

  int width{};
  int height{};

  std::cout << "Enter width and height: ";
  std::cin >> width >> height;

  /// We store areas, but the user entered width and height.
  /// We need to calculate the area before we can search for it.
  auto found{ std::find_if(areas.begin(), areas.end(),
                           /// Declare a new variable that's visible only to the lambda.
                           /// The type of userArea is automatically deduced to int.
                           [userArea{ width * height }](int knownArea) {
                             return (userArea == knownArea);
                           }) };

  if (found == areas.end())
  {
    std::cout << "I don't know this area :(\n";
  }
  else
  {
    std::cout << "Area found :)\n";
  }

  return 0;
} */
//************ point-5***
//************ point-6***
// returns a lambda
/* auto makeWalrus(const std::string& name)
{
  /// Capture name by reference and return the lambda.
  /// temporary string does when this function returns.
  return [&]() {
    std::cout << "I am a walrus, my name is " << name << '\n'; // Undefined behavior
  };
}

int main()
{
  /// Create a new walrus whose name is Roofus.
  /// sayName is the lambda returned by makeWalrus.
  auto sayName{ makeWalrus("Roofus") };

  /// Call the lambda function that makeWalrus returned.
  sayName();

  return 0;
} */
//************ point-6***
//************ point-7-unintended copies of a lambda***
/* #include <functional>

void myInvoke(const std::function<void()>& fn)
{
  fn();
}
int main(int argc, char const *argv[])
{
  int i{ 0 };

  auto count{
    [i]() mutable
    {
      std::cout << ++i << "\n";
    }
  };
  /// when the count is passed as an argument, function myInvoke creates a copy of count and makes changes to that copy, hence
  /// you see 1 printed 3 times.
  /// use std::ref in order to avoid such case.
  myInvoke(std::ref(count));
  myInvoke(std::ref(count));
  myInvoke(std::ref(count));

  return 0;
} */
//************ point-7***
//************ QUIZ***
/* int i{};
static int j{};

int getValue()
{
  return 0;
}

int main()
{
  int a{};
  constexpr int b{};
  static int c{};
  static constexpr int d{};
  const int e{};
  const int f{ getValue() };
  static const int g{};
  static const int h{ getValue() };

  [](){
    /// Try to use the variables without explicitly capturing them.
    /// a;  //No. a has automatic storage duration.
    b;    
    c;
    d;
    e;
    /// f;  //No. f‘s value depends on getValue, which might require the program to run.
    g;
    h;
    i;
    j;
  }();

  return 0;
} */
//************ QUIZ***
//************ QUIZ***
/* int main()
{
  std::string favoriteFruit{ "grapes" };

  auto printFavoriteFruit{
    [=]() {
      std::cout << "I like " << favoriteFruit << '\n';
    }
  };

  favoriteFruit = "bananas with chocolate";

  printFavoriteFruit();

  return 0;
} */
//************ QUIZ***
//************ QUIZ***
/**
 * @brief
 * TODO:We’re going to write a little game with square numbers (numbers which can be created by multiplying an integer with itself (1, 4, 9, 16, 25, …)).
  Ask the user to input 2 numbers, the first is the square root of the number to start at, the second is the amount of numbers to generate.
   Generate a random integer from 2 to 4, and square numbers in the range that was chosen by the user. Multiply each square number 
   by the random number. You can assume that the user enters valid numbers.

  The user has to calculate which numbers have been generated. The program checks if the user guessed correctly and removes the guessed 
  number from the list. If the user guessed wrong, the game is over and the program prints the number that was closest to the user’s final 
  guess, but only if the final guess was not off by more than 4.

  Here are a couple of sample sessions to give you a better understanding of how the game works:

  Start where? 4
  How many? 8
  I generated 8 square numbers. Do you know what each number is after multiplying it by 2?
  > 32
  Nice! 7 number(s) left.
  > 72
  Nice! 6 number(s) left.
  > 50
  Nice! 5 number(s) left.
  > 126
  126 is wrong! Try 128 next time.
  The user chose to start at 4 and wants to play with 8 numbers.
  Each square number will be multiplied by 2. 2 was randomly chosen by the program.
  The program generates 8 square numbers, starting with 4 as a base:
  16 25 36 49 64 81 100 121
  But each number is multiplied by 2, so we get:
  32 50 72 98 128 162 200 242
  Now the user starts to guess. The order in which the guesses are entered doesn’t matter.
  32 is in the list.
  72 is in the list.
  126 is not in the list, the user loses. There is a number in the list (128) that is not more then 4 away from the user’s guess, 
  so that number is printed. 
 */

//************ QUIZ***
