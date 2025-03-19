/**
 * *Be alert for c++'s most vexing parse.
 * 
*/

#include <bits/stdc++.h>

using namespace std;

class Widget {
private:
	int _data;
public:
	Widget() { std::cout << "default ctor\n"; }
	Widget(int x) : _data(x) {}
	Widget(const Widget& rhs) :_data(rhs.data()) {}
	Widget& operator=(const Widget& rhs) {
		this->_data = rhs.data();
		return *this;
	}
	bool operator==(const Widget& rhs) { return this->data() == rhs.data(); }
	int data() const { return _data; }
};

int main(int argc, char const *argv[])
{
    // This will be regarded as a function declaration , which returns Widget and takes no arguments 
    // instead of default ctor. We should use brace init to avoid such errors.
    Widget (w());	//Widget w{}; 
	
    return 0;
}

	