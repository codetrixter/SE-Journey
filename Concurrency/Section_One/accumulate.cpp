/**
 * @file accumulate.cpp
 * @author Abhishek
 * @brief Here we discuss on how to use std accumulate algorithm:
 * @version 0.1
 * @date 2022-10-07
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <string>

void sequential_accumulate()
{
    std::vector<int> vec{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int sum = std::accumulate(vec.begin(), vec.end(), 0);

    int product = std::accumulate(vec.begin(), vec.end(), 1,
                                  std::multiplies<>());

    auto dash_fold = [](std::string a, int b)
    {
        return std::move(a) + "-" + std::to_string(b);
    };

    std::string s = std::accumulate(std::next(vec.begin()), vec.end(), std::to_string(vec[0]),
                                    dash_fold);
    std::cout << sum << "\n";
    std::cout << product << "\n";
    std::cout << s;
}
int main(int argc, char const *argv[])
{
    sequential_accumulate();
    return 0;
}
