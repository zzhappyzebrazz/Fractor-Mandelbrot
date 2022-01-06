#include <iostream>

class Animal {
public:
	virtual void speak() = 0;
	virtual void run() = 0;
};

class Dog :public Animal {
public:
	virtual void speak() {
		std::cout << "Woof\n";
	}
};
class Muc :public Dog {
public:
	virtual void run() {
		std::cout << "Running\n";
	}
};
class Cat :public Animal {
public:
	virtual void speak() {
		std::cout << "Moew\n";
	}
};
void test(Animal& a) {
	a.speak();
}
class Dui :public Muc {
public:
	virtual void speak() {
		std::cout << "Gau \n";
	}
	//virtual void run() {
	//	std::cout << "Chay \n";
	//}
};
int mainAbstractClass() {
	Muc muc;
	//muc.speak();
	//Cat cat;
	//cat.speak();
	Animal* animals[5];
	animals[0] = &muc;
	//animals[0]->run();
	//test(muc);
	Dui dui;
	animals[1] = &dui;
	dui.run();
	test(dui);
	std::cin.get();
	return 0;
}