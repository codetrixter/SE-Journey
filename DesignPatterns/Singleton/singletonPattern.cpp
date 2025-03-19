/**
 * *Here we discuss about the singleton pattern and what are its pros and cons:
 * ! It is used for components where only single instance is needed:
 * 1. Database repository.
 * 2. Object Factory.
 * ! constructor call is expensive hence needed to be made only once.
 * ! Want to prevent anyone from creating extra copies.
 * ! Do lazy initialization and thread safety.
 *
 */

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <fstream>

using namespace std;

class SingletonDatabase
{
    SingletonDatabase()
    {
        std::cout << "Initializing database" << std::endl;

        std::ifstream ifs("capitals.txt");

        std::string s, s2;
        //fetches value line by line from the txt file.
        while (getline(ifs, s))
        {
            getline(ifs, s2);
            int pop = stoi(s2);
            capitals[s] = pop;
        }
    }
    map<string, int> capitals;

public:
    SingletonDatabase(SingletonDatabase const &) = delete;
    void operator=(SingletonDatabase const &) = delete;

    static SingletonDatabase &getInstance()
    {
        static SingletonDatabase sd;
        return sd;
    }

    int get_population(const std::string& name)
  {
    return capitals[name];
  }
};

int main(int argc, char const *argv[])
{
    string city = "New York";

    cout << "city has pop" 
    << SingletonDatabase::getInstance().get_population(city) <<endl;
    return 0;
}
