#pragma once
#include <exception>

template <typename T>
class ForwardList {
	struct node {
		T data;
		node* next = nullptr;
	};
	node* head;
	node* tail;
	size_t list_size{ 0 };

public:
	ForwardList() {}
	~ForwardList();

	size_t size() const { return list_size; }
	bool empty() const { return list_size == 0; }

	void push_back(const T&);
	void push_front(const T&);
	bool insert(const T&, const T&);

	T pop_back();
	T pop_front();
	bool erase(const T&);

	void print();

private:
	//node* create_node(const T&);
	void create_first_node(const T&);
	//node* find_node(const T&);
	//node* find_previous_node(const T&);
};

template <typename T>
void ForwardList<T>::create_first_node(const T& el) {
	node* tmp = new node;
	tmp->data = el;
	head = tmp;
	tail = tmp;
	tmp->next = nullptr;
}

template <typename T>
void ForwardList<T>::push_back(const T& el) {
	if (size() == 0) {
		create_first_node(el);
	}
	else {
		node* tmp = new node;
		tmp->data = el;
		tmp->next = nullptr;
		tail->next = tmp;
		tail = tmp;
	}

	++list_size;
}

template <typename T>
void ForwardList<T>::push_front(const T& el) {
	if (size() == 0) {
		create_first_node(el);
	}
	else {
		node* tmp = new node;
		tmp->data = el;
		tmp->next = head;
		head = tmp;
	}
	++list_size;
}

template <typename T>
T ForwardList<T>::pop_back() {
	if (size() == 0) {
		throw std::logic_error("Error: size = 0");
	}

	node* tmp = tail;
	T data = tmp->data;

	node*ptr = head;
	while (ptr->next != nullptr) {
		if (ptr->next->next == nullptr) {
			ptr->next = nullptr;
			break;
		}
		ptr = ptr->next;
	}

	--list_size;
	tail = ptr;

	if (size() == 0) {
		head = tail = nullptr;
	}

	delete tmp;
	return data;

}

template <typename T>
T ForwardList<T>::pop_front() {
	if (size() == 0) {
		throw  std::logic_error("Error: size = 0");
	}
	
	node* tmp = head;
	T data = tmp->data;
	head = head->next;
	--list_size;

	if (size() == 0) {
		head = tail = nullptr;
	}

	delete tmp;
	return data;
}

template <typename T>
bool ForwardList<T>::insert(const T& what, const T& which) {
	if (size() == 0) {
		return false;
	}

	node* ptr = head;
	while (ptr != nullptr) {
		if (which == ptr->data) {

			++list_size;
			node* tmp = new node;
			tmp->data = what;
			tmp->next = ptr->next;
			ptr->next = tmp;
			if (tmp->next == nullptr) {
				tail = tmp;
			}
			return true;
		}
		ptr = ptr->next;
	}

	return false;
}

template <typename T>
void ForwardList<T>::print() {
	node* ptr = head;
	while (ptr != nullptr) {
		std::cout << ptr->data << " ";
		ptr = ptr->next;
	}
	std::cout << std::endl;
}

template <typename T>
bool ForwardList<T>::erase(const T& el) {
	if (size() == 0) {
		throw std::logic_error("Error: size = 0");
	}

	node* cur = head;
	node* prev = nullptr;
	while (cur->data != el && cur != nullptr) {
		prev = cur;
		cur = cur->next;
	}

	if (cur != nullptr) {
		if (prev != nullptr) {
			prev->next = cur->next;
		}
		else {
			head = cur->next;
		}
		if (cur->next == nullptr && prev != nullptr) {
			tail = prev;
		}
		delete cur;
		--list_size;

		if (size() == 0) {
			head = tail = nullptr;
		}

		return true;
	}

	return false;
}

template <typename T>
ForwardList<T>::~ForwardList() {
	while (head) {
		pop_back();
	}
}
