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
            dice[1] = "";
            dice[2] = "";
            dice[3] = "";
            dice[4] = "";
            dice[5] = "";
        }

        void setWires();
        void setEW(string a, string b){ ExplosiveWire[0] = a; ExplosiveWire[1] = b;}
        void setDF(string a, string b){ DefuseWire[0] = a; DefuseWire[1] = b;}
        void setOptions(int i, int x, char t){wireOptions[i][x] = t;}
        void setClues();

        string intToString(int m, int i);
        string getExplosive(){return (ExplosiveWire[0] + " " + ExplosiveWire[1]);}
        string getDefuse(){return (DefuseWire[0] + " " + DefuseWire[1]);}
        char getWO(int i, int x){return wireOptions[i][x];}

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