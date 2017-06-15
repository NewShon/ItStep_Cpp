#pragma once

template<typename T>
class Stack
{
	T* stack;
	size_t capacity;
	size_t size;
public:
	Stack();
	Stack(const Stack&);
	Stack(Stack&&);
	~Stack();

	void push(const T& el);
	bool empty() const;
	size_t get_size() const;
	T top() const;
	T pop();

	Stack& operator=(const Stack&);
	Stack& operator=(Stack&&);

	bool operator==(const Stack&);
	bool operator!=(const Stack&);
};


template<typename T>
Stack<T>::Stack() : capacity(32), size(0)
{ stack = new T[capacity]; }


template<typename T>
Stack<T>::Stack(const Stack& newStack) : capacity(newStack.capacity), size(newStack.size)
{
	stack = new T[capacity];
	for (size_t i = 0; i < capacity; ++i)
		stack[i] = newStack.stack[i];
}


template<typename T>
Stack<T>::Stack(Stack&& newStack) : capacity(newStack.capacity), size(newStack.size)
{
	newStack.capacity = 0;
	newStack.size = 0;

	stack = newStack.stack;
	newStack.stack = nullptr;
}


template<typename T>
void Stack<T>::push(const T& el)
{
	if (size == capacity)
	{
		capacity *= 2;
		T* tmp = new T[capacity];
		for (size_t i = 0; i < capacity; ++i)
			tmp[i] = stack[i];

		delete[] stack;
		stack = tmp;
		
		tmp = nullptr;
	}
	stack[size++] = el;
}


template<typename T>
bool Stack<T>::empty() const 
{ return size == 0; }


template<typename T>
T Stack<T>::top() const
{ if (size != 0) return stack[size - 1]; }


template<typename T>
T Stack<T>::pop() 
{ if (size != 0) return stack[--size]; }


template<typename T>
size_t Stack<T>::get_size() const 
{ return size; }


template<typename T>
Stack<T>& Stack<T>::operator=(const Stack& newStack)
{
	if (this == &newStack) return *this;
	size = newStack.size;
	capacity = newStack.capacity;

	delete[] stack;
	stack = new T[capacity];
	for (size_t i = 0; i < newStack.size; ++i)
		stack[i] = newStack.stack[i];
	return *this;
}


template<typename T>
Stack<T>& Stack<T>::operator=(Stack&& newStack)
{
	size = newStack.size;
	newStack.size = 0;

	capacity = newStack.capacity;
	newStack.capacity = 0;

	delete[] stack;
	stack = newStack.stack;
	newStack.stack = nullptr;

	return *this;
}


template<typename T>
bool Stack<T>::operator==(const Stack& newStack)
{
	if (size == newStack.size)
	{
		for (size_t i = 0; i < size; ++i) {
			if (stack[i] != newStack.stack[i])
				return false;
		}
		return true;
	}
	return false;
}


template<typename T>
bool Stack<T>::operator!=(const Stack& newStack) 
{ return !(*this == newStack); }


template<typename T>
Stack<T>::~Stack()
{ delete[] stack; }