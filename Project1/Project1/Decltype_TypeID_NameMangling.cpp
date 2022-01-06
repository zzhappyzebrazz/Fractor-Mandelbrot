#include <iostream>
#include <typeinfo>
struct test{};
template<class T>
auto thu(T value){
	return value;
}
int mainDecltype() {
	std::string value;
	auto var = "string";
	std::cout << typeid(var).name() << std::endl;
	decltype(value) name = "test";
	std::cout << name << std::endl;
	std::cout << thu("Hello there") << std::endl;
	std::cin.get();
	return 0;
}