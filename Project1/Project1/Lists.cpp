#include <iostream>
#include <list>	


int mainList()
{
	std::list<int> numbers;
	numbers.push_back(10);
	numbers.push_back(20);
	numbers.push_back(30);

	std::list<int>::iterator it = numbers.begin();
	it++;
	std::cout << "Before insert" << *it << std::endl;

	it = numbers.insert(it, 100);
	std::cout << "After insert" << *it << std::endl;

	for (std::list<int>::iterator it = numbers.begin(); it != numbers.end(); it++) {
		std::cout << *it << std::endl;
	}



	std::cin.get();
	return 0;
}