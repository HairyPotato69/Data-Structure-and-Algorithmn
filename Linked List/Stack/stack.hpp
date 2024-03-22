#ifndef stack_type
#define stack_type 

// Uses the same node from singly linked list
#include "node.hpp"

class stack {
private:
	Node* head{};
	int size{};
public:
	stack();
	bool push(const type data);
	bool pop(type& data);
	bool peek(type& data);
	bool isEmpty();
	int get_size();
};
};
#endif
