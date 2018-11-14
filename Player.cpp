//
// Created by Britta on 14.11.2018.
//
#include <stdlib.h>

class Player{

public:
    virtual int play(int *) = 0;
};




class RandomPlayer : public Player{

public:
    int play(int *field){
        int test = rand() % 7;
        int test2 = rand() % 7;
        int test3 = rand() % 7;

        return rand()% 7;
    }
};