#pragma once

/**
	\file Set.h
	\brief Some basic set functionality.
	\author Thomas Moffet (Biendeo)
	\date 28/10/15 - 28/10/15

	LONG DESCRIPTION LONG DESCRIPTION
	Ideally this should work on all compilers for all systems.

	Priority: Medium.
*/

#ifdef __cplusplus

#include <cstdlib>
#include <stdexcept>

#include "LinkedList.h"

namespace Biendeo {

	class IntSet : public IntLinkedList {
		public:
		IntSet() : IntLinkedList() {}
		IntSet(int *arr, int arrSize);
		~IntSet() {}
		void add(int num);
		bool isElement(int num);
		int remove(int num);
	};
	
	IntSet::IntSet(int *arr, int arrSize) {
		first = NULL;
		last = NULL;
		size = 0;
		for (int i = 0; i < arrSize; i++) {
			add(arr[i]);
		}
	}
	
	void IntSet::add(int num) {
		if (!isElement(num)) {
			Node *newNode = new Node(num);
			if (last == NULL) {
				first = newNode;
			} else {
				last->next = newNode;
				newNode->previous = last;
			}
			last = newNode;
			size++;
		} else {
			std::cerr << num << " is already in the set." << std::endl;
		}
	}
	
	bool IntSet::isElement(int num) {
		Node *currentNode = first;
		while (currentNode != NULL) {
			if (currentNode->val == num) {
				return true;
			}
			currentNode = currentNode->next;
		}
		
		return false;
	}
	
	int IntSet::remove(int num) {
		if (isElement(num)) {
			Node *currentNode = first;
			while (currentNode->val != num) {
				currentNode = currentNode->next;
			}
			if (currentNode == first) {
				if (currentNode == last) {
					first = NULL;
					last = NULL;
				} else {
					currentNode->next->previous = currentNode->previous;
					first = currentNode->next;
				}
			} else {
				if (currentNode == last) {
					last = currentNode->previous;
				} else {
					currentNode->next->previous = currentNode->previous;
				}
				currentNode->previous->next = currentNode->next;				
			}
			delete currentNode;
			size--;
			return num;
		} else {
			std::cerr << num << " is not in the set." << std::endl;
			return 0;
		}
	}
}

#endif

// Anything from here on out can be used in both C and C++.