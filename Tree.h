#pragma once

/**
	\file Tree.h
	\brief Some basic tree functionality.
	\author Thomas Moffet (Biendeo)
	\date 28/10/15 - 30/10/15

	LONG DESCRIPTION LONG DESCRIPTION
	Ideally this should work on all compilers for all systems.

	Priority: Medium.
*/

#ifdef __cplusplus

#include <cstdlib>
#include <stdexcept>

namespace Biendeo {

	class IntTree {
		protected:
		class Node {
			public:
			int val;
			Node *parent;
			Node *left;
			Node *right;
			Node(int num);
			~Node();
		};
		
		void addTo(int num, Node *currentNode);

		Node *head;
		int size;

		public:
		IntTree();
		~IntTree();
		void add(int num);
		int getSize();
	};

	IntTree::Node::Node(int num) {
		val = num;
		parent = NULL;
		left = NULL;
		right = NULL;
	}
	
	IntTree::Node::~Node() {
		if (left != NULL) {
			delete left;
		}
		if (right != NULL) {
			delete right;
		}
		if (parent != NULL) {
			if (parent->left == this) {
				parent->left = NULL;
			} else if (parent->right == this) {
				parent->right = NULL;
			}
		}
		// TODO: Figure out how to get the tree's size in this.
	}

	IntTree::IntTree() {
		head = NULL;
		size = 0;
	}
	
	IntTree::~IntTree() {
		delete head;
	}
	
	void IntTree::add(int num) {
		addTo(num, head);
	}

	void IntTree::addTo(int num, Node *currentNode) {
		if (head == NULL) {
			Node *newNode = new Node(num);
			head = newNode;
			size++;
		} else {
			if (num > currentNode->val) {
				if (currentNode->right != NULL) {
					addTo(num, currentNode->right);
				} else {
					Node *newNode = new Node(num);
					newNode->parent = currentNode;
					currentNode->right = newNode;
					size++;
				}
			} else if (num < currentNode->val) {
				if (currentNode->left != NULL) {
					addTo(num, currentNode->left);
				} else {
					Node *newNode = new Node(num);
					newNode->parent = currentNode;
					currentNode->left = newNode;
					size++;
				}
			}
		}
	}

	int IntTree::getSize() {
		return size;
	}
}

#endif

// Anything from here on out can be used in both C and C++.