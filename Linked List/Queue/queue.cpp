#include "queue.h"
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
  Node* current_node{head};
  head = current_node ->get_next();

}
