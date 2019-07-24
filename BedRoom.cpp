#include "BedRoom.hpp"

using std::cout;

/**
    bedroom constructor
    @param none
    @return none
*/
BedRoom::BedRoom() {
    homework = new Item(2);


    //create room menu
    menuBedRoom = new Menu;
    menuBedRoom->setTitle("You're in your bedroom. Where do you want to go?");
    menuBedRoom->addPrompt("UP");
    menuBedRoom->addPrompt("RIGHT");
    menuBedRoom->addPrompt("DOWN");
    menuBedRoom->addPrompt("LEFT");
    menuBedRoom->addPrompt("BACKPACK");
    menuBedRoom->addPrompt("HELP");
    menuBedRoom->addPrompt("EXIT GAME");

    menuHomework = new Menu;
    menuHomework->setTitle("You see your unfinished math homework. Do you want to finish it?");
    menuHomework->addPrompt("Yes");
    menuHomework->addPrompt("No");
}
/**
    bedroom virtual action method
    @param int, Space*&, Queue*&
    @return none
*/
int BedRoom::action(int num, Space *&curSpace, Queue *&curBackpack) {

    //direction: up
    if (num == 1 ){
        cout << "You look at the bed and decide you don’t want to make your bed cause it’s Saturday.\n\n";
    }
    //direction: right
    else if (num == 2){
        cout << "You exit your bedroom.\n\n";
        curSpace = east;
    }
    //direction: down
    else if (num == 3){
        if(!roomCompleted){
            homeworkChoice = 3;
            while (homeworkChoice > 2 || homeworkChoice < 1){
                menuHomework->display();
                cout << "You must select an integer from 1 to 2.\n";
                homeworkChoice = integerValidation();
            }
            if (homeworkChoice == 1){
                homeworkAnswer = -2;


                while (homeworkAnswer > 9999 || homeworkAnswer < 0){
                    cout << "You decide to do your homework.\n"
                            "What's 8 x 3?\n";
                    homeworkAnswer = integerValidation();
                }

                if(homeworkAnswer == 24){
                    cout << "Looks right to me. You wrote in the right answer.\n"
                            "You put your completed homework in your backpack.\n";
                    curBackpack->addBack(homework);
                    roomCompleted = true;
                }
                else{
                    cout << "Hmmm...That doesn't look quite right. I'll come back to this.\n";
                }


            }
            else if (homeworkChoice == 2)
            {
                cout << "You chose not to do your homework.\n";
            }

        }
        else if (roomCompleted){
            cout <<"This is where you finished your homework. There’s nothing left to do here.\n"
                   "It’s just your desk against the wall.\n\n";
        }
    }
    //direction: left
    else if (num == 4){
        cout << "There’s nothing here but a blank wall.\n\n";
    }
}
/**
    display map method
    @param none
    @return none
*/
void BedRoom::printMap(){
    std::cout << "\n#########################################################################\n"
                 "##########           OUTSIDE             ################################\n"
                 "#######################  ################################################\n"
                 "#######################  #################################          #####\n"
                 "################                 ####               ######          #####\n"
                 "################                 ####               ######          #####\n"
                 "##    1    #####     LIVING      ####                               #####\n"
                 "##4  BED* 2           ROOM               GARDEN     ######          #####\n"
                 "##    3    #####                 ####               ######   POND   #####\n"
                 "################                 ####               ######          #####\n"
                 "################                 ####               ######          #####\n"
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
void BedRoom::printMenu() {
    menuBedRoom->display();
}
/**
    virtual destructor
    @param none
    @return none
*/
BedRoom::~BedRoom(){
    delete menuBedRoom;
    delete menuHomework;
    delete homework;
}
