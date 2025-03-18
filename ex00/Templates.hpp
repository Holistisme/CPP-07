#pragma once

/* ############################################################################################## */

#include <iostream>
#include <iomanip>

/* ############################################################################################## */

#include "ColorFormatLib/ColorFormat.hpp"

/* ############################################################################################## */

template <typename T>
void swap(T &firstValue, T& secondValue) {
	T tmp = firstValue;

	firstValue	= secondValue;
	secondValue = tmp;
}

template <typename T>
T min(const T &firstValue, const T &secondValue) { return firstValue < secondValue ? firstValue : secondValue; }

template <typename T>
T max(const T &firstValue, const T &secondValue) { return firstValue > secondValue ? firstValue : secondValue; }

/* ############################################################################################## */

template <typename T>
std::string templateToString(const T &value) {
	std::ostringstream stream; stream << value;
	return stream.str();
}

template <typename T>
void displayValues(const T &firstValue, const T &secondValue) {
	std::cout << "Value " << ColorFormat::formatString("1", "blue", "bold")	  << ": "
						  << ColorFormat::formatString(templateToString(firstValue),  "blue",	"italic") << "." << std::endl;
	std::cout << "Value " << ColorFormat::formatString("2", "yellow", "bold") << ": "
						  << ColorFormat::formatString(templateToString(secondValue), "yellow", "italic") << "." << std::endl;
}

template <typename T>
void checkFunctions(T &firstValue, T &secondValue) {
	displayValues(firstValue, secondValue);

	std::cout << ColorFormat::formatString("Swap!", "italic") << std::endl;
	swap(firstValue, secondValue);
	displayValues(firstValue, secondValue);

	std::ostringstream parameters;
	parameters << "(" << ColorFormat::formatString(templateToString(firstValue),  "blue",	"italic") << ", "
					  << ColorFormat::formatString(templateToString(secondValue), "yellow",	"italic") << ")";
	std::cout << "\nmin" << parameters.str() << " = " << ColorFormat::formatString(templateToString(::min(firstValue, secondValue)), "red")	<< std::endl;
	std::cout << "max" << parameters.str() << " = " << ColorFormat::formatString(templateToString(::max(firstValue, secondValue)), "green") << std::endl;
}