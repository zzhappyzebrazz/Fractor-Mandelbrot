#include <iostream>
#include <map>

class Person {
private:
	std::string name;
	int age;

public:
	Person() : name(""), age(){}
	Person(const Person& other) {
		std::cout << "Copy constructor" << std::endl;
		name = other.name;
		age = other.age;
	}
	Person(std::string name, int age) :
		name(name), age(age) {
	}

	void print() const {
		std::cout << name << ": " << age << std::flush;
	}

	bool operator < (const Person& other) const {
		if (name == other.name) {
			return age < other.age;
		}
		return name < other.name;
	}
};
int mainMap() {
	std::map<std::string, int> ages;

	ages["Mike"] = 40;
	ages["Jonh"] = 20;
	ages["joe"] = 30;
	ages["Mike"] = 70;

	if (ages.find("Nike") != ages.end()) {
		//std::cout << "Found" << std::endl;
	}
	ages.insert(std::make_pair("Peter", 100));//sorted pair value in order of its key
	for (std::map<std::string, int>::iterator it = ages.begin(); it != ages.end(); it++) {
		//std::cout << it->first << ": " << it->second << std::endl;
	}
	
	std::map<int, Person> people;
	people[0] = Person("A", 10);
	people[56] = Person("B", 13);
	people[33] = Person("C", 34);

	people.insert(std::make_pair(55, Person("f", 90)));//run copy constructor 2 times

	for (std::map<int, Person>::iterator it = people.begin(); it != people.end(); it++) {
		//it->second.print();
	}

	std::map<Person, int> human;
	human[Person("A", 89)] = 90;
	human[Person("X", 23)] = 78;
	human[Person("Q", 12)] = 36;

	for (std::map<Person, int>::iterator it = human.begin(); it != human.end(); it++) {
		std::cout << it->second << ": " << std::flush;
		it->first.print();
	}
	//std::cout << ages["joe"] << std::endl;
	std::cin.get();
	return 0;
}