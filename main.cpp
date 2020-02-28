#include "GameBoard.hpp"
#include "TypeConverter.hpp"
#include "Player.hpp"
// #include "GreenCards.hpp"
// #include "BlackCards.hpp"

#include <iostream>
#include <string>

using namespace std;

int main() {
    cout << "\n\nInitializing Game...\n\n" << endl;

    GameBoard* gameboard = new GameBoard();
    gameboard->initializeGameBoard();
    gameboard->gameplay();
}