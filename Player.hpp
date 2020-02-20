#ifndef _PLAYER_HPP_
#define _PLAYER_HPP_

#include <string>
#include <list>

#include "BlackCards.hpp"
#include "GreenCards.hpp"
#include "DeckBuilder.hpp"

using namespace std;

class Player {
    private:
        int honour;
        int numberOfProvinces = 4;

        Stronghold* stronghold;
        DeckBuilder* deckBuilder;
        list<GreenCard*>* fateDeck;
        list<BlackCard*>* dynastyDeck;
        list<GreenCard*>* hand;
        list<BlackCard*>* provinces;
        list<Holding*>* holdings;
        list<Personality*>* army;
    public:
        Player();

        int getHonour();
        int getNumberOfProvinces();
        Stronghold* getStronghold();
        list<GreenCard*>* getFateDeck();
        list<BlackCard*>* getDynastyDeck();
        list<GreenCard*>* getHand();
        list<BlackCard*>* getProvinces();
        list<Holding*>* getHoldings();
        list<Personality*>* getArmy();

        void setHonour(int);
        void setNumberOfProvinces(int);
        void setStronghold(Stronghold&);
        void setFateDeck(list<GreenCard*>&);
        void setDynastyDeck(list<BlackCard*>&);
        void setHand(list<GreenCard*>&);
        void setProvinces(list<BlackCard*>&);
        void setHoldings(list<Holding*>&);
        void setArmy(list<Personality*>&);

        list<GreenCard*>* newHand(int);
        void printHand();
};


#endif
