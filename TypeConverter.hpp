#ifndef _TYPECONVERTER_HPP_
#define _TYPECONVERTER_HPP_

#include "BlackCards.hpp"

enum Personalities{ATTACKER = 1, DEFENDER, SHOGUN, CHANCELLOR, CHAMPION} PERSONALITY;
enum Holdings{PLAIN = 6, MINE, GOLD_MINE, CRYSTAL_MINE, FARMS, SOLO, STRONGHOLD} HOLDING;
enum Followers{FOOTSOLDIER = 13, ARCHER, SIEGER, CAVALRY, NAVAL, BUSHIDO} FOLLOWER;
enum Items{KATANA = 18, SPEAR, BOW, NINJATO, WAKIZASHI} ITEM;

// enum {PERSONALITY = 1, HOLDING, FOLLOWER, ITEM};

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