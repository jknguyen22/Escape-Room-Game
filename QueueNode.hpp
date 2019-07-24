#ifndef QUEUENODE_HPP
#define QUEUENODE_HPP

#include "Item.hpp"

//structure for nodes in queue
struct QueueNode {
    //everything is public in structs
    QueueNode* next;
    QueueNode* prev;
    Item* val;
    QueueNode(Item* itemValue);
    ~QueueNode();
};


#endif //QUEUENODE_HPP
