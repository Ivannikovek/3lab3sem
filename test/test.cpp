#include "pch.h"
#include "CityList.h"
#include <iostream>
#include <fstream>

TEST(TestCities, FuncAdd) {
	setlocale(LC_ALL, "Russian");
	std::string read_str;
	std::ifstream in;
	in.open("input.txt");
	if (!in.is_open()) {
		std::cerr << "File not open!!!" << std::endl;
		FAIL();
	}

	CityList test;

	while (getline(in, read_str))
		test.add(read_str);

	in.close();
	ASSERT_EQ(test.get_size(), 6);
}


TEST(TestCities, FuncSearch) {
	setlocale(LC_ALL, "Russian");
	std::string read_str;
	std::ifstream in;
	in.open("input.txt");
	if (!in.is_open()) {
		std::cerr << "File not open!!!" << std::endl;
		FAIL();
	}

	CityList test;

	while (getline(in, read_str))
		test->add(read_str);


	ASSERT_STREQ("S -> P -> R -> T -> Q -> O",
		test->search("S", "O").c_str());
	ASSERT_STREQ("S -> P -> R -> T",
		test->search("S", "T").c_str());
}


TEST(TestCity, FuncPush) {
	setlocale(LC_ALL, "Russian");
	City* city1 = new City("1");

	City* city2, * city3, * city4, * city5;

	city1->push(city2 = new City("2"), 2);
	city1->push(city3 = new City("3"), 3);
	city1->push(city4 = new City("4"), 4);
	city1->push(city5 = new City("5"), 5);

	ASSERT_EQ(city1->returnCost("2"), 2);
	ASSERT_EQ(city1->returnCost("3"), 3);
	ASSERT_EQ(city1->returnCost("4"), 4);
	ASSERT_EQ(city1->returnCost("5"), 5);

	delete city1;
	delete city2;
	delete city3;
	delete city4;
	delete city5;
}

TEST(TestCity, FuncReturnCost) {
	setlocale(LC_ALL, "Russian");
	City* city1 = new City("1");

	City* city2, * city3, * city4, * city5;

	city1->push(city2 = new City("2"), 2);
	city1->push(city3 = new City("3"), 3);
	city1->push(city4 = new City("4"), 4);
	city1->push(city5 = new City("5"), 5);

	ASSERT_EQ(city1->returnCost("2"), 2);
	ASSERT_EQ(city1->returnCost("3"), 3);
	ASSERT_EQ(city1->returnCost("4"), 4);
	ASSERT_EQ(city1->returnCost("5"), 5);

	delete city1;
	delete city2;
	delete city3;
	delete city4;
	delete city5;
}