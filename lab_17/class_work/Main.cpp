#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <ctime>


template<typename T>
void print(T& ar) {
	for (auto& el : ar) {
		std::cout << el << " ";
	}
	std::cout << std::endl;
}
void task1() {
	using namespace std;
	srand(unsigned(time(0)));

	vector<int> v;
	for (size_t i = 0; i < 20; ++i) {
		v.push_back(rand() % 21);
	}

	int counter = count(v.begin(), v.end(), 10);
	cout << "counter\t: " << counter << endl;

	print(v);

	counter = count_if(v.begin(), v.end(), bind(less_equal<int>(), placeholders::_1, 10));
	cout << "counter less 10\t: " << counter << endl;

	auto it = find_if(v.begin(), v.end(), bind(greater<int>(), placeholders::_1, 10));
	if (it != v.end()) {
		cout << "greater:\t" << *it;
	}

	cout << endl;

	it = find_if(v.begin(), v.end(), bind(not_equal_to<int>(), placeholders::_1, 1));
	if (it != v.end()) {
		cout << "not_equal_to:\t" << *it;
	}

	cout << endl;
	it = adjacent_find(v.begin(), v.end());
	if (it != v.end()) {
		cout << "adjacent_find:\t" << *it << " ";
		++it;
		cout << *it;
	}

	cout << endl;
	bool allof = all_of(v.begin(), v.end(), bind(greater<int>(), placeholders::_1, 0));
	cout << "all elements are greater then 0:\t" << boolalpha << allof;

	cout << endl;
	bool noneof = none_of(v.begin(), v.end(), bind(less<int>(), placeholders::_1, 5));
	cout << "all elements that greater then 5:\t" << boolalpha << noneof;

	cout << endl;
	noneof = any_of(v.begin(), v.end(), bind(less<int>(), placeholders::_1, 0));
	cout << "negative element is:\t" << boolalpha << noneof;
}

void printt(const int val) {
	std::cout << val << " ";
}

class Sum {
	int sum{ 0 };
public:
	void operator()(int val) {
		sum += val;
	}
	int getSum() {
		return sum;
	}
};


int main() {
	using namespace std;
	srand(unsigned(time(0)));

	vector<int> v1 = { 1,2,3 };
	vector<int> v2 = { 1,2,3 };
	
	bool ex2 = equal(v1.begin(), v1.end(), v2.begin());
	cout << "ex2:\t" << boolalpha << ex2 << endl;

	v1.push_back(5);
	v1.push_back(4);
	v2.push_back(4);
	v2.push_back(5);

	bool ex3 = is_permutation(v1.begin(), v1.end(), v2.begin());
	cout << "ex3:\t" << boolalpha << ex3 << endl;

	auto it = mismatch(v1.begin(), v1.end(), v2.begin());
	cout << "ex4:\t" << *(it.first) << " " << *(it.second) << endl;

	vector<int>patern{ 1,2 };
	auto it1 = search(v1.begin(), v1.end(), patern.begin(), patern.end());
	cout << "ex5:\t" << *(it1) << endl;

	vector<int>pattern{ 1,1,1 };
	auto it2 = search(v1.begin(), v1.end(), pattern.begin(), pattern.end());
	if (it2 != v1.end()) {
		cout << "ex6:\t" << *(it2) << endl;
	}
	else {
		cout << "ex6:\tNot found" << endl;
	}
		
	for_each(v1.begin(), v1.end(), printt);
	cout << endl;

	Sum s1 = for_each(v1.begin(), v1.end(), Sum());
	cout << "s1:\t" << s1.getSum() << endl;

	cout << endl;
	return 0;
}