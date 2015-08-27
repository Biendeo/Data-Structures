#ifndef _BIENDEO_HEADER_H_
#define _BIENDEO_HEADER_H_

/**
	\file arrays.h
	\brief A set of functions for C/C++ which make arrays easy work.
	\author Thomas Moffet (Biendeo)
	\date 27/08/2015 - 28/08/2015

	LONG DESCRIPTION LONG DESCRIPTION
	Ideally this should work on all compilers for all systems.

	Priority: Very low. I don't really know how to do much of this without overloading C++ operators. Making C functions for this will be finicky, but I'll take a stab at it.
*/

// Anything within this block is available only to C++.
#ifdef __cplusplus

class intArrayEx {
	public:
	int size;

	intArrayEx();
	int append(int n);

};

/**
	\brief The default constructor for intArrayEx.
*/
intArrayEx::intArrayEx() {
	size = 0;
}

/**
	\brief Adds a number to the end of the array.
*/
int intArrayEx::append(int n) {

}

#endif

// Anything from here on out can be used in both C and C++.

#endif