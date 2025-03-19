#pragma once

/* ############################################################################################## */

#include <iostream>
#include <sstream>

/* ############################################################################################## */

#include "ColorFormatLib/ColorFormat.hpp"

/* ############################################################################################## */

template <typename T>
void iter(T *array, const size_t length, void (*func)(T &)) {
	for (size_t index = 0 ; index < length ; index++)
		func(array[index]);
}

/* ############################################################################################## */

template <typename T>
std::string arrayToString(T *array, const size_t length) {
	std::ostringstream stream;

	for (size_t index = 0 ; index < length ; index++) {
		stream << array[index];
		if (index + 1 < length)
			stream << ", ";
	}
	return stream.str() + ".";
}