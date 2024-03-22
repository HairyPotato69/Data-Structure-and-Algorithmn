#include "stack.hpp"
#include <iostream>

stack::stack() {
	head = NULL;
}

bool stack::push(const type data) {
	Node* new_node{ new Node(data) };
	if (!new_node)
		return 0;
	if (isEmpty()) {
		head = new_node;
		return 1;
	}

	new_node->set_next(head);
	head = new_node;

	size++;
	return 1;
}

bool stack::pop(type& data) {
	if (isEmpty())
		return 0;

	Node* node{ head };
	data = node->get_data();

	if (get_size() == 1) {
		head = NULL;
		delete node;
		size--;
		return 0;
	}

	head = node->get_next();
	delete node;
	size--;

	return 1;
}

bool stack::peek(type& data) {
	if (isEmpty())
		return 0;

	data = head->get_data();

	return 1;
}

bool stack::isEmpty() {
	if (size == 0)
		return 1;
	return 0;
}

int stack::get_size() {
	return size;
}
// !!! Stack !!!
