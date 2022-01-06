//#include <memory> to initiate smart pointer
#include <iostream>//already included <memory>

class Test {
public:
	Test() {
		std::cout << "Test ctor\n";
	}
	void greet() {
		std::cout << "Hello\n";
	}
	virtual ~Test() {
		std::cout << "Test dtor\n";
	}
};

class Temp {
private:
	std::unique_ptr<Test[]> pTest;//auto clean up all the object created when going out of scope
public:
	Temp() :pTest(new Test[2]) {

	}
};

int mainSmartPointer() {
	//{
	//	std::unique_ptr<Test> pTest(new Test[2]);
	//	pTest[0].greet();
	//}
	//std::cout << *pTest << std::endl;
	//{
	//	Temp temp;
	//}
	std::shared_ptr<Test> pTest2(nullptr);
	{
	std::shared_ptr<Test> pTest1 = std::make_shared<Test>();
	pTest2 = pTest1;//2nd pointer pointed to the object
	auto pTest3 = pTest1;
	}

	std::cout << "Finish \n";
	return 0;
}//the object declared with shared pointer will be destroy if the number of pointer pointed to it go to zero

