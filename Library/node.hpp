#pragma once
#ifndef node_type
#define node_type

using type = int;

namespace single_node {

	class Node {

	private:
		type data{};
		Node* next{};
	public:
		Node(const type data);
		type get_data();
		Node* get_next();
		void set_next(Node* next);
		void set_data(const type data);
	};

}

namespace double_node {
	class Node {
	private:
		type data{};
		Node* next{};
		Node* previous{};
	public:
		Node(const type data);
		type get_data();
		Node* get_next();
		Node* get_prev();
		void set_next(Node* next);
		void set_prev(Node* prev);
		void set_data(const type data);
	};
}

namespace tree_node {
	class Node {
	private:
		type data{};
		Node* root{};
		Node* ancestor{};
		Node* left{};
		Node* right{};
	public:
		Node(const type data);

		type get_data();
		Node* get_root();
		Node* get_ancestor();
		Node* get_left();
		Node* get_right();
		void set_data(const type data);
		void set_root(Node* root);
		void set_left(Node* left);
		void set_right(Node* right);
	};
}

#endif
