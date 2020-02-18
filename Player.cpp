#include <iostream>

#include "Player.hpp"

using namespace std;

Player::Player(int decksize, int handsize) {
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