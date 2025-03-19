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
        for(uint32_t i = 0; i < m_size; i++)
            printf("%c", m_data[i]);
        std::cout << std::endl;
    }

    private:
    char* m_data;
    uint32_t m_size;
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
