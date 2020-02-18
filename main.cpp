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
    gameBoard->printGameStatistics();

    // Footsoldier* f = new Footsoldier("kougias");
    // Chancellor* c = new Chancellor("leo");
    // cout << f->getName() << endl;
    // cout << c->getAttack() << endl;
}