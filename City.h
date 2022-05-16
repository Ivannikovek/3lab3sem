#ifndef _CITY_H_

#define _CITY_H_

#include <string>

class City {
private:
	struct Node {
		Node() : next(nullptr), previous(nullptr), city(nullptr), cost(-1) { };
		City* city;
		int cost;

		Node* next;
		Node* previous;
	};
public:
	City(const std::string& name);
	City(const City&) = delete;
	City& operator=(const City&) = delete;
	~City();

	int returnCost(const std::string& to) const;
	void push(City* city, int cost);
	void set_visited(bool is_visited);
	bool get_visited() const;
	std::string get_name() const;
private:
	std::string name;
	bool is_visited;
	int size;
	Node* head;
	Node* tail;
};

#endif //!_CITY_H_