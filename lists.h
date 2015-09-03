/**
	\file arrays.h
	\brief A set of functions for C/C++ which make arrays easy work.
	\author Thomas Moffet (Biendeo)
	\date 27/08/2015 - 3/09/2015

	LONG DESCRIPTION LONG DESCRIPTION
	Ideally this should work on all compilers for all systems.

	Priority: Very low. I don't really know how to do much of this without overloading C++ operators. Making C functions for this will be finicky, but I'll take a stab at it.
*/

#ifdef __cplusplus

#include <iostream>
#include <stdexcept>

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

	private:
	Item& getItem(const int &n);

	public:

	/// This stores the size of the array.
	int size;

	intListEx();
	void clear();
	int append(const int &n);
	int pop();
	int& operator[] (const int &n);
	void operator= (intListEx &arr);
	friend intListEx operator+ (intListEx &list1, intListEx &list2);
	friend std::ostream& operator<< (std::ostream &out, intListEx &arr);

};

/// Grabs an item in the list given an index.
intListEx::Item& intListEx::getItem(const int &n) {
	// TODO: NO POINTERS. :(
	Item *currentItem = first;
	for (int i = 0; i < n; i++) {
		currentItem = currentItem->next;
	}

	return *currentItem;
}

/// The default constructor for intListEx.
intListEx::intListEx() {
	size = 0;
	first = NULL;
}

/// Removes all items from the list (but it still exists).
void intListEx::clear() {
	while (size > 0) {
		pop();
	}
}

/// Adds a value to the end of the list.
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

/// Deletes the last value of the list (and returns it).
int intListEx::pop() {
	Item *corn = &getItem(size - 1);
	int value = corn->value;
	if (size > 1) {
		getItem(size - 2).next = NULL;
	}
	delete corn;
	size--;
	return value;
}

/// Accesses a specific member.
int& intListEx::operator[] (const int &n) {
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
		std::cerr << "ERROR: intListEx[" << n << "] is not a valid index (try 0.." << size - 1 << ")." << std::endl;
		exit(5); // TODO: Think of a good error code.
	}
	return first->value; // This never gets called. It just keeps the compiler happy.
}

/// Creates an identical array (with different addresses) of an existing
/// one.
void intListEx::operator= (intListEx &arr) {
	clear();
	if (arr.size > 0) {
		Item *currentItem = arr.first;
		while (currentItem->next != NULL) {
			append(currentItem->value);
			currentItem = currentItem->next;
		}
		append(currentItem->value);
	}
}

/// Adds two arrays together.
intListEx operator+ (intListEx &list1, intListEx &list2) {
	intListEx addedList;

	if (list1.size == 0) {
		addedList = list2;
	}
	
	addedList = list1;

	if (list2.size != 0) {
		intListEx::Item *currentItem = list2.first;
		while (currentItem->next != NULL) {
			addedList.append(currentItem->value);
			currentItem = currentItem->next;
		}
		addedList.append(currentItem->value);
	}

	return addedList;
}

/// This outputs the list to ostream.
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

/// The default constructor for an item.
intListEx::Item::Item() {
	value = 0;
	next = NULL;
}

/// The constructor for an item with a given value.
intListEx::Item::Item(const int &n) {
	value = n;
	next = NULL;
}

#endif

// Anything from here on out can be used in both C and C++.