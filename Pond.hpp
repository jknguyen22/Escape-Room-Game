#ifndef POND_HPP
#define POND_HPP
#include "Space.hpp"
#include "menu.hpp"

class Pond : public Space {
private:

    Menu* menuPond;
    Item* fish;

    Menu* menuPondYesNo;

    int fishingChoice;
public:
    Pond();
    int action(int num, Space *&curSpace, Queue *&curBackpack) override;
    void printMap() override;
    void printMenu() override;
    virtual ~Pond();
};


#endif //POND_HPP
