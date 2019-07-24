#ifndef LIVINGROOM_HPP
#define LIVINGROOM_HPP
#include "Space.hpp"
#include "menu.hpp"
#include "game.hpp"

class LivingRoom : public Space {
private:
    Menu* menuLivingRoom;

public:
    LivingRoom();
    int action(int num, Space *&curSpace, Queue *&curBackpack) override;
    void printMap() override;
    void printMenu() override;
    virtual ~LivingRoom();
};

#endif //LIVINGROOM_HPP
