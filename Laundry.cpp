#include "Laundry.hpp"

using std::cout;
/**
    laundry constructor
    @param none
    @return none
*/
Laundry::Laundry() {
    sock = new Item(4);


    menuLaundry = new Menu;
    menuLaundry->setTitle("You're in the laundry room. Where do you want to go?");
    menuLaundry->addPrompt("UP");
    menuLaundry->addPrompt("RIGHT");
    menuLaundry->addPrompt("DOWN");
    menuLaundry->addPrompt("LEFT");
    menuLaundry->addPrompt("BACKPACK");
    menuLaundry->addPrompt("HELP");
    menuLaundry->addPrompt("EXIT GAME");

    menuLaundryYesNo = new Menu;
    menuLaundryYesNo->setTitle("\nThere’s a pile of clothes left unfolded here. Do you want to \n"
                                "do the laundry?");
    menuLaundryYesNo->addPrompt("Yes");
    menuLaundryYesNo->addPrompt("No");

    menuLaundryChoice = new Menu;
    menuLaundryChoice->setTitle("What do you want to fold?");
    menuLaundryChoice->addPrompt("Socks");
    menuLaundryChoice->addPrompt("Shirts");
    menuLaundryChoice->addPrompt("Pants");
    menuLaundryChoice->addPrompt("Jackets");
}
/**
    laundry virtual action method
    @param int, Space*&, Queue*&
    @return none
*/
int Laundry::action(int num, Space *&curSpace, Queue *&curBackpack) {
    if(num == 1){
        cout << "There’s only a window here. You look outside it and see the garden. You see\n"
                "your brother Zenas relaxing under the warm sun. You have a feeling that he is the \n"
                "favored brother because he never has to do chores at home.\n";
    }
    else if(num == 2){
        if(!roomCompleted){
            int laundryYesNo = 3;

            cout << "You look at the right side of the room and see a bunch of unfolded clothes.\n\n";
            if (clothes[0] == 10){
                cout << "Pile of 10 socks.\n";
            }
            else if (clothes[0] == 0){
                cout << "You already folded the pile of socks.\n";
            }
            if (clothes[1] == 5){
                cout << "Pile of 5 shirts.\n";
            }
            else if (clothes[1] == 0){
                cout << "You already folded the pile of shirts.\n";
            }
            if (clothes[2] == 4){
                cout << "Pile of 4 pairs of pants.\n";
            }
            else if (clothes[2] == 0){
                cout << "You already folded the pile of pants.\n";
            }
            if (clothes[3] == 2){
                cout << "Pile of 2 jackets.\n";
            }
            else if (clothes[3] == 0){
                cout << "You already folded the pile of jackets.\n";
            }
            while(laundryYesNo > 2 || laundryYesNo < 1){
                menuLaundryYesNo->display();
                cout << "You must select an integer from 1 to 2.\n";
                laundryYesNo = integerValidation();
            }
            if (laundryYesNo == 1){
                int laundryChoice = 5;
                int laundryTemp = 5;
                while(laundryChoice > 4 || laundryChoice < 1){
                    menuLaundryChoice->display();
                    cout << "You must select an integer from 1 to 4.\n";
                    laundryChoice = integerValidation();
                }
//                laundryChoice -= 1;

                if (laundryChoice == 1){
                    if(clothes[0] == 10){
                        clothes[0] = 0;
                        cout << "You folded the pile of socks.\n";
                    }
                    else if (clothes[0] == 0){
                        cout << "You already folded the pile of socks.\n";
                    }
                }
                if (laundryChoice == 2) {
                    if(clothes[1] == 5){
                        clothes[1] = 0;
                        cout << "You folded the pile of shirts.\n";
                    }
                    else if (clothes[1] == 0){
                        cout << "You already folded the pile of shirts.\n";
                    }
                }
                if (laundryChoice == 3){
                    if(clothes[2] == 4){
                        clothes[2] = 0;
                        cout << "You folded the pile of pants.\n";
                    }
                    else if (clothes[2] == 0){
                        cout << "You already folded the pile of pants.\n";
                    }
                }

                if (laundryChoice == 4){
                    if(clothes[3] == 2){
                        clothes[3] = 0;
                        cout << "You folded the pile of jackets.\n";
                    }
                    else if (clothes[3] == 0){
                        cout << "You already folded the pile of jackets.\n";
                    }
                }

                if(clothes[0] == 0 && clothes[1] == 0 && clothes[2] == 0 && clothes[3] ==0){
                    cout <<"Looks like you finished folding all of the laundry.\n";

                    curBackpack->addBack(sock);
                    cout << "You pack a clean set of clothes in your backpack.\n";

                    roomCompleted = true;
                }
            }
            else if (laundryYesNo == 2){
                cout << "You chose not to do the laundry.\n";
            }
        }
        else if(roomCompleted){
            cout << "This is where you finished folding all of the laundry. There's\n"
                    "nothing left to do here.\n";
        }
    }
    else if (num==3){
        cout << "There's only a wall here.\n";
    }
    else if (num==4){
        cout << "You exit the laundry room.\n";
        curSpace = west;
    }
}
/**
    display map method
    @param none
    @return none
*/
void Laundry::printMap(){
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
                 "#########                            ###    1     ########          #####\n"
                 "#########                            ###          ########          #####\n"
                 "#########          KITCHEN              4 LAUNDRY2#######################\n"
                 "#########                            ###     *    #######################\n"
                 "#########                            ###     3    #######################\n"
                 "#########################################################################\n"
                 "#########################################################################\n";
}
/**
    display menu method
    @param none
    @return none
*/
void Laundry::printMenu() {
    menuLaundry->display();
}
/**
    virtual destructor
    @param none
    @return none
*/
Laundry::~Laundry(){
    delete sock;

    delete menuLaundry;
    delete menuLaundryYesNo;
    delete menuLaundryChoice;
}