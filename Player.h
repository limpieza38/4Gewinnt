//
// Created by Britta on 28.11.2018.
//

#ifndef INC_4GEWINNT_PLAYER_H
#define INC_4GEWINNT_PLAYER_H

#include "MoveStorage.h"
#include "PlayingField.h"
#include <array>

class Player
{
public:
  int name;
  MoveStorage storage;
  Player(int name);
  virtual int play(PlayingField *_playingField) = 0;
  virtual int chooseOtherColumn() = 0;
  void printStorageToFile();
  void saveMove(std::array<std::array<int, 7>, 6> field, int column);
};

#endif //INC_4GEWINNT_PLAYER_H
