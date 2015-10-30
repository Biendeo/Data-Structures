#pragma once

/**
	\file RBTree.h
	\brief Some basic red-black tree functionality.
	\author Thomas Moffet (Biendeo)
	\date 28/10/15 - 28/10/15

	LONG DESCRIPTION LONG DESCRIPTION
	Ideally this should work on all compilers for all systems.

	Priority: Medium.
*/

#ifdef __cplusplus

#include <cstdlib>
#include <stdexcept>

#include "Tree.h"

namespace Biendeo {
	
	class IntRBTree : public IntTree {
		class Node : public IntTree::Node {
			int color;

			public:
			//Node(int num, IntRBTree *) : IntTree::Node(num) {
			~Node() {}

		};
	};
}

#endif

// Anything from here on out can be used in both C and C++.