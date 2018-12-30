//
// Created by Britta on 14.11.2018.
//

#ifndef INC_4GEWINNT_PLAYINGFIELD_H
#define INC_4GEWINNT_PLAYINGFIELD_H

#include <array>
#include "neuralNetwork/NeuralNetwork.h"
#define ROWS 6
#define COLUMNS 7
class Player;

class PlayingField
{
private:
  int stones = 0;
  int maxStones = 42;
  int lastRow = -1;
  int lastColumn = -1;

public:
    std::array<std::array<int, COLUMNS>, ROWS>  field=
            {{{0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0}}};
  Player* currentPlayer;
  Player* waitingPlayer;
  PlayingField(Player* playerOne,Player* playerTwo);
  void print();
  bool setStone(int column);
  void switchPlayer();
  bool proofWinner();
  bool isFull();
  std::array<std::array<int, 7>, 6> copyField();
  std::array<int, 42> toOneDimensionalArray();
};

#endif //INC_4GEWINNT_PLAYINGFIELD_H
