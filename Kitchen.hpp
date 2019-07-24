#ifndef KITCHEN_HPP
#define KITCHEN_HPP
#include "Space.hpp"
#include "menu.hpp"

class Kitchen : public Space {
private:
    Menu* menuKitchen;
    Item* spoon;
    Menu* menuCereal;
    Menu* menuCerealSteps;

    int cerealChoice;
    int cerealStepsChoice;

public:
    Kitchen();
    int action(int num, Space *&curSpace, Queue *&curBackpack) override;
    void printMap() override;
    void printMenu() override;
    ~Kitchen();
};


#endif //KITCHEN_HPP
