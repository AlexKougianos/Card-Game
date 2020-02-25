#include "GameBoard.hpp"
#include "Player.hpp"
#include "GreenCards.hpp"
#include "BlackCards.hpp"

#include <iostream>
#include <string>

using namespace std;

int main() {
    cout << "\n\nInitializing Game...\n\n" << endl;

    // Items
    Katana* kata = new Katana("Katana");
    Spear* spea = new Spear("Spear");
    Bow* bow  = new Bow("Bow");

    // Followers
    Footsoldier* foot = new Footsoldier("Footsoldiers");
    Archer* arch = new Archer("Archer");

    // Personality
    Chancellor* C = new Chancellor("Chance");
    C->addFollower(foot);
    C->addFollower(arch);
    C->addItem(kata);
    C->addItem(spea);
    C->addItem(bow);
}