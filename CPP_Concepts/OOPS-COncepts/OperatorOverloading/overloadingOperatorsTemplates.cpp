/**
 * Here we will discuss about the effects of using function templates with user defined classes and how operator
 * overloading come to the rescue.
 */

 #include <iostream>
 #include <string>

 template <typename T>
T average(const T* myArray, int numValues)
{
    T sum { 0 };
    for (int count { 0 }; count < numValues; ++count)
        sum += myArray[count];

    sum /= numValues;
    return sum;
}

class Cents
{
private:
    int m_cents {};
public:
    Cents(int cents)
        : m_cents { cents }
    {
    }

    friend std::ostream& operator<< (std::ostream& out, const Cents& cents)
    {
        out << cents.m_cents << " cents ";
        return out;
    }

    Cents& operator+= (const Cents &cents)
    {
        m_cents += cents.m_cents;
        return *this;
    }

    Cents& operator/= (int x)
    {
        m_cents /= x;
        return *this;
    }
};

int main()
{
    Cents centsArray[] { Cents { 5 }, Cents { 10 }, Cents { 15 }, Cents { 14 } };
    std::cout << average(centsArray, 4) << '\n';

    return 0;
}

/*
## 📝 CONCEPT ANALYSIS

### 🔑 Core Concepts Demonstrated:
| # | Concept | Where Used |
|---|---------|-----------|
| 1 | **Operator overloading with templates** | `average()` works with Cents class |
| 2 | **operator+= and /= overloading** | Required for template to compile |
| 3 | **Template type requirements** | Class must support operations used in template |

### ⚡ Quick Revision:
- Templates generate code per type → class must support all used operators
- Overload `+=`, `/=`, `<<` etc. to make class work with generic algorithms
- C++20 concepts formalize these requirements explicitly
*/