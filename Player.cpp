#include <iostream>

#include "Player.hpp"

using namespace std;

Player::Player()
{
    stronghold = new Stronghold("Stronghold");
    deckBuilder = new DeckBuilder();
    honour = stronghold->getStartingHonour();
    money = STARTINGMONEY;
    harvest = stronghold->getHarvestValue();

    // Creating decks
    fateDeck = deckBuilder->createFateDeck();
    dynastyDeck = deckBuilder->createDynastyDeck();

    // Shuffling them
    deckBuilder->deckShuffler(fateDeck);
    deckBuilder->deckShuffler(dynastyDeck);

    holdings = new list<Holding *>();
    army = new list<Personality *>();
}

// Getters

int Player::getHonour() { return honour; }
int Player::getNumberOfProvinces() { return numberOfProvinces; }
int Player::getMoney() { return money; }
int Player::getHarvest() { return harvest; }
int Player::getToAttack() { return toAttack; }
int Player::getTotalAttack() { return totalAttack; }
int Player::getTotalDefence() { return totalDefence; }
Stronghold *Player::getStronghold() { return stronghold; }
list<GreenCard *> *Player::getFateDeck() { return fateDeck; }
list<BlackCard *> *Player::getDynastyDeck() { return dynastyDeck; }
list<GreenCard *> *Player::getHand() { return hand; }
list<BlackCard *> *Player::getProvinces() { return provinces; }
list<Holding *> *Player::getHoldings() { return holdings; }
list<Personality *> *Player::getArmy() { return army; }

// Setters

void Player::setHonour(int) {}
void Player::setNumberOfProvinces(int) {}
void Player::setMoney(int newMoney) { money = newMoney; }
void Player::setHarvest(int newHarvest) { harvest = newHarvest; }
void Player::setToAttack(int _toAttack) { toAttack = _toAttack; }
void Player::setTotalAttack(int _totalAttack) { totalAttack = _totalAttack; }
void Player::setTotalDefence(int _totalDefence) { totalDefence = _totalDefence; }
void Player::setStronghold(Stronghold &) {}
void Player::setFateDeck(list<GreenCard *> &) {}
void Player::setDynastyDeck(list<BlackCard *> &) {}
void Player::setHand(list<GreenCard *> &) {}
void Player::setProvinces(list<BlackCard *> &) {}
void Player::setHoldings(list<Holding *> &) {}
void Player::setArmy(list<Personality *> &) {}

void Player::addHolding(Holding *holding)
{
    setHarvest(getHarvest() + holding->getHarvestValue());

    // links...

    holdings->push_front(holding);
}

void Player::addPersonality(Personality *personality)
{
    army->push_front(personality);
}

// Add Item to Personality
bool Player::addItem(Personality *personality, Item *item)
{
    if (personality->getFollowers()->size() >= MAX_FOLLOWERS)
    {
        cout << "Can not add another follower" << endl;
        return false;
    }

    if (personality->getHonour() < item->getMinimumHonour())
    {
        cout << item->getMinimumHonour() << " honour is required to attach ";
        cout << item->getName() << " to " << personality->getName() << endl;
        return false;
    }

    if (getMoney() >= item->getCost())
    {
        cout << "You Purchased " << item->getName() << endl;
        setMoney(getMoney() - item->getCost());

        cout << "You have " << getMoney() << " gold" << endl;
        cout << "Do you want the bonus for " << item->getEffectCost() << " gold? (y for Yes, n for No)" << endl;
        char answer;
        cin >> answer;
        if (answer == 'y' or answer == 'Y')
        {
            if (getMoney() < item->getEffectCost())
            {
                cout << "You do not have enough gold" << endl;
            }
            else
            {
                item->setAttackBonus(item->getAttackBonus() + item->getEffectBonus());
                item->setDefenceBonus(item->getDefenceBonus() + item->getEffectBonus());
                setMoney(getMoney() - item->getEffectCost());
            }
        }
        personality->setAttack(personality->getAttack() + item->getAttackBonus());
        personality->setDefence(personality->getDefence() + item->getDefenceBonus());

        personality->addItem(item);
        return true;
    }
    else
    {
        cout << "You do not have enough money!" << endl;
        return false;
    }
}

