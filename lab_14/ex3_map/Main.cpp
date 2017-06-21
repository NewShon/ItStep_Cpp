#include <iostream>
#include <string>
#include <map>
#include <utility>

int main() {

	std::map<int, int> myMap
	{ {1,1}, {2,4}, {3,9}, {4,16}, {5,25}, {6,36}, {7,49}, {8,64}, {9,81} };

	for (auto& pair : myMap) {
		std::cout << pair.first << ": " << pair.second << std::endl;
	}

	myMap[7] = 14;

	myMap[10] = 30;

	myMap.erase(5);

	for (auto& pair : myMap) {
		pair.second += pair.first;
	}

	for (auto it = myMap.begin(); it != myMap.end();)
	{
		if (it->second == 21 || it->second == 42) {
			myMap.erase(it++);
		}
		else ++it;
	}

	if (myMap.find(7) == myMap.end()) {
		myMap[7] = 5;
	}
	
	size_t counter = 1;
	for (auto& pair : myMap) {
		if (pair.first % 2 != 0) {
			counter *= pair.second;
		}
	}

	std::cout << std::endl;

	std::cout << "Counter: " << counter << std::endl;

	std::cout << std::endl;
	for (auto& pair : myMap) {
		std::cout << pair.first << ": " << pair.second << std::endl;
	}

	return 0;
}