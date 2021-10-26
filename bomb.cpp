#include <iostream>
#include <vector>
#include <string>

#include "bomb.hpp"

void bomb_t::setWires(){
    int s1, c1, s2, c2;
    s1 = rand()%3; c1 = rand()%3;
    setOptions(s1, c1, 'X');
    setEW(intToString(1, s1), intToString(0, c1));
    bool same = true;
    do{
        s2 = rand()%3; c2 = rand()%3;
        if(!(s2 == s1 && c2 == c1)) {
            setOptions(s2, c2, 'D');
            setDF(intToString(1, s2), intToString(0, c2));
            same = false;
        }
    }while(same);
}

string bomb_t::intToString(int mode, int rand){
    // 0 -> shape && 1 -> color
    if(mode == 0){
        if(rand == 0) return "Triangle";
        if(rand == 1) return "Circle";
        if(rand == 2) return "Square";
    }else{
        if(rand == 0) return "Red";
        if(rand == 1) return "Blue";
        if(rand == 2) return "Green";
    }
    return "ERROR";
}

void bomb_t::setClues(){
    string xHint = "Explosive Wire is ";
    clues.push_back(xHint + ExplosiveWire[0]);
    clues.push_back(xHint + ExplosiveWire[1]);
    string dHint = "Defusal Wire is NOT ";
    for(int i=0; i<3; i++){
        for(int x=0; x<3; x++){
            if(wireOptions[i][x] == 'D'){
                //Color
                if(i != 0) clues.push_back(dHint + intToString(1, 0));
                if(i != 1) clues.push_back(dHint + intToString(1, 1));
                if(i != 2) clues.push_back(dHint + intToString(1, 2));
                //Shape
                if(x != 0) clues.push_back(dHint + intToString(0, 0));
                if(x != 1) clues.push_back(dHint + intToString(0, 1));
                if(x != 2) clues.push_back(dHint + intToString(0, 2));
            }
        }
    }
}

void bomb_t::printOneClue(){
    int rng = rand()%clues.size();
    printf("The Clue: %s\n", clues[rng].c_str());
}

void bomb_t::printAllClues(){
    printf("The Clues:\n");
    for(int i=0; i<(int)clues.size(); i++) printf("\t%s\n",clues[i].c_str());
}