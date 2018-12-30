//
// Created by Britta on 28.11.2018.
//

#ifndef INC_4GEWINNT_RANDOMPLAYER_H
#define INC_4GEWINNT_RANDOMPLAYER_H

#include <random>
#include "Player.h"

class RandomPlayer : public Player
{
  public:
    int play(PlayingField *);
    int chooseOtherColumn();
    RandomPlayer(int name) : Player(name){};
};

#endif //INC_4GEWINNT_RANDOMPLAYER_H
