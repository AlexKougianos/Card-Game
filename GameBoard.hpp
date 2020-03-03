#ifndef _GAMEBOARD_HPP_
#define _GAMEBOARD_HPP_

#include <iostream>
#include <windows.h>

#include "Player.hpp"

using namespace std;

enum Phases{starting = 1, equip, battle, economy, final};

class GameBoard {
    private:
        Player* player1;
        Player* player2;
        int playerTurn;
        int currentPhase;
    public:
        GameBoard();
        void initializeGameBoard();
        void printGameStatistics();
        void gameplay();

        void startingPhase(int);
        void equipPhase(int);
        void battlePhase(int, int);
        void economyPhase(int);
        void finalPhase(int, int);

        void discardSurplusFateCard(int);
        void printArena(int, int);
        int checkWinningCondition(int, int);

        Player* getPlayer(int);
        int getCurrentPhase();

        void enterToContinue();
        void winnigMessage(int, int);
};

#endif
