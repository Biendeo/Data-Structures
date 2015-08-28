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

	std::cout << "testA size = " << testA.size << std::endl;
	std::cout << "testA  = " << testA << std::endl;
	std::cout << "testB size = " << testB.size << std::endl;
	std::cout << "testB  = " << testB << std::endl;
	std::cout << "test(A+B) size = " << (testA + testB).size << std::endl;
	std::cout << "test(A+B)  = " << testA + testB << std::endl;

	return 0;
}