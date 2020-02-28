#include <iostream>

#include "Player.hpp"

using namespace std;

Player::Player()
{
    stronghold = new Stronghold("Stronghold");
    deckBuilder = new DeckBuilder();
    honour = stronghold->getStartingHonour();
    money = STARTINGMONEY;

    // Creating decks
    fateDeck = deckBuilder->createFateDeck();
    dynastyDeck = deckBuilder->createDynastyDeck();

    // Shuffling them
    deckBuilder->deckShuffler(fateDeck);
    deckBuilder->deckShuffler(dynastyDeck);

    holdings = new list<Holding *>();
    army = new list<Personality *>();
}

// Getters

int Player::getHonour() { return honour; }
int Player::getNumberOfProvinces() { return numberOfProvinces; }
int Player::getMoney() { return money; }
Stronghold *Player::getStronghold() { return stronghold; }
list<GreenCard *> *Player::getFateDeck() { return fateDeck; }
list<BlackCard *> *Player::getDynastyDeck() { return dynastyDeck; }
list<GreenCard *> *Player::getHand() { return hand; }
list<BlackCard *> *Player::getProvinces() { return provinces; }
list<Holding *> *Player::getHoldings() { return holdings; }
list<Personality *> *Player::getArmy() { return army; }

// Setters

void Player::setHonour(int) {}
void Player::setNumberOfProvinces(int) {}
void Player::setMoney(int newMoney) { money = newMoney; }
void Player::setStronghold(Stronghold &) {}
void Player::setFateDeck(list<GreenCard *> &) {}
void Player::setDynastyDeck(list<BlackCard *> &) {}
void Player::setHand(list<GreenCard *> &) {}
void Player::setProvinces(list<BlackCard *> &) {}
void Player::setHoldings(list<Holding *> &) {}
void Player::setArmy(list<Personality *> &) {}

void Player::addHolding(Holding *holding)
{
    holdings->push_front(holding);
}

void Player::addPersonality(Personality *personality)
{
    army->push_front(personality);
}

// Add Item to Personality
bool Player::addItem(Personality* personality, Item* item)
{
    if (personality->getFollowers()->size() >= MAX_FOLLOWERS)
    {
        cout << "Can not add another follower" << endl;
        return false;
    }

    if (personality->getHonour() < item->getMinimumHonour())
    {
        cout << item->getMinimumHonour() << " honour is required to attach ";
        cout << item->getName() << endl;
        return false;
    }

    if (getMoney() >= item->getCost())
    {
        cout << "You Purchased " << item->getName() << endl;
        setMoney(getMoney() - item->getCost());

        cout << "You have " << getMoney() << " gold" << endl;
        cout << "Do you want the bonus for " << item->getEffectCost() << " gold? (y for Yes, n for No)" << endl;
        char answer;
        cin >> answer;
        if (answer == 'y' or answer == 'Y')
        {
            if(getMoney() < item->getEffectCost()){
                cout << "You do not have enough gold" << endl;
            }
            else
            {
                item->setAttackBonus(item->getAttackBonus() + item->getEffectBonus());
                item->setDefenceBonus(item->getDefenceBonus() + item->getEffectBonus());
                setMoney(getMoney() - item->getEffectCost());
            }
        }
        personality->setAttack(personality->getAttack() + item->getAttackBonus());
        personality->setDefence(personality->getDefence() + item->getDefenceBonus());

        personality->addItem(item);
        return true;
    }
    else
    {
        cout << "You do not have enough money!" << endl;
        return false;
    }
}

// Add Follower to Personality
bool Player::addFollower(Personality* personality, Follower* follower)
{
    if (personality->getFollowers()->size() >= MAX_FOLLOWERS)
    {
        cout << "Can not add another follower" << endl;
        return false;
    }

    if (personality->getHonour() < follower->getMinimumHonour())
    {
        cout << follower->getMinimumHonour() << " honour is required to attach ";
        cout << follower->getName() << endl;
        return false;
    }

    if (getMoney() >= follower->getCost())
    {
        cout << "You Purchased " << follower->getName() << endl;
        setMoney(getMoney() - follower->getCost());

        cout << "You have " << getMoney() << " gold" << endl;
        cout << "Do you want the bonus for " << follower->getEffectCost() << " gold? (y for Yes, n for No)" << endl;
        char answer;
        cin >> answer;
        if (answer == 'y' or answer == 'Y')
        {
            if(getMoney() < follower->getEffectCost()){
                cout << "You do not have enough gold" << endl;
            }
            else
            {
                follower->setAttackBonus(follower->getAttackBonus() + follower->getEffectBonus());
                follower->setDefenceBonus(follower->getDefenceBonus() + follower->getEffectBonus());
                setMoney(getMoney() - follower->getEffectCost());
            }
        }
        personality->setAttack(personality->getAttack() + follower->getAttackBonus());
        personality->setDefence(personality->getDefence() + follower->getDefenceBonus());

        personality->addFollower(follower);
        return true;
    }
    else
    {
        cout << "You do not have enough money!" << endl;
        return false;
    }
}