// Add Follower to Personality
bool Player::addFollower(Personality *personality, Follower *follower)
{
    if (personality->getFollowers()->size() >= MAX_FOLLOWERS)
    {
        cout << "Can not add another follower" << endl;
        return false;
    }

    if (personality->getHonour() < follower->getMinimumHonour())
    {
        cout << follower->getMinimumHonour() << " honour is required to attach ";
        cout << follower->getName() << " to " << personality->getName() << endl;
        return false;
    }

    if (getMoney() >= follower->getCost())
    {
        cout << "You Purchased " << follower->getName() << endl;
        setMoney(getMoney() - follower->getCost());

        cout << "You have " << getMoney() << " gold" << endl;
        cout << "Do you want the bonus for " << follower->getEffectCost() << " gold? (y for Yes, n for No)" << endl;
        char answer;
        cin >> answer;
        if (answer == 'y' or answer == 'Y')
        {
            if (getMoney() < follower->getEffectCost())
            {
                cout << "You do not have enough gold" << endl;
            }
            else
            {
                follower->setAttackBonus(follower->getAttackBonus() + follower->getEffectBonus());
                follower->setDefenceBonus(follower->getDefenceBonus() + follower->getEffectBonus());
                setMoney(getMoney() - follower->getEffectCost());
            }
        }
        personality->setAttack(personality->getAttack() + follower->getAttackBonus());
        personality->setDefence(personality->getDefence() + follower->getDefenceBonus());

        personality->addFollower(follower);
        return true;
    }
    else
    {
        cout << "You do not have enough money!" << endl;
        return false;
    }
}

// Create
void Player::createHand(int numberOfCards)
{
    hand = new list<GreenCard *>();
    maxHandSize = numberOfCards;
    GreenCard *tempCard;
    for (int i = 0; i < numberOfCards; i++)
    {
        tempCard = fateDeck->front(); // Getting the first item of Fate Date
        hand->push_front(tempCard);   // Putting it in Hand
        fateDeck->pop_front();        // Deleting it from the Fate Deck
    }
}

void Player::createProvinces()
{
    provinces = new list<BlackCard *>();
    BlackCard *tempCard;
    for (int i = 0; i < 4; i++)
    {
        tempCard = dynastyDeck->front(); // Getting the first item of Dynasty Date
        provinces->push_front(tempCard); // Putting it in the Provinces
        dynastyDeck->pop_front();        // Deleting it from the Dynasty Deck
    }
}

// Starting Phase
void Player::untapEverything()
{
    cout << "Untap everything.." << endl;

    BlackCard *tempCard;
    if (holdings != NULL)
    {
        list<Holding *>::iterator it;
        for (it = holdings->begin(); it != holdings->end(); it++)
        {
            tempCard = *it;
            tempCard->setIsTapped(false);
        }
    }

    if (army != NULL)
    {
        list<Personality *>::iterator it2;
        for (it2 = army->begin(); it2 != army->end(); it2++)
        {
            tempCard = *it2;
            tempCard->setIsTapped(false);
        }
    }
}

void Player::drawFateCard()
{
    cout << "Draw Fate Card..." << endl;

    if (hand->size() == MAXHANDSIZE)
    {
        cout << "Cannot draw another card!" << endl;
        return;
    }
    GreenCard *tempCard;
    tempCard = fateDeck->front(); // Getting the first item of Fate Date
    hand->push_front(tempCard);   // Putting it in Hand
    fateDeck->pop_front();        // Deleting it from the Fate Deck
}

void Player::drawDynastyCard()
{
    cout << "Draw Dynasty Card..." << endl;

    if (provinces->size() == 4)
    {
        cout << "Cannot draw another card!" << endl;
        return;
    }
    BlackCard *tempCard;
    tempCard = dynastyDeck->front(); // Getting the first item of Dynasty Date
    provinces->push_back(tempCard);  // Putting it in Provinces
    dynastyDeck->pop_front();        // Deleting it from the Dynasty Deck
}

void Player::revealProvinces() // Making all Provinces revealed
{
    cout << "Reveal Provinces..." << endl;
    BlackCard *tempCard;
    list<BlackCard *>::iterator it;
    for (it = provinces->begin(); it != provinces->end(); it++)
    {
        tempCard = *it;
        tempCard->setIsRevealed(true);
    }
}

void Player::printHand(bool costs)
{
    cout << "\nPrinting hand:\n"
         << endl;
    GreenCard *tempCard;
    list<GreenCard *>::iterator it;
    int i = 1;
    for (it = hand->begin(); it != hand->end(); it++)
    {
        tempCard = *it;
        cout << i << ": " << tempCard->getName();
        if (costs)
        {
            cout << " (" << tempCard->getCost() << "g, ";
            cout << tempCard->getMinimumHonour() << " Minimum Honour)";
        }
        cout << endl;
        i++;
    }
    cout << "\n";
}

