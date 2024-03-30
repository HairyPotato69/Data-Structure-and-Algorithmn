#include "data_structure.hpp"
#include <iostream>

// !!! Singly !!!
linked_list::singly::Linked_List::Linked_List() {
	head = NULL;
	tail = NULL;
}

int linked_list::singly::Linked_List::get_size() {
	return size;
}

bool linked_list::singly::Linked_List::isEmpty() {
	if (size == 0)
		return 1;
	else
		return 0;
}

single_node::Node* linked_list::singly::Linked_List::find_node(const int index) {
	if (Linked_List::isEmpty() || index < 1 || index > size)
		return NULL;

	single_node::Node* current_node{ head };

	for (int count{ 1 }; count < index; count++)
		current_node = current_node->get_next();

	return current_node;
}

void linked_list::singly::Linked_List::push(single_node::Node* new_node) {
	// single_node::Node* new_node = new single_node::Node(data);

	if (isEmpty()) {
		head = new_node;
		tail = new_node;
	}

	// sets the next on this node 
	new_node->set_next(head);
	head = new_node;

	size++;
}

void linked_list::singly::Linked_List::push_back(single_node::Node* new_node) {
	// singly::Node* new_node = new singly::Node(data);

	if (size == 0) {
		head = new_node;
		tail = new_node;
	}

	new_node->set_next(tail);
	tail = new_node;
	size++;
}

bool linked_list::singly::Linked_List::insert(int index, const type data) {
	single_node::Node* new_node{ new single_node::Node(data) };

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

	single_node::Node* prev_node{ find_node(index - 1) };
	single_node::Node* next_node{ prev_node->get_next() };

	prev_node->set_next(new_node);
	new_node->set_next(next_node);

	size++;

	return 1;
}

