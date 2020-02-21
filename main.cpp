#include "GameBoard.hpp"
#include "Player.hpp"
#include "GreenCards.hpp"
#include "BlackCards.hpp"

#include <iostream>
#include <string>

using namespace std;

int main() {
    cout << "\n\nInitializing Game...\n\n" << endl;

    GameBoard* gameBoard = new GameBoard();
    gameBoard->initializeGameBoard();

    gameBoard->printGameStatistics();

    gameBoard->getPlayer(1)->printHand();
    gameBoard->getPlayer(2)->printHand();
    gameBoard->getPlayer(1)->printProvinces();
    gameBoard->getPlayer(2)->printProvinces();

    // Footsoldier* f = new Footsoldier("kougias");
    // Chancellor* c = new Chancellor("leo");
    // cout << f->getName() << endl;
    // cout << c->getAttack() << endl;
}
