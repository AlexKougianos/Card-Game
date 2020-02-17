#ifndef _GAMEBOARD_HPP_
#define _GAMEBOARD_HPP_

#include <iostream>

using namespace std;

class GameBoard {
    Player p1;
    Player p2;
    public:
        GameBoard();
        void initializeGameBoard();
        void printGameStatistics();
};

#endif