/**
 * *When using containers of newed pointers, remember to delete the pointers 
 * *before the container is destroyed.
*/
#include <bits/stdc++.h>

using namespace std;

class Widget {
private:
	int _data;
public:
	Widget(int x) : _data(x) {}
	Widget(const Widget& rhs) :_data(rhs.data()) {}
	Widget& operator=(const Widget& rhs) {
		this->_data = rhs.data();
		return *this;
	}
	//bool operator==(const Widget& rhs) { return this->data() == rhs.data(); }
	int data() const { return _data; }
};
int main(int argc, char const *argv[])
{
    
    vector<shared_ptr<Widget>> vWidgets;

    for (int i = 0;i < 10; i++)
        vWidgets.push_back(make_shared<Widget>(i));
    
    return 0;
}
