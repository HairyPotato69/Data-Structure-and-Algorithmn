#ifndef queue_type
#define queue_type 

#include "node.h"


class queue{
    private:
        int size{};
        Node* head{};
    public:
        bool dequeue(type data);
        bool enqueue();
        bool isEmpty();
        int getSize();
};
#endif
