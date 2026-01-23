/**
 * @file move-ctor&assign.cpp
 * @author Abhishek
 * @brief Here we discuss about the move constructor and move assignment operator:
 * 1- When do the move constructor and move assignment  is called?
 * A1- These are called when these are defined, and argument for construction or assignment is an r-value.
 * 
 * 2- The key purpose of move semantics??
 * A2- In case the arguments to construction or assignment are r-values then we already know that the argument value will be destryed after 
 * construction or assignemnt since it is temporary, hence instead of copying the value(which is expensive operation), we move/transfer the resource to the 
 * object we are constructing or assigning.
 * 
 * 3- Move functions should always leave both objects in a well defined state.
 * A3- In the below example we make a.m_ptr point to null which might look extraneous since a will be destryed anyways. But we do this because 
 * When “a” goes out of scope, a’s destructor will be called, and a.m_ptr will be deleted. If at that point, a.m_ptr is still pointing to the same 
 * object as m_ptr, then m_ptr will be left as a dangling pointer. When the object containing m_ptr eventually gets used (or destroyed), we’ll get 
 * undefined behavior.
 * @version 0.1
 * @date 2022-08-31
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>

template<typename T>
class Auto_ptr3
{
	T* m_ptr;
public:
	Auto_ptr3(T* ptr = nullptr)
		:m_ptr(ptr)
	{
	}

	~Auto_ptr3()
	{
		delete m_ptr;
	}

	// Copy constructor
	// Do deep copy of a.m_ptr to m_ptr
	Auto_ptr3(const Auto_ptr3& a)
	{
		std::cout << "copyctr called\n";
		m_ptr = new T;
		*m_ptr = *a.m_ptr;
	}

	// Move constructor
	// Transfer ownership of a.m_ptr to m_ptr
	Auto_ptr3(Auto_ptr3&& a) noexcept
		:m_ptr(a.m_ptr)
	{
		std::cout << "move ctr called\n";
		a.m_ptr = nullptr;	// we'll talk more about this line below
	}

	// Copy assignment
	// Do deep copy of a.m_ptr to m_ptr
	Auto_ptr3& operator=(const Auto_ptr3& a)
	{
		std::cout << "copy assignment called\n";
		// Self-assignment detection
		if (&a == this)
			return *this;

		// Release any resource we're holding
		delete m_ptr;

		// Copy the resource
		m_ptr = new T;
		*m_ptr = *a.m_ptr;

		return *this;
	}

	// Move assignment
	// Transfer ownership of a.m_ptr to m_ptr
	Auto_ptr3& operator= (Auto_ptr3&& a) noexcept
	{
		std::cout<< "move assignment called\n";
		// Self-assignment detection
		if (&a == this)
			return *this;

		// Release any resource we're holding
		delete m_ptr;

		//move the resource from a.m_ptr to m_ptr
		m_ptr = a.m_ptr;
		a.m_ptr = nullptr;
		
		return *this;
	}

	T& operator*() const { return *m_ptr; }
	T* operator->() const { return m_ptr; }
	bool isNull() const { return m_ptr == nullptr; }
};

class Resource
{
public:
	Resource() { std::cout << "Resource acquired\n"; }
	~Resource() { std::cout << "Resource destroyed\n"; }
};

Auto_ptr3<Resource> generateResource()
{
	Auto_ptr3<Resource> res{new Resource};
	
	//  @brief The C++ specification has a special rule that says automatic objects returned from a function by value can be moved even if they 
	//  are l-values. This makes sense, since res was going to be destroyed at the end of the function anyway! We might as well steal its resources instead 
	//  of making an expensive and unnecessary copy.
	//  Although the compiler can move l-value return values, in some cases it may be able to do even better by simply eliding the copy altogether 
	//  (which avoids the need to make a copy or do a move at all). In such a case, neither the copy constructor nor move constructor would be called.
	 
	
	return res; // this return value will invoke the copy/move constructor
}

// @brief Here the resource acquisation is done 3 times for copy version :
// 1- At line:69.
// 2- when genarateResource returns the res, object is copy constructed into temp, which acquires a resource.
// 3- returned res is assigned to mainres using deep copy assignment operator, hence resource is acquired here as well.

// For move semantics following happens:
// 1- Inside generateResource(), local variable res is created and initialized with a dynamically allocated Resource, which causes the first 
// “Resource acquired”.
// 2- Res is returned back to main() by value. Res is move constructed into a temporary object, transferring the dynamically created object stored 
// in res to the temporary object.
// 3- Res goes out of scope. Because res no longer manages a pointer (it was moved to the temporary), nothing interesting happens here.
// 4- The temporary object is move assigned to mainres. This transfers the dynamically created object stored in the temporary to mainres.
// 5- The assignment expression ends, and the temporary object goes out of expression scope and is destroyed. However, because the temporary no 
// longer manages a pointer (it was moved to mainres), nothing interesting happens here either.
// 6- At the end of main(), mainres goes out of scope, and our final “Resource destroyed” is displayed.
// @return int 

int main()
{
	Auto_ptr3<Resource> mainres;
	//In the presence of move contructor and assignment operator, copy versions are ignored.
	mainres = generateResource(); // this assignment will invoke the copy assignment

	return 0;
}


//*************************************Disabling copying in our smart pointer class***
// This class is closer to std::unique_ptr class.
/* template<typename T>
class Auto_ptr5
{
	T* m_ptr;
public:
	Auto_ptr5(T* ptr = nullptr)
		:m_ptr(ptr)
	{
	}

	~Auto_ptr5()
	{
		delete m_ptr;
	}

	// Copy constructor -- no copying allowed!
	Auto_ptr5(const Auto_ptr5& a) = delete;

	// Move constructor
	// Transfer ownership of a.m_ptr to m_ptr
	Auto_ptr5(Auto_ptr5&& a) noexcept
		: m_ptr(a.m_ptr)
	{
		a.m_ptr = nullptr;
	}

	// Copy assignment -- no copying allowed!
	Auto_ptr5& operator=(const Auto_ptr5& a) = delete;

	// Move assignment
	// Transfer ownership of a.m_ptr to m_ptr
	Auto_ptr5& operator=(Auto_ptr5&& a) noexcept
	{
		// Self-assignment detection
		if (&a == this)
			return *this;

		// Release any resource we're holding
		delete m_ptr;

		// Transfer ownership of a.m_ptr to m_ptr
		m_ptr = a.m_ptr;
		a.m_ptr = nullptr;

		return *this;
	}

	T& operator*() const { return *m_ptr; }
	T* operator->() const { return m_ptr; }
	bool isNull() const { return m_ptr == nullptr; }
};
class Resource
{
public:
	Resource() { std::cout << "Resource acquired\n"; }
	~Resource() { std::cout << "Resource destroyed\n"; }
};
int main()
{
	Auto_ptr5<Resource> mainres;
	//In the presence of move contructor and assignment operator, copy versions are ignored.
	//mainres = generateResource(); // this assignment will invoke the copy assignment
	return 0;
} */
//*************************************Disabling copying in our smart pointer class***
//*************************************Array class with copy and move operatiosn to see performance***
/**
 * @brief copy version of the array class takes: 0.0227284sec
 * Move version takes : 0.0154859sec ~30% faster than copy version
 * 
 */
