#include <iostream>
#include <algorithm>

template <typename T>
class stack {
public:
	using key_type = T;

private:

	struct Node {
		key_type data;
		Node* next {nullptr};
		Node() {}
		Node(key_type d) : data{d} {}
	};

	size_t sz {0};
	Node *head {nullptr};


public:
	stack();
	stack(const stack& s);
	stack& operator=(const stack& other);
	~stack();
	void push(const key_type& key);
	void pop();
	key_type top() const;
	bool empty() const;
	size_t size() const;
	void swap(stack& other);
};