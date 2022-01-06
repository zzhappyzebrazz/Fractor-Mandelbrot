#include <iostream>
#include <vector>

class Test {
	int id;
	std::string name;
public:
	Test(int id, std::string name) :id(id), name(name){}
	~Test() {
		std::cout << "Destructor\n" << std::flush;
	}
	void print()const {
		std::cout << id << name << std::endl;
	}
};

int mainSortingVector() {
	std::vector<Test> test;
	test.push_back(Test(12, "Q")); //1 destructor
	test.push_back(Test(43, "T"));//2 destructors
	test.push_back(Test(67, "U"));//3 destructors
	test.push_back(Test(90, "I"));//4 destructors

	std::cin.get();
	return 0;
}