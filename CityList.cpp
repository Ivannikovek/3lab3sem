#include "CityList.h"

CityList::CityList() : tail(nullptr), head(nullptr), size(0) { };

CityList::~CityList() {
	CityNode* iterator = head;
	while (iterator != nullptr) {
		CityNode* removing = iterator;
		iterator = iterator->next;
		delete removing;
	}
}

void CityList::add(const std::string& str) {
	std::string city1 = "";
	std::string city2 = "";

	std::string cost1 = "";
	std::string cost2 = "";

	std::string cur = "";

	for (size_t i = 0; i < str.size(); i++) {
		if (str[i] == ';') {
			if (city1.size() == 0)
				city1 = cur;
			else if (city2.size() == 0)
				city2 = cur;
			else if (cost1.size() == 0)
				cost1 = cur;
			cur = "";
		}
		else
			cur = cur + str[i];
	}
	cost2 = cur;
	if ((city1.size() == 0) || (city2.size() == 0) ||
		(cost1.size() == 0) || (cost2.size() == 0))
	{
		std::cout << "INVALID LINE" << std::endl;
		return;
	}

	City* buff1 = add_city(city1);
	City* buff2 = add_city(city2);
	if (cost1 != "N/A")
		buff1->push(buff2, stoi(cost1));
	if (cost2 != "N/A")
		buff2->push(buff1, stoi(cost2));
}

City* CityList::search_city(const std::string& name) const {
	CityNode* iterator = head;
	while (iterator != nullptr) {
		if (iterator->city->get_name() == name)
			return iterator->city;
		iterator = iterator->next;
	}
	return nullptr;
}

City* CityList::add_city(const std::string& name) {
	City* temp = search_city(name);
	if (temp != nullptr)
		return temp;

	City* new_city = new City(name);

	if (head == nullptr) {
		head = new CityNode();
		tail = head;
		head->city = new_city;
	}
	else {
		CityNode* lst = new CityNode();
		lst->city = new_city;

		tail->next = lst;
		lst->previous = tail;
		tail = lst;
	}

	size++;
	return new_city;
}

std::string CityList::search(const std::string& from, const std::string& to) {
	if (search_city(from) == nullptr)
		return "Invalid city";
	if (search_city(to) == nullptr)
		return "Invalid city";

	way = "";
	setStart();

	std::string current = search(from, to, 0);
	std::string previous;

	while ((current != from) && (current != previous)) {
		way = current + " -> " + way;
		previous = current;
		setStart();
		current = search(from, current, 0);
	}

	way = from + " -> " + way + to;
	return way;
}

void CityList::print() const {
	CityNode* iterator = head;

	while (iterator != nullptr)
	{
		std::cout << iterator->city->get_name() << " " << iterator->cost << std::endl;
		iterator = iterator->next;
	}
}

int CityList::get_size() const {
	return size;
}

std::string CityList::search(const std::string& from, const std::string& to, int way_cost) {
	City* curent = search_city(from);
	std::string name = "";
	curent->set_visited(true);
	CityNode* iterator = head;
	while (iterator != nullptr) {
		int cost = way_cost + curent->returnCost(iterator->city->get_name());
		if (cost >= 0 && iterator->cost > cost) {
			iterator->cost = cost;
			if (iterator->city->get_name() == to && cost != 0)
				name = curent->get_name();
		}

		iterator = iterator->next;
	}
	sort();

	iterator = head;

	std::string check = "";

	while (iterator != nullptr) {
		if (iterator->city->get_visited() == false) {
			check = search(iterator->city->get_name(), to, iterator->cost);
			break;
		}
		iterator = iterator->next;
	}
	if (check.size() != 0) {
		return check;
	}
	return name;
}

void CityList::sort() {
	for (size_t i = 0; i < size; i++) {
		CityNode* left = head;
		CityNode* right = head->next;
		for (size_t j = 0; j < size - 1; j++) {
			if (left->cost > right->cost)
			{
				swap(left, right);
				left = right->next;
				right = left->next;
			}
			else {
				left = left->next;
				right = right->next;
			}
		}
	}
}

void CityList::swap(CityNode* l, CityNode* r) {
	CityNode* temp = r->next;
	r->next = l;
	l->next = temp;

	temp = l->previous;
	l->previous = r;
	r->previous = temp;

	if (r->previous)
		r->previous->next = r;
	else
		head = r;

	if (l->next)
		l->next->previous = l;
	else
		tail = l;
}

void CityList::setStart() {
	CityNode* iterator = head;
	while (iterator != nullptr) {
		iterator->cost = 10000;
		iterator->city->set_visited(false);
		iterator = iterator->next;
	}
}