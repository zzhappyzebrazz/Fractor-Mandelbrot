#include <iostream>
#include <map>

int mainMultiMap() {

	std::multimap<int, std::string> lookup;
	lookup.insert(std::make_pair(10, "A"));
	lookup.insert(std::make_pair(56000, "VB"));
	lookup.insert(std::make_pair(10, "Aj"));//duplicate key, store value with duplicate key

	for (std::multimap<int, std::string>::iterator it = lookup.begin(); it != lookup.end(); it++) {
		std::cout << it->first << ": " << it->second << std::endl;
	}

	//tao ra 1 cap iterator cua type ..., its.first = doi tuong dau tien trong range 10 cua key lookup, its.second = last in range 10 of lookup's key
	auto its = lookup.equal_range(10);
	for (std::multimap<int, std::string>::iterator it = its.first; it != its.second; it++) {
		std::cout << it->first << ": " << it->second << std::endl;
	}
	std::cin.get();
	return 0;
}