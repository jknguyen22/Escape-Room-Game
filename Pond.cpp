#include "Pond.hpp"

using std::cout;
/**
    pond constructor
    @param none
    @return none
*/
Pond::Pond() {
    fish = new Item(6);

    menuPond = new Menu;
    menuPond->setTitle("You're in the pond. Where do you want to go?");
    menuPond->addPrompt("UP");
    menuPond->addPrompt("RIGHT");
    menuPond->addPrompt("DOWN");
    menuPond->addPrompt("LEFT");
    menuPond->addPrompt("BACKPACK");
    menuPond->addPrompt("HELP");
    menuPond->addPrompt("EXIT GAME");

    menuPondYesNo = new Menu;
    menuPondYesNo->setTitle("You see a fishing rod. Do you want to fish?");
    menuPondYesNo->addPrompt("Yes");
    menuPondYesNo->addPrompt("No");

}
/**
    pond virtual action method
    @param int, Space*&, Queue*&
    @return none
*/
int Pond::action(int num, Space *&curSpace, Queue *&curBackpack) {
    if(num == 1){
        if(!roomCompleted){
            fishingChoice = 3;
            while (fishingChoice > 2 || fishingChoice < 1){
                menuPondYesNo->display();
                cout << "You must select an integer from 1 to 2.\n";
                fishingChoice = integerValidation();
            }
            if (fishingChoice == 1){
                cout << "You decide to fish.\n";
                int rollFirst = (rand() % 10) + 1;

                cout << "You rolled: " << rollFirst << '\n';

                if(rollFirst >= 1 && rollFirst <= 6){
                    cout << "You got a SMALL fish.\n";
                    cout << "Yikes! This one isn't big enough for dinner!\n"
                            "You throw the SMALL fish back into the pond.\n";
                }
                else if(rollFirst >= 7 && rollFirst <= 9){
                    cout << "You got a MEDIUM fish.\n";
                    cout << "Yikes! This one isn't big enough for dinner!\n"
                            "You throw the MEDIUM fish back into the pond.\n";
                }
                else if (rollFirst == 10){
                    cout << "You got a LARGE fish.\n";
                    cout << "Yay!!! This one is definitely big enough for dinner!\n"
                            "You pack the LARGE fish into your backpack.\n";
                    curBackpack->addBack(fish);

                    roomCompleted = true;
                }
            }
            else if (fishingChoice ==2){
                cout << "You decide not to fish.\n";
            }

        }
        else if(roomCompleted){
            cout << "Looks like you've already caught a big enough fish for dinner tonight.\n"
                    "There's nothing left to do here but enjoy the nature.\n";
        }
    }
    else if(num == 2){
        cout << "You see a fence, there’s nothing interesting here.\n";
    }
    else if (num==3){
        cout << "You can't go over there. That's the deep end of the pond.\n";
    }
    else if (num==4){
        cout << "You exit the pond.\n";
        curSpace = west;
    }
}
/**
    display map method
    @param none
    @return none
*/
void Pond::printMap(){
    std::cout << "\n#########################################################################\n"
                 "##########           OUTSIDE             ################################\n"
                 "#######################  ################################################\n"
                 "#######################  #################################     1    #####\n"
                 "################                 ####               ######          #####\n"
                 "################                 ####               ######          #####\n"
                 "##         #####     LIVING      ####                     4         #####\n"
                 "##  BED               ROOM               GARDEN     ######          #####\n"
                 "##         #####                 ####               ######   POND   #####\n"
                 "################                 ####               ######     *   2#####\n"
                 "################                 ####               ######          #####\n"
                 "#######################  #################################          #####\n"
                 "#######################  #################################          #####\n"
                 "#########                            ###          ########          #####\n"
                 "#########                            ###          ########     3    #####\n"
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
void Pond::printMenu() {
    menuPond->display();
}
/**
    virtual destructor
    @param none
    @return none
*/
Pond::~Pond(){
    delete fish;

    delete menuPond;
    delete menuPondYesNo;

}