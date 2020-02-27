#include <iostream>

#include "Player.hpp"

using namespace std;

Player::Player() {
    stronghold = new Stronghold("Stronghold");
    deckBuilder = new DeckBuilder();
    honour = stronghold->getStartingHonour();

    // Creating decks
    fateDeck = deckBuilder->createFateDeck();
    dynastyDeck = deckBuilder->createDynastyDeck();

    // Shuffling them
    deckBuilder->deckShuffler(fateDeck);
    deckBuilder->deckShuffler(dynastyDeck);
}

// Getters

int Player::getHonour() {return honour;}
int Player::getNumberOfProvinces() {return numberOfProvinces;}
int Player::getMoney() {return money;}
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
void Player::setMoney(int newMoney) {money = newMoney;}
void Player::setStronghold(Stronghold&) {}
void Player::setFateDeck(list<GreenCard*>&) {}
void Player::setDynastyDeck(list<BlackCard*>&) {}
void Player::setHand(list<GreenCard*>&) {}
void Player::setProvinces(list<BlackCard*>&) {}
void Player::setHoldings(list<Holding*>&) {}
void Player::setArmy(list<Personality*>&) {}


void Player::createHand(int numberOfCards) {
    hand = new list<GreenCard*>();
    maxHandSize = numberOfCards;
    GreenCard* tempCard;
    for (int i=0; i < numberOfCards; i++) {
        tempCard = fateDeck->front();           // Getting the first item of Fate Date
        hand->push_front(tempCard);             // Putting it in Hand
        fateDeck->pop_front();                  // Deleting it from the Fate Deck
    }
}

void Player::createProvinces() {
    provinces = new list<BlackCard*>();
    BlackCard* tempCard;
    for (int i=0; i < 4; i++) {
        tempCard = dynastyDeck->front();         // Getting the first item of Dynasty Date
        provinces->push_front(tempCard);         // Putting it in the Provinces
        dynastyDeck->pop_front();                // Deleting it from the Dynasty Deck
    }
}

void Player::untapEverything() {
    //untap holdings, army, provinces?
    
    BlackCard* tempCard;
    if (holdings != NULL)
    {
        list<Holding*>::iterator it;
        for (it = holdings->begin(); it != holdings->end(); it++)
        {
            tempCard = *it;
            tempCard->setIsTapped(false);
        }
    }
    
    if (army != NULL)
    {
        list<Personality*>::iterator it2;
        for (it2 = army->begin(); it2 != army->end(); it2++)
        {
            tempCard = *it2;
            tempCard->setIsTapped(false);
        }
    }
}

void Player::drawFateCard() {
    // check not max
}

void Player::revealProvinces() {

}

void Player::printHand() {
    cout << "Printing hand:\n" << endl;
    GreenCard* tempCard;
    list<GreenCard*>::iterator it;
    int i = 1;
    for (it = hand->begin(); it != hand->end(); it++) {
        tempCard = *it;
        cout << i << ": " << tempCard->getName() << endl;
        i++;
    }
    cout << "\n\n";
}

void Player::printProvinces() {
    cout << "Printing Provinces:\n" << endl;
    BlackCard* tempCard;
    list<BlackCard*>::iterator it;
    int i = 1;
    for (it = provinces->begin(); it != provinces->end(); it++) {
        tempCard = *it;
        cout << i << ": "<< tempCard->getName() << endl;
        i++;
    }
    cout << "\n\n";
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
