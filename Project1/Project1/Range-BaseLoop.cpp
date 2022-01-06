#include <iostream>
#include <vector>

int mainRBL()
{
	auto texts = { "H", "K", "L" };
	for (auto text : texts) {
		std::cout << text << std::endl;
	}

	std::vector<int> number;
	number.push_back(9);
	number.push_back(9);
	number.push_back(9);
	number.push_back(9);
	number.push_back(9);
	for (auto text : number) {
		std::cout << text << std::endl;
	}

	std::string string = "Hello";
	for (auto text : string) {
		std::cout << text << std::endl;
	}


	std::cin.get();
	return 0;
}