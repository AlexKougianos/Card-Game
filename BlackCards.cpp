#include <iostream>
#include <string>

#include "BlackCards.hpp"

using namespace std;

// Black Card getters
string BlackCard::getName() { return name; }
int BlackCard::getCost() { return cost; }
bool BlackCard::getIsTapped() { return isTapped; }
bool BlackCard::getIsRevealed() { return isRevealed; }
int BlackCard::getType() { return type; }

// Black Card setters
void BlackCard::setName(string newName) { name = newName; }
void BlackCard::setCost(int newCost) { cost = newCost; }
void BlackCard::setIsTapped(bool newIsTapped) { isTapped = newIsTapped; }
void BlackCard::setIsRevealed(bool newIsRevealed) { isRevealed = newIsRevealed; }
void BlackCard::setType(int newType) { type = newType; }

//#####################
//# Personality Cards #
//#####################

// Getters
int Personality::getAttack() { return attack; }
int Personality::getDefence() { return defence; }
int Personality::getHonour() { return honour; }
bool Personality::getIsDead() { return isDead; }
list<Follower *> *Personality::getFollowers() { return followers; }
list<Item *> *Personality::getItems() { return items; }

// Setters
void Personality::setAttack(int newAttack) { attack = newAttack; }
void Personality::setDefence(int newDefence) { defence = newDefence; }
void Personality::setHonour(int newHonour) { honour = newHonour; }
void Personality::setIsDead(bool newIsDead) { isDead = newIsDead; }

// Adders
void Personality::addFollower(Follower *newFollower)        // Add Follower to Personality
{
    followers->push_back(newFollower);
}

void Personality::addItem(Item *newItem)                    // Add item to Personality
{
    items->push_back(newItem);
}

// Print
void Personality::print()
{
    cout << getName() << " with ";
    cout << getHonour() << " Honour." << endl;

    // Printing items
    cout << "\tItems: ";
    Item *item;
    list<Item *>::iterator it;
    int i = 1;
    for (it = items->begin(); it != items->end(); it++)
    {
        item = *it;
        if(i == 1)
            cout << item->getName();
        else
            cout << ", " << item->getName();
        i++;
    }
    cout << "\n";

    // Printing Followers
    cout << "\tFollowers: ";
        Follower *follower;
        list<Follower *>::iterator it2;
        i = 1;
        for (it2 = followers->begin(); it2 != followers->end(); it2++)
        {
            follower = *it2;
            if(i == 1)
                cout << follower->getName();
            else
                cout << ", " << follower->getName();
            i++;
        }
        cout << "\n";
}

// Constructors
Attacker::Attacker(string newName)
{
    setName(newName);
    setCost(5);
    setIsTapped(false);
    setIsRevealed(false);
    setAttack(3);
    setDefence(2);
    setHonour(2);
    setIsDead(false);
    setType(ATTACKER);
}

Defender::Defender(string newName)
{
    setName(newName);
    setCost(5);
    setIsTapped(false);
    setIsRevealed(false);
    setAttack(2);
    setDefence(3);
    setHonour(2);
    setIsDead(false);
    setType(DEFENDER);
}

Chancellor::Chancellor(string newName)
{
    setName(newName);
    setCost(15);
    setIsTapped(false);
    setIsRevealed(false);
    setAttack(5);
    setDefence(10);
    setHonour(8);
    setIsDead(false);
    setType(CHANCELLOR);
}

Shogun::Shogun(string newName)
{
    setName(newName);
    setCost(15);
    setIsTapped(false);
    setIsRevealed(false);
    setAttack(10);
    setDefence(5);
    setHonour(8);
    setIsDead(false);
    setType(SHOGUN);
}

Champion::Champion(string newName)
{
    setName(newName);
    setCost(30);
    setIsTapped(false);
    setIsRevealed(false);
    setAttack(20);
    setDefence(20);
    setHonour(12);
    setIsDead(false);
    setType(CHAMPION);
}

//#################
//# Holding Cards #
//#################

// Getters
int Holding::getHarvestValue() { return harvestValue; }

// Setters
void Holding::setHarvestValue(int newHarvestValue) { harvestValue = newHarvestValue; }

// Constructors
Solo::Solo(string newName)
{
    setName(newName);
    setCost(2);
    setIsTapped(false);
    setIsRevealed(false);
    setHarvestValue(2);
    setType(SOLO);
}

Plain::Plain(string newName)
{
    setName(newName);
    setCost(2);
    setIsTapped(false);
    setIsRevealed(false);
    setHarvestValue(2);
    setType(PLAIN);
}

Farmland::Farmland(string newName)
{
    setName(newName);
    setCost(3);
    setIsTapped(false);
    setIsRevealed(false);
    setHarvestValue(4);
    setType(FARMS);
}

// Mines

Mine::Mine(string newName)
{
    setName(newName);
    setCost(5);
    setIsTapped(false);
    setIsRevealed(false);
    setHarvestValue(3);
    setType(MINE);
}

GoldMine* Mine::getUpperHolding()
{
    return upperHolding;
}

