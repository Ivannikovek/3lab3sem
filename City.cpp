#include "City.h"

City::City(const std::string& name) :is_visited(false), size(0), name(name), head(nullptr), tail(nullptr) { };

City::~City() {
	Node* iterator = head;
	while (iterator != nullptr) {
		Node* removing = iterator;
		iterator = iterator->next;
		delete removing;
	}
}

int City::returnCost(const std::string & to) const {
	if (to == name)
		return 0;

	Node* temp = head;
	while (temp != nullptr) {
		if (temp->city->name == to)
			return temp->cost;
		temp = temp->next;
	}

	return 10000;
}

void City::push(City* city, int _cost) {
	if (head == nullptr) {
		head = new Node();
		tail = head;
		head->city = city;
		head->cost = _cost;
		size++;
		return;
	}

	Node* temp = new Node();
	temp->city = city;
	temp->cost = _cost;

	tail->next = temp;
	temp->previous = tail;
	tail = temp;
	size++;
}

void City::set_visited(bool is_visited) {
	City::is_visited = is_visited;
}

bool City::get_visited() const {
	return is_visited;
}

std::string City::get_name() const {
	return name;
}