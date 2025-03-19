#include <iostream>
class base
{
    private:
    int m_data1{};
    int m_data2{};

    public:
    base(int val):
        m_data1(val),
        m_data2(m_data1) {}

        void getval()
        {
            std::cout << m_data1 << " " << m_data2;
        }
};

int main(int argc, char const *argv[])
{
    base bb(10);
    bb.getval();
    return 0;
}
