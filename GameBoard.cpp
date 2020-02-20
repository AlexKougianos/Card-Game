#include "GameBoard.hpp"

GameBoard::GameBoard() {
    player1 = new Player();
    player2 = new Player();
    playerTurn = NULL;
    // initializeGameBoard();
}

void GameBoard::initializeGameBoard() {
    cout<<"Give max number of cards in hand."<<endl;
    cin>>maxNumberOfHand;

    player1->newHand(maxNumberOfHand);
    player2->newHand(maxNumberOfHand);

    playerTurn = player1;
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

player* GameBoard::getPlayer1() {return player1;}
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
