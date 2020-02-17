#include "GreenCards.hpp"

#include <iostream>
#include <string>

using namespace std;

int main() {
    cout << "\n\nInitializing Game...\n\n" << endl;

    // GameBoard* gameBoard = new GameBoard();
    Footsoldier* f = new Footsoldier("kougias");
    cout << f->getName() << endl;
}