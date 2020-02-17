#include <iostream>
#include <string>
#include "GreenCards.hpp"

using namespace std;

//Green Card getters
string GreenCard::getName() {return name;}
int GreenCard::getCost() {return cost;}
bool GreenCard::isTapped() {return isTapped;}
int GreenCard::getAtackkBonus() {return attackBonus;}
int GreenCard::getDefenceBonus() {return defenceBonus;}
int GreenCard::getMinimumHonour() {return minimumHonour;}
string GreenCard::getCardText() {return cardText;}
int GreenCard::getEffectBonus() {return effectBonus;}
int GreenCard::getEffectCost() {return effectCost;}
int GreenCard::getDurability() {return durability;}

//##################
//# Follower Cards #
//##################
Footsoldier::Footsoldier(string newName) {
    name=newName;
    cost=0;
    isTapped=false;
    attackBonus=2;
    deffenceBonus=0;
    minimumHonour=1;
    effectBonus=1;
    effectCost=2;
}

Archer::Archer(string newName) {
    name=newName;
    cost=0;
    isTapped=false;
    attackBonus=0;
    deffenceBonus=2;
    minimumHonour=1;
    effectBonus=1;
    effectCost=2; 
}

Cavalry::Cavarly(string newName) {
    name=newName;
    cost=3;
    isTapped=false;
    attackBonus=4;
    deffenceBonus=2;
    minimumHonour=3;
    effectBonus=3;
    effectCost=4;
}

Bushido::Bushido(string newName) {
    name=newName;
    cost=8;
    isTapped=false;
    attackBonus=8;
    deffenceBonus=8;
    minimumHonour=6;
    effectBonus=3;
    effectCost=8;
}

Naval::Naval(string newName) {
    name=newName;
    cost=3;
    isTapped=false;
    attackBonus=2;
    deffenceBonus=4;
    minimumHonour=3;
    effectBonus=3;
    effectCost=4;
}

Sieger::Sieger(string newName) {
    name=newName;
    cost=5;
    isTapped=false;
    attackBonus=3;
    deffenceBonus=3;
    minimumHonour=2;
    effectBonus=2;
    effectCost=3;
}

//##############
//# Item Cards #
//##############
Katana::Katana(string newName) {
    name=newName;
    cost=0;
    isTapped=false;
    attackBonus=2;
    defenceBonus=0;
    minimumHonour=1;
    effectBonus=1;
    effectCost=2;
    durability=3;
}

Spear::Spear(string newName) {
    name=newName;
    cost=0;
    isTapped=false;
    attackBonus=0;
    defenceBonus=2;
    minimumHonour=1;
    effectBonus=1;
    effectCost=2;
    durability=3;
}

Bow::Bow(string newName) {
    name=newName;
    cost=2;
    isTapped=false;
    attackBonus=2;
    defenceBonus=2;
    minimumHonour=2;
    effectBonus=3;
    effectCost=4;
    durability=5;
}

Ninjato::Ninjato(string newName) {
    name=newName;
    cost=4;
    isTapped=false;
    attackBonus=3;
    defenceBonus=3;
    minimumHonour=3;
    effectBonus=2;
    effectCost=2;
    durability=4;
}

Wakizashi::Wakizashi(string newName) {
    name=newName;
    cost=8;
    isTapped=false;
    attackBonus=5;
    defenceBonus=5;
    minimumHonour=3;
    effectBonus=3;
    effectCost=3;
    durability=8;
}