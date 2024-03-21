#ifndef queue_type
#define queue_type 

// Uses the same node from singly linked list
#include "node.h"

class Queue{
    private:
        int size{};
        Node* head{};
    public:
        Queue();
        bool dequeue(type data);
        bool enqueue();
        bool isEmpty();
        int getSize();
};
#endif
