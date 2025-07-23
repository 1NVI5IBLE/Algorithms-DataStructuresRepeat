#include "Ordered_Array.h"


template <typename T>
class MySet {
private:
	OrderedArray<T> data;

public:
	MySet() = default;

	MySet(int grow_size) : data(grow_size) {}


	int lenght() const {
		return data.length();
	}

	T getElement(int index) const {
		return data.getElement(index);
	}
};