void Mine::setUpperHolding(GoldMine* newUpperHolding)           // Linking Gold Mine to Mine
{
    if (newUpperHolding != NULL)
    {
        if (upperHolding != NULL)
        {
            cout << getName() << " already has a Gold Mine!" << endl;
            return;
        }
        upperHolding = newUpperHolding;
        newUpperHolding->setHarvestValue(this->getHarvestValue() + 2);
    }
}

void Mine::setUpperHolding(CrystalMine* newUpperHolding)        // Add Crystal Mine if Mine has linked Gold Mine
{
    if (newUpperHolding != NULL)
    {
        if(getUpperHolding() == NULL)
        {
            cout << "Can not attach Crystal Mine." << endl;
            return;
        }
        this->getUpperHolding()->setUpperHolding(newUpperHolding);
        newUpperHolding->setHarvestValue((this->getHarvestValue() + 5) + 6 * 3);       // Crystal Initial Harvest Value = 6
    }
}

void Mine::printUpperHoldings()
{
    if (getUpperHolding() != NULL)
    {
        cout << " <-> " << getUpperHolding()->getName();

        if (getUpperHolding()->getUpperHolding() != NULL)
        {
            cout << " <-> " << getUpperHolding()->getUpperHolding()->getName();
        }
    }
}

// Gold
GoldMine::GoldMine(string newName)
{
    setName(newName);
    setCost(7);
    setIsTapped(false);
    setIsRevealed(false);
    setHarvestValue(5);
    setType(GOLD_MINE);
}

Mine *GoldMine::getSubHolding()
{
    return subHolding;
}

CrystalMine *GoldMine::getUpperHolding()
{
    return upperHolding;
}

void GoldMine::setSubHolding(Mine *newSubHolding)                   // Linking Mine to Gold Mine
{
    if (newSubHolding != NULL)
    {
        if (subHolding != NULL)
        {
            cout << getName() << " already has a Mine!" << endl;
            return;
        }

        subHolding = newSubHolding;
        newSubHolding->setHarvestValue(this->getHarvestValue() + 4);

        if (upperHolding != NULL)                                   // Check if any Upper Holding is already linked
        {
            newSubHolding->setHarvestValue(this->getHarvestValue() + 5 * 2);             // Starting Gold Harvest value = 5
        }
    }
}

void GoldMine::setUpperHolding(CrystalMine *newUpperHolding)        // Linking Crystal Mine to Gold Mine
{
    if (newUpperHolding != NULL)
    {
        if (upperHolding != NULL)
        {
            cout << getName() << " already has a Crystal Mine!" << endl;
            return;
        }

        upperHolding = newUpperHolding;
        newUpperHolding->setHarvestValue(this->getHarvestValue() + 5);

        if (subHolding != NULL)                                                     // Checking if any Sub Holding is already linked
        {
            newUpperHolding->setHarvestValue(this->getHarvestValue() + 5 * 2);      // Starting Gold Mine Harvest value = 5
        }
    }
}

void GoldMine::printHoldings()
{
    if (getSubHolding() != NULL)
    {
        cout << " <-> " << getSubHolding()->getName();

        if (getUpperHolding() != NULL)
        {
            cout << " <-> " << getUpperHolding()->getName();
        }
    }
}

// Crystal
CrystalMine::CrystalMine(string newName)
{
    setName(newName);
    setCost(12);
    setIsTapped(false);
    setIsRevealed(false);
    setHarvestValue(6);
    setType(CRYSTAL_MINE);
}

GoldMine* CrystalMine::getSubHolding()
{
    return subHolding;
}

void CrystalMine::setSubHolding(GoldMine* newSubHolding)
{
    if (newSubHolding != NULL)
    {
        if (subHolding != NULL)
        {
            cout << getName() << " already has a Gold Mine!" << endl;
            return;
        }

        subHolding = newSubHolding;
        newSubHolding->setHarvestValue(this->getHarvestValue() + this->getHarvestValue());
    }
}

void CrystalMine::setSubHolding(Mine* newSubHolding)
{
    if (newSubHolding != NULL)
    {
        if(getSubHolding() == NULL)
        {
            cout << "Can not attach Crystal Mine." << endl;
            return;
        }

        getSubHolding()->setSubHolding(newSubHolding);
        newSubHolding->setHarvestValue((this->getHarvestValue() + 5) + 6 * 3);              // Crystal Mine Initial Harvest Value = 6
    }
}

void CrystalMine::printSubHoldings()
{
    if (getSubHolding() != NULL)
    {
        cout << " <-> " << getSubHolding()->getName();

        if (getSubHolding()->getSubHolding() != NULL)
        {
            cout << " <-> " << getSubHolding()->getSubHolding()->getName();
        }
    }
}

// Stronghold

Stronghold::Stronghold(string newName)
{
    setName(newName);
    setCost(0);
    setIsTapped(false);
    setIsRevealed(false);
    setHarvestValue(5);
    setStartingHonour(5);
    setInitialDefence(5);
    setType(STRONGHOLD);
}

int Stronghold::getStartingHonour() { return startingHonour; }
int Stronghold::getInitialDefence() { return initialDefense; }

void Stronghold::setStartingHonour(int newStartingHonour) { startingHonour = newStartingHonour; }
void Stronghold::setInitialDefence(int newInitialDefence) { initialDefense = newInitialDefence; }
