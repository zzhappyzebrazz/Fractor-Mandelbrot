#include <iostream>
#include <fstream>
#include <string>

int main1()
{
	std::ifstream input;
	std::string filename = "status.txt";
	input.open(filename);
	if (!input.is_open())
	{
		return 1;
	}	

	while (input)
	{
 		std::string line;
		std::getline(input, line,':');

		int population;
		input >> population; 
		//input.get();
		input >> std::ws;
		if (!input) { break; }
		std::cout << line << "--" << population << std::endl;
	}

	input.close();

	//std::cout << "" << std::endl;
	std::cin.get();
	return 0;
}