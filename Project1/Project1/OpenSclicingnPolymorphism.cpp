#include <iostream>

class Parent {
public:
	virtual ~Parent() {
		std::cout << "parent Dtor\n";
	}
	virtual void print() {
		std::cout << "parent\n" << std::flush;
	}
	Parent(const Parent& other) {
		std::cout << "Copy Ctor\n";
	}
	Parent(){}
};

class Child : public Parent {
public:
	~Child() {
		std::cout << "Child Dtor\n";
	}
	void print() {
		std::cout << "children\n" << std::flush;
	}
};

int mainOSP() {

	Child c1;
	Parent& p1 = c1;
	p1.print();
	Parent p2 = Child();

	p2.print();
	std::cin.get();
	return 0;
}