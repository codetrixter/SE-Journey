/**
 * *Beware the illusion of container independant code.
 * *While implementing your own containers, make sure to not generalize the container i.e:
 * *list should not be a deque which should not be a map.
 *
 * !Make sure to treat containers as they are:
 * !1- Only sequential containers can support push_front/push_back.
 * !2- Only associative containers can support count/lower_bound.
 *
 */

#include <bits/stdc++.h>
using namespace std;

class Widget
{
private:
    int _data;

public:
    Widget(int x) : _data(x) {}
    bool operator==(const Widget &rhs) { return this->data() == rhs.data(); }
    int data() const { return _data; }
};

int main(int argc, char const *argv[])
{
    typedef vector<Widget> WidgetContainer;

    typedef WidgetContainer::iterator WCIterator;
    //sort(WidgetContainer.begin(), WidgetContainer.end());
    WidgetContainer vw{Widget(1), Widget(2), Widget(3)};

    Widget bestWidget(2);

    WCIterator i = find(vw.begin(), vw.end(), bestWidget);

    // WidgetContainer::difference_type distance = i - vw.cbegin();
    return 0;
}
