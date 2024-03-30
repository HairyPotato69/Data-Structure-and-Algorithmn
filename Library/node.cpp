#include "node.hpp"
#include <cstdlib>

single_node::Node::Node(const type data) {
	this->data = data;
	next = NULL;
}

type single_node::Node::get_data() {
	return data;
}

single_node::Node* single_node::Node::get_next() {
	return next;
}

void single_node::Node::set_data(const type data) {
	this->data = data;
}

void single_node::Node::set_next(Node* next) {
	this->next = next;
}


double_node::Node::Node(const type data) {
	this->data = data;
	next = NULL;
	previous = NULL;
}

type double_node::Node::get_data() {
	return data;
}

double_node::Node* double_node::Node::get_next() {
	return next;
}

double_node::Node* double_node::Node::get_prev() {
	return previous;
}

void double_node::Node::set_data(const type data) {
	this->data = data;
}
void double_node::Node::set_next(Node* next) {
	this->next = next;
}

void double_node::Node::set_prev(Node* prev)
{
	this->previous = prev;
}
