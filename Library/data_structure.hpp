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

namespace tree {
	namespace TT {
		class TT {
		public:
			tree::Node* root{};
			int count{};
		private:
			// 
			TT();
			bool isEmpty();
			int get_size();
			// When inserting, you have two functions
			/*
				One is to handle an empty tree
				The other is for recursion
			*/
			bool insertLeaf(const type father, const type data);
			bool insertLeaf2(tree::Node* root, const type father, tree::Node* son);
			bool BFS();
			void TreeT(tree::Node* leaf);
		};
	}
	namespace BST {
		class BST {
		public:
			tree::Node* root{};
			int count{};
		private:
			BST();
			bool isEmpty();
			int get_size();
			// when inserting, you have two functions
			/*
				One is to handle an empty tree
				The other is for recursion
			*/
			bool insertLeaf(const type data);
			bool insertLeaf2(tree::Node* root, tree::Node* son);
			void BSTT(tree::Node* leaf, const type data);
			bool removeLeaf(const type data);
			bool removeLeaf2(tree::Node* previous, tree::Node* current, const type data);
			bool case2(tree::Node* previous, tree::Node* current);
			bool case3(tree::Node* current);
		};
	}
	namespace AVL {
		class AVL {
		};
	}
}

#endif // linked_list_type
