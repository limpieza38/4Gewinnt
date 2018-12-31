//
// Created by Britta on 03.12.2018.
//

#ifndef INC_4GEWINNT_GAMEMACHINE_H
#define INC_4GEWINNT_GAMEMACHINE_H

#include "Player/Player.h"
#include "PlayingField.h"

class GameMachine
{
private:
  PlayingField *playingField;
  static const bool print = true;
  Player *currentPlayer;
  Player *waitingPlayer;
  void switchPlayer();
  void playOneMove();

public:
  Player *playAGame(Player *playerA, Player *playerB);
};

#endif //INC_4GEWINNT_GAMEMACHINE_H
