Node::Node(const type data) {
	this->data = data;
	next = NULL;
}

type Node::get_data() {
	return data;
}

Node* Node::get_next() {
	return next;
}

void Node::set_data(const type data) {
	this->data = data;
}

void Node::set_next(Node* next) {
	this->next = next;
}

