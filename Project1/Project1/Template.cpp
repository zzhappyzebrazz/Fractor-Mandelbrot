#include <iostream>

template<class T>
class Test {
private:
	T obj;

public:
	Test(T obj) {
		std::cout << "Ctor\n" << std::flush;
		this->obj = obj;
	}
	const void print() const {
		std::cout << obj << std::endl;
	}
};

template<class K>
void print(K var) {
	std::cout << "Template " << var << std::endl;
}

void print(int n) {
	std::cout << "Non-Template " << n << std::endl;
}
template<class T>
void show(){
	std::cout << T() << std::endl;
}
int mainTemplate() {
	Test<std::string> test1("H");
	test1.print();
	Test<int> test2(9);
	test2.print();
	print("Hello");
	print(6);
	print<>(6);

	show<int>();

	std::cin.get();
	return 0;
}