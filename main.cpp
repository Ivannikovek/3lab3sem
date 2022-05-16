#include <iostream>
#include <fstream>
#include <string>

#include "CityList.h"

int main() {
	setlocale(LC_ALL, "Russian");
	std::string read_str;
	std::ifstream in;
	in.open("input_2.txt");
	if (!in.is_open()) {
		std::cout << "File not open!!!" << std::endl;
		return 0;
	}

	CityList test1;

	while (std::getline(in, read_str)){
		std::cout << read_str << std::endl;
		test1.add(read_str);
	}

	std::cout << test1.search("Москва", "Санкт-Петербург") << std::endl;
	std::cout << test1.search("Москва", "Хабаровск") << std::endl;
	std::cout << test1.search("Москва", "Владивосток") << std::endl;

	test1.print();
	std::cout << std::endl;

	in.close();
	in.open("input_1.txt");
	if (!in.is_open()){
		std::cout << "File not open!!!" << std::endl;
		return 0;
	}

	CityList test2;

	while (getline(in, read_str)) {
		std::cout << read_str << std::endl;
		test2.add(read_str);
	}

	std::cout << test2.search("S", "O") << std::endl;
	std::cout << test2.search("S", "P") << std::endl;
	std::cout << test2.search("S", "Q") << std::endl;
	std::cout << test2.search("S", "R") << std::endl;
	std::cout << test2.search("S", "T") << std::endl;

	test2.print();

	return 0;
}