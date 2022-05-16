#ifndef _CITY_LIST_H_

#define _CITY_LIST_H_

#include <string>
#include <iostream>

#include "City.h"

class CityList {
private:
	struct CityNode {
		CityNode() : previous(nullptr), city(nullptr), next(nullptr), cost(10000) { };

		int cost;

		City* city;
		CityNode* next;
		CityNode* previous;
	};
public:
	CityList();
	CityList(const CityList&) = delete;
	CityList& operator=(const CityList&) = delete;
	~CityList();

	void add(const std::string& str);
	std::string search(const std::string& from, const std::string& to);
	void print() const;
	int get_size() const;

private:
	std::string way;
	int size;
	CityNode* tail;
	CityNode* head;

private:
	void setStart();
	std::string search(const std::string& from, const std::string& to, int way);
	void sort();
	void swap(CityNode* l, CityNode* r);
	City* add_city(const std::string& name);
	City* search_city(const std::string& name) const;
};

#endif //!_CITIES_H_