void Player::printProvinces(bool costs)
{
    cout << "\nPrinting Revealed Provinces:\n"
         << endl;
    BlackCard *tempCard;
    list<BlackCard *>::iterator it;
    int i = 1;
    for (it = provinces->begin(); it != provinces->end(); it++)
    {
        tempCard = *it;
        if (tempCard->getIsRevealed() == true)
        {
            cout << i << ": " << tempCard->getName();
            if (costs)
            {
                cout << " (" << tempCard->getCost() << "g)";
            }
            cout << endl;
        }
        i++;
    }
    cout << "\n";
}

void Player::printArmy(bool honour)
{
    cout << "\nPrinting Army:\n"
         << endl;
    Personality *tempCard;
    list<Personality *>::iterator it;
    int i = 1;
    for (it = army->begin(); it != army->end(); it++)
    {
        tempCard = *it;
        if (tempCard->getIsDead() == false)
        {
            cout << i << ": " << tempCard->getName();
            if (honour)
            {
                cout << " (Honour: " << tempCard->getHonour() << ")";
            }
            cout << endl;
        }
        i++;
    }
    cout << "\n";
}

void Player::printHoldings()
{
    cout << "\nPrinting Holdings:\n"
         << endl;
    BlackCard *tempCard;
    list<Holding *>::iterator it;
    int i = 1;
    for (it = holdings->begin(); it != holdings->end(); it++)
    {
        tempCard = *it;
        cout << i << ": " << tempCard->getName() << endl;
        i++;
    }
    cout << "\n";
}

// equip phase
void Player::equip()
{
    if (getArmy()->size() == 0)
    {
        cout << "Player does not have an army yet!\n"
             << endl;
        return;
    }

    list<Personality *>::iterator armyIt;
    Personality *personality;

    list<GreenCard *>::iterator handIt;
    GreenCard *tempCard;

    int handCard, armyCard, i;

    do
    {
        printArmy(true);
        cout << "Choose which Personality to equip: (0 to exit)" << endl;
        cin >> armyCard;

        if (armyCard > 0 && armyCard <= getArmy()->size())
        {
            i = 1;
            for (armyIt = getArmy()->begin(); armyIt != getArmy()->end(); armyIt++)
            {
                if (i == armyCard)
                {
                    personality = *armyIt;
                    cout << "You picked: ";
                    personality->print();
                }
                i++;
            }

            printHand(true);
            cout << "\nYou have " << getMoney() << " gold" << endl;
            cout << "Choose a Fate card to buy: (0 to exit)" << endl;
            cin >> handCard;

            if (handCard > 0 && handCard <= getHand()->size())
            {
                i = 1;
                for (handIt = getHand()->begin(); handIt != getHand()->end(); handIt++)
                {
                    if (i == handCard)
                    {
                        tempCard = *handIt;
                        bool purchase;
                        if (getCorrectType(tempCard->getType()) == ITEM)
                        {
                            purchase = addItem(personality, (Item *)tempCard);
                        }
                        else if (getCorrectType(tempCard->getType()) == FOLLOWER)
                        {
                            purchase = addFollower(personality, (Follower *)tempCard);
                        }

                        if (purchase)
                        {
                            getHand()->erase(handIt);
                        }

                        break;
                    }
                    i++;
                }
            }
            else if (handCard != 0)
            {
                cout << "Wrong input. Try again!" << endl;
            }
        }
        else if (armyCard != 0)
        {
            cout << "Wrong input. Try again!" << endl;
        }
    } while (handCard != 0 && armyCard != 0);
}

// prepare battle
void Player::prepareBattle(Player *enemyPlayer)
{
    // init attack, defence
    setTotalAttack(0);
    setTotalDefence(stronghold->getInitialDefence());

    cout << "\nEnemy Provinces: " << endl;
    enemyPlayer->printProvinces();
    do
    {
        cout << "\nWhich enemy province do you want to attack? (0 to skip attack)" << endl;
        cin >> toAttack;
    } while (toAttack < 0 || toAttack > enemyPlayer->getNumberOfProvinces());

    printArmy();

    int index, i;
    do
    {
        cout << "\nChoose which Personality to activate: (0 to exit)" << endl;
        cin >> index;
        if (index < 0 || index > getArmy()->size())
        {
            cout << "Wrong input. Try again!" << endl;
        }
        else
        {
            Personality *personality;
            list<Personality *>::iterator it;
            i = 1;
            for (it = army->begin(); it != army->end(); it++)
            {
                if (i == index)
                {
                    personality = *it;
                    if (personality->getIsTapped() == true)
                    {
                        cout << "Personality is already Tapped" << endl;
                        break;
                    }
                    personality->setIsTapped(true);
                    cout << personality->getName() << " was activated!" << endl;
                    setTotalAttack(getTotalAttack() + personality->getAttack());
                    setTotalDefence(getTotalDefence() + personality->getDefence());
                }
                i++;
            }
        }
    } while (index != 0);
}

