#pragma once

/**
	\file IntListEx.h
	\brief A set of functions for C/C++ which make arrays easy work.
	\author Thomas Moffet (Biendeo)
	\date 27/08/2015 - 10/09/2015

	LONG DESCRIPTION LONG DESCRIPTION
	Ideally this should work on all compilers for all systems.

	Priority: Very low. I don't really know how to do much of this without overloading C++ operators. Making C functions for this will be finicky, but I'll take a stab at it.
*/

#ifdef __cplusplus

#include <iostream>
#include <cstdlib>
#include <stdexcept>

namespace Biendeo {

	/// The list class.
	class IntListEx {
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

		IntListEx();
		//~IntListEx();
		void clear();
		int append(const int &n);
		int prepend(const int &n);
		int shift();
		int pop();
		int& operator[] (const int &n);
		void operator= (IntListEx &arr);
		friend IntListEx operator+ (IntListEx &list1, IntListEx &list2);
		friend std::ostream& operator<< (std::ostream &out, IntListEx &arr);

	};

	/// Grabs an item in the list given an index.
	IntListEx::Item& IntListEx::getItem(const int &n) {
		// TODO: NO POINTERS. :(
		if (size < n) {
			// TODO: Throw an error.
			std::cout << "size is " << size << ", n is " << n << std::endl;
		}
		Item *currentItem = first;
		for (int i = 0; i < n; i++) {
			currentItem = currentItem->next;
		}

		return *currentItem;
	}

	/// The default constructor for IntListEx.
	IntListEx::IntListEx() {
		size = 0;
		first = NULL;
	}

	/*
	// TODO: This seg faults during temporary usage. Right now it's eating memory.
	/// The deconstructor for IntListEx.
	IntListEx::~IntListEx() {
		clear();
	}
	*/

	/// Removes all items from the list (but it still exists).
	void IntListEx::clear() {
		while (size > 0) {
			shift();
		}
	}

	/// Adds a value to the end of the list.
	int IntListEx::append(const int &n) {
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

	/// Adds a value to the beginning of the list.
	int IntListEx::prepend(const int &n) {
		Item *nextItem = first;
		first = new Item(n);
		first->next = nextItem;
		size++;
		return n;
	}

	/// Deletes the last value of the list (and returns it).
	int IntListEx::pop() {
		Item *corn = &getItem(size - 1);
		int value = corn->value;
		if (size > 1) {
			getItem(size - 2).next = NULL;
		} else {
			first = NULL;
		}
		delete corn;
		size--;
		return value;
	}

	/// Deletes the first value of the list (and returns it).
	int IntListEx::shift() {
		Item *corn = &getItem(0);
		int value = corn->value;
		first = corn->next;
		delete corn;
		size--;
		return value;
	}

	/// Accesses a specific member.
	int& IntListEx::operator[] (const int &n) {
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
			std::cerr << "ERROR: IntListEx[" << n << "] is not a valid index (try 0.." << size - 1 << ")." << std::endl;
			exit(5); // TODO: Think of a good error code.
		}
		return first->value; // This never gets called. It just keeps the compiler happy.
	}

	/// Creates an identical array (with different addresses) of an existing
	/// one.
	void IntListEx::operator= (IntListEx &arr) {
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
	IntListEx operator+ (IntListEx &list1, IntListEx &list2) {
		IntListEx addedList;

		if (list1.size == 0) {
			addedList = list2;
		}

		addedList = list1;

		if (list2.size != 0) {
			IntListEx::Item *currentItem = list2.first;
			while (currentItem->next != NULL) {
				addedList.append(currentItem->value);
				currentItem = currentItem->next;
			}
			addedList.append(currentItem->value);
		}

		return addedList;
	}

	/// This outputs the list to ostream.
	std::ostream& operator<< (std::ostream &out, IntListEx &arr) {
		if (arr.size == 0) {
			out << "<empty>";
		} else {
			IntListEx::Item *currentItem = arr.first;
			while (currentItem->next != NULL) {
				out << currentItem->value << ", ";
				currentItem = currentItem->next;
			}
			out << currentItem->value;
		}

		return out;
	}

	/// The default constructor for an item.
	IntListEx::Item::Item() {
		value = 0;
		next = NULL;
	}

	/// The constructor for an item with a given value.
	IntListEx::Item::Item(const int &n) {
		value = n;
		next = NULL;
	}

}

#endif

// Anything from here on out can be used in both C and C++.