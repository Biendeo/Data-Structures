#pragma once

/**
	\file Sorts.h
	\brief A set of functions for C/C++ which make sort integers in arrays.
	\author Thomas Moffet (Biendeo)
	\date 12/10/2015

	LONG DESCRIPTION LONG DESCRIPTION
	Ideally this should work on all compilers for all systems.

	Priority: High. I'm using this for uni now, so it'll be good as a reference.
*/

#ifdef __cplusplus

#include <cstdlib>
#include <stdexcept>

namespace Biendeo {
	
#else
#include <stdlib.h>
#endif

/// Swaps two numbers.
void intSwap(int *int1, int *int2) {
	int temp = *int1;
	*int1 = *int2;
	*int2 = temp;
}

/// Sorts an array by bubblesort.
void bubbleSort(int *arr, int numItems) {
	for (int upperBound = numItems; upperBound > 0; upperBound--) {
		for (int i = 0; i < upperBound - 1; i++) {
			if (arr[i] > arr[i + 1]) {
				intSwap(&(arr[i]), &(arr[i + 1]));
			}
		}
	}
}


#ifdef __cplusplus
}
#endif

// Anything from here on out can be used in both C and C++.