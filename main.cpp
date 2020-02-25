#include "GameBoard.hpp"
#include "Player.hpp"
#include "GreenCards.hpp"
#include "BlackCards.hpp"

#include <iostream>
#include <string>

using namespace std;

int main() {
    cout << "\n\nInitializing Game...\n\n" << endl;

    Mine* m = new Mine("m");
    GoldMine* gm = new GoldMine("gm");
    CrystalMine* cm = new CrystalMine("cm");

    cm->setSubHolding(m);
    cm->setSubHolding(gm);
    cm->setSubHolding(m);

    cout<<cm->getHarvestValue()<<endl;
}