// Create
void Player::createHand(int numberOfCards)
{
    hand = new list<GreenCard *>();
    maxHandSize = numberOfCards;
    GreenCard *tempCard;
    for (int i = 0; i < numberOfCards; i++)
    {
        tempCard = fateDeck->front(); // Getting the first item of Fate Date
        hand->push_front(tempCard);   // Putting it in Hand
        fateDeck->pop_front();        // Deleting it from the Fate Deck
    }
}

void Player::createProvinces()
{
    provinces = new list<BlackCard *>();
    BlackCard *tempCard;
    for (int i = 0; i < 4; i++)
    {
        tempCard = dynastyDeck->front(); // Getting the first item of Dynasty Date
        provinces->push_front(tempCard); // Putting it in the Provinces
        dynastyDeck->pop_front();        // Deleting it from the Dynasty Deck
    }
}

// Starting Phase
void Player::untapEverything()
{
    cout << "Untap everything.." << endl;

    BlackCard *tempCard;
    if (holdings != NULL)
    {
        list<Holding *>::iterator it;
        for (it = holdings->begin(); it != holdings->end(); it++)
        {
            tempCard = *it;
            tempCard->setIsTapped(false);
        }
    }

    if (army != NULL)
    {
        list<Personality *>::iterator it2;
        for (it2 = army->begin(); it2 != army->end(); it2++)
        {
            tempCard = *it2;
            tempCard->setIsTapped(false);
        }
    }
}

void Player::drawFateCard()
{
    cout << "Draw Fate Card..." << endl;

    if (hand->size() == MAXHANDSIZE)
    {
        cout << "Cannot draw another card!" << endl;
        return;
    }
    GreenCard *tempCard;
    tempCard = fateDeck->front();       // Getting the first item of Fate Date
    hand->push_front(tempCard);         // Putting it in Hand
    fateDeck->pop_front();              // Deleting it from the Fate Deck
}

void Player::drawDynastyCard()
{
    cout << "Draw Dynasty Card..." << endl;

    if (provinces->size() == 4)
    {
        cout << "Cannot draw another card!" << endl;
        return;
    }
    BlackCard *tempCard;
    tempCard = dynastyDeck->front();    // Getting the first item of Dynasty Date
    provinces->push_back(tempCard);     // Putting it in Provinces
    dynastyDeck->pop_front();           // Deleting it from the Dynasty Deck
}

void Player::revealProvinces()          // Making all Provinces revealed
{
    cout << "Reveal Provinces..." << endl;
    BlackCard *tempCard;
    list<BlackCard *>::iterator it;
    for (it = provinces->begin(); it != provinces->end(); it++)
    {
        tempCard = *it;
        tempCard->setIsRevealed(true);
    }
}

void Player::printHand(bool costs)
{
    cout << "\nPrinting hand:\n"
         << endl;
    GreenCard *tempCard;
    list<GreenCard *>::iterator it;
    int i = 1;
    for (it = hand->begin(); it != hand->end(); it++)
    {
        tempCard = *it;
        cout << i << ": " << tempCard->getName();
        if (costs)
        {
            cout << " (" << tempCard->getCost() << "g, ";
            cout << tempCard->getMinimumHonour() << " Minimum Honour)";
        }
        cout << endl;
        i++;
    }
    cout << "\n";
}

void Player::printProvinces(bool costs)
{
    cout << "\nPrinting Revealed Provinces:\n"
         << endl;
    BlackCard *tempCard;
    list<BlackCard *>::iterator it;
    int i = 1;
    for (it = provinces->begin(); it != provinces->end(); it++)
    {
        tempCard = *it;
        if (tempCard->getIsRevealed() == true)
        {
            cout << i << ": " << tempCard->getName();
            if (costs)
            {
                cout << " (" << tempCard->getCost() << "g)";
            }
            cout << endl;
        }
        i++;
    }
    cout << "\n";
}

