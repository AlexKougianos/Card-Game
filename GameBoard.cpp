#include "GameBoard.hpp"

GameBoard::GameBoard()
{
    player1 = new Player();
    player2 = new Player();
    playerTurn = 0;
    currentPhase = starting;
}

void GameBoard::initializeGameBoard()
{
    int handSize;
    // cout << "Give starting number of cards in hand."<<endl;
    // cin >> handSize;
    handSize = STARTINGHANDSIZE;

    player1->createHand(handSize);
    player2->createHand(handSize);

    player1->createProvinces();
    player2->createProvinces();

    playerTurn = (player1->getHonour() >= player2->getHonour()) ? 1 : 2;
}

void GameBoard::gameplay()
{
    do
    {
        cout << "\e[1m"
             << "\n--- Starting Phase: ---\n"
             << "\e[0m" << endl;
        startingPhase(1);
        startingPhase(2);
        cout << "\n--- Equip Phase: ---\n"
             << endl;
        equipPhase(1);
        equipPhase(2);
        cout << "\n--- Battle Phase: ---\n"
             << endl;
        battlePhase(1);
        battlePhase(2);
        cout << "\n--- Economy Phase: ---\n"
             << endl;
        economyPhase(1);
        economyPhase(2);
        cout << "\n--- Final Phase: ---\n"
             << endl;
        finalPhase(1);
        finalPhase(2);
    } while (checkWinningCondition() == 0);
}

void GameBoard::startingPhase(int player)
{
    Player *currentPlayer = getPlayer(player);
    cout << "\e[1m"
         << "Player" << player << ":\n"
         << "\e[0m" << endl;
    currentPlayer->untapEverything();
    currentPlayer->drawFateCard();
    currentPlayer->revealProvinces();
    currentPlayer->printHand();
    currentPlayer->printProvinces();
}

void GameBoard::equipPhase(int player)
{
    Player *currentPlayer = getPlayer(player);
    cout << "\nPlayer" << player << ": " << endl;

    if (currentPlayer->getArmy()->size() == 0)
    {
        cout << "Player does not have an army yet!" << endl;
        return;
    }

    // equip
    list<Personality *>::iterator armyIt;
    Personality *personality;

    list<GreenCard *>::iterator handIt;
    GreenCard *tempCard;

    int handCard, armyCard, i;

    do
    {
        currentPlayer->printArmy();
        cout << "Choose which Personality to equip: (0 to exit)" << endl;
        cin >> armyCard;

        if (armyCard > 0 && armyCard <= currentPlayer->getArmy()->size())
        {
            i = 1;
            for (armyIt = currentPlayer->getArmy()->begin(); armyIt != currentPlayer->getArmy()->end(); armyIt++)
            {
                if (i == armyCard)
                {
                    personality = *armyIt;
                    cout << "You picked " << personality->getName() << endl;
                }
            }

            currentPlayer->printHand(true);
            cout << "\nYou have " << currentPlayer->getMoney() << " gold" << endl;
            cout << "Choose a Fate card to buy: (0 to exit)" << endl;
            cin >> handCard;

            if(handCard > 0 && handCard <= currentPlayer->getHand()->size()) {
                i = 1;
                for (handIt = currentPlayer->getHand()->begin(); handIt != currentPlayer->getHand()->end(); handIt++)
                {
                    if (i == handCard)
                    {
                        tempCard = *handIt;
                        if (currentPlayer->getMoney() >= tempCard->getCost())
                        {
                            cout << "You Purchased " << tempCard->getName() << endl;
                            currentPlayer->getHand()->erase(handIt);
                            currentPlayer->setMoney(currentPlayer->getMoney() - tempCard->getCost());

                            // putting purchased card to the picked personality
                            if (getCorrectType(tempCard->getType()) == ITEM)
                            {
                                cout << "ITEM" << endl;
                                personality->addItem((Item*)tempCard);
                            }
                            else if (getCorrectType(tempCard->getType()) == FOLLOWER)
                            {
                                cout << "FOLLOWER" << endl;
                                personality->addFollower((Follower*)tempCard);    
                            }
                        }
                        else
                        {
                            cout << "You do not have enough money!" << endl;
                        }
                        break;
                    }
                    i++;
                }
            }
            else if(handCard != 0)
            {
                cout << "Wrong input. Try again!" << endl;
            }
            
        }
        else if(armyCard != 0)
        {
            cout << "Wrong input. Try again!" << endl;
        }
    } while (handCard != 0 && armyCard != 0);
}

void GameBoard::battlePhase(int player)
{
    Player *currentPlayer = getPlayer(player);
    cout << "Player" << player << ": " << endl;
}

void GameBoard::economyPhase(int player)
{
    Player *currentPlayer = getPlayer(player);
    cout << "\nPlayer" << player << ": " << endl;

    list<BlackCard *>::iterator it;
    BlackCard *tempCard;
    int answer, i, count = 4;

    do
    {
        currentPlayer->printProvinces(true);
        cout << "\nYou have " << currentPlayer->getMoney() << " gold" << endl;

        cout << "Give number you want to buy. (0 to exit)" << endl;
        cin >> answer;

        if (answer >= 0 && answer <= count)
        {
            i = 1;
            for (it = currentPlayer->getProvinces()->begin(); it != currentPlayer->getProvinces()->end(); it++)
            {
                if (i == answer)
                {
                    tempCard = *it;
                    if (currentPlayer->getMoney() >= tempCard->getCost())
                    {
                        cout << "You Purchased " << tempCard->getName() << endl;
                        currentPlayer->getProvinces()->erase(it);
                        currentPlayer->drawDynastyCard();
                        count--;
                        currentPlayer->setMoney(currentPlayer->getMoney() - tempCard->getCost());

                        // putting purchased card to holdings or army
                        if (getCorrectType(tempCard->getType()) == HOLDING)
                        {
                            currentPlayer->addHolding((Holding *)tempCard);
                        }
                        else if (getCorrectType(tempCard->getType()) == PERSONALITY)
                        {
                            currentPlayer->addPersonality((Personality *)tempCard);
                        }
                    }
                    else
                    {
                        cout << "You do not have enough money!" << endl;
                    }
                    break;
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

void GameBoard::finalPhase(int player)
{
    Player *currentPlayer = getPlayer(player);
    cout << "\nPlayer" << player << ": " << endl;
}

int GameBoard::checkWinningCondition()
{
    cout << "won?" << endl;
    int c;
    cin >> c;

    return c;
}

void GameBoard::printGameStatistics()
{
    cout << "Printing Statistics...\n"
         << endl;
}

Player *GameBoard::getPlayer(int i)
{
    switch (i)
    {
    case 1:
        return player1;
    case 2:
        return player2;
    default:
        return NULL;
    }
}

int GameBoard::getCurrentPhase()
{
    return currentPhase;
}

// cout << "\nPlayer1:\n\n" << endl;
// //printing card names
// list<GreenCard*>* green = player1->getFateDeck();
// GreenCard* card;
// list<GreenCard*>::iterator it;
// int i = 1;
// for (it = green->begin(); it != green->end(); it++) {
//     card = *it;
// 	cout << i << ": " << card->getName() << endl;
//     i++;
// }
// cout << "\nPlayer2:\n\n" << endl;
// //printing card names
// i = 1;
// green = player2->getFateDeck();
// for (it = green->begin(); it != green->end(); it++) {
//     card = *it;
// 	cout << i << ": " << card->getName() << endl;
//     i++;
// }