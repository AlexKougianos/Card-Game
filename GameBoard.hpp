#ifndef _GAMEBOARD_HPP_
#define _GAMEBOARD_HPP_

#include <iostream>

#include "Player.hpp"

using namespace std;

class GameBoard {
    private:
        Player* player1;
        Player* player2;
    public:
        GameBoard(int, int);
        void initializeGameBoard(int, int);
        void printGameStatistics();
        void gameplay();
};

#endif