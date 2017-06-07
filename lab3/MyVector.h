#pragma once
class MyVector
{
	int *arr;
	unsigned int size;
	unsigned int capacity;
public:
	MyVector() : size(0), capacity(32) { arr = new int[32]; }

	MyVector(const MyVector& newVector) : size(newVector.size), capacity(newVector.capacity)
	{
		arr = new int[newVector.capacity];
		for (int i = 0; i < newVector.size; ++i)
			arr[i] = newVector.arr[i];
	}

	MyVector(MyVector&& newVector) : size(newVector.size), capacity(newVector.capacity), arr(newVector.arr)
	{
		newVector.arr = nullptr;
		newVector.size = 0;
		newVector.capacity = 0;
	}

	bool empty()const;
	unsigned int get_size()const;
	unsigned int get_capacity()const;
	void push_back(int);
	int pop_back();
	int& at(int);
	void print();

	~MyVector(){ delete[] arr; }
};

