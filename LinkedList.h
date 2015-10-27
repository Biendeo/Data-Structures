#pragma once

/**
	\class HugeInt
	\brief A set of functions that make big integers easy to use.
	\author Thomas Moffet (Biendeo)
	\date 10/09/2015 - 10/09/2015

	LONG DESCRIPTION LONG DESCRIPTION
	Ideally this should work on all compilers for all systems.

	Priority: Low.
*/

#ifdef __cplusplus

#include <iostream>
#include <cstdlib>
#include <stdexcept>

namespace Biendeo {

	class IntLinkedList {
		class Node {
			public:
			Node *next;
			Node *previous;
			int val;
			Node(int num);
		};
		
		Node *first;
		Node *last;
		int size;
		
		public:
		IntLinkedList();
		IntLinkedList(int *arr, int arrSize);
		~IntLinkedList();
		int *toArray();
		int &getElementByPosition(int pos);
		void append(int num);
		int pop();
	};
	
	IntLinkedList::Node::Node(int num) {
		next = NULL;
		previous = NULL;
		val = num;
	}
	
	IntLinkedList::IntLinkedList() {
		first = NULL;
		last = NULL;
		size = 0;
	}
	
	IntLinkedList::~IntLinkedList() {
		while (size > 0) {
			pop();
		}
	}
	
	IntLinkedList::IntLinkedList(int *arr, int arrSize) {
		for (int i = 0; i < arrSize; i++) {
			append(arr[i]);
		}
	}
	
	int *IntLinkedList::toArray() {
		int *arr = new int[size];
		int i = 0;
		for (Node *currentNode; currentNode != NULL; currentNode = currentNode->next) {
			arr[i] = currentNode->val;
			i++;
		}
		
		return arr;
	}
	
	int &IntLinkedList::getElementByPosition(int pos) {
		try {
			if (pos < 0 || pos >= size) {
				throw pos;
			}
		}
		catch (int pos) {
			std::cout << "IntLinkedList.getElementByPosition() tried to access position " << pos << " when max size was " << size << "." << std::endl;
		}
		
		// TODO: Make this more efficient by utilising previous pointers.
		Node *getNode = first;
		for (int i = 0; i != pos; i++) {
			if (i == 0) {
				continue;
			}
			getNode = getNode->next;
		}
		
		return getNode->val;
	}
	
	void IntLinkedList::append(int num) {
		Node *newNode = new Node(num);
		newNode->previous = last;
		if (last == NULL) {
			first = newNode;
		} else {
			last->next = newNode;
		}
		last = newNode;
		size++;
	}
	
	int IntLinkedList::pop() {
		int num = last->val;
		Node *lastNode = last;
		if (size > 1) {
			last->previous->next = NULL;
		}
		last = last->previous;
		delete lastNode;
		size--;
		return num;
	}
}

#endif