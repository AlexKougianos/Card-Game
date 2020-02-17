#ifndef _GREENCARD_HPP_
#define _GREENCARD_HPP_

#include <string>

class GreenCard {
    string name;
    int cost;
    bool isTapped;
    int attackBonus;
    int defenceBonus;
    int minimumHonour;
    string cardText;
    int effectBonus;
    int effectCost;
    public:
        virtual string getName();
        virtual int getCost();
        virtual bool isTapped();
        virtual int getAtackkBonus();
        virtual int getDefenceBonus();
        virtual int getMinimumHonour();
        virtual string getCardText();
        virtual int getEffectBonus();
        virtual int getEffectCost();
        virtual int getDurability();    
};

//##################
//# Follower Cards #
//##################
class Follower : private GreenCard {};

class Footsoldier : private Follower {
    public:
        Footsoldier(string);
};

class Archer : private Follower {
    public:
        Archer(string);
};

class Cavalry : private Follower {
    public:
        Cavalry(string);
};

class Bushido : private Follower {
    public:
        Bushido(string);
};

class Sieger : private Follower {
    public:
        Sieger(string);
};

class Naval : private Follower {
    public:
        Naval(string);
};

//##############
//# Item Cards #
//##############
class Item : private GreenCard {
    int durability;
};

class Katana : private Item {
    public:
        Katana(string);
};

class Spear : private Item {
    public:
        Spear(string);
};

class Bow : private Item {
    public:
        Bow(string);
};

class Ninjato : private Item {
    public:
        Ninjato(string);
};

class Wakizashi : private Item {
    public:
        Wakizashi(string);
};

#endif