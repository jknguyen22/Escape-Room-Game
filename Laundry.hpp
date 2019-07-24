#ifndef LAUNDRY_HPP
#define LAUNDRY_HPP

#include "Space.hpp"
#include "menu.hpp"

class Laundry : public Space {
private:

    Menu* menuLaundry;
    Item* sock;
    Menu* menuLaundryYesNo;
    Menu* menuLaundryChoice;

    int clothes [4] = { 10, 5, 4, 2};


public:
    Laundry();
    int action(int num, Space *&curSpace, Queue *&curBackpack) override;
    void printMap() override;
    void printMenu() override;
    virtual ~Laundry();
};


#endif //LAUNDRY_HPP
