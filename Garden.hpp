#ifndef GARDEN_HPP
#define GARDEN_HPP
#include "Space.hpp"
#include "menu.hpp"

class Garden : public Space {
private:
    Menu* menuGarden;
    Item* weed;
    Menu* menuMonsterYesNo;

    int fightChoice;
    int monsterHealth;


public:
    Garden();
    int action(int num, Space *&curSpace, Queue *&curBackpack) override;
    void printMap() override;
    void printMenu() override;
    virtual ~Garden();
};

#endif //GARDEN_HPP
