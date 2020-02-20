#ifndef _GAMEBOARD_HPP_
#define _GAMEBOARD_HPP_

#include <iostream>

#include "Player.hpp"

using namespace std;

class GameBoard {
    private:
        Player* player1;
        Player* player2;
        Player* playerTurn;
        int maxNumberOfHand;
    public:
        GameBoard();
        void initializeGameBoard();
        void printGameStatistics();
        void gameplay();

        player* getPlayer1();
};

#endif
