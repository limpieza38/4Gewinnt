//
// Created by Britta on 28.11.2018.
//

#ifndef INC_4GEWINNT_CMDINPUTPLAYER_H
#define INC_4GEWINNT_CMDINPUTPLAYER_H

#include "Player.h"
#include "../PlayingField.h"

class CmdInputPlayer : public Player
{
public:
  int play(PlayingField *);
  int chooseOtherColumn();
};

#endif //INC_4GEWINNT_CMDINPUTPLAYER_H
