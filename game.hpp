
#ifndef GAME_HPP
#define GAME_HPP

#include <vector>
#include "menu.hpp"
#include "utility.hpp"
#include "Item.hpp"
#include "QueueNode.hpp"
#include "Queue.hpp"
#include "Space.hpp"

using std::vector;
//game states
enum GameState
{
    MAIN_MENU, GAME_SETUP, PLAYING, OUTOFTIME,  ENDING, QUITTING, WIN
};

class Game
{
private:
    GameState gameState;
    int startGameChoice;

    int brChoice;

    Item* note;


    Space* curSpace;
    Space* bedRoom;
    Space* kitchen;
    Space* livingRoom;
    Space* laundry;
    Space* garden;
    Space* pond;

    Queue* backpack;



    // Menus for the game
    Menu* menuPlayGame;



    int startSteps = 0;
    int stepLimit = 45;

public:
    Game();

    //game state controller
    void startGame();

    //main menu for game
    void mainMenu();

    //setup menu for game
    void gameSetup();

    //play function for game
    void play();

    //ending function for game
    void ending();


    //setter for gamestate
    void setGameState(GameState state);

    //getter for gamestate
    GameState getGameState();

    void setStartGameChoice(int choice);

    //constructor for menus
    void createMenus();

    //display for lose condition
    void timeLose();

    //display for reading note
    void readNote();

    //display for win condition
    void win();
    
    //destructor for game
    ~Game();

};

#endif //GAME_HPP
