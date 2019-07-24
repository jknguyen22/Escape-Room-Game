#ifndef BEDROOM_HPP
#define BEDROOM_HPP
#include "Space.hpp"
#include "menu.hpp"

class BedRoom : public Space {
private:
    Menu* menuBedRoom;
    Menu* menuHomework;
    int homeworkChoice;
    int homeworkAnswer;
    Item* homework;

public:
    BedRoom();
    int action(int num, Space *&curSpace, Queue *&curBackpack) override;
    void printMap() override;
    void printMenu() override;

    virtual ~BedRoom();
};

#endif //BEDROOM_HPP