/* #include <chrono>

template <typename T>
class DynamicArray
{
private:
	T* m_array;
	int m_length;

public:
	DynamicArray(int length)
		: m_array(new T[length]), m_length(length)
	{
	}

	~DynamicArray()
	{
		delete[] m_array;
	}

	// Copy constructor
	DynamicArray(const DynamicArray &arr) = delete;
	// DynamicArray(const DynamicArray &arr)
	// 	: m_length(arr.m_length)
	// {
	// 	m_array = new T[m_length];
	// 	for (int i = 0; i < m_length; ++i)
	// 		m_array[i] = arr.m_array[i];
	// } 

	// Copy assignment
	DynamicArray& operator=(const DynamicArray &arr) = delete;
	// DynamicArray& operator=(const DynamicArray &arr)
	// {
	// 	if (&arr == this)
	// 		return *this;

	// 	delete[] m_array;

	// 	m_length = arr.m_length;
	// 	m_array = new T[m_length];

	// 	for (int i = 0; i < m_length; ++i)
	// 		m_array[i] = arr.m_array[i];

	// 	return *this;
	// }

	//Move constructor
	DynamicArray(DynamicArray&& arr) noexcept
	{
		m_length = arr.m_length;
		m_array = arr.m_array;
		arr.m_length = 0;
		arr.m_array = nullptr;
	}

	// Move assignement
	DynamicArray& operator= (DynamicArray&& arr) noexcept
	{
		if(&arr == this)
			return *this;
		
		delete[] m_array;

		m_length = arr.m_length;
		m_array = arr.m_array;
		arr.m_array = nullptr;
		arr.m_length = 0;

		return *this;
	}
	int getLength() const { return m_length; }
	T& operator[](int index) { return m_array[index]; }
	const T& operator[](int index) const { return m_array[index]; }

};

class Timer
{
private:
	// Type aliases to make accessing nested type easier
	using clock_t = std::chrono::high_resolution_clock;
	using second_t = std::chrono::duration<double, std::ratio<1> >;

	std::chrono::time_point<clock_t> m_beg { clock_t::now() };

public:
	void reset()
	{
		m_beg = clock_t::now();
	}

	double elapsed() const
	{
		return std::chrono::duration_cast<second_t>(clock_t::now() - m_beg).count();
	}
};

// Return a copy of arr with all of the values doubled
DynamicArray<int> cloneArrayAndDouble(const DynamicArray<int> &arr)
{
	DynamicArray<int> dbl(arr.getLength());
	for (int i = 0; i < arr.getLength(); ++i)
		dbl[i] = arr[i] * 2;

	return dbl;
}

int main()
{
	Timer t;

	DynamicArray<int> arr(1000000);

	for (int i = 0; i < arr.getLength(); i++)
		arr[i] = i;

	arr = cloneArrayAndDouble(arr);

	std::cout << t.elapsed();
} */
//*************************************Array class with copy and move operatiosn to see performance***
