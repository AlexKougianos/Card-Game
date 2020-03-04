#include "GameBoard.hpp"

GameBoard::GameBoard()
{
    player1 = new Player();
    player2 = new Player();
    playerTurn = 0;
}

void GameBoard::initializeGameBoard()
{
    int handSize = STARTINGHANDSIZE;

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
        cout << BGRN("---------- STARTING PHASE: ----------\n") << endl;
        sleep(2);
        startingPhase(1);
        enterToContinue();

        startingPhase(2);
        enterToContinue();

        cout << BGRN("---------- EQUIP PHASE: ----------\n") << endl;
        sleep(2);
        equipPhase(1);
        enterToContinue();

        equipPhase(2);
        enterToContinue();

        cout << BGRN("---------- BATTLE PHASE: ----------\n") << endl;
        sleep(2);
        battlePhase(1, 2);
        enterToContinue();

        cout << BGRN("---------- ECONOMY PHASE: ----------\n") << endl;
        sleep(2);
        economyPhase(1);
        enterToContinue();

        economyPhase(2);
        enterToContinue();
        
        cout << BGRN("---------- FINAL PHASE: ----------\n") << endl;
        sleep(2);
        finalPhase(1, 2);

    } while (checkWinningCondition(1, 2) == 0);
}

void GameBoard::startingPhase(int player)
{
    Player *currentPlayer = getPlayer(player);
    cout << BOLD("     PLAYER ") << player << ":\n" << endl;

    // Adding Money from harvest Value
    cout << BYEL("You are granted with extra ") << Bold << currentPlayer->getHarvest() << RST;
    cout << BYEL(" gold from your Harvest!") <<endl;

    currentPlayer->setMoney(currentPlayer->getMoney() + currentPlayer->getHarvest());
    cout << BYEL("You now have ") << Bold << currentPlayer->getMoney() << RST << BYEL(" gold.") << endl;

    currentPlayer->untapEverything();
    currentPlayer->drawFateCard();
    currentPlayer->revealProvinces();

    currentPlayer->printHand();
    currentPlayer->printProvinces();
}

void GameBoard::equipPhase(int player)
{
    Player *currentPlayer = getPlayer(player);
    cout << BOLD("     PLAYER ") << player << ":\n" << endl;

    currentPlayer->equip();
}

void GameBoard::battlePhase(int player1, int player2)
{
    Player *currentPlayer1 = getPlayer(player1);
    Player *currentPlayer2 = getPlayer(player2);

    // if both players do not have an army we skip the battle phase
    if(currentPlayer1->getArmy()->size() == 0 && currentPlayer2->getArmy()->size() == 0)
    {
        cout << BRED("Players do not have armies to battle!\n") << endl;
        return;
    }

    // Tapping for battle
    cout << BOLD("     PLAYER ") << player1 << BOLD(": PREPARING\n") << endl;
    currentPlayer1->prepareBattle(currentPlayer2);
    
    cout << BOLD("     PLAYER ") << player2 << BOLD(": PREPARING\n") << endl;
    currentPlayer2->prepareBattle(currentPlayer1);

    cout << endl << BOLD("     PLAYER ") << player1 << BOLD(": BATTLE!\n") << endl;
    currentPlayer1->battle(currentPlayer2);

    cout << endl << BOLD("     PLAYER ") << player2 << BOLD(": BATTLE!\n") << endl;
    currentPlayer2->battle(currentPlayer1);
}

void GameBoard::economyPhase(int player)
{
    Player *currentPlayer = getPlayer(player);
    cout << BOLD("     PLAYER ") << player << ":\n" << endl;

    currentPlayer->economy();
}

void GameBoard::finalPhase(int player1, int player2)
{
    discardSurplusFateCard(player1);
    discardSurplusFateCard(player2);

    printArena(player1, player2);
}

void GameBoard::discardSurplusFateCard(int player)
{
    Player* currentPlayer = getPlayer(player);

    if (currentPlayer->getHand()->size() <= MAXHANDSIZE)
    {
        return;
    }

    cout << BOLD("     PLAYER ") << player << ":\n" << endl;

    if (currentPlayer->getHand()->size() > MAXHANDSIZE)
    {
        list<GreenCard*>::iterator it;
        GreenCard* tempCard;
        int handCard, i;

        cout << BRED("Too many Fate Cards!") << endl;
        cout << BRED("Pick card to discard.");
        currentPlayer->printHand();

        do
        {
            cin >> handCard;

            if (handCard > 0 && handCard <= MAXHANDSIZE + 1)
            {
                i = 1;
                for (it = currentPlayer->getHand()->begin(); it != currentPlayer->getHand()->end(); it++)
                {
                    if (i == handCard)
                    {
                        tempCard = *it;
                        cout << tempCard->getName() << BBLU(" was discarded!\n") << endl;
                        currentPlayer->getHand()->erase(it);
                        break;
                    }
                    i++;
                }
            }
            else
            {
                cout << BRED("Wrong input. Try again!") << endl;
            }

        } while (handCard <= 0 && handCard > MAXHANDSIZE);
    }

    enterToContinue();
}

