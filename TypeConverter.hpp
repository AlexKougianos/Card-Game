#ifndef _TYPECONVERTER_HPP_
#define _TYPECONVERTER_HPP_

enum PERSONALITY
{
    ATTACKER = 1,
    DEFENDER,
    SHOGUN,
    CHANCELLOR,
    CHAMPION
};
enum HOLDING
{
    PLAIN = 6,
    MINE,
    GOLD_MINE,
    CRYSTAL_MINE,
    FARMS,
    SOLO,
    STRONGHOLD
};
enum FOLLOWER
{
    FOOTSOLDIER = 13,
    ARCHER,
    SIEGER,
    CAVALRY,
    NAVAL,
    BUSHIDO
};
enum ITEM
{
    KATANA = 18,
    SPEAR,
    BOW,
    NINJATO,
    WAKIZASHI
};

enum TYPE
{
    PERSONALITY = 1,
    HOLDING,
    FOLLOWER,
    ITEM
};

int getCorrectType(int);

#endif