void Player::printArmy(bool honour)
{
    cout << "\nPrinting Army:\n"
         << endl;
    Personality *tempCard;
    list<Personality *>::iterator it;
    int i = 1;
    for (it = army->begin(); it != army->end(); it++)
    {
        tempCard = *it;
        if (tempCard->getIsDead() == false)
        {
            cout << i << ": " << tempCard->getName();
            if(honour) 
            {
                cout << " (Honour: " << tempCard->getHonour() << ")";
            }
            cout << endl;
        }
        i++;
    }
    cout << "\n";
}

void Player::printHoldings()
{
    cout << "\nPrinting Holdings:\n"
         << endl;
    BlackCard *tempCard;
    list<Holding *>::iterator it;
    int i = 1;
    for (it = holdings->begin(); it != holdings->end(); it++)
    {
        tempCard = *it;
        cout << i << ": " << tempCard->getName() << endl;
        i++;
    }
    cout << "\n";
}

// equip phase
void Player::equip()
{
    if (getArmy()->size() == 0)
    {
        cout << "Player does not have an army yet!" << endl;
        return;
    }

    list<Personality *>::iterator armyIt;
    Personality *personality;

    list<GreenCard *>::iterator handIt;
    GreenCard *tempCard;

    int handCard, armyCard, i;

    do
    {
        printArmy(true);
        cout << "Choose which Personality to equip: (0 to exit)" << endl;
        cin >> armyCard;

        if (armyCard > 0 && armyCard <= getArmy()->size())
        {
            i = 1;
            for (armyIt = getArmy()->begin(); armyIt != getArmy()->end(); armyIt++)
            {
                if (i == armyCard)
                {
                    personality = *armyIt;
                    cout << "You picked: ";
                    personality->print();
                }
            }

            printHand(true);
            cout << "\nYou have " << getMoney() << " gold" << endl;
            cout << "Choose a Fate card to buy: (0 to exit)" << endl;
            cin >> handCard;

            if (handCard > 0 && handCard <= getHand()->size())
            {
                i = 1;
                for (handIt = getHand()->begin(); handIt != getHand()->end(); handIt++)
                {
                    if (i == handCard)
                    {
                        tempCard = *handIt;
                        bool purchase;
                        if (getCorrectType(tempCard->getType()) == ITEM)
                        {
                            purchase = addItem(personality, (Item *)tempCard);
                        }
                        else if (getCorrectType(tempCard->getType()) == FOLLOWER)
                        {
                            purchase = addFollower(personality, (Follower *)tempCard);
                        }

                        if(purchase)
                        {
                            getHand()->erase(handIt);
                        }

                        break;
                    }
                    i++;
                }
            }
            else if (handCard != 0)
            {
                cout << "Wrong input. Try again!" << endl;
            }
        }
        else if (armyCard != 0)
        {
            cout << "Wrong input. Try again!" << endl;
        }
    } while (handCard != 0 && armyCard != 0);
}

// economy phase
void Player::economy()
{
    list<BlackCard *>::iterator it;
    BlackCard *tempCard;
    int answer, i, count = 4;

    do
    {
        printProvinces(true);
        cout << "\nYou have " << getMoney() << " gold" << endl;

        cout << "Give number you want to buy. (0 to exit)" << endl;
        cin >> answer;

        if (answer >= 0 && answer <= count)
        {
            i = 1;
            for (it = getProvinces()->begin(); it != getProvinces()->end(); it++)
            {
                if (i == answer)
                {
                    tempCard = *it;
                    if (getMoney() >= tempCard->getCost())
                    {
                        cout << "You Purchased " << tempCard->getName() << endl;
                        getProvinces()->erase(it);
                        drawDynastyCard();
                        count--;
                        setMoney(getMoney() - tempCard->getCost());

                        // putting purchased card to holdings or army
                        if (getCorrectType(tempCard->getType()) == HOLDING)
                        {
                            addHolding((Holding *)tempCard);
                        }
                        else if (getCorrectType(tempCard->getType()) == PERSONALITY)
                        {
                            addPersonality((Personality *)tempCard);
                        }
                    }
                    else
                    {
                        cout << "You do not have enough money!" << endl;
                    }
                    break;
                }
                i++;
            }
        }
        else
        {
            cout << "Wrong input. Try again!" << endl;
        }
    } while (answer != 0);
}