#include <iostream>
#include <string>

#include "BlackCards.hpp"

using namespace std;

// Black Card getters
string BlackCard::getName() {return name;}
int BlackCard::getCost() {return cost;}
bool BlackCard::getIsTapped() {return isTapped;}
bool BlackCard::getIsRevealed() {return isRevealed;}

// Black Card setters
void BlackCard::setName(string newName) {name = newName;}
void BlackCard::setCost(int newCost) {cost = newCost;}
void BlackCard::setIsTapped(bool newIsTapped) {isTapped = newIsTapped;}
void BlackCard::setIsRevealed(bool newIsRevealed) {isRevealed = newIsRevealed;}

//#####################
//# Personality Cards #
//#####################

// Getters
int Personality::getAttack() {return attack;}
int Personality::getDefence() {return defence;}
int Personality::getHonour() {return honour;}
bool Personality::getIsDead() {return isDead;}

// Setters
void Personality::setAttack(int newAttack) {attack = newAttack;}
void Personality::setDefence(int newDefence) {defence = newDefence;}
void Personality::setHonour(int newHonour) {honour = newHonour;}
void Personality::setIsDead(bool newIsDead) {isDead = newIsDead;}

// Constructors
Attacker::Attacker(string newName) {
    setName(newName);
    setCost(5);
    setIsTapped(false);
    setIsRevealed(false);
    setAttack(3);
    setDefence(2);
    setHonour(2);
    setIsDead(false);
}

Defender::Defender(string newName) {
    setName(newName);
    setCost(5);
    setIsTapped(false);
    setIsRevealed(false);
    setAttack(2);
    setDefence(3);
    setHonour(2);
    setIsDead(false);
}

Chancellor::Chancellor(string newName) {
    setName(newName);
    setCost(15);
    setIsTapped(false);
    setIsRevealed(false);
    setAttack(5);
    setDefence(10);
    setHonour(8);
    setIsDead(false);
}

Shogun::Shogun(string newName) {
    setName(newName);
    setCost(15);
    setIsTapped(false);
    setIsRevealed(false);
    setAttack(10);
    setDefence(5);
    setHonour(8);
    setIsDead(false);
}

Champion::Champion(string newName) {
    setName(newName);
    setCost(30);
    setIsTapped(false);
    setIsRevealed(false);
    setAttack(20);
    setDefence(20);
    setHonour(12);
    setIsDead(false);
}

//#################
//# Holding Cards #
//#################

// Getters
int Holding::getHarvestValue() {return harvestValue;}

// Setters
void Holding::setHarvestValue(int newHarvestValue) {harvestValue = newHarvestValue;}

// Constructors
Solo::Solo(string newName) {
    setName(newName);
    setCost(2);
    setIsTapped(false);
    setIsRevealed(false);
    setHarvestValue(2);
}

Plain::Plain(string newName) {
    setName(newName);
    setCost(2);
    setIsTapped(false);
    setIsRevealed(false);
    setHarvestValue(2);
}

Farmland::Farmland(string newName) {
    setName(newName);
    setCost(3);
    setIsTapped(false);
    setIsRevealed(false);
    setHarvestValue(4);
}

GiftAndFavour::GiftAndFavour(string newName) {
    setName(newName);
    setCost(3);
    setIsTapped(false);
    setIsRevealed(false);
    setHarvestValue(4);
}

// Mines

Mine::Mine(string newName) {
    setName(newName);
    setCost(5);
    setIsTapped(false);
    setIsRevealed(false);
    setHarvestValue(3);
    setUpperHolding(NULL);
}

Holding* Mine::getUpperHolding() {
    if (!upperHolding) {
        cout<<getName()<<" does not have a Gold Mine!"<<endl;
    }
    return upperHolding;
}

void Mine::setUpperHolding(Holding* newUpperHolding) {
    if (upperHolding) {
        cout<<getName()<<" already has a Gold Mine!"<<endl;
        return;
    }
    upperHolding = newUpperHolding;
    // ?
    // if (newUpperHolding->getUpperHolding() != NULL)
    // ?
    setHarvestValue(getHarvestValue() + 2);
}

// Gold
GoldMine::GoldMine(string newName) {
    setName(newName);
    setCost(7);
    setIsTapped(false);
    setIsRevealed(false);
    setHarvestValue(5);
    setSubHolding(NULL);
    setUpperHolding(NULL);
}

Holding* GoldMine::getSubHolding() {
    if (!subHolding) {
        cout<<getName()<<" does not have a Mine!"<<endl;
    }
    return subHolding;
}

Holding* GoldMine::getUpperHolding() {
    if (!upperHolding) {
        cout<<getName()<<" does not have a Crystal Mine!"<<endl;
    }
    return upperHolding;
}

void GoldMine::setSubHolding(Holding* newSubHolding) {
    if (subHolding) {
        cout<<getName()<<" already has a Mine!"<<endl;
        return;
    }
    subHolding = newSubHolding;
    if (!upperHolding) {
        setHarvestValue(getHarvestValue() + 4);
    }
    else {
        setHarvestValue(getHarvestValue() + getHarvestValue()*2);
    }
    
}

void GoldMine::setUpperHolding(Holding* newUpperHolding) {
    if (upperHolding) {
        cout<<getName()<<" already has a Crystal Mine!"<<endl;
        return;
    }
    upperHolding = newUpperHolding;
    if (!subHolding) {
        setHarvestValue(getHarvestValue() + 5);
    }
    else {
        setHarvestValue(getHarvestValue() + getHarvestValue()*2);
    }
}

// Crystal
CrystalMine::CrystalMine(string newName) {
    setName(newName);
    setCost(12);
    setIsTapped(false);
    setIsRevealed(false);
    setHarvestValue(6);
}

Holding* CrystalMine::getSubHolding() {
    if (!subHolding) {
        cout<<getName()<<" does not have a Gold Mine!"<<endl;
    }
    return subHolding;
}

void CrystalMine::setSubHolding(Holding* newSubHolding) {
    if (subHolding) {
        cout<<getName()<<" already has a Gold Mine!"<<endl;
        return;
    }
    subHolding = newSubHolding;
    // ?
    // if (newSubHolding->getSubHolding() != NULL) {}
    //
    setHarvestValue(getHarvestValue() + getHarvestValue() * 2);
}

// Stronghold

Stronghold::Stronghold(string newName) {
    setName(newName);
    setCost(0);
    setIsTapped(false);
    setIsRevealed(false);
    setHarvestValue(5);
    setStartingHonour(5);
    setInitialDefence(5);
}

int Stronghold::getStartingHonour() {return startingHonour;}
int Stronghold::getInitialDefence() {return initialDefense;}

void Stronghold::setStartingHonour(int newStartingHonour) {startingHonour = newStartingHonour;}
void Stronghold::setInitialDefence(int newInitialDefence) {initialDefense = newInitialDefence;}