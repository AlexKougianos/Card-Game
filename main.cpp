#include "GameBoard.hpp"
#include "Player.hpp"
#include "GreenCards.hpp"
#include "BlackCards.hpp"

#include <iostream>
#include <string>

using namespace std;

int main() {
    cout << "\n\nInitializing Game...\n\n" << endl;

    GameBoard* gameBoard = new GameBoard();
    gameBoard->initializeGameBoard();

    gameBoard->printGameStatistics();

    gameBoard->getPlayer(1)->printHand();
    gameBoard->getPlayer(2)->printHand();
    gameBoard->getPlayer(1)->printProvinces();
    gameBoard->getPlayer(2)->printProvinces();


    // Mines
    cout<<endl<<"Harvest Values: "<<endl;
    Mine* mine = new Mine("m");
    GoldMine* gmine = new GoldMine("gm");
    CrystalMine* cmine = new CrystalMine("cm");
    cout<<"Mine: "<<mine->getHarvestValue()<<endl;
    cout<<"Gold Mine: "<<gmine->getHarvestValue()<<endl;
    cout<<"Crystal Mine: "<<cmine->getHarvestValue()<<endl;
    
    mine->setUpperHolding(gmine);
    cout<<endl<<"-> Mine with GoldMine(+2 to mine): "<<mine->getHarvestValue()<<endl;
    
    gmine->setSubHolding(mine);
    cout<<endl<<"-> GoldMine with Mine(+4 to GoldMine): "<<gmine->getHarvestValue()<<endl;
    cout<<"  -> GoldMine with only CrystalMine (+5 to GoldMine)"<<endl;

    gmine->setUpperHolding(cmine);
    cout<<endl<<"-> GoldMine with Mine and CrystalMine(+ *2 to GoldMine): "<<gmine->getHarvestValue()<<endl;

    cmine->setSubHolding(gmine);
    cout<<endl<<"-> CrystalMine with only GoldMine(+ *2 to CrystalMine): "<<cmine->getHarvestValue()<<endl;
    cout<<"  -> CrystalMine with GoldMine and Mine(+ *3 to CrystalMine)"<<endl;
}