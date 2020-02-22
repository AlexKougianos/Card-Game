#include "GameBoard.hpp"

GameBoard::GameBoard() {
    player1 = new Player();
    player2 = new Player();
    playerTurn = 0;
}

void GameBoard::initializeGameBoard() {
    int maxHandSize;
    // cout << "Give max number of cards in hand."<<endl;
    // cin >> maxHandSize;
    maxHandSize = MAXHANDSIZE;

    player1->createHand(maxHandSize);
    player2->createHand(maxHandSize);

    player1->createProvinces();
    player2->createProvinces();

    playerTurn = (player1->getHonour() >= player2->getHonour())?1:2;
    cout << "Player" << playerTurn << " plays first\n" << endl;
}

void GameBoard::printGameStatistics() {
    cout << "Printing Statistics...\n" << endl;

    cout << "Players = 2" << endl;
    cout << "Fate Deck size = " << player1->getFateDeck()->size() << endl;
    cout << "Dynasty Deck size = " << player1->getDynastyDeck()->size() << endl;
    cout << "Number of Provinces = " << player1->getNumberOfProvinces() << endl;
}

void GameBoard::gameplay() {

}

Player* GameBoard::getPlayer(int i) {
    switch(i) {
        case 1:
            return player1;
        case 2:
            return player2;
        default:
            return NULL;
    }
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