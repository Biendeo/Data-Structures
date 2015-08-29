#include <iostream>

#include "arrays.h"

int main(int argc, char *argv[]) {
	intArrayEx testA;
	intArrayEx testB;
	testA.append(1);
	testA.append(2);
	testA.append(3);
	testB.append(2);
	testB.append(5);
	intArrayEx testC;

	std::cout << "testA size = " << testA.size << std::endl;
	std::cout << "testA  = " << testA << std::endl;

	std::cout << "testB size = " << testB.size << std::endl;
	std::cout << "testB  = " << testB << std::endl;

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

	return 0;
}