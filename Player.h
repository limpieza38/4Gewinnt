//
// Created by Britta on 28.11.2018.
//

#ifndef INC_4GEWINNT_PLAYER_H
#define INC_4GEWINNT_PLAYER_H


#include "MoveStorage.h"

class PlayingField;

class Player {
private:
    static int lastName;
public:
    int name;
    MoveStorage storage;
    Player();
    virtual int play(PlayingField* _playingField)=0;
    void printStorageToFile();
};


#endif //INC_4GEWINNT_PLAYER_H
