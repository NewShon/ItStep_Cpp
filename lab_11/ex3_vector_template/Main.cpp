#include "MyVector.h"

void test()
{
	int arr1[20];
	for (int i = 0; i < 20; ++i)
		arr1[i] = i;

	MyVector<int> a(arr1, 10);

	a.push_back(15);

	a.insert(4, 100);
	if (a.at(5) == 100)
		std::cout << "Test 1: OK!\n";
	else
		std::cout << "Test 1:Error!!!\n";

	a.resize(50);
	if (a.get_capacity() == 50)
		std::cout << "Test 2: OK!\n";
	else
		std::cout << "Test 2:Error!!!\n";
}

int main(int argc, char* argv[])
{

	test();


	return 0;
}