#include <iostream>

class Test {
private:
	int id;
	std::string name;

public:
	Test() : id(0), name("") {
		std::cout << "Default Ctors\n" << std::flush;
	}
	Test(int id, std::string name) : id(id), name(name) {
		std::cout << "Assignment Ctors\n" << std::flush;
	}
	~Test() {
		std::cout << "Dtors" << std::endl;
	}

	void print() {
		std::cout << id << ": " << name << std::endl;
	}
	//Assignment = operator overloading
	const Test& operator=(const Test& other) {
		std::cout << "overloading operator\n" << std::flush;
		this->id = other.id;
		this->name = other.name;
		
		return *this;
	}
	//Copy constructor explicit overloading
	Test(const Test& other) {
		std::cout << "Copy constructor\n" << std::flush;
		*this = other;
	}
	friend std::ostream &operator<<(std::ostream &out,const Test& other) {
		out << other.id << ": " << other.name;
		return out;
	}
};

int mainOverloading() {
	Test test1(10, "P");
	test1.print();
	Test test2(20, "o");
	test2 = test1;
	test2.print();

	Test test4 = test1;
	test4.print();
	std::cout << test4 << std::endl;
	std::cin.get();
	return 0;
}