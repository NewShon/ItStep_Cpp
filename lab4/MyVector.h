#pragma once
class MyVector
{
	int *arr;
    unsigned int size;
	unsigned int capacity;
	
public:
	static int surviving_vectors;
	static int all_vectors;

	MyVector();
	MyVector(const MyVector& newVector);
	MyVector(MyVector&& newVector);
	MyVector(int [], int);
	~MyVector(){ delete[] arr; --surviving_vectors; }


	bool empty() const;
	unsigned int get_size() const;
	unsigned int get_capacity() const;
	void push_back(int);
	int pop_back();
	int& at(int);
	void print();

	void sort();
	int get_min() const;
	int get_max() const;

private:
	int get_min_max(bool) const;
};

