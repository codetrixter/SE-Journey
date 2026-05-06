#include <iostream>
#include <cstring>

class String
{
    public:
    String() = default;

    String(const char* string)
    {
        std::cout << "created! \n";
        m_size = strlen(string);
        m_data = new char[m_size];
        memcpy(m_data, string, m_size); 
    }

    String(const String& str)
    {
        std::cout << "copied! \n";
        m_size = str.m_size;
        m_data = new char[m_size];
        memcpy(m_data, str.m_data, m_size);
    }

    String(String&& other)
    {
        std::cout << "Moved! \n";
        m_size = other.m_size;
        m_data = other.m_data;
        
        //deallocating previous object
        other.m_size = 0;
        other.m_data = nullptr;
    }

    ~String()
    {
        std::cout << "Destroyed \n";
        delete m_data;
    }

    void print()
    {
        for(u_int32_t i = 0; i < m_size; i++)
            printf("%c", m_data[i]);
        std::cout << std::endl;
    }

    private:
    char* m_data;
    u_int32_t m_size;
};

class Entity
{
    public:
    Entity(const String& name):
    m_name{name}
    {

    }
    //here the passed object needs to be casted or else the copy ctor will be called.
    Entity(String&& other):
    m_name{static_cast<String&&>(other)}    
    {

    }

    void printName()
    {
        m_name.print();
    }
    private:
    String m_name;

};
int main(int argc, char const *argv[])
{
    // while creating object like this, the object is first created and then copied to Entity constructor. 
    Entity en("Abhishek");  //String object is created first temporarily and then copied.
    en.printName();
    return 0;
}

/*
╔══════════════════════════════════════════════════════════════════════════════╗
║              CONCEPT ANALYSIS — moveSemanticsBasics.cpp                    ║
╚══════════════════════════════════════════════════════════════════════════════╝

## Concepts

### 1. Custom Move Constructor
`String(String&& other)` — steals `m_data` pointer and `m_size` from `other`,
then nullifies `other` to prevent double delete.

### 2. Avoiding Unnecessary Copies with Rvalue Overloads
`Entity(String&& other) : m_name{static_cast<String&&>(other)}` — forwards the
rvalue to invoke String's move constructor instead of copy.

Without the `static_cast<String&&>`, `other` (being a named variable = lvalue)
would invoke the copy constructor. `std::move` is the idiomatic way to do this.

**Key Takeaway:** To propagate rvalue-ness through constructors, you must
explicitly cast named rvalue references back to rvalue (`std::move` or
`static_cast<T&&>`).

#### Alternatives / Idiomatic C++
- Use `std::move(other)` instead of `static_cast<String&&>(other)`.
- Use `std::string` instead of manual char* management.
- Perfect forwarding with templates:
  ```cpp
  template<typename T>
  Entity(T&& name) : m_name{std::forward<T>(name)} {}
  ```

---

## 🔁 Quick Revision
- Move ctor steals resources (pointer swap), nullifies source.
- Named `T&&` parameters are lvalues — use `std::move` to forward.
- `std::string` handles all of this internally — prefer it over raw char*.

### ⚠️ Gotchas
- `delete m_data` in destructor when `m_data` might be nullptr is safe (no-op).
- Forgetting to nullify source's pointer → double free on destruction.
*/