// battle
void Player::battle(Player *enemy)
{
    if (getToAttack() == 0)
    {
        cout << "Player does not intend to attack" << endl;
        return;
    }

    cout << "Player attacks Enemy Province " << getToAttack() << endl;

    enterToContinue();

    // printing battle statistics
    cout << "\nAttacker:" << endl;
    cout << "\tAttack: " << getTotalAttack() << endl;
    cout << "\tDefence: " << getTotalDefence() << endl;

    cout << "\nDefender:" << endl;
    cout << "\tAttack: " << enemy->getTotalAttack() << endl;
    cout << "\tDefence: " << enemy->getTotalDefence() << endl;

    enterToContinue();

    // determining winner
    if (getTotalAttack() > enemy->getTotalDefence())           // <----TODO
    {
        cout << "Attacker wins!" << endl;
        cout << "Defender's army died" << endl;
        Personality *personality;
        list<Personality *>::iterator it;
        for (it = enemy->getArmy()->begin(); it != enemy->getArmy()->end(); it++)
        {
            enemy->getArmy()->erase(it);
            it = enemy->getArmy()->begin();
        }
        cout << "army size = " << enemy->getArmy()->size() << endl;

        cout << "Destroying the attacked province" << endl;
        BlackCard* tempCard;
        list<BlackCard*>::iterator it2;
        int i = 1;
        for(it2 = enemy->getProvinces()->begin(); it2 != enemy->getProvinces()->end(); it2)
        {
            if(i == toAttack){
                enemy->getProvinces()->erase(it2);
                break;
            }
            i++;
        }
        cout << "enemy provinces = " << enemy->getProvinces()->size() << endl;
    }
    else if (getTotalAttack() < enemy->getTotalDefence())
    {
        cout << "Defender wins!" << endl;
    }
    else
    {
        cout << "It's a tie!" << endl;
    }
}

// economy phase
void Player::economy()
{
    list<BlackCard *>::iterator it;
    BlackCard *tempCard;
    int answer, i, count = 4;

    do          // A loop that shows available Provinces to buy
    {
        printProvinces(true);
        cout << "\nYou have " << getMoney() << " gold" << endl;

        cout << "Give number you want to buy. (0 to exit)" << endl;
        cin >> answer;
        if (answer == 0)
        {
            break;
        }

        if (answer <= count)        // Answer has to be revealed Province
        {
            i = 1;
            for (it = getProvinces()->begin(); it != getProvinces()->end(); it++)   // Loop to find picked Province
            {
                if (i == answer)
                {
                    tempCard = *it;

                    if (getMoney() >= tempCard->getCost())
                    {
                        cout << "You Purchased " << tempCard->getName() << endl;    // Purchase the card
                        getProvinces()->erase(it);                                  // Erase it from provinces
                        drawDynastyCard();                                          // Replacing it with new, not revealed card
                        setMoney(getMoney() - tempCard->getCost());
                        count--;                                                    // if count reaches 0, there are no revealed Provinces left

                        // putting purchased card to holdings or army
                        if (getCorrectType(tempCard->getType()) == HOLDING)         // Check is card is Holding or Personality
                        {

                            if (tempCard->getType() == MINE)                        // if card is Mine
                            {
                                if (!toSubHolding((Mine*)tempCard))                 // Check for Gold Mines to link
                                {
                                    addHolding((Holding*)tempCard);                 // if not, add to Holings
                                }
                            }

                            else if (tempCard->getType() == GOLD_MINE)              // if card is Gold Mine
                            {
                                // Check for Crystal Mines or Mines to link
                                if (!toSubHolding((GoldMine*)tempCard) && !toUpperHolding((GoldMine*)tempCard))             
                                {
                                    // if no Mine or Crystal Mines are available, add to Holdings
                                    addHolding((Holding*)tempCard);
                                }
                            }

                            else if (tempCard->getType() == CRYSTAL_MINE)           // if card is Crystal Mine
                            {
                                if (!toUpperHolding((CrystalMine*)tempCard))        // Check for Gold Mines to link
                                {
                                    addHolding((Holding*)tempCard);                 // if not, add to Holdings
                                }
                            }

                            else                                                    // if card is other Holdings
                            {
                                addHolding((Holding *)tempCard);                    // Add to Holdings
                            }

                        }

                        else if (getCorrectType(tempCard->getType()) == PERSONALITY)
                        {
                            addPersonality((Personality *)tempCard);    	        // if card is Personality, add to army
                        }

                    }

                    else
                    {
                        cout << "You do not have enough money!" << endl;
                    }

                    break;               // Start the initial loop again
                }

                i++;
            }
        }

        else
        {
            cout << "Wrong input. Try again!" << endl;
        }

    } while (answer != 0);
}

