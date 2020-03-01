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
        cout << "\e[1m"
             << "\n----- STARTING PHASE: -----\n"
             << "\e[0m" << endl;
        startingPhase(1);
        enterToContinue();
        startingPhase(2);
        enterToContinue();

        cout << "\e[1m"
             << "\n----- EQUIP PHASE: -----\n"
             << "\e[0m" << endl;
        equipPhase(1);
        enterToContinue();
        equipPhase(2);
        enterToContinue();

        cout << "\e[1m"
             << "\n----- BATTLE PHASE: -----\n"
             << "\e[0m" << endl;
        battlePhase(1, 2);
        enterToContinue();

        cout << "\e[1m"
             << "\n----- ECONOMY PHASE: -----\n"
             << "\e[0m" << endl;
        economyPhase(1);
        enterToContinue();
        economyPhase(2);
        enterToContinue();
        
        cout << "\e[1m"
             << "\n----- FINAL PHASE: -----\n"
             << "\e[0m" << endl;
        finalPhase(1);
        finalPhase(2);
    } while (checkWinningCondition(1, 2) == 0);
}

void GameBoard::startingPhase(int player)
{
    Player *currentPlayer = getPlayer(player);
    cout << "\e[1m"
         << "     PLAYER" << player << ":\n"
         << "\e[0m" << endl;
    cout << "You are granted with extra " << currentPlayer->getHarvest();
    cout << " gold from your Harvest!" <<endl;
    currentPlayer->setMoney(currentPlayer->getMoney() + currentPlayer->getHarvest());
    cout << "You now have " << currentPlayer->getMoney() << " gold." << endl;
    currentPlayer->untapEverything();
    currentPlayer->drawFateCard();
    currentPlayer->revealProvinces();
    currentPlayer->printHand();
    currentPlayer->printProvinces();
}

void GameBoard::equipPhase(int player)
{
    Player *currentPlayer = getPlayer(player);
    cout << "\e[1m"
         << "     PLAYER" << player << ":\n"
         << "\e[0m" << endl;

    currentPlayer->equip();
}

void GameBoard::battlePhase(int player1, int player2)
{
    Player *currentPlayer1 = getPlayer(player1);
    Player *currentPlayer2 = getPlayer(player2);

    // if one player does not have an army we skip the battle phase
    if(currentPlayer1->getArmy()->size() == 0 || currentPlayer2->getArmy()->size() == 0)
    {
        cout << "Players do not have army to battle yet!" << endl;
        return;
    }

    cout << "\e[1m"
         << "     PLAYER" << player1 << ": PREPARING\n"
         << "\e[0m" << endl;

    currentPlayer1->prepareBattle(currentPlayer2);
    
    cout << "\e[1m"
         << "     PLAYER" << player2 << ": PREPARING\n"
         << "\e[0m" << endl;
    currentPlayer2->prepareBattle(currentPlayer1);

    cout << "\e[1m"
         << "     PLAYER" << player1 << ": BATTLE!\n"
         << "\e[0m" << endl;
    currentPlayer1->battle(currentPlayer2);

    cout << "\e[1m"
         << "     PLAYER" << player2 << ": BATTLE\n"
         << "\e[0m" << endl;
    currentPlayer2->battle(currentPlayer1);
}

void GameBoard::economyPhase(int player)
{
    Player *currentPlayer = getPlayer(player);
    cout << "\e[1m"
         << "     PLAYER" << player << ":\n"
         << "\e[0m" << endl;

    currentPlayer->economy();
}

void GameBoard::finalPhase(int player)
{
    Player *currentPlayer = getPlayer(player);
    cout << "\e[1m"
         << "     PLAYER" << player << ":\n"
         << "\e[0m" << endl;
}

int GameBoard::checkWinningCondition(int player, int enemy)
{
    Player *currentPlayer = getPlayer(player);
    Player *currentEnemy = getPlayer(enemy);
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

void GameBoard::enterToContinue()
{
    cout << "Press Enter to Continue\n" << endl;
    cin.ignore();
}

void GameBoard::winnigMessage(int winner, int loser) {
    cout << "       _____________________________________________         " <<endl
         << "      / # # # # # # # # # # # # # # # # # # # # # # \\       " <<endl
         << "     / # #                                       # # \\      " <<endl
         << "     | #         P L A Y E R   "<< winner <<"   WON ! ! !       # |       " <<endl
         << "     \\ # #                                       # # /      " <<endl
         << "      \\ # # # # # # # # # # # # # # # # # # # # # # /       " <<endl<<endl<<endl;

    cout << "       _____________________________________________         " <<endl
         << "      / ------------------------------------------- \\       " <<endl
         << "     / ___            P L A Y E R   "<< loser <<"            ___ \\      " <<endl
         << "     | _            P E R F O R M I N G            _ |       " <<endl
         << "     \\ ___           S E P P U K U !             ___ /      " <<endl
         << "      \\ ------------------------------------------- /       " <<endl<<endl;

    cout << "##############################|  ############################" <<endl
         << "###########################|       |#########################" <<endl
         << "########################|_____________|######################" <<endl
         << "###########################|_ 	     |#######################" <<endl
         << "##########################/ -	    /########################" <<endl
         << "###########################\\__      |########################"<<endl
         << "############################|__    /#########################" <<endl
         << "##############################\\__ |_#########################"<<endl
         << "#############################/ /    |########################" <<endl
         << "############################| |     \\########################"<<endl
         << "############################|  \\     \\#######################"<<endl
         << "###########################/    \\     |######################"<<endl
         << "###############__#########|      |     |#####################" <<endl
         << "############___||---------|/    /     /------_###############" <<endl
         << "###########|____  _______ | -- /     /______\\ \\##############"<<endl
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