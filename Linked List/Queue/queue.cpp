#include "queue.hpp"
#include <iostream>

int Queue::getSize(){
  return size;
}

bool Queue::isEmpty(){
  if (size == 0)
    return 1;
  else
    return 0;
}

bool Queue::dequeue(type data){
  if (isEmpty())
    return 0;
  Node* current_node{head};
  head = current_node->get_next();
  data = current_node->get_data();
  delete current_node;
  return 1;
}
