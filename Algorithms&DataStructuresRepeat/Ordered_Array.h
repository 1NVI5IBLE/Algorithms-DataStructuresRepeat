#include <iostream>

template <typename T>
class OrderedArray {
private:
	T* elements;
	int size;
	int capacity;
	int growSize;

	void resize() {
		int newCapacity = capacity + growSize;
		T* newElements = new T[newCapacity];
		for (int i = 0; i < size; i++) {
			newElements[i] = elements[i]
		}
		delete[] elements;
		elements = newElements;
		capacity = newCapacity;
	}

public:

	OrderedArray() : size(0), capacity(10), growSize(10) {
		elements = new T[capacity];
	}

	OrderedArray(int grow_size) : size(0), capacity(grow_size), growSize(grow_size) {
		elements = new T[capacity]
	}

	~OrderedArray() {
		delete[] elements;
	}
	
	void push(const T& newElement) {
		if (size == capacity) {
			resize();
		}

		int i = size - 1;
		while (i >= 0 && elements[i] > newElement) {
			elements[i + 1] = elements[i];
			--i;
		}
		elements[i + 1] = newElement;
		++size;
	}


};

