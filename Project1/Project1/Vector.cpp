#include <iostream>
#include <vector>

int mainVector()
{
	std::vector<std::string> strings;
	strings.push_back("one");
	strings.push_back("two");
	strings.push_back("three");

	for (std::vector<std::string>::iterator it = strings.begin(); it != strings.end(); it++) {
		std::cout << *it << std::endl;
	}

	std::cin.get();
	return 0;
}