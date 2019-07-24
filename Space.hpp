#ifndef SPACE_HPP
#define SPACE_HPP
#include <iostream>
#include "utility.hpp"
#include "Queue.hpp"
#include "Item.hpp"

using std::string;

class Space {

protected:
    Space* north;
    Space* east;
    Space* south;
    Space* west;

    string name;
    bool roomCompleted;

public:
    Space();
    virtual void setNorth(Space* direction);
    virtual void setEast(Space* direction);
    virtual void setSouth(Space* direction);
    virtual void setWest(Space* direction);

    virtual void printMap() = 0;
    virtual int action(int num, Space *&curSpace, Queue *&curBackpack) = 0;
    virtual void printMenu() = 0;
    bool isRoomCompleted();
    virtual ~Space();

};


#endif //SPACE_HPP
