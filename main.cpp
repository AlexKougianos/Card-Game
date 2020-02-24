#include "GameBoard.hpp"
#include "Player.hpp"
#include "GreenCards.hpp"
#include "BlackCards.hpp"

#include <iostream>
#include <string>

using namespace std;

int main() {
    cout << "\n\nInitializing Game...\n\n" << endl;

    // Mines

    Mine* mine = new Mine("m");
    GoldMine* gmine = new GoldMine("gm");
    CrystalMine* cmine = new CrystalMine("cm");

    cout << "Mine: " << mine->getHarvestValue()<<endl;          //3
    cout << "Gold Mine: "<< gmine->getHarvestValue()<<endl;     //5
    cout << "Crystal Mine: " << cmine->getHarvestValue()<<endl; //6

    mine->setUpperHolding(gmine);
    cout<<mine->getHarvestValue()<<endl;

    // gmine->setSubHolding(mine);                              //9
    // cout<<gmine->getHarvestValue()<<endl;
    
    gmine->setUpperHolding(cmine);
    cout<<gmine->getHarvestValue()<<endl;                       //
}