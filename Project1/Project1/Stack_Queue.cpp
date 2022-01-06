#include <iostream>
#include <stack>
#include <queue>

class Test {
private:
	std::string name;
public:
	Test(std::string name) :name(name){}
	~Test() {
		std::cout << "Destructors\n" << std::flush;
	}
	void print() const {
		std::cout << name << std::endl;
	}
};
int mainS_Q()
{
	//LIFO
	std::stack<Test> testStack;//LIFO
	testStack.push(Test("N"));
	testStack.push(Test("A"));
	testStack.push(Test("Z"));

	//Test &test1 = testStack.top();
	//testStack.pop();
	//test1.print();

	//testStack.pop();
	//Test test2 = testStack.top();
	//test2.print();

	while (testStack.size()) {
		Test &test1 = testStack.top();
		test1.print();
		testStack.pop();
	}

	std::cout << "\n";

	//FIFO
	std::queue<Test> testQueue;//LIFO
	testQueue.push(Test("N"));
	testQueue.push(Test("A"));
	testQueue.push(Test("Z"));

	while (testQueue.size()) {
		Test& test1 = testQueue.front();
		test1.print();
		testQueue.pop();
	}

	std::cin.get();
	return 0;
}