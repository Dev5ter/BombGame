#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cstdio>

using namespace std;

#include "bomb.hpp"

bool setSeed(int argc, char* argv[]);
bomb_t setUpBomb();
void printSolution(bomb_t TNT);

int main(int argc, char* argv[]){
    if(!setSeed(argc, argv)) return 1;
    
    bomb_t TNT = setUpBomb();
    printSolution(TNT);
    TNT.printOneClue();
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

void printSolution(bomb_t TNT){
    printf("            Shape   \n");
    printf("        | T | C | S |\n");
    printf(" C                  \n");
    printf(" O   |R|  %c   %c   %c\n", TNT.getWO(0,0), TNT.getWO(0,1), TNT.getWO(0,2));
    printf(" L   |B|  %c   %c   %c\n", TNT.getWO(1,0), TNT.getWO(1,1), TNT.getWO(1,2));
    printf(" O   |G|  %c   %c   %c\n", TNT.getWO(2,0), TNT.getWO(2,1), TNT.getWO(2,2));
    printf(" R                  \n\n");
    printf("Explosive Wire: %s\n", TNT.getExplosive().c_str());
    printf("Defuse Wire:    %s\n", TNT.getDefuse().c_str());
}