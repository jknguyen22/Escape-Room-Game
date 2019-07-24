#include "QueueNode.hpp"
/**
    QueueNode constructor that sets an integer
    as its value
    @param integer
    @return none
*/
QueueNode::QueueNode(Item* itemValue) {
    val = itemValue;
    next = nullptr;
    prev = nullptr;
}
/**
    QueueNode destructor
    @param integer
    @return none
*/
QueueNode::~QueueNode(){
//    delete val;
}