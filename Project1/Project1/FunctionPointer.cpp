#include <iostream>
#include <algorithm>
#include <vector>

void test() {
	std::cout << "Hello \n";
}
bool match(std::string text) {
	return text.size() == 3;
}
int countMatch(std::vector<std::string> &test, bool(*match)(std::string text)) {
	int i = 0;
	//for (std::vector<std::string>::iterator it = test.begin(); it != test.end(); it++)
	for(int it = 0; it < test.size(); it++)
	{
		if (match(test[it]))
			i++;
	}
	return i;
}
int mainFunctionPointer() {

	void (*pF)();
	//pF = &test;
	pF = test;

	//(*pF)();
	pF();
	std::vector<std::string> tests;
	tests.push_back("one");
	tests.push_back("two");
	tests.push_back("Three");
	tests.push_back("fou");
	tests.push_back("fiv");

	std::cout << match(tests[0]) << std::endl;
	std::cout << countMatch(tests, match);
	std::cin.get();
	return 0;
}