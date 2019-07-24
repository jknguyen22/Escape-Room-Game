#include <iostream>
#include "game.hpp"

int main() {
    srand(static_cast<unsigned int>(time(NULL)));

    //create a game
    Game gameFinal;

    //start game
    gameFinal.startGame();

    //test to see if exited safely
    std::cout << "Game DONE\n";

    return 0;
}