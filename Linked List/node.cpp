#include "node.h"
#include <cstdlib>

singly::Node::Node(const type data) {
	this->data = data;
	next = NULL;
}

type singly::Node::get_data() {
	return data;
}

singly::Node* singly::Node::get_next() {
	return next;
}

void singly::Node::set_data(const type data) {
	this->data = data;
}

void singly::Node::set_next(Node* next) {
	this->next = next;
}


doubly::Node::Node(const type data) {
	this ->data = data;
	next = NULL;
	previous = NULL;
}

type doubly::Node::get_data() {
	return data;
}

doubly::Node* doubly::Node::get_next() {
	return next;
}

doubly::Node* doubly::Node::get_prev() {
	return previous;
}

void doubly::Node::set_data(const type data) {
	this->data = data;
}
void doubly::Node::set_next(Node* next) {
	this->next = next;
}
