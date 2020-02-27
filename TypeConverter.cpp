#include "TypeConverter.hpp"

int getCorrectType(int type) {
	if(type >= 1 && type <= 5)
		return 1;
	if(type >= 6 && type <= 12)
		return 2;
	if(type >= 13 && type <= 17)
		return 3;
	if(type >= 18 && type <= 22)
		return 4;
}



// TypeConverter::TypeConverter() {}

// void TypeConverter::getCorrectType(BlackCard *card, Personality **person, Holding **hold)
// {
// 	if (card->getType() == PERSONALITY{}) {
// 		(*person) = getPersonality(card);
// 		(*hold) = NULL;
// 	}
// 	else {
// 		(*hold) = getHolding(card);
// 		(*person) = NULL;
// 	}
// }

// void TypeConverter::getCorrectType(GreenCard *card, Follower **follow, Item **item)
// {
// 	if (card->getType() == FOLLOWER{}) {
// 		(*follow) = getFollower(card);
// 		(*item) = NULL;
// 	}
// 	else {
// 		(*item) = getItem(card);
// 		(*follow) = NULL;
// 	}
// }

// Personality *TypeConverter::getPersonality(BlackCard *d)
// {
// 	if (d->getType() == PERSONALITY{})
// 		return (Personality *)d;
// 	return NULL;
// }

// Holding *TypeConverter::getHolding(BlackCard *d)
// {
// 	if (d->getType() == HOLDING)
// 		return (Holding *)d;
// 	return NULL;
// }

// Follower *TypeConverter::getFollower(GreenCard *d)
// {
// 	if (d->getType() == FOLLOWER{})
// 		return (Follower *)d;
// 	return NULL;
// }

// Item *TypeConverter::getItem(GreenCard *d)
// {
// 	if (d->getType() == ITEM{})
// 		return (Item *)d;
// 	return NULL;
// }
