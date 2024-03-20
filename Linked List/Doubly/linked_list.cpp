#include "linked_list.h"
#include <iostream>

Linked_List::Linked_List() {
	head = NULL;
	tail = NULL;
}

int Linked_List::get_size() {
	return size;
}

bool Linked_List::isEmpty() {
	if (size == 0)
		return 1;
	else
		return 0;
}

bool Linked_List::isUpperLower(int& index) {
	// true if upper
	if (index > size / 2) {
		index = (size - index) + 1;
		return 1;
	}
	else
		return 0;
}

Node* Linked_List::find_node(int index) {
	Node* current_node{ NULL };
	if (index > size || index < 0)
		return NULL;

	// if upper
	if (isUpperLower(index)) {
		current_node = tail;
		for (int count{ 1 }; count < index; count++)
			current_node = current_node->get_prev();
		return current_node;
	}
	// if lower

	current_node = head;

	for (int count{ 1 }; count < index; count++)
		current_node = current_node->get_next();

	return current_node;
}


void Linked_List::push(Node* new_node) {
	
	if (isEmpty()) {
		head = new_node;
		tail = new_node;
	}
	new_node->set_next(head);
	head = new_node;

	size++;
}

void Linked_List::push_back(Node* new_node) {
	if (isEmpty()) {
		head = new_node;
		tail = new_node;
	}
	new_node->set_prev(tail);
	tail = new_node;
	size++;
}

bool Linked_List::insert(int index, const type data) {
	Node* new_node{ new Node(data) };
	Node* current_node{ nullptr };
	Node* prev_node{ nullptr };

	if (size - index > 1)
		return 0;

	if (isUpperLower(index))
		current_node = find_node(index);
	else 
		current_node = find_node(index);

	prev_node = current_node->get_prev();

	new_node->set_next(current_node);
	new_node->set_prev(prev_node);

	current_node->set_prev(new_node);
	prev_node->set_next(new_node);
	size++;
	return 1;
}

bool Linked_List::insert(const type data) {
	Node* new_node{ new Node(data) };
	if (isEmpty()) {
		push(new_node);
		return 1;
	}
	if (data <= head->get_data()) {
		new_node->set_next(head);
		head->set_prev(new_node);
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
	new_node->set_prev(prev_node);
	prev_node->set_next(new_node);
	current_node->set_prev(new_node);
	size++;
	return 1;

}

void Linked_List::front(type& value) {
	Node* node{ head };
	value = node->get_data();
}

void Linked_List::back(type& value) {
	Node* node{ tail };
	value = node->get_data();
}

bool Linked_List::value_at(int index, type& value) {
	Node* current_node{ NULL };
	
	if (isEmpty())
		return 0;
	if (isUpperLower(index))
		current_node = find_node(index);
	else
		current_node = find_node(index);
	value = current_node->get_data();
	
	return 1;
}

void Linked_List::pop_front() {
	Node* node{ head };

	if (size == 1) {
		head = NULL;
		tail = NULL;
	}
	else {
		node->get_next()->set_prev(NULL);
		head = node->get_next();
	}

	size--;

	delete node;
}

void Linked_List::pop_back() {
	Node* node{ tail };
	if (size == 1) {
		head = NULL;
		tail = NULL;
	}
	else {
		node->get_prev()->set_next(NULL);
		tail = node->get_prev();
	}
	size--;
	delete node;
}

bool Linked_List::remove(int index) {
	if (isEmpty() || index > size || index < 0)
		return 0;

	Node* current_node{ NULL };
	Node* prev_node{ NULL };
	Node* next_node{ NULL };

	if (index == 1){
		pop_front();
		return 1;
	}
	if (index == size) {
		pop_back();
		return 1;
	}
	if (isUpperLower(index))
		current_node = find_node(index);
	else 
		current_node = find_node(index);

	prev_node = current_node->get_prev();
	next_node = current_node->get_next();

	prev_node->set_next(next_node);
	next_node->set_prev(prev_node);
	
	return 1;
}

void Linked_List::print() {

	Node* node{ nullptr };
	for (int count{ 1 }; count <= size; count++) {
		node = find_node(count);
	}
}
