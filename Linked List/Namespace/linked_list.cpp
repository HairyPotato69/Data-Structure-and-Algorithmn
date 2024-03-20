#include "linked_list.h"
#include <iostream>

singly::Linked_List::Linked_List(){
	head = NULL;
	tail = NULL;
}

int singly::Linked_List::get_size(){
	return size;
}

bool singly::Linked_List::isEmpty() {
	if (size == 0)
		return 1;
	else
		return 0;
}

singly::Node* singly::Linked_List::find_node(const int index) {
	if (Linked_List::isEmpty() || index < 1 || index > size)
		return NULL;

	singly::Node* current_node{ head };
	
	for (int count{ 1 }; count < index; count++) 
		current_node = current_node->get_next();

	return current_node;
}

void singly::Linked_List::push(singly::Node* new_node) {
	// singly::Node* new_node = new singly::Node(data);

	if (isEmpty()) {
		head = new_node;
		tail = new_node;
	}

	// sets the next on this node 
	new_node->set_next(head);
	head = new_node;

	size++;
}

void singly::Linked_List::push_back(singly::Node* new_node) {
	// singly::Node* new_node = new singly::Node(data);

	if (size == 0) {
		head = new_node;
		tail = new_node;
	}
	
	new_node->set_next(tail);
	tail = new_node;
	size++;
}

bool singly::Linked_List::insert(int index, const type data) {
	singly::Node* new_node{ new singly::Node(data) };

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

	singly::Node* prev_node { find_node(index - 1) };
	singly::Node* next_node { prev_node->get_next() };

	prev_node->set_next(new_node);
	new_node->set_next(next_node);

	size++;

	return 1;
 }

// This only works if the list has already been arranged in order
bool singly::Linked_List::insert(const type data) {
	singly::Node* new_node{ new singly::Node(data) };
	if (isEmpty()) {
		push(new_node);
		return 1;
	}
	if (head->get_data() > data) {
		new_node->set_next(head);
		head = new_node;
		return 1;
	}

	singly::Node* prev_node{ head };
	singly::Node* current_node{ head->get_next() };

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

void singly::Linked_List::front(type& value) {
	value = head->get_data();
}

void singly::Linked_List::back(type& value) {
	value = tail->get_data();
}

bool singly::Linked_List::value_at(const int index, type& value) {
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

void singly::Linked_List::pop_front() {
	singly::Node* node{ head };
	head = head->get_next();

	if (size == 1) {
		head = NULL;
		tail = NULL;
	}
	size--;

	delete node;
}

//
//void singly::Linked_List::pop_back() {
//	singly::Node* last_node{ head };
//	for (int count{ 1 }; count < size - 1; count++) {
//
//	}
//}

bool singly::Linked_List::remove(const int index){

	if (isEmpty() || index < 0 || index > size)
		return 0;

	if (index == 1) {
		pop_front();
		return 1;
	}

	singly::Node* previous = find_node(index-1);
	singly::Node* node = previous->get_next();

	previous->set_next(node->get_next());
	delete node;
	size--;
	return 1;

}

void singly::Linked_List::print() {
	singly::Node* node{ nullptr };
	for (int count{ 1 }; count <= size; count++) {
		node = find_node(count);
	}

}


doubly::Linked_List::Linked_List() {
	head = NULL;
	tail = NULL;
}

int doubly::Linked_List::get_size() {
	return size;
}

bool doubly::Linked_List::isEmpty() {
	if (size == 0)
		return 1;
	else
		return 0;
}

bool doubly::Linked_List::isUpperLower(int& index) {
	// true if upper
	if (index > size / 2) {
		index = (size - index) + 1;
		return 1;
	}
	else
		return 0;
}

doubly::Node* doubly::Linked_List::find_node(int index) {
	doubly::Node* current_node{ NULL };
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


void doubly::Linked_List::push(doubly::Node* new_node) {
	
	if (isEmpty()) {
		head = new_node;
		tail = new_node;
	}
	new_node->set_next(head);
	head = new_node;

	size++;
}

void doubly::Linked_List::push_back(doubly::Node* new_node) {
	if (isEmpty()) {
		head = new_node;
		tail = new_node;
	}
	new_node->set_prev(tail);
	tail = new_node;
	size++;
}

bool doubly::Linked_List::insert(int index, const type data) {
	doubly::Node* new_node{ new Node(data) };
	doubly::Node* current_node{ nullptr };
	doubly::Node* prev_node{ nullptr };

	if (size - index > 1)
		return 0;

	if (isUpperLower(index))
		current_node = find_node(index);
		// prev_node = find_node(index + 1);

		/*Delete later*/
		//new_node->set_next(current_node);
		//new_node->set_prev(prev_node);
		//prev_node->set_next(new_node);
		//current_node->set_prev(new_node);
	else 
		current_node = find_node(index);
		// prev_node = find_node(index - 1);

	prev_node = current_node->get_prev();

	new_node->set_next(current_node);
	new_node->set_prev(prev_node);

	current_node->set_prev(new_node);
	prev_node->set_next(new_node);
	size++;
	return 1;
}

bool doubly::Linked_List::insert(const type data) {
	doubly::Node* new_node{ new Node(data) };
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
	doubly::Node* prev_node{ head };
	doubly::Node* current_node{ head->get_next() };

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

void doubly::Linked_List::front(type& value) {
	doubly::Node* node{ head };
	value = node->get_data();
}

void doubly::Linked_List::back(type& value) {
	doubly::Node* node{ tail };
	value = node->get_data();
}

bool doubly::Linked_List::value_at(int index, type& value) {
	doubly::Node* current_node{ NULL };
	
	if (isEmpty())
		return 0;
	if (isUpperLower(index))
		current_node = find_node(index);
	else
		current_node = find_node(index);
	value = current_node->get_data();
	
	return 1;
}

void doubly::Linked_List::pop_front() {
	doubly::Node* node{ head };

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

void doubly::Linked_List::pop_back() {
	doubly::Node* node{ tail };
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

bool doubly::Linked_List::remove(int index) {
	if (isEmpty() || index > size || index < 0)
		return 0;

	doubly::Node* current_node{ NULL };
	doubly::Node* prev_node{ NULL };
	doubly::Node* next_node{ NULL };

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

void doubly::Linked_List::print() {

	doubly::Node* node{ nullptr };
	for (int count{ 1 }; count <= size; count++) {
		node = find_node(count);
	}
}
