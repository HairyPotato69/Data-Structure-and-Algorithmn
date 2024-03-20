#pragma once
#ifndef linked_list_type
#define linked_list_type
#include "node.h"
#include <cstdlib> // #include <stdlib.h>

class Linked_List {
	private:
		Node* head{};
		Node* tail{};
		int size{};
	public:
		Linked_List();
		int get_size();
		bool isEmpty();
		Node* find_node(const int index);
		void push(Node* new_node);
		void push_back(Node* new_node);
		bool insert(int index, const type data);
		bool insert(const type data);
		// get data
		void front(type& value);
		void back(type& value);
		bool value_at(const int index, type& value);
		// delete node
		void pop_front();
		//void pop_back();
		bool remove(const int index);
		// print
		void print();
	};

#endif // linked_list_type
