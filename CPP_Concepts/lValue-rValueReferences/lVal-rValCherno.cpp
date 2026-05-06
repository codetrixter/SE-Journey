/**
 * * Lvalues abd Rvalues are in c++ even before c++11, with the advent of c++11, Lvalue and 
 * * Rvalue references were introduced.
*/

// Takes an l-value and returns an l-value.
int lValueFunc(int a)
{
    return a;
}

//This function takes the r-value as input and returns the rvalue as well.
int rValueFunc(int&& a)
{
    return a;
}

//This function while return an l-value but can take both l and r values as parameters.
int lRvalueFunc(const int& value)
{
    return value;
} 

int main(int argc, char const *argv[])
{
    int x = 10; //x here is an L-value.
    lValueFunc(x);  //l-value is passed hence no error
    lValueFunc(222); //here the rvalus is converted to an lvalue while being passed to the function
    rValueFunc(20); //r-value is passed 
    //rValueFunc(22) = 100; //lvalue required on lHS of = operator.

    //-------------------

    lRvalueFunc(x);
    lRvalueFunc(20);

    return 0;
}

/*
## 📝 CONCEPT ANALYSIS

### 🔑 Core Concepts Demonstrated:
| # | Concept | Where Used |
|---|---------|-----------|
| 1 | **lvalue reference parameter** | `int lValueFunc(int a)` takes lvalue (copy) |
| 2 | **rvalue reference parameter** | `int rValueFunc(int&& a)` binds only to rvalues |
| 3 | **const lvalue reference** | `const int&` binds to BOTH lvalues and rvalues |
| 4 | **Implicit conversion** | rvalue passed to value param → copied into lvalue |

### 🔄 Alternatives & Modern C++ Idioms:
- Perfect forwarding: `template<typename T> void f(T&& x)` — universal reference
- `std::move` to cast lvalue to rvalue for move semantics
- `std::forward` preserves value category in templates

### 🏭 Real-World Usage:
- Move constructors use `T&&` to steal resources from temporaries
- `const T&` is the universal "read-only" parameter type
- Rvalue references enable zero-copy transfers in containers

### ⚡ Quick Revision:
- `T&` binds to lvalues only
- `T&&` binds to rvalues only (named rvalue ref is itself an lvalue!)
- `const T&` binds to both lvalues and rvalues
- Rvalue references (C++11) enable move semantics
*/
