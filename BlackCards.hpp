#ifndef _BLACKCARD_HPP_
#define _BLACKCARD_HPP_

#include <string>
#include <list>

#include "GreenCards.hpp"

using namespace std;

class BlackCard {
    private:
        string name;
        int cost;
        bool isTapped;
        bool isRevealed;
    public:
        virtual string getName();
        virtual int getCost();
        virtual bool getIsTapped();
        virtual bool getIsRevealed();

        virtual void setName(string);
        virtual void setCost(int);
        virtual void setIsTapped(bool);
        virtual void setIsRevealed(bool);
};

//#####################
//# Personality Cards #
//#####################

#define MAX_ITEM_CAPACITY  2
#define MAX_FOLLOWERS      4

class Personality : public BlackCard {
    private:
        int attack;
        int defence;
        int honour;
        bool isDead;
        list<Follower*>* followers = new list<Follower*>();
        list<Item*>* items = new list<Item*>();
    public:
        virtual int getAttack();
        virtual int getDefence();
        virtual int getHonour();
        virtual bool getIsDead();
        virtual list<Follower*>* getFollowers();
        virtual list<Item*>* getItems();

        virtual void setAttack(int);
        virtual void setDefence(int);
        virtual void setHonour(int);
        virtual void setIsDead(bool);
        virtual void addFollower(Follower*);
        virtual void addItem(Item*);
};

class Attacker : public Personality {
    public:
        Attacker(string);
};

class Defender : public Personality {
    public:
        Defender(string);
};

class Chancellor : public Personality {
    public:
        Chancellor(string);
};

class Shogun : public Personality {
    public:
        Shogun(string);
};

class Champion : public Personality {
    public:
        Champion(string);
};

//#################
//# Holding Cards #
//#################

class Holding : public BlackCard {
    private:
        int harvestValue;
        Holding* subHolding;
    public:
        virtual int getHarvestValue();
        virtual void setHarvestValue(int);
};

class Solo : public Holding {
    public:
        Solo(string);
};

class Plain : public Holding {
    public:
        Plain(string);
};

class Farmland : public Holding {
    public:
        Farmland(string);
};

class GiftAndFavour : public Holding {
    public:
        GiftAndFavour(string);
};

// Mines

class GoldMine;
class CrystalMine;

class Mine : public Holding {
    private:
        GoldMine* upperHolding;
    public:
        Mine(string);
        GoldMine* getUpperHolding();
        void setUpperHolding(GoldMine*);
        void setUpperHolding(CrystalMine*);
};

class GoldMine : public Holding {
    private:
        Mine* subHolding;
        CrystalMine* upperHolding;
    public:
        GoldMine(string);

        Mine* getSubHolding();
        CrystalMine* getUpperHolding();

        void setSubHolding(Mine*);
        void setUpperHolding(CrystalMine*);
};

class CrystalMine : public Holding {
    private:
        GoldMine* subHolding;
    public:
        CrystalMine(string);
        GoldMine* getSubHolding();
        void setSubHolding(GoldMine*);
        void setSubHolding(Mine*);
};


class Stronghold : public Holding {
    private:
        int startingHonour;
        int initialDefense;
    public:
        Stronghold(string);
        int getStartingHonour();
        int getInitialDefence();

        void setStartingHonour(int);
        void setInitialDefence(int);
};

#endif