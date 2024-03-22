# Data Structure and Algorithmn
 Contains references to learn DSA and coding samples in different languages

> We are computer science students looking to improve our DSA and programming skills. This repository contains resources to learn programming languages and sample coding for different data structure and algorithms

# So, what is this?
This repository serves as a reference for DSA. 

**Main** branch will store concepts and theories on DSA. Refer to **Python** branch for coding in `.py` format, **C++** branch is for coding in `.cpp` format.

# Topics
- [Data Structures](#data-structures)
  - [Linked list](#linked-list)
  - [Queue](#queue)
  - [Stack](#stack)
  - [Tree](#tree)
- [Algorithms](#Algorithms)

# Data Structures
## Linked List
It is the fundamental data structure and should be mastered before venturing into other structures. Once this is mastered, you think think of other structures as linked list but with _extra steps_.
![basic linked list](https://github.com/HairyPotato69/Data-Structure-and-Algorithmn/blob/main/Images/Linked%20list/linked%20list.png)
_basic linked list_

**Why?**
1. Dynamic data structure
2. Easier to update or delete
3. Memory usage efficiency
4. Implementation of more advanced structures uses linked list

**Composition**
1. Node
   - Data: holds value or data associated with the node
   - Next: holds address of the next node
   - Previous (optional): holds address of the previous node
2. Head: points to the first node in the linked list
3. Tail: points to the final node in the linked list

**Types of linked list**
1. Singly Linked List
2. Doubly Linked List
3. Circular doubly linked list
4. Queue
5. Stack
 
**Basic operations**
1. Inserting values
![Insertion](https://github.com/HairyPotato69/Data-Structure-and-Algorithmn/blob/main/Images/Linked%20list/insertion.png)
    - push_front: Adding node to the front of the list
    - push_back: Adding node to the back of the list
    - insert: Adding node to the middle of the list
    - insert: Adding node in an orderly manner, given that the list is in orderly manner
3. Deleting values
![Deletion](https://github.com/HairyPotato69/Data-Structure-and-Algorithmn/blob/main/Images/Linked%20list/deletion.png)
   - pop_front: Removing the first node of the list
   - pop_back: Removing the last node of the list
   - remove: Removing the node in the middle of the list (index)
   - remove: Remove the first node that matches the value
5. Retrieving values
   - front: Get value from the first node of the list
   - back: Get value from the final node of the list
   - value_at: Get value from the node in the middle of the list
6. Retrieve node
   - find node: find node based on the index given
7. Reverse: reverses the list

## Queue
![Basic queue](https://github.com/HairyPotato69/Data-Structure-and-Algorithmn/blob/main/Images/Linked%20list/queue.png)
It is essentially linked list but with restrictions. Queue has FIFO (_first in first out_) and LILO (_last in last out_) characteristics. <br>
For example, the first data you insert into a queue will also be the first data to leave the queue. 
To put into perspective, imagine a queue at a cinema. The first person to enter the queue will be the first to enter/leave. _simple queue_ 

**Types of Queue**
1. Simple Queue
2. Circular Queue
3. Double Ended Queue
4. Priority Queue
   - Ascending Priority Queue
   - Descending Priority Queue

**Basic operations**
1. Enqueue: Inserting node into the end of the queue 
2. Dequeue: Removing the node at the front of the queue and return its value
3. isEmpty: Determine if the queue is empty
4. Peek: Retrieving the value of the front node without removing it

## Stack
![Basic Stack](https://github.com/HairyPotato69/Data-Structure-and-Algorithmn/blob/main/Images/Linked%20list/stack.png)
It is also a linked list but with restriction. Stack has FILO (_first in last out_) and LIFO (_last in first out_) characteristics. <br>
For example, the first data you insert into a stack will be the last data to leave the stack. 
To put into perspective, imagine a pile of clothes. You add clothes to the top of the stack (_most recently added data/last in_) and take clothes from the top of the stack (_first out_)

**Basic operations**
1. push: Adding node to the top of the stack
2. pop: Removing the node from the top of the stack and return its value
3. top: Retrieving the value of the top most node of the stack without removing it
4. isEmpty: Determine if the stack is empty
5. size: Determine the number of nodes in the stack

## Tree

# Algorithms
