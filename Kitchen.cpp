#include "Kitchen.hpp"

using std::cout;
/**
    kitchen constructor
    @param none
    @return none
*/
Kitchen::Kitchen() {

    spoon = new Item(3);

    menuKitchen = new Menu;
    menuKitchen->setTitle("You're in the kitchen. Where do you want to go?");
    menuKitchen->addPrompt("UP");
    menuKitchen->addPrompt("RIGHT");
    menuKitchen->addPrompt("DOWN");
    menuKitchen->addPrompt("LEFT");
    menuKitchen->addPrompt("BACKPACK");
    menuKitchen->addPrompt("HELP");
    menuKitchen->addPrompt("EXIT GAME");

    menuCereal = new Menu;
//    menuCereal->getTitle().assign("You see the milk and cereal sitting on the countertop. Do you want to make cereal?");
    menuCereal->setTitle("You see the milk and cereal sitting on the countertop. Do you want to make cereal?");
    menuCereal->addPrompt("Yes");
    menuCereal->addPrompt("No");

    menuCerealSteps = new Menu;
    menuCerealSteps->setTitle("You grab a bowl. What do you do next?");
    menuCerealSteps->addPrompt("Pour milk into the bowl.");
    menuCerealSteps->addPrompt("Pour dry cereal into the bowl.");


}
/**
    kitchen virtual action method
    @param int, Space*&, Queue*&
    @return none
*/
int Kitchen::action(int num, Space *&curSpace, Queue *&curBackpack) {
    if(num == 1){
        cout << "You exit the kitchen.\n";
        curSpace = north;
    }
    else if(num == 2){
        cout << "You exit the kitchen.\n";
        curSpace = east;
    }
    else if (num==3){
        if(!roomCompleted){
            cerealChoice = 3;
            while (cerealChoice > 2 || cerealChoice < 1){
                menuCereal->display();
                cout << "You must select an integer from 1 to 2.\n";
                cerealChoice = integerValidation();
            }
            if (cerealChoice == 1){
                cerealStepsChoice = 3;
                cout << "You decide to make cereal.\n";

                while(cerealStepsChoice > 2 || cerealStepsChoice < 1){
                    menuCerealSteps->display();
                    cout << "You must select an integer from 1 to 2.\n";
                    cerealStepsChoice = integerValidation();
                }
                if(cerealStepsChoice == 1){
                    cout << "You pour milk first into the bowl. Then you pour the dry cereal into the \n"
                            "bowl. You start to realize this was a mistake and your mind goes blank. \n"
                            "You throw the abomination into the trash. You did not successfully make\n"
                            "or eat cereal.\n";
                }
                else if(cerealStepsChoice == 2){
                    cout << "You pour the dry cereal first into the bowl. Then you pour the milk into \n"
                            "the bowl. Of course you remembered that this is the proper way to make\n"
                            "cereal. You eat your cereal. Delicious.\n";

                    curBackpack->addBack(spoon);
                    cout << "You pack your dirty cereal spoon into your backpack as proof to your\n"
                            "mother you had cereal.\n";

                    roomCompleted = true;
                }

            }
            else if (cerealChoice == 2){
                cout << "You decide not to make cereal.\n";
            }
        }
        else if(roomCompleted){
            cout << "This is where you successfully made and ate cereal. There's\n"
                    "nothing left to do here.\n";
        }


//        curBackpack->addBack(spoon);
    }
    else if (num==4){
        cout << "You see the usual kitchen wall as always. There’s a sink, stove, oven\n"
                "and clean countertops.\n";
    }
}
/**
    display map method
    @param none
    @return none
*/
void Kitchen::printMap(){
    std::cout << "\n#########################################################################\n"
                 "##########           OUTSIDE             ################################\n"
                 "#######################  ################################################\n"
                 "#######################  #################################          #####\n"
                 "################                 ####               ######          #####\n"
                 "################                 ####               ######          #####\n"
                 "##         #####     LIVING      ####                               #####\n"
                 "##  BED               ROOM               GARDEN     ######          #####\n"
                 "##         #####                 ####               ######   POND   #####\n"
                 "################                 ####               ######          #####\n"
                 "################                 ####               ######          #####\n"
                 "#######################  #################################          #####\n"
                 "#######################  #################################          #####\n"
                 "#########              1             ###          ########          #####\n"
                 "#########                            ###          ########          #####\n"
                 "#########4         KITCHEN*         2     LAUNDRY #######################\n"
                 "#########                            ###          #######################\n"
                 "#########              3             ###          #######################\n"
                 "#########################################################################\n"
                 "#########################################################################\n";
}
/**
    display menu method
    @param none
    @return none
*/
void Kitchen::printMenu() {
    menuKitchen->display();
}
/**
    virtual destructor
    @param none
    @return none
*/
Kitchen::~Kitchen(){
    cout << "TEST" << "\n";
    delete spoon;

    delete menuKitchen;
    delete menuCereal;
    delete menuCerealSteps;
}