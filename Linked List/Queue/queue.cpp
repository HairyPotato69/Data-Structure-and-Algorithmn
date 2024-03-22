#include "queue.hpp"
#include <iostream>

queue::queue() {
	head = NULL;
}

bool queue::dequeue(type& data) {
	
	if (isEmpty())
		return 0;
	Node* first_node{ head };

	if (get_size() == 1) {
		data = first_node->get_data();
		head = NULL;
		delete first_node;
		return 1;
	}

	data = first_node->get_data();
	head = first_node->get_next();

	delete first_node;
	size--;
	
	return 1;
}

bool queue::enqueue(const type data) {
	Node* new_node(new Node(data));
	Node* current_node{ nullptr };
	if (!new_node)
		return 0;

	if (isEmpty()) {
		head = new_node;
		size++;
		return 1;
	}

	for (int i{ 1 }; i < size; i++)
		current_node = current_node->get_next();
	
	current_node->set_next(new_node);
	size++;
	
	return 1;
}

bool queue::isEmpty() {
	if (size == 0)
		return 1;
	return 0;
}

int queue::get_size() {
	return size;
}

bool queue::peek(type& data) {
	if (isEmpty())
		return 0;

	data = head->get_data();
	
	return 1;
}