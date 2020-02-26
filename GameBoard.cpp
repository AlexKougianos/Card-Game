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
    int maxHandSize;
    // cout << "Give max number of cards in hand."<<endl;
    // cin >> maxHandSize;
    maxHandSize = MAXHANDSIZE;

    player1->createHand(maxHandSize);
    player2->createHand(maxHandSize);

    player1->createProvinces();
    player2->createProvinces();

    playerTurn = (player1->getHonour() >= player2->getHonour()) ? 1 : 2;
    // cout << "Player" << playerTurn << " plays first\n"
    //      << endl;
}

void GameBoard::gameplay()
{
    // do {
        cout << "\e[1m" << "\n--- Starting Phase: ---\n" << "\e[0m" << endl;
        startingPhase(1);
        startingPhase(2);
        cout << "\n--- Equip Phase: ---\n"<< endl;
        equipPhase(1);
        equipPhase(2);
        cout << "\n--- Battle Phase: ---\n" << endl;
        battlePhase(1);
        battlePhase(2);
        cout << "\n--- Economy Phase: ---\n" << endl;
        economyPhase(1);
        economyPhase(2);
        cout << "\n--- Final Phase: ---\n" << endl;
        finalPhase(1);
        finalPhase(2);
    // } while(checkWinningCondition() == 0);
}

void GameBoard::startingPhase(int player)
{
    Player* currentPlayer = getPlayer(player);
    cout << "\e[1m" <<"Player" << player << ":\n" << "\e[0m" << endl;
    currentPlayer->untapEverything();
    currentPlayer->drawFateCard();
    currentPlayer->revealProvinces();
    currentPlayer->printHand();
    currentPlayer->printProvinces();
}

void GameBoard::equipPhase(int player)
{
    Player* currentPlayer = getPlayer(player);
    cout << "Player" << player << ": " << endl;
}

void GameBoard::battlePhase(int player)
{
    Player* currentPlayer = getPlayer(player);
    cout << "Player" << player << ": " << endl;
}

void GameBoard::economyPhase(int player)
{
    Player* currentPlayer = getPlayer(player);
    cout << "Player" << player << ": " << endl;
}

void GameBoard::finalPhase(int player)
{
    Player* currentPlayer = getPlayer(player);
    cout << "Player" << player << ": " << endl;
}

int GameBoard::checkWinningCondition() {
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