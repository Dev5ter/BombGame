#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cstdio>

using namespace std;

#include "bomb.hpp"

bool setSeed(int argc, char* argv[]);
bomb_t setUpBomb();
void theMainGame(bomb_t TNT);
void turnOfGame(bomb_t TNT, int& go, bool& yourTurn);

int main(int argc, char* argv[]){
    if(!setSeed(argc, argv)) return 1;
    
    bomb_t TNT = setUpBomb();

    theMainGame(TNT);

    TNT.printSolution();
    TNT.printAllClues();

    return 0;
}

bool setSeed(int argc, char* argv[]){
    if(argc != 2){
        fprintf(stderr, "usage: ./%s seed#\n", argv[0]);
        return false;
    }
    srand(atoi(argv[1]));
    return true;
}

bomb_t setUpBomb(){
    bomb_t b;
    b.setWires();
    b.setClues();
    return b;
}

void theMainGame(bomb_t TNT){
    int gameOver = 0; int player;
    cout << "Are you player 1/2?\n";
    cin >> player;
    bool yourTurn = !(player-1);
    while(!gameOver) turnOfGame(TNT, gameOver, yourTurn);
    
}

void turnOfGame(bomb_t TNT, int& go, bool& yourTurn){
    //Rolling of the dice
    int dice; char trash;
    if(yourTurn){
        dice = TNT.rollDice();
        printf("You rolled '%s' on the dice!\n", TNT.textDice(dice).c_str());
        TNT.diceToAction1(dice, go);
    }else{
        dice = TNT.rollDice();
        printf("They rolled '%s' on the dice!\n", TNT.textDice(dice).c_str());
        TNT.diceToAction2(dice, go);
    }

    yourTurn = !yourTurn;

    cout << "Press and Enter any key to move on to the next turn!\n";
    cin >> trash;
}