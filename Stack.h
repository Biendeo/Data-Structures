#pragma once

/**
	\file Stack.h
	\brief Some basic stack functionality.
	\author Thomas Moffet (Biendeo)
	\date 28/10/2015 - 28/10/2015

	LONG DESCRIPTION LONG DESCRIPTION
	Ideally this should work on all compilers for all systems.

	Priority: Medium
*/

#ifdef __cplusplus

#include <cstdlib>
#include <stdexcept>

namespace Biendeo {

	class IntStack {
		protected:
		int *stack;
		int size;
		int maxSize;
		
		public:
		IntStack(int givenSize);
		IntStack(int *arr, int arrSize);
		~IntStack();
		void add(int num);
		int pop();
		int getSize();
		int getMaxSize();
	};
	
	IntStack::IntStack(int givenSize) {
		stack = new int[givenSize];
		maxSize = givenSize;
		size = 0;
	}
	
	/// Makes a stack of the size of the array.
	IntStack::IntStack(int *arr, int arrSize) {
		stack = new int[arrSize];
		maxSize = arrSize;
		for (int i = 0; i < arrSize; i++) {
			add(arr[i]);
		}
	}
	
	IntStack::~IntStack() {
		delete[] stack;
	}
	
	void IntStack::add(int num) {
		try {
			if (size >= maxSize) {
				throw size;
			}
		}
		catch (int size) {
			std::cerr << "IntStack.add() tried to exceed its size of " << size << "." << std::endl;
			return;
		}
		
		stack[size] = num;
		size++;
	}
	
	int IntStack::pop() {
		try {
			if (size <= 0) {
				throw size;
			}
		}
		catch (int size) {
			std::cerr << "IntStack.pop() tried to go below size " << size << "." << std::endl;
			return 0;
		}
		
		// Does the program need to clean it from memory, or is just ignoring it fine?
		size--;
		return stack[size];
	}
	
	int IntStack::getSize() {
		return size;
	}
	
	int IntStack::getMaxSize() {
		return maxSize;
	}
}

#endif

// Anything from here on out can be used in both C and C++.