#include "Garden.hpp"

using std::cout;

/**
    garden constructor
    @param none
    @return none
*/
Garden::Garden() {
    monsterHealth = 10;

    weed = new Item(5);

    menuGarden = new Menu;
    menuGarden->setTitle("You're in the garden. Where do you want to go?");
    menuGarden->addPrompt("UP");
    menuGarden->addPrompt("RIGHT");
    menuGarden->addPrompt("DOWN");
    menuGarden->addPrompt("LEFT");
    menuGarden->addPrompt("BACKPACK");
    menuGarden->addPrompt("HELP");
    menuGarden->addPrompt("EXIT GAME");

    menuMonsterYesNo = new Menu;
    menuMonsterYesNo->setTitle("Do you want to attack it?");
    menuMonsterYesNo->addPrompt("Yes");
    menuMonsterYesNo->addPrompt("No");

}
/**
    garden virtual action method
    @param int, Space*&, Queue*&
    @return none
*/
int Garden::action(int num, Space *&curSpace, Queue *&curBackpack) {
    if(num == 1){

    }
    else if(num == 2){
        cout << "You exit the garden.\n";
        curSpace = east;
    }
    else if (num==3){
        if (roomCompleted){
            cout << "You look at the giant hole in the garden. This is where you defeated the monster\n"
                    "weed.\n";
        }
        else if(!roomCompleted){
            cout << "The 10 ft. tall monster weed roars at you. You must defeat it.\n"
                    "Monster Weed's HP: " << monsterHealth << '\n';

            fightChoice = 3;
            while (fightChoice > 2 || fightChoice < 1){
                menuMonsterYesNo->display();
                cout << "You must select an integer from 1 to 2.\n";
                fightChoice = integerValidation();
            }
            if(fightChoice == 1){
                int rollFirst = (rand() % 3) + 1;
                if (rollFirst == 1 || rollFirst == 2){
                    if((monsterHealth-2) <= 0){
                        monsterHealth = 0;
                        cout << "You attack it with your fists!\n";
                        cout << "The monster weed's HP is " << monsterHealth << '\n';

                    }
                    else{
                        monsterHealth -= 2;
                        cout << "You attack it with your fists!\n";
                        cout << "The monster weed's HP is " << monsterHealth << '\n';

                    }

                }
                else if (rollFirst == 3){
                    if((monsterHealth - 5)<= 0){
                        monsterHealth = 0;
                        cout << "You attack it with your signature DROP KICK!\n";
                        cout << "The monster weed's HP is " << monsterHealth << '\n';

                    }
                    else{
                        monsterHealth -= 5;

                        cout << "You attack it with your signature DROP KICK!\n";
                        cout << "The monster weed's HP is " << monsterHealth << '\n';

                    }
                }
                if(monsterHealth <= 0){
                    cout << "You defeated the monster weed!\n";

                    curBackpack->addBack(weed);
                    cout << "You add the root of the monster weed to your backpack.\n";

                    roomCompleted = true;
                }
            }
            else if (fightChoice == 2){
                cout << "You chose to not attack it.\n";
            }

        }

    }
    else if (num==4){
        cout << "You exit the garden.\n";
        curSpace = west;
    }
}
/**
    display map method
    @param none
    @return none
*/
void Garden::printMap(){
    std::cout << "\n#########################################################################\n"
                 "##########           OUTSIDE             ################################\n"
                 "#######################  ################################################\n"
                 "#######################  #################################          #####\n"
                 "################                 ####       1       ######          #####\n"
                 "################                 ####               ######          #####\n"
                 "##         #####     LIVING      ####              2                #####\n"
                 "##  BED               ROOM           4   GARDEN     ######          #####\n"
                 "##         #####                 ####      *        ######   POND   #####\n"
                 "################                 ####               ######          #####\n"
                 "################                 ####       3       ######          #####\n"
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
void Garden::printMenu() {
    menuGarden->display();
}
/**
    virtual destructor
    @param none
    @return none
*/
Garden::~Garden(){

    delete weed;
    delete menuGarden;
    delete menuMonsterYesNo;

}