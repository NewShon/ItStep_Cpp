#include <vector>
#include <iostream>
#include <fstream>
#include <map>
#include<list>
#include <set>


void vect()
{
	std::ifstream in("input.txt");
	std::vector<long long> myVector;

	long long num;
	while (in >> num)
		myVector.push_back(num);


	std::cout << myVector.size() << std::endl;
	std::cout << myVector.capacity() << std::endl;


	for (size_t i = 0; i < 50; ++i)
		myVector.pop_back();

	std::cout << std::endl;

	std::cout << myVector.size() << std::endl;
	std::cout << myVector.capacity() << std::endl;

	myVector.shrink_to_fit();

	std::cout << std::endl;

	std::cout << myVector.size() << std::endl;
	std::cout << myVector.capacity() << std::endl;


	std::vector<long long> newVector;
	for (size_t i = 0; i < myVector.size(); i += 2)
		newVector.push_back(myVector[i]);


	std::cout << std::endl;

	newVector.shrink_to_fit();
	std::cout << newVector.size() << std::endl;
	std::cout << newVector.capacity() << std::endl;
}
void myList()
{
	std::ifstream in("input.txt");
	std::list<int> myList;

	for (int i = 10; i >= 0; --i)
		myList.push_back(i);

	myList.sort();
	std::list<int>::iterator it = myList.begin();

	++it;
	myList.insert(it, 6);
	myList.remove(1);

	myList.sort();
	myList.unique();


	for (auto el : myList)
		std::cout << el << " ";

}



int main(){

	myList();

	return 0;
}