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
void Personality::addFollower(Follower *newFollower)
{
    if (followers->size() >= MAX_FOLLOWERS)
    {
        cout << "Can not add another follower" << endl;
        return;
    }
    if (getHonour() < newFollower->getMinimumHonour())
    {
        cout << newFollower->getMinimumHonour() << " is required to attach " << newFollower->getName() << endl;
        return;
    }

    followers->push_front(newFollower);

    cout << "Do you want the bonus for " << newFollower->getEffectCost() << " gold? (y for Yes, n for No)" << endl;
    char answer;
    cin >> answer;
    if (answer == 'y' or answer == 'Y')
    {
        newFollower->setAttackBonus(newFollower->getAttackBonus() + newFollower->getEffectBonus());
        newFollower->setDefenceBonus(newFollower->getDefenceBonus() + newFollower->getEffectBonus());
    }
    setAttack(getAttack() + newFollower->getAttackBonus());
    setDefence(getDefence() + newFollower->getDefenceBonus());
}

void Personality::addItem(Item *newItem)
{
    if (items->size() >= MAX_ITEM_CAPACITY)
    {
        cout << "Can not add another item" << endl;
        return;
    }
    if (getHonour() < newItem->getMinimumHonour())
    {
        cout << newItem->getName() << " is required to attach " << newItem->getName() << endl;
        return;
    }

    items->push_front(newItem);

    cout << "Do you want the bonus for " << newItem->getEffectCost() << " gold? (y for Yes, n for No)" << endl;
    char answer;
    cin >> answer;
    if (answer == 'y' || answer == 'Y')
    {
        newItem->setAttackBonus(newItem->getAttackBonus() + newItem->getEffectBonus());
        newItem->setDefenceBonus(newItem->getDefenceBonus() + newItem->getEffectBonus());
    }
    setAttack(getAttack() + newItem->getAttackBonus());
    setDefence(getAttack() + newItem->getAttackBonus());
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
    if (upperHolding == NULL)
    {
        cout << getName() << " does not have a Gold Mine!" << endl;
    }
    return upperHolding;
}

void Mine::setUpperHolding(GoldMine* newUpperHolding) // <-- chain starting from Mine
{
    if (newUpperHolding != NULL)
    {
        if (upperHolding != NULL)
        {
            cout << getName() << " already has a Gold Mine!" << endl;
            return;
        }
        upperHolding = newUpperHolding;
        setHarvestValue(getHarvestValue() + 2);
        // if (newUpperHolding->getUpperHolding() != NULL)
        // {
        //     setHarvestValue(getHarvestValue() + 6 * 3);     // Crystal Initial Harvest Value = 6
        // }
    }
}

void Mine::setUpperHolding(CrystalMine* newUpperHolding)
{
    if (newUpperHolding != NULL)
    {
        if(getUpperHolding() == NULL)
        {
            cout << "Can not attach Crystal Mine." << endl;
            return;
        }
        getUpperHolding()->setUpperHolding(newUpperHolding);
        setHarvestValue((getHarvestValue() + 5) + 6 * 3);   // Crystal Initial Harvest Value = 6
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
    if (subHolding == NULL)
    {
        cout << getName() << " does not have a Mine!" << endl;
    }
    return subHolding;
}

CrystalMine *GoldMine::getUpperHolding()
{
    if (upperHolding == NULL)
    {
        cout << getName() << " does not have a Crystal Mine!" << endl;
    }
    return upperHolding;
}

void GoldMine::setSubHolding(Mine *newSubHolding)
{
    if (newSubHolding != NULL)
    {
        if (subHolding != NULL)
        {
            cout << getName() << " already has a Mine!" << endl;
            return;
        }
        subHolding = newSubHolding;
        setHarvestValue(getHarvestValue() + 4);
        if (upperHolding != NULL)
        {
            setHarvestValue(getHarvestValue() + 5 * 2); // Starting Harvest value = 5
        }
    }
}

void GoldMine::setUpperHolding(CrystalMine *newUpperHolding)
{
    if (newUpperHolding != NULL)
    {
        if (upperHolding != NULL)
        {
            cout << getName() << " already has a Crystal Mine!" << endl;
            return;
        }
        upperHolding = newUpperHolding;
        setHarvestValue(getHarvestValue() + 5);
        if (subHolding != NULL)
        {
            setHarvestValue(getHarvestValue() + 5 * 2); // Starting Harvest value = 5
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
    if (subHolding == NULL)
    {
        cout << getName() << " does not have a Gold Mine!" << endl;
    }
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
        setHarvestValue(getHarvestValue() + getHarvestValue()); // <-- TODO add Mine
        // if (newSubHolding->getSubHolding() != NULL)
        // {
        //     setHarvestValue(getHarvestValue() + 6 * 3); // Starting Harvest value = 6
        // }
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
        setHarvestValue((getHarvestValue() + 5) + 6 * 3);   // Crystal Initial Harvest Value = 6
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