#ifndef queue_type
#define queue_type 

// Uses the same node from singly linked list
#include "node.hpp"

class Queue{
    private:
        int size{};
        Node* head{};
    public:
        Queue();
        bool dequeue(type& data);
        bool enqueue(const type data);
        bool peek(type& data);
        bool isEmpty();
        int getSize();
};
#endif
