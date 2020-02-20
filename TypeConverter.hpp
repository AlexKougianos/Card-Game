#ifndef _TYPECONVERTER_HPP_
#define _TYPECONVERTER_HPP_

// #include "Card.hpp"
// #include "Personality.hpp"
// #include "Holding.hpp"
// #include "Follower.hpp"
// #include "Item.hpp"
#include "GreenCards.hpp"
#include "BlackCards.hpp"

enum Personalities{ATTACKER, DEFENDER, SHOGUN, CHANCELLOR, CHAMPION};
enum Holdings{PLAIN, MINE, GOLD_MINE, CRYSTAL_MINE, FARMS, SOLO, STRONGHOLD};
enum Followers{FOOTSOLDIER, ARCHER, SIΕGER, CAVALRY, NAVAL, BUSHIDO};
enum Items{KATANA, SPEAR, BOW, NINJATO, WAKIZASHI};

class TypeConverter
{
public:
	TypeConverter();
	void getCorrectType(BlackCard *card, Personality **person, Holding **hold);
	void getCorrectType(GreenCard *card, Follower **follow, Item **item);
	Personality *getPersonality(BlackCard *d);
	Holding *getHolding(BlackCard *d);
	Follower *getFollower(GreenCard *d);
	Item *getItem(GreenCard *d);
};

#endif
