#ifndef QUEUE_HPP
#define QUEUE_HPP

#include "QueueNode.hpp"
#include "Item.hpp"
class Queue {

private:
    //private members
    QueueNode* head;

public:
    //function prototypes
    Queue();
    bool isEmpty();
    void addBack(Item* itemValue);
    Item* getFront();
    void removeFront();
    void printQueue();
    bool checkQueue();
    ~Queue();
};

#endif //QUEUE_HPP
