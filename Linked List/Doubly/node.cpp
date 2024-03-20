#include "node.h"
#include <cstdlib>

Node::Node(const type data) {
	this ->data = data;
	next = NULL;
	previous = NULL;
}

type Node::get_data() {
	return data;
}

Node* Node::get_next() {
	return next;
}

Node* Node::get_prev() {
	return previous;
}

void Node::set_data(const type data) {
	this->data = data;
}
void Node::set_next(Node* next) {
	this->next = next;
}

void Node::set_prev(Node* prev)
{
	this->previous = prev;
}
