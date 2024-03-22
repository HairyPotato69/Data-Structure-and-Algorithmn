#include "linked_list.hpp"
#include <iostream>

Linked_List::Linked_List(){
	head = NULL;
	tail = NULL;
}

int Linked_List::get_size(){
	return size;
}

bool Linked_List::isEmpty() {
	if (size == 0)
		return 1;
	else
		return 0;
}

Node* Linked_List::find_node(const int index) {
	if (Linked_List::isEmpty() || index < 1 || index > size)
		return NULL;

	Node* current_node{ head };
	
	for (int count{ 1 }; count < index; count++) 
		current_node = current_node->get_next();

	return current_node;
}

void Linked_List::push(Node* new_node) {

	if (isEmpty()) {
		head = new_node;
		tail = new_node;
	}

	// sets the next on this node 
	new_node->set_next(head);
	head = new_node;

	size++;
}

void Linked_List::push_back(Node* new_node) {

	if (size == 0) {
		head = new_node;
		tail = new_node;
	}
	
	new_node->set_next(tail);
	tail = new_node;
	size++;
}

bool Linked_List::insert(int index, const type data) {
	Node* new_node{ new Node(data) };

	if (index - size > 1)
		return 0;

	if (isEmpty()) {
		push(new_node);
		return 1;
	}

	if (index - size == 1 && size > 1) {
		push_back(new_node);
		return 1;
	}

	Node* prev_node { find_node(index - 1) };
	Node* next_node { prev_node->get_next() };

	prev_node->set_next(new_node);
	new_node->set_next(next_node);

	size++;

	return 1;
 }

// This only works if the list has already been arranged in order
bool Linked_List::insert(const type data) {
	Node* new_node{ new Node(data) };
	if (isEmpty()) {
		push(new_node);
		return 1;
	}
	if (head->get_data() > data) {
		new_node->set_next(head);
		head = new_node;
		return 1;
	}

	Node* prev_node{ head };
	Node* current_node{ head->get_next() };

	while (current_node != NULL) {
		if (current_node->get_data() > data)
			break;
		prev_node = current_node;
		current_node = current_node->get_next();
	}

	new_node->set_next(current_node);
	prev_node->set_next(new_node);
	size++;

	return 1;
}

void Linked_List::front(type& value) {
	value = head->get_data();
}

void Linked_List::back(type& value) {
	value = tail->get_data();
}

bool Linked_List::value_at(const int index, type& value) {
	if (isEmpty() || index > size || index < 0)
		return 0;
	if (index == 1) {
		front(value);
		return 1;
	}
	if (index == size && size > 1) {
		back(value);
		return 1;
	}

	value = find_node(index)->get_data();
	return 1;
}

void Linked_List::pop_front() {
	Node* node{ head };
	head = head->get_next();

	if (size == 1) {
		head = NULL;
		tail = NULL;
	}
	size--;

	delete node;
}

bool Linked_List::remove(const int index){

	if (isEmpty() || index < 0 || index > size)
		return 0;

	if (index == 1) {
		pop_front();
		return 1;
	}

	Node* previous = find_node(index-1);
	Node* node = previous->get_next();

	previous->set_next(node->get_next());
	delete node;
	size--;
	return 1;

}

void Linked_List::print() {
	Node* node{ nullptr };
	for (int count{ 1 }; count <= size; count++) {
		node = find_node(count);
	}

}
