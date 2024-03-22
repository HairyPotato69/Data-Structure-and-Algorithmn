#pragma once
#ifndef linked_list_type
#define linked_list_type
#include "node.hpp"
#include <cstdlib> // #include <stdlib.h>

namespace linked_list {
	namespace singly {

		class Linked_List {
		private:
			single_node::Node* head{};
			single_node::Node* tail{};
			int size{};
		public:
			Linked_List();
			int get_size();
			bool isEmpty();
			single_node::Node* find_node(const int index);
			void push(single_node::Node* new_node);
			void push_back(single_node::Node* new_node);
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
	}

	namespace doubly {
		class Linked_List
		{
		private:

			double_node::Node* head{};
			double_node::Node* tail{};
			int size{};
		public:
			Linked_List();
			int get_size();
			bool isEmpty();
			bool isUpperLower(int& index);
			double_node::Node* find_node(int index);

			// insert node
			void push(double_node::Node* new_node);
			void push_back(double_node::Node* new_node);
			bool insert(int index, const type data);
			bool insert(const type data);
			// get data
			void front(type& value);
			void back(type& value);
			bool value_at(int index, type& value);
			// delete node
			void pop_front();
			void pop_back();
			bool remove(int index);
			// print
			void print();

		};

	}

	// Uses node from singly linked list

	namespace queue {
		class queue {
		private:
			single_node::Node* head{};
			int size{};
		public:
			queue();
			bool dequeue(type& data);
			bool enqueue(const type data);
			bool peek(type& data);
			bool isEmpty();
			int get_size();
		};
	}

	namespace stack {
		class stack {
		private:
			single_node::Node* head{};
			int size{};
		public:
			stack();
			bool push(const type data);
			bool pop(type& data);
			bool peek(type& data);
			bool isEmpty();
			int get_size();
		};

	}
}

#endif // linked_list_type
