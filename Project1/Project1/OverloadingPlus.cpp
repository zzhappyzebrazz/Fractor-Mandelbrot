#include "Complex.h"

int mainOverloading1() {
	programming::Complex c1(6.3, 8.7);
	programming::Complex c2(c1);//copy constructor
	programming::Complex c3(10, 60);
	//c2 = c2 + c1;//oveloading assignment, overloading +
	std::cout << c2 + c1 << std::endl;
	std::cout << c2 - c3 - c1 << std::endl;

	if (c1 != c2) {
		std::cout << "Yes\n" << std::flush;
	}
	else
		std::cout << "No\n" << std::flush;
	std::cout << *c1 + *programming::Complex(6, 7)<< std::endl;
	std::cin.get();
	return 0;
}