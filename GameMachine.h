//
// Created by Britta on 03.12.2018.
//

#ifndef INC_4GEWINNT_GAMEMACHINE_H
#define INC_4GEWINNT_GAMEMACHINE_H

#include "Player.h"
#include "PlayingField.h"

class GameMachine
{
private:
  PlayingField *playingField;
  static const bool print = true;
  void playOneMove();
  Player *currentPlayer;
  Player *waitingPlayer;
  void switchPlayer();

public:
  Player *playAGame(Player *player1, Player *player2);
};

#endif //INC_4GEWINNT_GAMEMACHINE_H
