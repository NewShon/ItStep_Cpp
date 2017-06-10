#include "Test.h"
#include "MyVector.h"
#include <iostream>

int main(int argc, char* argv[])
{
	//Test t;
	//t.test();
	MyVector m1;
	MyVector m2;
	m1 = m2;

	std::cout << (m1 != m1) << std::endl;
	std::cout << (m1 >= m1) << std::endl;
	std::cout << (m1 > m1) << std::endl;

	for (int i = 0; i < 10; ++i)
		m1.push_back(i);
	m1.print();

	std::cout << "m1 size = " << m1.get_size() << std::endl;
	m1.clear();
	std::cout << "m1 size = " << m1.get_size() << std::endl;


	std::cout << "m1 capacity = " << m1.get_capacity() << std::endl;
	m1.reserve(100);
	std::cout << "m1 capacity = " << m1.get_capacity() << std::endl;

	return 0;
}
