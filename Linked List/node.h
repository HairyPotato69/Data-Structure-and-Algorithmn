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
		Node(int data);
	};

}

#endif