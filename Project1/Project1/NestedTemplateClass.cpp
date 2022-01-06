#include <iostream>
#include "ringBuffer.h"

//ringBuffer

int main() {
	ringBuffer<std::string> textstring(3);

	textstring.add("one");
	textstring.add("two");
	textstring.add("three");
	textstring.add("four");
	for (int i = 0; i < textstring.size(); i++)
		std::cout << textstring.get(i) << std::endl;

	std::cin.get();
	return 0;
}