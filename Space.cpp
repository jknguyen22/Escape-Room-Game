#include "Space.hpp"
/**
    Base class Space constructor
    @param none
    @return none
*/
Space::Space(){
    Space* north = nullptr;
    Space* east = nullptr;
    Space* south = nullptr;
    Space* west = nullptr;
    roomCompleted = false;
}
/**
    set all north wall to a viable exit
    @param none
    @return none
*/
void Space::setNorth(Space* direction){
    north = direction;
}
/**
    set all east wall to a viable exit
    @param none
    @return none
*/
void Space::setEast(Space* direction){
    east = direction;
}
/**
    set all south wall to a viable exit
    @param none
    @return none
*/
void Space::setSouth(Space* direction){
    south = direction;
}
/**
    set all west wall to a viable exit
    @param none
    @return none
*/
void Space::setWest(Space* direction){
    west = direction;
}

/**
    virtual action method for derived classes
    @param none
    @return none
*/
int Space::action(int num, Space *&curSpace, Queue *&curBackpack) {

}
void Space::printMenu(){

}
/**
    checks if the task of a room has been completed
    @param none
    @return bool
*/
bool Space::isRoomCompleted(){
    if (roomCompleted == true){
         return true;
    }
    else{
        return false;
    }
}
/**
    space destructor
    @param none
    @return none
*/
Space::~Space(){
    delete north;
    delete east;
    delete south;
    delete west;
}
