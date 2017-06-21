#include <iostream>
#include <map>
#include <vector>


int main() {

	std::vector<int> myVec;
	for (size_t i = 0; i < 99; i+=2)
		myVec.push_back(i);

	std::cout << "Size: " << myVec.size() << std::endl;
	std::cout << "Capacity: " << myVec.capacity() << std::endl;

	myVec[0] = myVec.size();

	myVec.erase(myVec.begin() + 7);
	myVec.erase(myVec.begin() + 13);
	myVec.erase(myVec.begin() + 19);

	size_t counter = 0;
	for (size_t i = 0; i < myVec.size(); ++i)
		if (myVec[i] % 4 == 0)
			++counter;

	std::cout << "Counter: " << counter << std::endl;

	myVec[19] = 99;

	myVec.pop_back();

	myVec.back() = 101;

	std::cout << "MyVec.size(): " << myVec.size() << std::endl;
	for (auto el : myVec)
		std::cout << el << " ";

	std::cout << std::endl;
	std::cout << std::endl;
	
	for (size_t i = 0; i < myVec.size(); ++i) {
	//	std::cout << i << " " << *(myVec.begin() + i) << std::endl;
	//	if ((*(myVec.begin() + i)) % 2 == 0) {
	//		std::cout << "Inner loop" << std::endl;
			myVec.erase(myVec.begin() + i);
	//	}
	}

	for (auto el : myVec)
		std::cout << el << " ";
	std::cout << std::endl;

	return 0;
}