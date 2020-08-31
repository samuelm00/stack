#include "stack.h"
#include <algorithm>


template <typename T>
stack<T>::stack() {head = new Node;}

template <typename T>
stack<T>::stack(const stack& s) : stack{} {
	for (Node* h{s.head}; h != nullptr; h = h->next) {
		this->push(h->data);
	}
}

template <typename T>
stack<T>::~stack() {
	Node* help;
	while (head) {
		help = head;
		head = head->next;
		delete help;
	}
}

template <typename T>
void stack<T>::swap(stack& other) {
	std::swap(this->head, other.head);
	std::swap(this->sz, other.sz);
}

template <typename T>
typename stack<T>::stack& stack<T>::operator=( const stack& other ) {
	stack tmp {other};
	this->swap(tmp);
	return *this;
}

template <typename T>
void stack<T>::push(const key_type& key) {
	if (sz == 0) {
		head->data = key;
	}
	else {
		Node* help {head};
		while (help->next != nullptr) help = help->next;
		help->next = new Node(key);
	}
	++sz;
}

template <typename T>
void stack<T>::pop() {
	if (sz == 0) throw std::runtime_error("Stack is empty!");
	Node* help {head->next};
	delete head;
	head = help;
	--sz;
}

template <typename T>
typename stack<T>::key_type stack<T>::top() const {
	return head->data;
}

template <typename T>
bool stack<T>::empty() const { return sz == 0; }

template <typename T>
size_t stack<T>::size() const { return sz; }

template <typename T>
void swap(stack<T>& l, stack<T>& r) { l.swap(r); }