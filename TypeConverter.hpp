#ifndef _TYPECONVERTER_HPP_
#define _TYPECONVERTER_HPP_

// #include "BlackCards.hpp"

enum PERSONALITY{ATTACKER = 1, DEFENDER, SHOGUN, CHANCELLOR, CHAMPION};
enum HOLDING{PLAIN = 6, MINE, GOLD_MINE, CRYSTAL_MINE, FARMS, SOLO, STRONGHOLD};
enum FOLLOWER{FOOTSOLDIER = 13, ARCHER, SIEGER, CAVALRY, NAVAL, BUSHIDO};
enum ITEM{KATANA = 18, SPEAR, BOW, NINJATO, WAKIZASHI};

enum TYPE{PERSONALITY = 1, HOLDING, FOLLOWER, ITEM};

int getCorrectType(int);

// class TypeConverter
// {
// public:
// 	TypeConverter();
// 	void getCorrectType(BlackCard *card, Personality **person, Holding **hold);
// 	void getCorrectType(GreenCard *card, Follower **follow, Item **item);
// 	Personality *getPersonality(BlackCard *d);
// 	Holding *getHolding(BlackCard *d);
// 	Follower *getFollower(GreenCard *d);
// 	Item *getItem(GreenCard *d);
// };

#endif