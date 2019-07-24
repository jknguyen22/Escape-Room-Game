#include <chrono>
#include <ctime>
#include <iostream>
#include <ratio>
#include "game.hpp"
#include "utility.hpp"
#include "BedRoom.hpp"
#include "LivingRoom.hpp"
#include "Kitchen.hpp"
#include "Laundry.hpp"
#include "Garden.hpp"
#include "Pond.hpp"

using std::cout;
using std::cin;
using std::vector;

/**
    Game state controller
    @param none
    @return none
*/
Game::Game(){
    brChoice = 0;

    //create item
    note = new Item(1);

    //create queue called backpack
    backpack = new Queue;

    //bedroom livingroom kitchen laundry garden pond outside
    bedRoom = new BedRoom();
    livingRoom = new LivingRoom();
    kitchen = new Kitchen();
    laundry = new Laundry();
    garden = new Garden();
    pond = new Pond();

    bedRoom->setEast(livingRoom);

    //set living room exits
    //livingRoom->setNorth() set this to outside space
    livingRoom->setEast(garden);
    livingRoom->setSouth(kitchen);
    livingRoom->setWest(bedRoom);

    //set kitchen exits
    kitchen->setNorth(livingRoom);
    kitchen->setEast(laundry);

    //set laundry exits
    laundry->setWest(kitchen);

    //set garden exits
    garden->setWest(livingRoom);
    garden->setEast(pond);

    //set pond exits
    pond->setWest(garden);

    // Create the menus of the game
    createMenus();

    // Displays the main menu
    setGameState(MAIN_MENU);
}

/**
    Different states of the Game based on GameState
    @param none
    @return none
*/
void Game::startGame()
{
    while(gameState != QUITTING)
    {
        if (gameState == MAIN_MENU)
        {
            mainMenu();
        }
        else if (gameState == GAME_SETUP)
        {
            gameSetup();
        }
        else if (gameState == PLAYING)
        {
            play();
        }
        else if (gameState == ENDING)
        {
            ending();
        }
        else if (gameState == WIN) {
            win();
        }
        else if (gameState == OUTOFTIME){
            timeLose();
        }
        else
        {
            gameState = QUITTING;
        }
    }
}

/**
    Main Menu that asks if they want to play or quit the game
    @param none
    @return none
*/
void Game::mainMenu()
{
    menuPlayGame->display();
    startGameChoice = integerValidation();

    while(startGameChoice != 1 && startGameChoice != 2)
    {
        cout << "You must select either 1 or 2.  Please try again.\n";
        startGameChoice = integerValidation();
    }
    if (startGameChoice == 1)
    {
        setGameState(GAME_SETUP);
    }
    else if (startGameChoice == 2)
    {
        setGameState(QUITTING);
    }
}

/**
    Function that sets the game up, prompts user1 and user 2
    to select a character
    @param none
    @return none
*/
void Game::gameSetup()
{
    cout << "Welcome to the Escape Room Game. There is a boy who dreams of going outside, but is only allowed\n"
            "to if he completes all of the chores at home. In order to win you need to complete all of\n"
            "the chores at home. You can interact with each side of a space using numbers 1-4.\n"
            "Your mom has a very little patience to deal with your shenanigans. If you run out of steps, \n"
            "then you lose.\n";

    cout << "\nYou wake up and look at the clock to see that it’s 10AM on a Saturday morning.\n"
            "You then remember that you had lunch date plans with the cutest girl in town.\n"
            "You start to get dressed and see a note on your desk. You read it.\n";

    readNote();

    curSpace = bedRoom;
    backpack->addBack(note);
    cout << "You grab your backpack and put the note in your backpack.\n";
    backpack->printQueue();


    setGameState(PLAYING);
}
/**
    play game function
    @param none
    @return none
*/
void Game::play()
{
    cout << "Current Steps: " << startSteps + 1 << '\n';
    do{
        if(startSteps > stepLimit){
            cout << "\n";
            setGameState(OUTOFTIME);
            break;
        }
cout << "\nSteps remaining: " << stepLimit - startSteps << " steps.\n";
        curSpace->printMap();
        brChoice = 8;
        while(brChoice > 7 || brChoice < 1)
        {
            curSpace->printMenu();
            cout << "You must select an integer 1-7.\n";
            brChoice = integerValidation();
        }
        if(brChoice >= 1 && brChoice <= 4){
            curSpace->action(brChoice, curSpace, backpack);
            if(curSpace == livingRoom && brChoice == 1 && backpack->checkQueue()) {
                setGameState(WIN);
            }
        }
        else if(brChoice == 5){
            backpack->printQueue();
        }
        else if(brChoice == 6){
            cout << "\nHELP NOTES\n"
                    "***How to solve each room***\n"
                    "BEDROOM: answer is 24\n"
                    "KITCHEN: Choose (2) pour dry cereal first\n"
                    "LAUNDRY: Choose 1, 2, 3, and 4 for each different pile of clothes\n"
                    "GARDEN: Attack the monster until its health is zero\n"
                    "POND: Keep rolling for large fish (1/10 chance)\n"
                    "LIVING ROOM: must complete all chores\n\n";
        }
        else if (brChoice == 7){
            setGameState(ENDING);
        }
        startSteps++;

    }while(getGameState() == PLAYING);

}
/**
    ending game message
    @param none
    @return none
*/
void Game::ending()
{
    while(!backpack->isEmpty()){
        backpack->removeFront();
    }

    cout << "The game has ended.\n";
    setGameState(QUITTING);

}


/**
    setter for game state
    @param GameState
    @return none
*/void Game::setGameState(GameState state)
{
    gameState = state;
}
/**
    getter for game state
    @param none
    @return none
*/
GameState Game::getGameState()
{
    return gameState;
}

/**
    Setter for gameState based on given argument/choice
    @param int
    @return none
*/
void Game::setStartGameChoice(int choice)
{
    startGameChoice = choice;
}

/**
    constructor for menus
    @param none
    @return none
*/
void Game::createMenus()
{
    menuPlayGame = new Menu;
    menuPlayGame->setTitle("Welcome to the Life of You!!! (Press 1 or 2)");
    menuPlayGame->addPrompt("Play game");
    menuPlayGame->addPrompt("Quit");

}
/**
    display menu for reading note
    @param none
    @return none
*/
void Game::readNote(){
    cout << "'Good Morning dearest son,\n\n"
            "You woke up late again, I know you. Don’t forget to do all of your chores before you\n"
            "head out today. In case you forgot what you need to do, here’s the list\n"
            "- Do your Homework\n"
            "- Eat cereal for breakfast\n"
            "- Do the laundry\n"
            "- Pull the weeds in the Garden\n"
            "- Catch the biggest fish in the pond for dinner\n"
            "I’ll be waiting in the living room to make sure everything is done before you leave.\n"
            "PS I hope I raised you right because there’s only one right way to make cereal.'\n\n";

}
/**
    game lose method to declare loss
    @param none
    @return none
*/
void Game::timeLose(){
    cout << "Looks like you ran out of steps!\n"
            "Mom: You're not going out to play today!\n";
    ending();
}

/**
    game win method to declare win
    @param none
    @return none
*/
void Game::win() {
    cout << "    YOU WIN!     \n";
    setGameState(ENDING);
}

/**
    game destructor
    @param none
    @return none
*/
Game::~Game()
{
    // Delete Menus
    delete menuPlayGame;

    backpack->~Queue();
    delete backpack;

    delete bedRoom;
    delete livingRoom;
    delete kitchen;
    delete laundry;
    delete garden;
    delete pond;

}
