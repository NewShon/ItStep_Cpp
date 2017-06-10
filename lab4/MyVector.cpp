#include "MyVector.h"
#include <iostream>

int MyVector::surviving_vectors = 0;
int MyVector::all_vectors = 0;


MyVector::MyVector() : size(0), capacity(32) { arr = new int[32]; ++surviving_vectors; ++all_vectors; }

MyVector::MyVector(const MyVector& newVector) : size(newVector.size), capacity(newVector.capacity)
{
	++surviving_vectors;
	++all_vectors;
	arr = new int[newVector.capacity];
	for (int i = 0; i < newVector.size; ++i)
		arr[i] = newVector.arr[i];
}

MyVector::MyVector(MyVector&& newVector) : size(newVector.size), capacity(newVector.capacity), arr(newVector.arr)
{
	++surviving_vectors;
	++all_vectors;
	newVector.arr = nullptr;
	newVector.size = 0;
	newVector.capacity = 0;
}

MyVector::MyVector(int array[], int s) : capacity(s), size(s)
{
	++surviving_vectors;
	++all_vectors;
	arr = new int[s];
	arr = array;
}



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
	std::cout << "Size:\t\t" << size << std::endl;
	std::cout << "Capacity:\t" << capacity << std::endl;
	for (int i = 0; i < size; i++)
		std::cout << arr[i] << std::endl;
}

void MyVector::sort(){
	for (int d = size / 2; d > 0; d /= 2)
	{
		for (int i = d, j; i < size; i++)
		{
			int temp = arr[i];
			for (j = i; j >= d; j -= d)
			{
				if (temp < arr[j - d])
					arr[j] = arr[j - d];
				else break;
			}
			arr[j] = temp;
		}
	}
}

int MyVector::get_min() const { return get_min_max(0); }
int MyVector::get_max() const { return get_min_max(1); }

int MyVector::get_min_max(bool b) const{
	int* tmp = new int[size];
	for (int i = 0; i < size; ++i)
		tmp[i] = arr[i];

	int element;
	if (b) { 
		element = tmp[size - 1];
		delete[] tmp;
		return element;
	}
	element = tmp[0];
	delete[] tmp;
	return element;
}