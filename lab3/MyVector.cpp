#include "MyVector.h"
#include <iostream>

bool MyVector::empty()const{
	if (size == 0) return 1;
	return 0;
}

unsigned int MyVector::get_size() const { return size; }

unsigned int MyVector::get_capacity() const { return capacity; }

void MyVector::push_back(int element) 
{
	if (size == capacity)
	{
		int* arr1 = new int[capacity * 2];
		capacity *= 2;
		for (int i = 0; i < size; i++)
			arr1[i] = arr[i];
		arr1[size++] = element;
		delete[] arr;
		arr = arr1;
	}
	else arr[size++] = element;
}

int MyVector::pop_back() 
{
	if (size == 0) return false;
	return arr[--size];
}

int& MyVector::at(int id) { return arr[id]; }

void MyVector::print() 
{
	std::cout << size << std::endl;
	std::cout << capacity << std::endl;
	for (int i = 0; i < size; i++)
	{
		std::cout << arr[i] << std::endl;
	}
}