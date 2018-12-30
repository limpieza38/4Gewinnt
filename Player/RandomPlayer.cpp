//
// Created by Britta on 28.11.2018.
//
#include <functional>
#include "RandomPlayer.h"

int RandomPlayer::play(PlayingField *_playingField)
{
    return rand() % 7;
}

int RandomPlayer::chooseOtherColumn()
{
    return rand() % 7;
}
