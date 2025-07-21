#include <iostream>

template <typename T>
class OrderedArray {
private:
	T* elements;
	int size;
	int capacity;
	int growSize;
};

