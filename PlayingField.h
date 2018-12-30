//
// Created by Britta on 14.11.2018.
//

#ifndef INC_4GEWINNT_PLAYINGFIELD_H
#define INC_4GEWINNT_PLAYINGFIELD_H

#include <array>

class PlayingField
{
private:
  const int rows = 6;
  const int columns = 7;
  int stones = 0;
  int maxStones = 42;
  int lastRow = -1;
  int lastColumn = -1;
  std::array<std::array<int, 7>, 6> field =
      {{{0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0}}};

public:
  void print();
  bool setStone(int column, int color);
  bool proofWinner();
  bool isFull();
  std::array<std::array<int, 7>, 6> copyField();
  std::array<int, 42> toOneDimensionalArray();
};

#endif //INC_4GEWINNT_PLAYINGFIELD_H