void Player::enterToContinue()
{
    cout << "Press Enter to Continue\n"
         << endl;
    cin.ignore();
}

// Check for available Upper Holding linkings
bool Player::toSubHolding (Mine* newMine)
{
    list<Holding*>::iterator it;
    Holding* tempCard;

    for (it = getHoldings()->begin(); it != getHoldings()->end(); it++)
    {
        tempCard = *it;

        // Check if current Holding is Gold Mine and available to link
        if (tempCard->getType() == GOLD_MINE)
        {
            if (((GoldMine*)tempCard)->getSubHolding() == NULL)
            {
                ((GoldMine*)tempCard)->setSubHolding(newMine);

                cout << newMine->getName() << " linked to:";
                cout << tempCard->getName() << endl;

                return true;         // Mine linked
            }
        }

        // Check if current is Crystal Mine with Gold Mine and available to link
        if (tempCard->getType() == CRYSTAL_MINE)
        {
            if (((CrystalMine*)tempCard)->getSubHolding() != NULL)
            {
                if (((CrystalMine*)tempCard)->getSubHolding()->getSubHolding() == NULL)
                {
                    ((CrystalMine*)tempCard)->setSubHolding(newMine);

                    cout << newMine->getName() << " linked to: ";
                    cout << tempCard->getName() << endl;

                    return true;    // Mine linked
                }
            }
        }
    }

    return false;        // No Gold or Crystal Mines available to link
}

// Check for available Upper Holding linkings
bool Player::toSubHolding (GoldMine* newGoldMine)
{
    list<Holding*>::iterator it;
    Holding* tempCard;

    for (it = getHoldings()->begin(); it != getHoldings()->end(); it++)
    {
        tempCard = *it;

        // Check if current Holding is Crystal Mine and available to link
        if (tempCard->getType() == CRYSTAL_MINE)
        {
            if (((CrystalMine*)tempCard)->getSubHolding() == NULL)
            {
                ((CrystalMine*)tempCard)->setSubHolding(newGoldMine);

                cout << newGoldMine->getName() << " linked to: ";
                cout << tempCard->getName() << endl;

                return true;        // Gold Mine linked
            }
            
        }
        
    }

    return false;        // No Crystal Mines available to link
}

// Check for available Sub Holding linkings
bool Player::toUpperHolding(GoldMine* newGoldMine)
{
    list<Holding*>::iterator it;
    Holding* tempCard;

    for (it = getHoldings()->begin(); it != getHoldings()->end(); it++)
    {
        tempCard = *it;

        // Check if current Holding is Mine and available to link
        if (tempCard->getType() == MINE)
        {
            if (((Mine*)tempCard)->getUpperHolding() == NULL)
            {
                ((Mine*)tempCard)->setUpperHolding(newGoldMine);

                cout << newGoldMine->getName() << " linked to: ";
                cout << tempCard->getName() << endl;

                return true;        // Gold Mine linked
            }
            
        }
        
    }

    return false;        // No Mines available to link
}
        
// Check for available Sub Holding linkings
bool Player::toUpperHolding(CrystalMine* newCrystalMine)
{
    list<Holding*>::iterator it;
    Holding* tempCard;

    for (it = getHoldings()->begin(); it != getHoldings()->end(); it++)
    {
        tempCard = *it;

        // Check if current Holding is Gold Mine and available to link
        if (tempCard->getType() == GOLD_MINE)
        {
            if (((GoldMine*)tempCard)->getUpperHolding() == NULL)
            {
                ((GoldMine*)tempCard)->setUpperHolding(newCrystalMine);

                cout << newCrystalMine->getName() << " linked to: ";
                cout << tempCard->getName() << endl;

                return true;         // Mine linked
            }
        }

        // Check if current is Crystal Mine with Gold Mine and available to link
        if (tempCard->getType() == MINE)
        {
            if (((Mine*)tempCard)->getUpperHolding() != NULL)
            {
                if (((Mine*)tempCard)->getUpperHolding()->getUpperHolding() == NULL)
                {
                    ((Mine*)tempCard)->setUpperHolding(newCrystalMine);

                    cout << newCrystalMine->getName() << " linked to: ";
                    cout << tempCard->getName() << endl;

                    return true;    // Mine linked
                }
            }
        }
    }

    return false;        // No Gold Mines or Mines available to link
}