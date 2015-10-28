#pragma once

/**
	\file Queue.h
	\brief Some basic queue functionality.
	\author Thomas Moffet (Biendeo)
	\date 28/10/2015 - 28/10/2015

	LONG DESCRIPTION LONG DESCRIPTION
	Ideally this should work on all compilers for all systems.

	Priority: Medium.
*/

#ifdef __cplusplus

#include <cstdlib>
#include <stdexcept>

#include "Stack.h"

namespace Biendeo {

	class IntQueue : public IntStack {
		public:
		IntQueue(int givenSize) : IntStack(givenSize) {}
		IntQueue(int *arr, int arrSize) : IntStack(arr, arrSize) {}
		~IntQueue() {}
		void add(int num);
		int pop();
	};
	
	void IntQueue::add(int num) {
		try {
			if (size >= maxSize) {
				throw size;
			}
		}
		catch (int size) {
			std::cerr << "IntQueue.add() tried to exceed its size of " << size << "." << std::endl;
			return;
		}
		
		for (int i = size - 1; i >= 0; i--) {
			stack[i + 1] = stack[i]; 
		}
		
		stack[0] = num;
		size++;
	}
	
	int IntQueue::pop() {
		try {
			if (size <= 0) {
				throw size;
			}
		}
		catch (int size) {
			std::cerr << "IntQueue.pop() tried to go below size " << size << "." << std::endl;
			return 0;
		}
		
		// Does the program need to clean it from memory, or is just ignoring it fine?
		size--;
		return stack[size];
	}
}

#endif

// Anything from here on out can be used in both C and C++.