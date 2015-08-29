#ifndef _BIENDEO_HEADER_H_
#define _BIENDEO_HEADER_H_

/**
	\file arrays.h
	\brief A set of functions for C/C++ which make arrays easy work.
	\author Thomas Moffet (Biendeo)
	\date 27/08/2015 - 29/08/2015

	LONG DESCRIPTION LONG DESCRIPTION
	Ideally this should work on all compilers for all systems.

	Priority: Very low. I don't really know how to do much of this without overloading C++ operators. Making C functions for this will be finicky, but I'll take a stab at it.
*/

// Anything within this block is available only to C++.
#ifdef __cplusplus

#include <iostream>
#include <stdexcept>

class intArrayEx {
	private:

	protected:

	class Item {
		public:
		int value;
		Item *next;

		Item();
		Item(const int &n);
	};
	Item *first;

	public:

	int size;

	intArrayEx();
	int append(const int &n);
	int& operator[] (const int &n);
	void operator= (intArrayEx &arr);
	friend intArrayEx operator+ (intArrayEx &array1, intArrayEx &array2);
	friend std::ostream& operator<< (std::ostream &out, intArrayEx &arr);

};

/**
	\brief The default constructor for intArrayEx.

	UNFINISHED
*/
intArrayEx::intArrayEx() {
	size = 0;
	first = NULL;
}

/**
	\brief Adds a number to the end of the array.
*/
int intArrayEx::append(const int &n) {
	if (size == 0) {
		first = new Item(n);
	} else {
		Item *currentItem = first;
		while (currentItem->next != NULL) {
			currentItem = currentItem->next;
		}

		currentItem->next = new Item(n);
	}

	size++;
	return n;
}

/**
	\brief Accesses a specific member.

	UNIMPLEMENTED
*/
int& intArrayEx::operator[] (const int &n) {
	try {
		if (n >= size || n < 0) {
			throw n;
		} else {
			Item *currentItem = first;
			for (int i = 1; i <= n; i++) {
				currentItem = currentItem->next;
			}
			return currentItem->value;
		}
	}
	catch (int) {
		std::cerr << "ERROR: intArrayEx[" << n << "] is not a valid index (try 0.." << size - 1 << ")." << std::endl;
	}
}

/**
	\brief Creates an identical array (with different addresses) of an existing
	one.
*/
void intArrayEx::operator= (intArrayEx &arr) {
	// TODO: ADD A BIT TO CLEAR THE LIST FIRST
	if (arr.size > 0) {
		Item *currentItem = arr.first;
		while (currentItem->next != NULL) {
			append(currentItem->value);
			currentItem = currentItem->next;
		}
		append(currentItem->value);
	}
}

/**
	\brief Adds two arrays together.
*/
intArrayEx operator+ (intArrayEx &array1, intArrayEx &array2) {
	intArrayEx addedArray;

	if (array1.size == 0) {
		addedArray = array2;
	}
	
	addedArray = array1;

	if (array2.size != 0) {
		intArrayEx::Item *currentItem = array2.first;
		while (currentItem->next != NULL) {
			addedArray.append(currentItem->value);
			currentItem = currentItem->next;
		}
		addedArray.append(currentItem->value);
	}

	return addedArray;
}

/**
	\brief Pipes 
*/

std::ostream& operator<< (std::ostream &out, intArrayEx &arr) {
	if (arr.size == 0) {
		out << "<empty>";
	} else {
		intArrayEx::Item *currentItem = arr.first;
		while (currentItem->next != NULL) {
			out << currentItem->value << ", ";
			currentItem = currentItem->next;
		}
		out << currentItem->value;
	}

	return out;
}

/**
	\brief The default constructor for an item.
*/
intArrayEx::Item::Item() {
	value = 0;
	next = NULL;
}

/**
	\brief The constructor for an item with a given value.
*/
intArrayEx::Item::Item(const int &n) {
	value = n;
	next = NULL;
}

#endif

// Anything from here on out can be used in both C and C++.

#endif