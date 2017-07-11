#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

#define print(el) { std::cout << el << " "; }
#define br() { std::cout << std::endl; }

int main() { 

	//start
	std::vector<int> v = { 1,10, 2,3,6,8,10,10,10,4,7,3,6,2,7 };

	for (auto& el : v) {
		print(el);
	}
	br();

	//1
	std::replace_if(v.begin(), v.end(), [](const int& num) { return num % 10 == 0; }, 11);

	for (auto& el : v) {
		print(el);
	}
	br();

	//2
	std::sort(v.begin(), v.end(), [](int a, int b) { return a > b; });
	
	for (auto& el : v) {
		print(el);
	}
	br();

	//3
	const int w = 5;
	const int n = 1;

	std::vector<int> v2;
	std::back_insert_iterator<std::vector<int>> it(v2);
	std::copy_if(v.begin(), v.end(), it, [&w, &n](const int& el) { return w*n < el; });

	for (auto& el : v2) {
		print(el);
	}
	br();

	//4
	const int x = 5;

	std::vector<int> v3;
	std::back_insert_iterator<std::vector<int>> it2(v3);

	std::transform(v2.begin(), v2.end(), it2, [&x](int& el) { return el += x; });

	for (auto& el : v2) {
		print(el);
	}
	br();
	
	
	return 0; 
}
