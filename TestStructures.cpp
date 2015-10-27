/**
	\file TestStructures.cpp
	\brief A test file that demonstrates the capabilities of all the headers.
	\author Thomas Moffet (Biendeo)
	\date 27/08/2015 - 3/09/2015

	LONG DESCRIPTION LONG DESCRIPTION
	Ideally this should work on all compilers for all systems.
*/

#include <iostream>
#include <cstdlib>
#include <ctime>

#include "Sorts.h"
#include "LinkedList.h"

// Experimental stuff
#include "IntListEx.h"
#include "HugeInt.h"

void testSorts();
void testIntListEx();
void testHugeInt();
void testLinkedList();

int main(int argc, char *argv[]) {
	testIntListEx();
	testHugeInt();
	testSorts();
	testLinkedList();

	return EXIT_SUCCESS;
}

void testSorts() {
	using namespace Biendeo;

	std::cout << "--== Testing Sorts ==--" << std::endl;

	const int ARRAY_SIZE = 20;
	srand(time(NULL));

	int *arrA = new int[ARRAY_SIZE];
	std::cout << "Original array:" << std::endl;
	for (int i = 0; i < ARRAY_SIZE; i++) {
		arrA[i] = rand() % 100;
		std::cout << arrA[i] << std::endl;
	}
	std::cout << std::endl;
	std::cout << "Sorted array:" << std::endl;
	bubbleSort(arrA, ARRAY_SIZE);
	for (int i = 0; i < ARRAY_SIZE; i++) {
		std::cout << arrA[i] << std::endl;
	}

	delete[] arrA;

	std::cout << std::endl;
}

void testLinkedList() {
	using namespace Biendeo;

	std::cout << "--== Testing Linked Lists ==--" << std::endl;

	IntLinkedList listA = IntLinkedList();

	listA.append(1);
	listA.append(5);
	listA.append(8);
	listA.append(3);
	listA.append(2);

	int x = listA.getElementByPosition(3);
	std::cout << x << std::endl;
	x = listA.getElementByPosition(4);
	std::cout << x << std::endl;
	x = listA.getElementByPosition(5);
	std::cout << x << std::endl;
}

void testIntListEx() {
	using namespace Biendeo;

	std::cout << "--== Testing IntListEx ==--" << std::endl;
	IntListEx testA = IntListEx();
	IntListEx testB = IntListEx();
	testA.append(1);
	testA.append(2);
	testA.append(3);
	testB.append(2);
	testB.append(5);
	IntListEx testC = IntListEx();

	std::cout << "testA size = " << testA.size << std::endl;
	std::cout << "testA = " << testA << std::endl;

	std::cout << "testB size = " << testB.size << std::endl;
	std::cout << "testB = " << testB << std::endl;

	// TODO: Fix the + operator.
	std::cout << "test(A+B) size = " << (testA + testB).size << std::endl;
	std::cout << "test(A+B) = " << testA + testB << std::endl;

	std::cout << "testC size = " << testC.size << std::endl;
	std::cout << "testC = " << testC << std::endl;

	std::cout << "testA[0] = " << testA[0] << ", testA[1] = " << testA[1] << ", testA[2] = " << testA[2] << std::endl;

	// testA[-1] = 900;    // THIS WILL ERROR
	testA[0] = 592345;
	testA[1] = 123456789;
	testA[2] = 95;
	// testA[3] = 7458;    // THIS WILL ERROR

	std::cout << "testA = " << testA << std::endl;

	testA.pop();

	std::cout << "Popped testA = " << testA << std::endl;

	testA.clear();

	std::cout << "Cleared testA = " << testA << std::endl;

	testA = testB;

	std::cout << "testA = testB = " << testA << std::endl;

	testA = testC;

	std::cout << "testA = testC = " << testA << std::endl;

	std::cout << std::endl;
}

void testHugeInt() {
	using namespace Biendeo;

	std::cout << "--== Testing HugeInt ==--" << std::endl;

	HugeInt a = HugeInt();
	HugeInt b = HugeInt(0);
	HugeInt c = HugeInt(123456789);
	HugeInt d = HugeInt(5012353);

	std::cout << "a = " << a << std::endl;
	std::cout << "b = " << b << std::endl;
	std::cout << "c = " << c << std::endl;
	std::cout << "d = " << d << std::endl;

	c.setDisplayType(HugeInt::DisplayType::CommaInt);

	std::cout << "c + d = " << c + d << std::endl;

	std::cout << std::endl;
}