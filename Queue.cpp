#include <iostream>
#include "Queue.hpp"
#include "QueueNode.hpp"

using std::cout;
/**
    Queue constructor that sets head to NULL
    @param none
    @return none
*/
Queue::Queue(){
    head = nullptr;
}
/**
    checks if head is NULL
    @param none
    @return bool
*/
bool Queue::isEmpty(){
    if (head == nullptr){
        return true;    //true for empty Q
    }
    else if ( head != nullptr){
        return false;   //false for non-empty Q
    }
}
/**
    creates a new node to the list with passed value
    @param int
    @return none
*/
void Queue::addBack(Item* itemValue){
    if(isEmpty()){

        QueueNode* newNode =  new QueueNode(itemValue);
        newNode->next= newNode;
        newNode->prev = newNode;
        head = newNode;
        return;
    }
    else if (!isEmpty()){

        QueueNode* lastNode = head->prev;

        QueueNode* newNode = new QueueNode(itemValue);
        newNode->next= head;
        head->prev = newNode;
        newNode->prev = lastNode;
        lastNode->next = newNode;

    }
}
/**
    Queue constructor that sets head to NULL
    @param none
    @return none
*/
//https://www.geeksforgeeks.org/circular-linked-list-set-2-traversal/
Item* Queue::getFront(){
    if(isEmpty()){
        cout << "Backpack is empty\n";
    }
    else if (!isEmpty()){
        return head->val;
    }
}
/**
    deletes front node
    @param none
    @return none
*/
void Queue::removeFront() {
    if(isEmpty()){
        cout << "Queue is empty!\n";
    }
    else if (!isEmpty()){
        if (head->next == head || head->next == nullptr){
            delete head;
            head = nullptr;
        }
        else{
            QueueNode* temp = head->next;
            //ref https://stackoverflow.com/questions/37596049/is-p-next-prev-the-same-as-p
            head->next->prev = head->prev;
            head->prev->next = head->next;

            delete head;
            head = nullptr;
            head = temp;
        }
    }

}
/**
    prints queue list
    @param none
    @return none
*/
void Queue::printQueue(){
    if(isEmpty()){
        cout << "Backpack is empty!\n";

    }
    else if (!isEmpty()){
        QueueNode* temp = head;
        cout << "Backpack: \n";
        do{
            if (temp->val->getItemNumber() == 1){
                cout << "Mom's Note\n";
                temp = temp->next;
            }
            else if (temp->val->getItemNumber() == 2){
                cout << "Completed Homework\n";
                temp = temp->next;
            }
            else if (temp->val->getItemNumber() == 3){
                cout << "Cereal Spoon\n";
                temp = temp->next;
            }
            else if (temp->val->getItemNumber() == 4){
                cout << "Clean socks\n";
                temp = temp->next;
            }
            else if (temp->val->getItemNumber() == 5){
                cout << "Weed root\n";
                temp = temp->next;
            }
            else if (temp->val->getItemNumber() == 6){
                cout << "Big fish\n";
                temp = temp->next;
            }

        }
        while((temp != head));
    }
    cout << '\n';
}
/**
    bool method that checks all tasks
    @param none
    @return bool
*/
bool Queue::checkQueue(){
    bool item1 = false;
    bool item2 = false;
    bool item3 = false;
    bool item4 = false;
    bool item5 = false;
    bool item6 = false;
    if(isEmpty()){
        cout << "Backpack is empty!\n";

    }
    else if (!isEmpty()){
        QueueNode* temp = head;

        cout << "\nBackpack: \n";
        do{
            if (temp->val->getItemNumber() == 1){
                cout << "Mom's Note\n";
                item1 = true;
                temp = temp->next;
            }
            else if (temp->val->getItemNumber() == 2){
                cout << "Completed Homework\n";
                item2 = true;
                temp = temp->next;
            }
            else if (temp->val->getItemNumber() == 3){
                cout << "Cereal Spoon\n";
                item3 = true;
                temp = temp->next;
            }
            else if (temp->val->getItemNumber() == 4){
                cout << "Clean socks\n";
                item4 = true;
                temp = temp->next;
            }
            else if (temp->val->getItemNumber() == 5){
                cout << "Weed root\n";
                item5 = true;
                temp = temp->next;
            }
            else if (temp->val->getItemNumber() == 6){
                cout << "Big fish\n";
                item6 = true;
                temp = temp->next;
            }

        }
        while((temp != head));
    }
    cout << '\n';
    if ((item1) && (item2 )&& (item3) && (item4) && (item5) && (item6)){
        return true;
    }
    else{
        return false;
    }
}
/**
    Queue destructor that uses removeFront method
    @param none
    @return none
*/
Queue::~Queue(){
    while(head != nullptr){
        removeFront();
    }
}