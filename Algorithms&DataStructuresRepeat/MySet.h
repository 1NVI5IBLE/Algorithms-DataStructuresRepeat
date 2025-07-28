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

	void add(const T& element) {
		if (data.search(element) == -1) {
			data.push(element);
		}
	}

	MySet<T> operator | (const MySet<T>& other) const {
		MySet<T> result;

		for (int i = 0; i < this->lenght(); i++) {
			result.add(this->getElement(i));
		}

		//other set will go here

	}

};