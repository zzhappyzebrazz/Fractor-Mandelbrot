#include <iostream>
#include <fstream>
#pragma pack(push,1)
struct Person {
	char name[50];
	int age;
	double height;

};
#pragma pack(pop)

int main_writeBinary()
{
	Person someone = {"LaiMinhHa", 23, 168};

	std::string fileName = "test.bin";
	std::ofstream outputFile;
	outputFile.open(fileName, std::ios::binary);

	if (outputFile.is_open()) {

		outputFile.write(reinterpret_cast<char *>(&someone), sizeof(Person));

		outputFile.close();
	}
	else
		std::cout << "Faled to open" + fileName << std::get_new_handler;
	
	Person echo = {};
	std::ifstream inputFile;
	inputFile.open(fileName, std::ios::binary);

	if (inputFile.is_open()) {

		inputFile.read(reinterpret_cast<char*>(&echo), sizeof(Person));

		inputFile.close();
	}
	else
		std::cout << "Faled to open" + fileName << std::get_new_handler;


	std::cout << echo.name << "," << echo.age << "," << echo.height << std::endl;
	std::cin.get();
	return 0;
}