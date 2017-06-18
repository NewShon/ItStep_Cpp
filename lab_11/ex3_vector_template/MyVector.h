#pragma once
#include <iostream>

template<typename T>
class MyVector
{
	T *arr;
	size_t size;
	size_t capacity;

public:
	static size_t surviving_vectors;
	static size_t all_vectors;

	MyVector();
	MyVector(const MyVector&);
	MyVector(MyVector&&);
	MyVector(T[], size_t);
	~MyVector(){ delete[] arr; --surviving_vectors; }


	bool empty() const;
	size_t get_size() const;
	size_t get_capacity() const;
	void push_back(T);
	T pop_back();
	T& at(size_t);
	void print();

	void sort();
	size_t get_min() const;
	size_t get_max() const;

	MyVector& operator=(const MyVector&);
	MyVector& operator=(MyVector&&);

	T operator[](const size_t);

	bool operator==(const MyVector&);
	bool operator!=(const MyVector&);
	bool operator<(const MyVector&);
	bool operator>(const MyVector&);
	bool operator>=(const MyVector&);
	bool operator<=(const MyVector&);

	void clear() { size = 0; }
	void resize(size_t);

	void insert(const T&, const T&);

private:
	T get_min_max(bool) const;
};



template<typename T>
size_t MyVector<T>::surviving_vectors = 0;
template<typename T>
size_t MyVector<T>::all_vectors = 0;

template<typename T>
MyVector<T>::MyVector() : size(0), capacity(32) 
{ 
	arr = new T[32];
	++surviving_vectors; 
	++all_vectors; 
}

template<typename T>
MyVector<T>::MyVector(const MyVector& newVector) : size(newVector.size), capacity(newVector.capacity)
{
	++surviving_vectors;
	++all_vectors;
	arr = new T[newVector.capacity];
	for (size_t i = 0; i < newVector.size; ++i)
		arr[i] = newVector.arr[i];
}

template<typename T>
MyVector<T>::MyVector(MyVector&& newVector) : size(newVector.size), capacity(newVector.capacity), arr(newVector.arr)
{
	++surviving_vectors;
	++all_vectors;

	newVector.arr = nullptr;
	newVector.size = 0;
	newVector.capacity = 0;
}

template<typename T>
MyVector<T>::MyVector(T array[], size_t s) : capacity(s), size(s)
{
	++surviving_vectors;
	++all_vectors;

	arr = new T[s];
	arr = array;
}


template<typename T>
bool MyVector<T>::empty()const
{ return size == 0; }

template<typename T>
size_t MyVector<T>::get_size() const
{ return size; }

template<typename T>
size_t MyVector<T>::get_capacity() const 
{ return capacity; }

template<typename T>
void MyVector<T>::push_back(T element)
{
	if (size == capacity)
	{
		capacity *= 2;
		T* arr1 = new T[capacity];

		for (int i = 0; i < size; ++i)
			arr1[i] = arr[i];

		arr1[size++] = element;
		arr = arr1;
		arr1 = nullptr;
		return;
	}
	arr[size++] = element;
}

template<typename T>
T MyVector<T>::pop_back()
{
	if (size == 0) return false;
	return arr[--size];
}

template<typename T>
T& MyVector<T>::at(size_t id) { return arr[id]; }

template<typename T>
void MyVector<T>::print()
{
	std::cout << "Size:\t\t" << size << std::endl;
	std::cout << "Capacity:\t" << capacity << std::endl;
	for (size_t i = 0; i < size; ++i)
		std::cout << arr[i] << std::endl;
}

template<typename T>
void MyVector<T>::sort(){
	for (int d = size / 2; d > 0; d /= 2)
	{
		for (int i = d, j; i < size; i++)
		{
			T temp = arr[i];
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

template<typename T>
size_t MyVector<T>::get_min() const { return get_min_max(0); }

template<typename T>
size_t MyVector<T>::get_max() const { return get_min_max(1); }

template<typename T>
T MyVector<T>::get_min_max(bool b) const{
	T* tmp = new T[size];
	for (int i = 0; i < size; ++i)
		tmp[i] = arr[i];

	T element;
	if (b) {
		element = tmp[size - 1];
		delete[] tmp;
		return element;
	}
	element = tmp[0];
	delete[] tmp;
	return element;
}

template<typename T>
MyVector<T>& MyVector<T>::operator=(const MyVector& newVector)
{
	if (this == &newVector) return *this;

	size = newVector.size;
	capacity = newVector.capacity;
	delete[]arr;
	arr = new T[capacity];

	for (int i = 0; i < size; ++i)
		arr[i] = newVector.arr[i];

	return *this;
}

template<typename T>
MyVector<T>& MyVector<T>::operator=(MyVector&& newVector){
	if (this == &newVector) return *this;

	size = newVector.size;
	capacity = newVector.capacity;
	delete[]arr;
	arr = new T[capacity];

	for (int i = 0; i < size; ++i)
		arr[i] = newVector.arr[i];

	newVector.size = 0;
	newVector.capacity = 0;
	newVector.arr = nullptr;

	return *this;
}

template<typename T>
T MyVector<T>::operator[](const size_t id){
	if (id < size) return arr[id];
	return 0;
}

template<typename T>
bool MyVector<T>::operator==(const MyVector& newVector){
	bool flag = 0;
	if (size == newVector.size && capacity == newVector.capacity){
		flag = 1;
		for (int i = 0; i < size; ++i)
			if (arr[i] != newVector.arr[i]) flag = 0;
	}
	return flag;
}

template<typename T>
bool MyVector<T>::operator!=(const MyVector& newVector)
{ return !(*this == newVector); }

template<typename T>
bool MyVector<T>::operator<(const MyVector& newVector) {
	return size < newVector.size;
}

template<typename T>
bool MyVector<T>::operator>(const MyVector& newVector) {
	return size > newVector.size;
}

template<typename T>
bool MyVector<T>::operator>=(const MyVector& newVector) {
	return size >= newVector.size;
}

template<typename T>
bool MyVector<T>::operator<=(const MyVector& newVector) {
	return size <= newVector.size;
}

template<typename T>
void MyVector<T>::resize(size_t s){
	if (s < capacity) return;
	capacity = s;
	T* arr1 = new T[s];

	for (int i = 0; i < size; ++i)
		arr1[i] = arr[i];
	delete[] arr;
	arr = arr1;
	arr1 = nullptr;
}

template<typename T>
void MyVector<T>::insert(const T& find_el, const T& element)
{
	size_t i = 0;
	T* tmp = new T[capacity * 2];
	bool flag = 0;
	for (; i < size; ++i)
	{
		if (arr[i] == find_el)
		{
			flag = 1;
			capacity *= 2;
			
			for (size_t j = 0; j <= i; ++j)
				tmp[j] = arr[j];

			tmp[++i] = element;
			break;
		}
	}

	if (!flag) return;

	++i;
	for (; i < size; ++i)
		tmp[i] = arr[i-1];
	
	delete[]arr;
	arr = tmp;
	tmp = nullptr;
}