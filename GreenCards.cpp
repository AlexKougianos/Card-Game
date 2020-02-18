#include <iostream>
#include <string>
#include "GreenCards.hpp"

using namespace std;

// Green Card getters
string GreenCard::getName() {return name;}
int GreenCard::getCost() {return cost;}
bool GreenCard::getIsTapped() {return isTapped;}
int GreenCard::getAttackBonus() {return attackBonus;}
int GreenCard::getDefenceBonus() {return defenceBonus;}
int GreenCard::getMinimumHonour() {return minimumHonour;}
string GreenCard::getCardText() {return cardText;}
int GreenCard::getEffectBonus() {return effectBonus;}
int GreenCard::getEffectCost() {return effectCost;}

// Green Card setters
void GreenCard::setName(string newName) {name = newName;}
void GreenCard::setCost(int newCost) {cost = newCost;}
void GreenCard::setIsTapped(bool newIsTapped) {isTapped = newIsTapped;}
void GreenCard::setAttackBonus(int newAttackBonus) {attackBonus = newAttackBonus;}
void GreenCard::setDefenceBonus(int newDefenceBonus) {defenceBonus = newDefenceBonus;}
void GreenCard::setMinimumHonour(int newMinimumHonour) {minimumHonour = newMinimumHonour;}
void GreenCard::setCardText(string newCardText) {cardText = newCardText;}
void GreenCard::setEffectBonus(int newEffectBonus) {effectBonus = newEffectBonus;}
void GreenCard::setEffectCost(int newEffectCost) {effectCost = newEffectCost;}

//##################
//# Follower Cards #
//##################

Footsoldier::Footsoldier(string newName) {
    setName(newName);
    setCost(0);
    setIsTapped(false);
    setAttackBonus(2);
    setDefenceBonus(2);
    setMinimumHonour(1);
    setEffectBonus(1);
    setEffectCost(2);
}

Archer::Archer(string newName) {
    setName(newName);
    setCost(0);
    setIsTapped(false);
    setAttackBonus(0);
    setDefenceBonus(2);
    setMinimumHonour(1);
    setEffectBonus(1);
    setEffectCost(2);
}

Cavalry::Cavalry(string newName) {
    setName(newName);
    setCost(3);
    setIsTapped(false);
    setAttackBonus(4);
    setDefenceBonus(2);
    setMinimumHonour(3);
    setEffectBonus(3);
    setEffectCost(4);
}

Bushido::Bushido(string newName) {
    setName(newName);
    setCost(8);
    setIsTapped(false);
    setAttackBonus(8);
    setDefenceBonus(8);
    setMinimumHonour(6);
    setEffectBonus(3);
    setEffectCost(8);
}

Naval::Naval(string newName) {
    setName(newName);
    setCost(3);
    setIsTapped(false);
    setAttackBonus(2);
    setDefenceBonus(4);
    setMinimumHonour(3);
    setEffectBonus(3);
    setEffectCost(4);
}

Sieger::Sieger(string newName) {
    setName(newName);
    setCost(5);
    setIsTapped(false);
    setAttackBonus(3);
    setDefenceBonus(3);
    setMinimumHonour(2);
    setEffectBonus(2);
    setEffectCost(3);
}

//##############
//# Item Cards #
//##############

int Item::getDurability() {return durability;}
void Item::setDurability(int newDurability) {durability = newDurability;}

Katana::Katana(string newName) {
    setName(newName);
    setCost(0);
    setIsTapped(false);
    setAttackBonus(2);
    setDefenceBonus(0);
    setMinimumHonour(1);
    setEffectBonus(1);
    setEffectCost(2);
    setDurability(3);
}

Spear::Spear(string newName) {
    setName(newName);
    setCost(0);
    setIsTapped(false);
    setAttackBonus(0);
    setDefenceBonus(2);
    setMinimumHonour(1);
    setEffectBonus(1);
    setEffectCost(2);
    setDurability(3);
}

Bow::Bow(string newName) {
    setName(newName);
    setCost(2);
    setIsTapped(false);
    setAttackBonus(2);
    setDefenceBonus(2);
    setMinimumHonour(2);
    setEffectBonus(3);
    setEffectCost(4);
    setDurability(5);
}

Ninjato::Ninjato(string newName) {
    setName(newName);
    setCost(4);
    setIsTapped(false);
    setAttackBonus(3);
    setDefenceBonus(3);
    setMinimumHonour(3);
    setEffectBonus(2);
    setEffectCost(2);
    setDurability(4);
}

Wakizashi::Wakizashi(string newName) {
    setName(newName);
    setCost(8);
    setIsTapped(false);
    setAttackBonus(5);
    setDefenceBonus(5);
    setMinimumHonour(3);
    setEffectBonus(3);
    setEffectCost(3);
    setDurability(8);
}