#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <string>


bool dA(const std::string& s1) {
	return s1[0] == 'a';
}
struct delA {
	bool operator()(const std::string& s1) const {
		return s1[0] == 'h';
	}
};

class DelSymb {
	char symb;
public:
	DelSymb(char s) : symb(s) {};
	bool operator()(const std::string& s1) const {
		return s1[0] == symb;
	}
};
class Pred { 
	int value; 
public: 
	Pred(const int v) : value(v) { } 
	bool operator()(const int elem) { return elem < value; } 
};
bool ex3(int el) {
	return el % 2 != 0;
}
class Pred2 {
	int value;
public:
	Pred2(const int v) : value(v) { }
	bool operator()(const int elem) { 
		return ((elem % 2 == 0) && (elem > value));
	}
};


void task1() {
	std::vector<int> v = { 5, 2 , 6 ,5 ,5, -1, -1 };
	for (int i = -10; i < 3; ++i) {
		v.push_back(i);
	}

	for (auto& el : v) {
		std::cout << el << " ";
	}
	std::cout << std::endl;
	std::cout << std::endl;


	size_t count = std::count(v.begin(), v.end(), 0);
	std::cout << "Zero: " << count << std::endl << std::endl;


	std::replace(v.begin(), v.end(), -1, 1);
	for (auto& el : v) {
		std::cout << el << " ";
	}
	std::cout << std::endl;
	std::cout << std::endl;


	auto it = std::find(v.begin(), v.end(), 5);
	*(++it) = 6;


	std::replace(v.begin(), v.end(), -1, 1);

	for (auto& el : v) {
		std::cout << el << " ";
	}
	std::cout << std::endl;
	std::cout << std::endl;


	it = std::remove(v.begin(), v.end(), -5);
	v.erase(it, v.end());

	for (auto& el : v) {
		std::cout << el << " ";
	}
	std::cout << std::endl;
	std::cout << std::endl;
}
void task2() {
	std::list<std::string> l = { "abba","hello,","can","you","hear","me?", "asc", "abacavba" };

	for (auto& el : l) {
		std::cout << el << " ";
	}

	l.remove_if(DelSymb('a'));
	std::cout << std::endl;

	for (auto& el : l) {
		std::cout << el << " ";
	}


	std::cout << std::endl;
}




int main() {
	
	std::vector<int> v = { 5, 2 , 6 ,5 ,5, -1, -1 };
	for (int i = -10; i < 3; ++i) {
		v.push_back(i);
	}

	std::replace(v.begin(), v.end(), -1, 1);

	auto it = std::find(v.begin(), v.end(), 5);
	*(++it) = 6;

	std::replace(v.begin(), v.end(), -1, 1);

	it = std::remove(v.begin(), v.end(), -5);
	v.erase(it, v.end());

	for (auto& el : v) {
		std::cout << el << " ";
	}
	std::cout << std::endl;


	size_t c = std::count_if(v.begin(), v.end(), Pred(0));
	std::cout << c << std::endl;

	std::replace_if(v.begin(), v.end(), Pred(0), 0);

	for (auto& el : v) {
		std::cout << el << " ";
	}
	std::cout << std::endl;

	it = std::find_if(v.begin(), v.end(), ex3);
	std::cout << *it << std::endl;


	it = std::remove_if(v.begin(), v.end(), Pred2(-1));
	v.erase(it, v.end());

	for (auto& el : v) {
		std::cout << el << " ";
	}
	std::cout << std::endl;
	
	return 0;
}