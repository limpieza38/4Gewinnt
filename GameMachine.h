//
// Created by Britta on 03.12.2018.
//

#ifndef INC_4GEWINNT_GAMEMACHINE_H
#define INC_4GEWINNT_GAMEMACHINE_H

#include "Player.h"

class GameMachine {
private:
    PlayingField * playingField;
    static const bool print = true;
    void playOneMove();
public:
    int playAGame(Player* playerA, Player* playerB);
};


#endif //INC_4GEWINNT_GAMEMACHINE_H
