/**
 * *Here we learn about the first principle of the SOLID, which is Single resposonsibility:
 * In the below exapmple the persistence can be separated out of Journal class and be made independent.
 * By making persistence independent following things can be done:
 * 1- It can be accessed by many other modules.
 * 2- Easier code to read.
 */
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

struct Journal
{
    string title;
    vector<string> entries;

    explicit Journal(const string &title)
        : title{title}
    {
    }

    void add(const string &entry);

    // persistence is a separate concern
    void save(const string &filename);
};

void Journal::add(const string &entry)
{
    static int count = 1;
    stringstream stream;
    stream << count++;
    entries.push_back(stream.str() + ": " + entry);
}

void Journal::save(const string &filename)
{
    ofstream ofs(filename);
    for (auto &s : entries)
        ofs << s << endl;
}

struct PersistenceManager
{
    static void save(const Journal &j, const string &filename)
    {
        ofstream ofs(filename);
        for (auto &s : j.entries)
            ofs << s << endl;
    }
};

int main()
{
    Journal journal{"Dear Diary"};
    journal.add("I ate a bug");
    journal.add("I cried today");

    // journal.save("diary.txt");

    // created an object of persistence manager and then used persistence.
    PersistenceManager pm;
    pm.save(journal, "diary.txt");
}