#ifndef BOMB_H
#define BOMB_H

#include <iostream>
#include <vector>
using namespace std;

struct bomb_t{
    public:
        bomb_t(){
            ExplosiveWire[0] = ExplosiveWire[1] = DefuseWire[0] = DefuseWire[1] = "";
            for(int i=0; i<3; i++) for(int x=0; x<3; x++) wireOptions[i][x] = '~';
            dice[0] = "Cut Wire";
            dice[1] = "Cut Wire";
            dice[2] = "Clue";
            dice[3] = "Clue";
            dice[4] = "Clue & Cut Wire";
            dice[5] = "Clue & Opponent Force Cut";
        }

        void setWires();
        void setEW(string a, string b){ ExplosiveWire[0] = a; ExplosiveWire[1] = b;}
        void setDF(string a, string b){ DefuseWire[0] = a; DefuseWire[1] = b;}
        void setOptions(int i, int x, char t){wireOptions[i][x] = t;}
        void setClues();
        void printSolution();

        string intToString(int m, int i);
        string getExplosive(){return (ExplosiveWire[0] + " " + ExplosiveWire[1]);}
        string getDefuse(){return (DefuseWire[0] + " " + DefuseWire[1]);}
        char getWO(int i, int x){return wireOptions[i][x];}
        char getWO(string s);

        int rollDice(){return rand()%6;}
        string textDice(int i){return dice[i];}

        string giveClue(){return dice[rand()%6];}
        void cutWire(int &gameOver, bool, bool);

        void diceToAction1(int i, int& go);
        void diceToAction2(int i, int& go);

        void printOneClue();
        void printAllClues();
    private:
        //[0] SHAPE && [1] COLOR
        string ExplosiveWire[2];
        string DefuseWire[2];
        char wireOptions[3][3];
        vector<string> clues;
        string dice[6];
};

#endif