// This only works if the list has already been arranged in order
bool linked_list::singly::Linked_List::insert(const type data) {
	single_node::Node* new_node{ new single_node::Node(data) };
	if (isEmpty()) {
		push(new_node);
		return 1;
	}
	if (head->get_data() > data) {
		new_node->set_next(head);
		head = new_node;
		return 1;
	}

	single_node::Node* prev_node{ head };
	single_node::Node* current_node{ head->get_next() };

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

void linked_list::singly::Linked_List::front(type& value) {
	value = head->get_data();
}

void linked_list::singly::Linked_List::back(type& value) {
	value = tail->get_data();
}

bool linked_list::singly::Linked_List::value_at(const int index, type& value) {
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

void linked_list::singly::Linked_List::pop_front() {
	single_node::Node* node{ head };
	head = head->get_next();

	if (size == 1) {
		head = NULL;
		tail = NULL;
	}
	size--;

	delete node;
}

bool linked_list::singly::Linked_List::remove(const int index) {

	if (isEmpty() || index < 0 || index > size)
		return 0;

	if (index == 1) {
		pop_front();
		return 1;
	}

	single_node::Node* previous = find_node(index - 1);
	single_node::Node* node = previous->get_next();

	previous->set_next(node->get_next());
	delete node;
	size--;
	return 1;

}

void linked_list::singly::Linked_List::print() {
	single_node::Node* node{ nullptr };
	for (int count{ 1 }; count <= size; count++) {
		node = find_node(count);
	}

}

// !!! Singly !!!

// !!! Doubly !!!

linked_list::doubly::Linked_List::Linked_List() {
	head = NULL;
	tail = NULL;
}

int linked_list::doubly::Linked_List::get_size() {
	return size;
}

bool linked_list::doubly::Linked_List::isEmpty() {
	if (size == 0)
		return 1;
	else
		return 0;
}

bool linked_list::doubly::Linked_List::isUpperLower(int& index) {
	// true if upper
	if (index > size / 2) {
		index = (size - index) + 1;
		return 1;
	}
	else
		return 0;
}

double_node::Node* linked_list::doubly::Linked_List::find_node(int index) {
	double_node::Node* current_node{ NULL };
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

void linked_list::doubly::Linked_List::push(double_node::Node* new_node) {

	if (isEmpty()) {
		head = new_node;
		tail = new_node;
	}
	new_node->set_next(head);
	head = new_node;

	size++;
}

void linked_list::doubly::Linked_List::push_back(double_node::Node* new_node) {
	if (isEmpty()) {
		head = new_node;
		tail = new_node;
	}
	new_node->set_prev(tail);
	tail = new_node;
	size++;
}

bool linked_list::doubly::Linked_List::insert(int index, const type data) {
	double_node::Node* new_node{ new double_node::Node(data) };
	double_node::Node* current_node{ nullptr };
	double_node::Node* prev_node{ nullptr };

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

bool linked_list::doubly::Linked_List::insert(const type data) {
	double_node::Node* new_node{ new double_node::Node(data) };
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
	double_node::Node* prev_node{ head };
	double_node::Node* current_node{ head->get_next() };

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

void linked_list::doubly::Linked_List::front(type& value) {
	double_node::Node* node{ head };
	value = node->get_data();
}

void linked_list::doubly::Linked_List::back(type& value) {
	double_node::Node* node{ tail };
	value = node->get_data();
}

bool linked_list::doubly::Linked_List::value_at(int index, type& value) {
	double_node::Node* current_node{ NULL };

	if (isEmpty())
		return 0;
	if (isUpperLower(index))
		current_node = find_node(index);
	else
		current_node = find_node(index);
	value = current_node->get_data();

	return 1;
}

void linked_list::doubly::Linked_List::pop_front() {
	double_node::Node* node{ head };

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

void linked_list::doubly::Linked_List::pop_back() {
	double_node::Node* node{ tail };
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

bool linked_list::doubly::Linked_List::remove(int index) {
	if (isEmpty() || index > size || index < 0)
		return 0;

	double_node::Node* current_node{ NULL };
	double_node::Node* prev_node{ NULL };
	double_node::Node* next_node{ NULL };

	if (index == 1) {
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

void linked_list::doubly::Linked_List::print() {

	double_node::Node* node{ nullptr };
	for (int count{ 1 }; count <= size; count++) {
		node = find_node(count);
	}
}

// !!! Doubly !!!

// !!! Queue !!!
linked_list::queue::queue::queue() {
	head = NULL;
}

bool linked_list::queue::queue::dequeue(type& data) {

	if (isEmpty())
		return 0;
	single_node::Node* first_node{ head };

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

bool linked_list::queue::queue::enqueue(const type data) {
	single_node::Node* new_node(new single_node::Node(data));
	single_node::Node* current_node{ nullptr };
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

bool linked_list::queue::queue::isEmpty() {
	if (size == 0)
		return 1;
	return 0;
}

int linked_list::queue::queue::get_size() {
	return size;
}

bool linked_list::queue::queue::peek(type& data) {
	if (isEmpty())
		return 0;

	data = head->get_data();

	return 1;
}

// !!! Queue !!!

// !!! Stack !!!

linked_list::stack::stack::stack() {
	head = NULL;
}

bool linked_list::stack::stack::push(const type data) {
	single_node::Node* new_node{ new single_node::Node(data) };
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

bool linked_list::stack::stack::pop(type& data) {
	if (isEmpty())
		return 0;

	single_node::Node* node{ head };
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

bool linked_list::stack::stack::peek(type& data) {
	if (isEmpty())
		return 0;

	data = head->get_data();

	return 1;
}

bool linked_list::stack::stack::isEmpty() {
	if (size == 0)
		return 1;
	return 0;
}

int linked_list::stack::stack::get_size() {
	return size;
}
// !!! Stack !!!

// !!! Trees !!!
trees::TT::TT::TT() {
	root = NULL;
}
bool trees::TT::TT::isEmpty() {
	if (count == 0)
		return 1;
	return 0;
}
int trees::TT::TT::get_size() {
	return count;
}
bool trees::TT::TT::insertLeaf(const type father,const type data) {
	// create a new node to insert
	tree_node::Node* new_leaf{ new tree_node::Node(data) };
	// if the tree is empty 
	if (isEmpty()) {
		root = new_leaf;
		count++;
		return 1;
	}
	// insertLeaf2 will only return either 0 or 1
	return insertLeaf2(root, father, new_leaf);
}

bool trees::TT::TT::insertLeaf2(tree_node::Node* root, const type father, tree_node::Node* son) {
	// if the current node is an empty node ( you have reached the end) of the tree
	if (root == NULL)
		return 0;
	// if the value in the node matches the value of the parent
	if (root->get_data() == father) {
		// check left first
		if (root->get_left() == NULL) {
			root->set_left(son);
			count++;
			// successful
			return 1;
		}
		if (root->get_right() == NULL) {
			root->set_right(son);
			count++;
			return 1;
		}
		// if both left and right has been occupied
		return 0;
	}
	// if insertion is successful, you end the recursion
	if(insertLeaf2(root->get_left(), father, son)) 
		return 1;
	// if its successful in one side, theres no need to check the other
	return insertLeaf2(root->get_right(), father, son);
}

void trees::TT::TT::TreeT(tree_node::Node* leaf) {
	if (isEmpty())
		return;
	TreeT(leaf->get_left());
	std::cout << leaf->get_data();
	TreeT(leaf->get_right());
}