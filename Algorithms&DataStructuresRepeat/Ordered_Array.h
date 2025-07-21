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

	int lenght() const {
		return size;
	}

	T getElement(int index) const {
		if (index >= 0 && index < size) {
			return elements[index];
		}
		return T();
	}

	bool remove(int index) {
		if (index < 0 || index >= size) {
			return false;
		}
		for (int i = index; i < size - 1; ++i) {
			elements[i] = elements[i + 1];
		}
		--size;
		return true;
	}

	int search(const T& target) const {
		int left = 0;
		int right = size - 1;

		while (left <= right) {
			int middle = (left + right) / 2;

			if (elements[middle] < target) {
				left = middle + 1;
			}
			else {
				right = mid - 1;
			}
		}
		return -1;
	}

};

