#ifndef _BLACKCARD_HPP_
#define _BLACKCARD_HPP_

#include <string>

using namespace std;

class BlackCard {
    string name;
    int cost;
    bool isTapped;
    bool isRevealed;
    public:
        virtual string getName();
        virtual int getCost();
        virtual bool isTapped();
        virtual bool isRevealed();
};

//#####################
//# Personality Cards #
//#####################
class Personality : private BlackCard {};

class Attacker : private Personality {
    public:
        Attacker(string newName);
};

class Defender : private Personality {
    public:
        Defender(string newName);
};

class Chanselor : private Personality {
    public:
        Chanselor(string newName);
};

class Shogun : private Personality {
    public:
        Shogun(string newName);
};

class Champion : private Personality {
    public:
        Champion(string newName);
};

//#################
//# Holding Cards #
//#################
class Holding : private BlackCard {
    int harvestValue;
    // Holding* upperHolding;
    // Holding* subHolding;
};

class Solo : private Holding {
    public:
        Solo(string newName);
};

class Plain : private Holding {
    public:
        Plain(string newName);
};

class Mine : private Holding {
    public:
        Mine(string newName);
};

class GoldMine : private Holding {
    public:
        GoldMine(string newName);
};

class CrystalMine : private Holding {
    public:
        CrystalMine(string newName);
};

class Farmland : private Holding {
    public:
        Farmland(string newName);
};

class GiftAndFavour : private Holding {
    public:
        GiftAndFavour(string newName);
};

class Stronghold : private Holding {
    int startingHonour;
    int initialDefense;
    public:
        Stronghold(string newName);
};

#endif