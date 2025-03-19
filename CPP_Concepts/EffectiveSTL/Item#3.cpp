/**
 * *Make copying cheap and correct for objects in containers.
 * 
 * *Containers are used to store objects, but the operations on these stored objects is done mostly by
 * *copying.
 * 
 * **NOTE:Use containers to store pointers to the objects rather than the objects itself. 
*/

class Widget {
private:
	int _data;
public:
	Widget(int x) : _data(x) {}
    
	// take good care of cp ctor and cp assiganment definition, because they may get called frequently 
    // in STL functions 	Widget(const Widget& rhs) :_data(rhs.data()) {} 
	Widget& operator=(const Widget& rhs) {
		this->_data = rhs.data();
		return *this;
	}
	bool operator==(const Widget& rhs) { return this->data() == rhs.data(); }
	int data() const { return _data; }
};