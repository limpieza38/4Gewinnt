//
// Created by Britta on 28.11.2018.
//

#ifndef INC_4GEWINNT_RANDOMPLAYER_H
#define INC_4GEWINNT_RANDOMPLAYER_H

#include <random>
#include "Player.h"

class RandomPlayer : public Player
{
  private:
    static const std::default_random_engine generator;
    static const std::uniform_int_distribution<int> distribution;

  public:
    int play(PlayingField *);
    RandomPlayer(int name) : Player(name){};
};

#endif //INC_4GEWINNT_RANDOMPLAYER_H
