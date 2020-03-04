#ifndef _PLAYER_HPP_
#define _PLAYER_HPP_

#include <string>
#include <list>

#include "BlackCards.hpp"
#include "GreenCards.hpp"
#include "DeckBuilder.hpp"
#include "Colours.hpp"

using namespace std;

class Player {
    private:
        int honour;
        int numberOfProvinces = 4;
        int money;
        int harvest;
        int maxHandSize;
        int toAttack;
        int totalAttack;
        int totalDefence;

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
        int getMoney();
        int getHarvest();
        int getMaxHandSize();
        int getToAttack();
        int getTotalAttack();
        int getTotalDefence();
        Stronghold* getStronghold();
        list<GreenCard*>* getFateDeck();
        list<BlackCard*>* getDynastyDeck();
        list<GreenCard*>* getHand();
        list<BlackCard*>* getProvinces();
        list<Holding*>* getHoldings();
        list<Personality*>* getArmy();

        void setHonour(int);
        void setNumberOfProvinces(int);
        void setMoney(int);
        void setHarvest(int);
        void setToAttack(int);
        void setTotalAttack(int);
        void setTotalDefence(int);

        bool toSubHolding(Mine*);
        bool toSubHolding(GoldMine*);
        bool toUpperHolding(GoldMine*);
        bool toUpperHolding(CrystalMine*);
        
        void addHolding(Holding*);
        void addPersonality(Personality*);
        bool addItem(Personality*, Item*);
        bool addFollower(Personality*, Follower*);

        void createHand(int);
        void createProvinces();

        void untapEverything();
        void drawFateCard();
        void drawDynastyCard();
        void revealProvinces();

        void printHand(bool = false);
        void printProvinces(bool = false);
        void printArmy(bool = false);
        void printHoldings();
        void printStronghold();

        void equip();
        void prepareBattle(Player*);
        void battle(Player*);
        void economy();

        void enterToContinue();
};


#endif
