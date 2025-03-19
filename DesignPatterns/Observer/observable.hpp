#pragma once

#include <string>
#include <vector>
#include <algorithm>

//Forward declaration of the class
template <typename> class Observer;

template <typename T>
class Observable
{
    std::vector<Observer<T>*> observerList;
    public:

    void notify(T& source, const std::string& field_name)
    {
        for(auto obs : observerList)
        {
            obs->field_changed(source, field_name);
        }
    }

    void subscribe(Observer<T>& observer)
    {
        observerList.push_back(&observer);
    }

    void unsubscribe(Observer<T>& observer)
    {
        //erase-remove IDOME
        observerList.erase(
            std::remove(observerList.begin(), observerList.end(), &observer),
            observerList.end()
        );
    }
};
