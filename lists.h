#ifndef _BIENDEO_LISTS_H_
#define _BIENDEO_LISTS_H_

/**
	\file arrays.h
	\brief A set of functions for C/C++ which make arrays easy work.
	\author Thomas Moffet (Biendeo)
	\date 27/08/2015 - 29/08/2015

	LONG DESCRIPTION LONG DESCRIPTION
	Ideally this should work on all compilers for all systems.

	Priority: Very low. I don't really know how to do much of this without overloading C++ operators. Making C functions for this will be finicky, but I'll take a stab at it.
*/

#ifdef __cplusplus

#include <iostream>
#include <stdexcept>

/// \class intListEx
class intListEx {
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

	/// This stores the size of the array.
	int size;

	intListEx();
	int append(const int &n);
	int& operator[] (const int &n);
	void operator= (intListEx &arr);
	friend intListEx operator+ (intListEx &array1, intListEx &array2);
	friend std::ostream& operator<< (std::ostream &out, intListEx &arr);

};

/// The default constructor for intListEx.
intListEx::intListEx() {
	size = 0;
	first = NULL;
}

/**
	\fn int intListEx::apend(const int &n)
	Adds a number to the end of the array.
*/
int intListEx::append(const int &n) {
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
	Accesses a specific member.
*/
int& intListEx::operator[] (const int &n) {
	try {
		if (n >= size || n < 0) {
			throw n;
			return first->value; // This never gets called. It just keeps the compiler happy.
		} else {
			Item *currentItem = first;
			for (int i = 1; i <= n; i++) {
				currentItem = currentItem->next;
			}
			return currentItem->value;
		}
	}
	catch (int) {
		std::cerr << "ERROR: intListEx[" << n << "] is not a valid index (try 0.." << size - 1 << ")." << std::endl;
	}
	
}

/**
	Creates an identical array (with different addresses) of an existing
	one.
*/
void intListEx::operator= (intListEx &arr) {
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
	Adds two arrays together.
*/
intListEx operator+ (intListEx &array1, intListEx &array2) {
	intListEx addedArray;

	if (array1.size == 0) {
		addedArray = array2;
	}
	
	addedArray = array1;

	if (array2.size != 0) {
		intListEx::Item *currentItem = array2.first;
		while (currentItem->next != NULL) {
			addedArray.append(currentItem->value);
			currentItem = currentItem->next;
		}
		addedArray.append(currentItem->value);
	}

	return addedArray;
}

/**
	Pipes
*/
std::ostream& operator<< (std::ostream &out, intListEx &arr) {
	if (arr.size == 0) {
		out << "<empty>";
	} else {
		intListEx::Item *currentItem = arr.first;
		while (currentItem->next != NULL) {
			out << currentItem->value << ", ";
			currentItem = currentItem->next;
		}
		out << currentItem->value;
	}

	return out;
}

/**
	The default constructor for an item.
*/
intListEx::Item::Item() {
	value = 0;
	next = NULL;
}

/**
	The constructor for an item with a given value.
*/
intListEx::Item::Item(const int &n) {
	value = n;
	next = NULL;
}

#endif

// Anything from here on out can be used in both C and C++.

#endif