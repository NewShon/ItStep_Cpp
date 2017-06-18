#ifndef __QUEUE_H__
#define __QUEUE_H__

template <class T>
class Queue
{
	T* data;
	size_t tail;
	size_t head;
	size_t capacity;
public:
	Queue();
	Queue(const Queue<T>&);
	Queue(Queue<T>&&);
	Queue& operator=(const Queue<T>&);
	Queue& operator=(Queue<T>&&);
	~Queue();
	
	size_t size() const;
	bool empty() const;
	void clear();
	
	void push(const T&);
	void pop();
	T& back();
	T& front();
};

template <class T>
Queue<T>::Queue() : head(0), tail(0), capacity(32) 
{ data = new T[capacity]; }

template <class T>
Queue<T>::Queue(const Queue<T>& newQ) : tail(newQ.tail), head(newQ.head), capacity(newQ.capacity)
{
	data = new T[capacity];

	for (size_t i = 0; i < tail; ++i)
		data[i] = newQ.data[i];
}

template <class T>
Queue<T>::Queue(Queue<T>&& newQ) : tail(newQ.tail), head(newQ.head), capacity(capacity), data(newQ.data)
{
	newQ.tail = 0;
	newQ.head = 0;
	newQ.capacitu = 0;
	newQ.data = nullptr;
}

template <class T>
Queue<T>& Queue<T>::operator=(const Queue<T>& newQ)
{
	if (this == &newQ)
		return *this;

	tail = newQ.tail;
	head = newQ.head;
	capacity = newQ.capacity;

	delete[]data;
	data = new T[capacity];

	for (size_t i = 0; i < capacity; ++i)
		data[i] = newQ.data[i];

	return *this;
}

template <class T>
Queue<T>& Queue<T>::operator=(Queue<T>&& newQ)
{
	if (this == &newQ)
		return *this;

	tail = newQ.tail;
	head = newQ.head;
	capacity = newQ.capacity;

	delete[] data;
	data = newQ.data;

	newQ.data = nullptr;
	newQ.head = 0;
	newQ.tail = 0;
	newQ.capacity = 0;

	return *this;
}

template <class T>
Queue<T>::~Queue<T>(){ delete[] data; }

template <class T>
size_t Queue<T>::size() const { return capacity; }

template <class T>
bool Queue<T>::empty() const { return tail == 0; }

template <class T>
void Queue<T>::clear()
{
	head = 0;
	tail = 0;
	capacity = 32;
	delete[] data;
	data = new T[capacity];
}

template <class T>
void Queue<T>::push(const T& element)
{
	if (tail + 1 == capacity && head == 0 || tail + 1 == head) return;
	data[tail++] = element;
	if (tail == capacity) tail = 0;
}

template <class T>
void Queue<T>::pop()
{
	if (head == tail) return;
	if (++head == capacity) head = 0;
}

template <class T>
T& Queue<T>::back() { return data[tail - 1]; }

template <class T>
T& Queue<T>::front() { return data[head]; }











#endif /* __QUEUE_H__ */
