#include "Complex.h"


int mainComplexnumber() {
	programming::Complex complex(6.3, 9.7);
	programming::Complex complex1(complex);//Copy constructor
	programming::Complex complex2;
	complex2 = complex1;//Assignment overloading
	std::cout << complex1 << complex2 << complex << std::endl;

	std::cin.get();
	return 0;
}