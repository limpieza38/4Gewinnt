//
// Created by Britta on 14.11.2018.
//

#ifndef INC_4GEWINNT_PLAYINGFIELD_H
#define INC_4GEWINNT_PLAYINGFIELD_H

#include <array>

class Player;

class PlayingField
{
private:
  const int rows = 6;
  const int columns = 7;
  int stones = 0;
  int maxStones = 42;
  int lastRow = -1;
  int lastColumn = -1;
    std::array<std::array<int, 7>, 6>  field=
            {{{0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0}}};

public:
  Player* currentPlayer;
  Player* waitingPlayer;
  PlayingField(Player* playerOne,Player* playerTwo);
  void print();
  bool setStone(int column);
  void switchPlayer();
  bool proofWinner();
  bool isFull();
    std::array<std::array<int, 7>, 6>  copyField();
};
#endif //INC_4GEWINNT_PLAYINGFIELD_H
