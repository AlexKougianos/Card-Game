#include <iostream>
#include <string>
#include "BlackCards.hpp"

using namespace std;

// Black Card getters
string BlackCard::getName() {return name;}
int BlackCard::getCost() {return cost;}
bool BlackCard::isTapped() {return isTapped;}
bool BlackCard::isRevealed() {return isRevealed;}

//#####################
//# Personality Cards #
//#####################
Attacker::Attacker(string newName) {
    name=newName;
    cost=5;
    Attack=3;
    Defence=2;
    Honor=2;
}

Defender::Defender(string newName) {
    name=newName;
    cost=5;
    Attack=2;
    Defence=3;
    Honor=2;
}

Chanselor::Chanselor(string newName) {
    name=newName;
    cost=15;
    Attack=5;
    Defence=10;
    Honor=8;
}

Shogun::Shogun(string newName) {
    name=newName;
    cost=15;
    Attack=10;
    Defence=5;
    Honor=8;
}

Champion::Champion(string newName) {
    name=newName;
    cost=30;
    Attack=20;
    Defence=20;
    Honor=12;
}

//#################
//# Holding Cards #
//#################
Solo::Solo(string newName) {
    name=newName;
    cost=2;
    harvestValue=2;
}

Plain::Plain(string newName) {
    name=newName;
    cost=2;
    harvestValue=2;
}

Mine::Mine(string newName) {
    name=newName;
    cost=5;
    harvestValue=3;
}

GoldMine::GoldMine(string newName) {
    name=newName;
    cost=7;
    harvestValue=5;
}

CrystalMine::CrystalMine(string newName) {
    name=newName;
    cost=12;
    harvestValue=6;
}

Farmland::Farmland(string newName) {
    name=newName;
    cost=3;
    harvestValue=4;
}

GiftAndFavour::GiftAndFavour(string newName) {
    name=newName;
    cost=3;
    harvestValue=4;
}

Stronghold::Stronghold(string newName) {
    name=newName;
    cost=0;
    harvestValue=5;
    startingHonour=5;
    initialDefense=5;
}