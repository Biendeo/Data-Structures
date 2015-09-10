/**
	\file testStructures.cpp
	\brief A test file that demonstrates the capabilities of all the headers.
	\author Thomas Moffet (Biendeo)
	\date 27/08/2015 - 3/09/2015

	LONG DESCRIPTION LONG DESCRIPTION
	Ideally this should work on all compilers for all systems.
*/

#include <iostream>

#include "lists.h"

int main(int argc, char *argv[]) {
	intListEx testA;
	intListEx testB;
	testA.append(1);
	testA.append(2);
	testA.append(3);
	testB.append(2);
	testB.append(5);
	intListEx testC;

	std::cout << "testA size = " << testA.size << std::endl;
	std::cout << "testA  = " << testA << std::endl;

	std::cout << "testB size = " << testB.size << std::endl;
	std::cout << "testB  = " << testB << std::endl;

	// TODO: Fix the + operator.
	std::cout << "test(A+B) size = " << (testA + testB).size << std::endl;
	std::cout << "test(A+B)  = " << testA + testB << std::endl;

	std::cout << "testC size = " << testC.size << std::endl;
	std::cout << "testC  = " << testC << std::endl;

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

	return 0;
}