#include "GameBoard.hpp"

GameBoard::GameBoard()
{
    player1 = new Player();
    player2 = new Player();
    playerTurn = 0;
    currentPhase = starting;
}

void GameBoard::initializeGameBoard()
{
    int handSize = STARTINGHANDSIZE;

    player1->createHand(handSize);
    player2->createHand(handSize);

    player1->createProvinces();
    player2->createProvinces();

    playerTurn = (player1->getHonour() >= player2->getHonour()) ? 1 : 2;
}

void GameBoard::gameplay()
{
    do
    {
        cout << "\e[1m"
             << "\n----- STARTING PHASE: -----\n"
             << "\e[0m" << endl;
        startingPhase(1);
        startingPhase(2);
        cout << "\e[1m"
             << "\n----- EQUIP PHASE: -----\n"
             << "\e[0m" << endl;
        equipPhase(1);
        equipPhase(2);
        cout << "\e[1m"
             << "\n----- BATTLE PHASE: -----\n"
             << "\e[0m" << endl;
        battlePhase(1, 2);
        cout << "\e[1m"
             << "\n----- ECONOMY PHASE: -----\n"
             << "\e[0m" << endl;
        economyPhase(1);
        economyPhase(2);
        cout << "\e[1m"
             << "\n----- FINAL PHASE: -----\n"
             << "\e[0m" << endl;
        finalPhase(1);
        finalPhase(2);
    } while (checkWinningCondition() == 0);
}

void GameBoard::startingPhase(int player)
{
    Player *currentPlayer = getPlayer(player);
    cout << "\e[1m"
         << "     PLAYER" << player << ":\n"
         << "\e[0m" << endl;
    currentPlayer->untapEverything();
    currentPlayer->drawFateCard();
    currentPlayer->revealProvinces();
    currentPlayer->printHand();
    currentPlayer->printProvinces();
}

void GameBoard::equipPhase(int player)
{
    Player *currentPlayer = getPlayer(player);
    cout << "\e[1m"
         << "     PLAYER" << player << ":\n"
         << "\e[0m" << endl;

    currentPlayer->equip();
}

void GameBoard::battlePhase(int player1, int player2)
{
    Player *currentPlayer1 = getPlayer(player1);
    Player *currentPlayer2 = getPlayer(player2);

    // if one player does not have an army we skip the battle phase
    if(currentPlayer1->getArmy()->size() == 0 || currentPlayer2->getArmy()->size() == 0)
    {
        cout << "Players do not have army to battle yet!" << endl;
        return;
    }

    cout << "\e[1m"
         << "     PLAYER" << player1 << ": PREPARING\n"
         << "\e[0m" << endl;

    currentPlayer1->prepareBattle(currentPlayer2);
    
    cout << "\e[1m"
         << "     PLAYER" << player2 << ": PREPARING\n"
         << "\e[0m" << endl;
    currentPlayer2->prepareBattle(currentPlayer1);

    cout << "\e[1m"
         << "     PLAYER" << player1 << ": BATTLE!\n"
         << "\e[0m" << endl;
    currentPlayer1->battle(currentPlayer2);

    cout << "\e[1m"
         << "     PLAYER" << player2 << ": BATTLE\n"
         << "\e[0m" << endl;
    currentPlayer2->battle(currentPlayer1);
}

void GameBoard::economyPhase(int player)
{
    Player *currentPlayer = getPlayer(player);
    cout << "\e[1m"
         << "     PLAYER" << player << ":\n"
         << "\e[0m" << endl;

    currentPlayer->economy();
}

void GameBoard::finalPhase(int player)
{
    Player *currentPlayer = getPlayer(player);
    cout << "\e[1m"
         << "     PLAYER" << player << ":\n"
         << "\e[0m" << endl;
}

int GameBoard::checkWinningCondition()
{
    cout << "won?" << endl;
    int c;
    cin >> c;

    return c;
}

void GameBoard::printGameStatistics()
{
    cout << "Printing Statistics...\n"
         << endl;
}

Player *GameBoard::getPlayer(int i)
{
    switch (i)
    {
    case 1:
        return player1;
    case 2:
        return player2;
    default:
        return NULL;
    }
}

int GameBoard::getCurrentPhase()
{
    return currentPhase;
}

// cout << "\nPlayer1:\n\n" << endl;
// //printing card names
// list<GreenCard*>* green = player1->getFateDeck();
// GreenCard* card;
// list<GreenCard*>::iterator it;
// int i = 1;
// for (it = green->begin(); it != green->end(); it++) {
//     card = *it;
// 	cout << i << ": " << card->getName() << endl;
//     i++;
// }
// cout << "\nPlayer2:\n\n" << endl;
// //printing card names
// i = 1;
// green = player2->getFateDeck();
// for (it = green->begin(); it != green->end(); it++) {
//     card = *it;
// 	cout << i << ": " << card->getName() << endl;
//     i++;
// }