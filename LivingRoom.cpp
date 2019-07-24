#include "LivingRoom.hpp"

using std::cout;
/**
    livingroom constructor
    @param none
    @return none
*/
LivingRoom::LivingRoom() {
    menuLivingRoom = new Menu;
    menuLivingRoom->setTitle("You're in the living room. Where do you want to go?");
    menuLivingRoom->addPrompt("UP");
    menuLivingRoom->addPrompt("RIGHT");
    menuLivingRoom->addPrompt("DOWN");
    menuLivingRoom->addPrompt("LEFT");
    menuLivingRoom->addPrompt("BACKPACK");
    menuLivingRoom->addPrompt("HELP");
    menuLivingRoom->addPrompt("EXIT GAME");
}
/**
    livingroom virtual action method
    @param int, Space*&, Queue*&
    @return none
*/
int LivingRoom::action(int num, Space *&curSpace, Queue *&curBackpack) {
    //direction: up
    if (num == 1 ){
        cout << "Hello my boy! Ah! It looks like you’re trying to leave. Let me do a quick check if you\n"
                "finished all of the chores I requested of you...";
        if(curBackpack->checkQueue() == true){
            cout << "Looks like you finished all the tasks!\n";
//            curSpace = north;
        }
        else if (curBackpack->checkQueue() == false){
            cout << "Looks like you haven't finished all the tasks yet!\n";
        }
    }
        //direction: right
    else if (num == 2){
        cout << "You exit the living room.";
        curSpace = east;
    }
        //direction: down
    else if (num == 3){
        cout <<"You exit the living room.";
        curSpace = south;
    }
        //direction: left
    else if (num == 4){
        cout << "You exit the living room.";
        curSpace = west;
    }
}
/**
    display map method
    @param none
    @return none
*/
void LivingRoom::printMap(){
    std::cout << "\n#########################################################################\n"
                 "##########           OUTSIDE             ################################\n"
                 "#######################  ################################################\n"
                 "#######################  #################################          #####\n"
                 "################        1        ####               ######          #####\n"
                 "################                 ####               ######          #####\n"
                 "##         #####     LIVING      ####                               #####\n"
                 "##  BED         4     ROOM*     2        GARDEN     ######          #####\n"
                 "##         #####                 ####               ######   POND   #####\n"
                 "################                 ####               ######          #####\n"
                 "################        3        ####               ######          #####\n"
                 "#######################  #################################          #####\n"
                 "#######################  #################################          #####\n"
                 "#########                            ###          ########          #####\n"
                 "#########                            ###          ########          #####\n"
                 "#########          KITCHEN                LAUNDRY #######################\n"
                 "#########                            ###          #######################\n"
                 "#########                            ###          #######################\n"
                 "#########################################################################\n"
                 "#########################################################################\n";
}
/**
    display menu method
    @param none
    @return none
*/
void LivingRoom::printMenu(){
    menuLivingRoom->display();
}
/**
    virtual destructor
    @param none
    @return none
*/
LivingRoom::~LivingRoom(){
    delete menuLivingRoom;

}
