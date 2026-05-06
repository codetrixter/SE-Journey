/**
 * @file timerClass.cpp
 * @author Abhishek
 * @brief Here we see how to check the peformance of our functions by using Chrono library.
 * @version 0.1
 * @date 2022-06-11
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <array>
#include <chrono> // for std::chrono functions
#include <cstddef> // for std::size_t
#include <iostream>
#include <numeric> // for std::iota
#include <algorithm>

const int g_arrayElements { 10000 };

class Timer
{
private:
    // Type aliases to make accessing nested type easier
    using clock_type = std::chrono::steady_clock;
    using second_type = std::chrono::duration<double, std::ratio<1> >;

    std::chrono::time_point<clock_type> m_beg{ clock_type::now() };

public:

    void reset()
    {
        m_beg = clock_type::now();
    }

    double elapsed() const
    {
        return std::chrono::duration_cast<second_type>(clock_type::now() - m_beg).count();
    }
};

void sortArray(std::array<int, g_arrayElements>& array)
{

    // Step through each element of the array
    // (except the last one, which will already be sorted by the time we get there)
    for (std::size_t startIndex{ 0 }; startIndex < (g_arrayElements - 1); ++startIndex)
    {
        // smallestIndex is the index of the smallest element we’ve encountered this iteration
        // Start by assuming the smallest element is the first element of this iteration
        std::size_t smallestIndex{ startIndex };

        // Then look for a smaller element in the rest of the array
        for (std::size_t currentIndex{ startIndex + 1 }; currentIndex < g_arrayElements; ++currentIndex)
        {
            // If we've found an element that is smaller than our previously found smallest
            if (array[currentIndex] < array[smallestIndex])
            {
                // then keep track of it
                smallestIndex = currentIndex;
            }
        }

        // smallestIndex is now the smallest element in the remaining array
        // swap our start element with our smallest element (this sorts it into the correct place)
        std::swap(array[startIndex], array[smallestIndex]);
    }
}

int main()
{
    std::array<int, g_arrayElements> array;
    std::iota(array.rbegin(), array.rend(), 1); // fill the array with values 10000 to 1

    Timer t;

    //sortArray(array);
    std::sort(array.begin(), array.end());  //around 1000 times faster than selection sort technique

    std::cout << "Time taken: " << t.elapsed() << " seconds\n";

    return 0;
}

/*
## 📝 CONCEPT ANALYSIS

### 🔑 Core Concepts Demonstrated:
| # | Concept | Where Used |
|---|---------|-----------|
| 1 | **std::chrono library** | `steady_clock`, `duration`, `duration_cast` |
| 2 | **Type aliases in class** | `using clock_type = std::chrono::steady_clock` |
| 3 | **RAII timing** | Timer starts in constructor (member init) |
| 4 | **Selection sort vs std::sort** | ~1000x performance difference |
| 5 | **std::iota** | Fill array with sequential values |

### 🔄 Alternatives & Modern C++ Idioms:
- C++20: `std::chrono::high_resolution_clock` for max precision
- Use RAII scoped timer that prints on destruction for automatic profiling
- Google Benchmark library for production benchmarking
- `std::ranges::sort` (C++20) for range-based sorting

### 🏭 Real-World Usage:
- Profiling hot paths in game loops, trading systems, rendering
- `steady_clock` preferred over `system_clock` (immune to system time changes)
- Scoped timers used in logging frameworks for function-level profiling

### ⚡ Quick Revision:
- `steady_clock` = monotonic, best for measuring durations
- `duration_cast` converts between time units
- Selection sort O(n²) vs std::sort O(n log n) — massive difference at scale
- Type aliases make chrono code readable
*/