#include <iostream>

#include "Player.hpp"

using namespace std;

Player::Player() {
    stronghold = new Stronghold("Stronghold");
    deckBuilder = new DeckBuilder();
    honour = stronghold->getStartingHonour();
    fateDeck = deckBuilder->createFateDeck();
    dynastyDeck = deckBuilder->createDynastyDeck();
}

// Getters

int Player::getHonour() {return honour;}
int Player::getNumberOfProvinces() {return numberOfProvinces;}
Stronghold* Player::getStronghold() {return stronghold;}
list<GreenCard*>* Player::getFateDeck() {return fateDeck;}
list<BlackCard*>* Player::getDynastyDeck() {return dynastyDeck;}
list<GreenCard*>* Player::getHand() {return hand;}
list<BlackCard*>* Player::getProvinces() {return provinces;}
list<Holding*>* Player::getHoldings() {return holdings;}
list<Personality*>* Player::getArmy() {return army;}

// Setters

void Player::setHonour(int) {}
void Player::setNumberOfProvinces(int) {}
void Player::setStronghold(Stronghold&) {}
void Player::setFateDeck(list<GreenCard*>&) {}
void Player::setDynastyDeck(list<BlackCard*>&) {}
void Player::setHand(list<GreenCard*>&) {}
void Player::setProvinces(list<BlackCard*>&) {}
void Player::setHoldings(list<Holding*>&) {}
void Player::setArmy(list<Personality*>&) {}


list<GreenCard*>* newHand(int numberOfCards) {
    hand = new list<GreenCard*>();
    GreenCard* tempCard;
    for (int i=0; i<=numberOfCards) {
        tempCard = fateDeck->pop_back();
        hand->push_back(tempCard);
    }
}

void Player::printHand() {
    GreenCard* tempCard;
    list<GreenCard*>::iterator it;
    for (it = hand->begin(); it!=hand->end(); it++) {
        tempCard = *it;
        cout<<tempCard->getName()<<endl;
    }
}
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
