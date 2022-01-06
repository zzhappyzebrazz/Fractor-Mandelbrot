#include <iostream>
#include<typeinfo>
#include <string>

template <class T, class S>
auto test(T value1, S value2) -> decltype(value1 + value2) {
	return value1 + value2;
}

auto get() {
	return 0.1;
}

auto test2() -> decltype(get()) {
	return get();
}

int mainauto() {

	auto value = 9.0;
	auto string = "hello";

	std::cout << typeid(string).name() << std::endl;
	std::cout << test(6,5.2) << std::endl;
	std::cout << test2() << std::endl;//print out the address of the function test2
	std::cin.get();
	return 0;
}