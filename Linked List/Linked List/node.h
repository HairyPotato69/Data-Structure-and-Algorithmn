#pragma once
#ifndef node_type
#define node_type

using type = int;

namespace singly {

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

namespace doubly {
	class Node {
	private:
		type data{};
		Node* next{};
		Node* previous{};
	public:
		Node(const type data);
		type get_data();
		Node* get_next();
		void set_next();
		void set_data();
	};
}

#endif