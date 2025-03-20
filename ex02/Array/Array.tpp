#include "Array.hpp"

/* ############################################################################################## */

template <typename T>
Array<T>::Array(void) : _array(NULL), _size(0) {}

template <typename T>
Array<T>::Array(const unsigned int size) : _array(new T[size]()), _size(size) {}

template <typename T>
Array<T>::Array(const Array &source) : _array(new T[source._size]()), _size(source._size) {
	for (size_t index = 0 ; index < _size ; index++)
		_array[index] = source._array[index];
}

template <typename T>
Array<T> &Array<T>::operator=(const Array &source) {
	if (this != &source) {
		delete[] _array;
		_array = (new T[source._size]());
		_size  = (source._size);
		for (size_t index = 0 ; index < _size ; index++)
			_array[index] = source._array[index];
	}
	return *this;
}

template <typename T>
Array<T>::~Array(void) { delete[] _array; }

/* ############################################################################################## */

template <typename T>
T &Array<T>::operator[](const unsigned int index) {
	if (index >= _size)
		throw std::out_of_range("Index out of range");
	return _array[index];
}

template <typename T>
const T &Array<T>::operator[](const unsigned int index) const {
	if (index >= _size)
		throw std::out_of_range("Index out of range");
	return _array[index];
}

template <typename T>
unsigned int Array<T>::size(void) const { return _size; }

/* ############################################################################################## */

template <typename T>
void fillArray(Array<T> &arrayClass, const T *arraySource, const size_t arrayLength) {
	for (size_t index = 0 ; index < arrayLength ; index++)
		arrayClass[index] = arraySource[index];
}