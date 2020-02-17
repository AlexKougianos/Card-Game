#ifndef _GREENCARD_HPP_
#define _GREENCARD_HPP_

#include <string>

using namespace std;

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
        virtual bool getIsTapped();
        virtual int getAttackBonus();
        virtual int getDefenceBonus();
        virtual int getMinimumHonour();
        virtual string getCardText();
        virtual int getEffectBonus();
        virtual int getEffectCost();

        virtual void setName(string);
        virtual void setCost(int);
        virtual void setIsTapped(bool);
        virtual void setAttackBonus(int);
        virtual void setDefenceBonus(int);
        virtual void setMinimumHonour(int);
        virtual void setCardText(string);
        virtual void setEffectBonus(int);
        virtual void setEffectCost(int);
};

//##################
//# Follower Cards #
//##################

class Follower : public GreenCard {};

class Footsoldier : public Follower {
    public:
        Footsoldier(string);
};

class Archer : public Follower {
    public:
        Archer(string);
};

class Cavalry : public Follower {
    public:
        Cavalry(string);
};

class Bushido : public Follower {
    public:
        Bushido(string);
};

class Sieger : public Follower {
    public:
        Sieger(string);
};

class Naval : public Follower {
    public:
        Naval(string);
};

//##############
//# Item Cards #
//##############

class Item : public GreenCard {
        int durability;
    public:
        int getDurability();
        void setDurability(int);
};

class Katana : public Item {
    public:
        Katana(string);
};

class Spear : public Item {
    public: 
        Spear(string);
};

class Bow : public Item {
    public:
        Bow(string);
};

class Ninjato : public Item {
    public:
        Ninjato(string);
};

class Wakizashi : public Item {
    public:
        Wakizashi(string);
};

#endif