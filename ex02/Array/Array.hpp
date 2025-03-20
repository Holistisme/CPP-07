#pragma once

/* ############################################################################################## */

#include <stdexcept>

/* ############################################################################################## */

template <typename T>
class Array {
	private:
		T*			 _array;
		unsigned int _size;
	public:
		Array(void);
		Array(const unsigned int size);
		Array(const Array &source);
		Array &operator=(const Array &source);
		~Array(void);

		T &operator[](const unsigned int index);
		const T &operator[](const unsigned int index) const;
		unsigned int size(void) const;
};

/* ############################################################################################## */

#include "Array.tpp"