void GameBoard::printArena(int player1, int player2)
{
    Player* p1 = getPlayer(player1);
    Player* p2 = getPlayer(player2);

    cout << BOLD("###################") << endl
         << BOLD("#      ARENA      #") << endl
         << BOLD("###################") << endl;

    enterToContinue();

    cout << endl << "     PLAYER " << player1 << ":\n" << endl;
    p1->printArmy();
    p1->printHoldings();
    p1->printProvinces();
    p1->printStronghold();

    enterToContinue();

    cout << endl << "     PLAYER " << player2 << ":\n" << endl;
    p2->printArmy();
    p2->printHoldings();
    p2->printProvinces();
    p2->printStronghold();

    enterToContinue();
}

int GameBoard::checkWinningCondition(int player, int enemy)
{
    Player* currentPlayer = getPlayer(player);
    Player* currentEnemy = getPlayer(enemy);
    if(currentEnemy->getProvinces()->size() == 0) {
        winnigMessage(player, enemy);
        return player;
    }
    else if(currentPlayer->getProvinces()->size() == 0) {
        winnigMessage(enemy, player);
        return enemy;
    }
    return 0;
}

void GameBoard::printGameStatistics()
{
    cout << "Printing Statistics...\n" << endl;
}

Player* GameBoard::getPlayer(int i)
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

void GameBoard::enterToContinue()
{
    cout << BCYN("\nPress Enter to Continue\n");
    cin.ignore();
}

void GameBoard::winnigMessage(int winner, int loser) {
    cout << BGRN("       _____________________________________________         ") <<endl
         << BGRN("      / # # # # # # # # # # # # # # # # # # # # # # \\       ") <<endl
         << BGRN("     / # #                                       # # \\      ") <<endl
         << BGRN("     | #         P L A Y E R   "<< winner <<"   WON ! ! !       # |       ") <<endl
         << BGRN("     \\ # #                                       # # /      ") <<endl
         << BGRN("      \\ # # # # # # # # # # # # # # # # # # # # # # /       ") <<endl<<endl<<endl;

    cout << BRED("       _____________________________________________         ") <<endl
         << BRED("      / ------------------------------------------- \\       ") <<endl
         << BRED("     / ___            P L A Y E R   "<< loser <<"            ___ \\      ") <<endl
         << BRED("     | _            P E R F O R M I N G            _ |       ") <<endl
         << BRED("     \\ ___           S E P P U K U !             ___ /      ") <<endl
         << BRED("      \\ ------------------------------------------- /       ") <<endl<<endl;

    cout << "##############################|  ############################" <<endl
         << "###########################|       |#########################" <<endl
         << "########################|_____________|######################" <<endl
         << "###########################|_        |#######################" <<endl
         << "##########################/ -       /########################" <<endl
         << "###########################\\__      |########################"<<endl
         << "############################|__    /#########################" <<endl
         << "##############################\\__ |_#########################"<<endl
         << "#############################/ /    |########################" <<endl
         << "############################| |     \\########################"<<endl
         << "############################|  \\     \\#######################"<<endl
         << "###########################/    \\     |######################"<<endl
         << "###############__#########/      |     |#####################" <<endl
         << "############___||---------|/    /     /------_###############" <<endl
         << "###########|/_/_| _______ | -- /     /______\\ \\##############"<<endl
         << "###############||---------|\\  /    /--------/-###############"<<endl
         << "#########################/  /     ||#########################" <<endl
         << "#######################/    -/-/-//##########################" <<endl
         << "####################/         ___/###########################" <<endl
         << "###############_-/     __       \\   ___-#####################"<<endl
         << "##############|          -______  /     \\####################"<<endl
         << "################\\-                       |###################"<<endl
         << "###################\\________________--\\__|###################"<<endl
         << "#############################################################" <<endl
         <<endl;
}
