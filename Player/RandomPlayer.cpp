//
// Created by Britta on 28.11.2018.
//
#include <functional>
#include "RandomPlayer.h"

int RandomPlayer::play(PlayingField *_playingField)
{
    while (true)
    {
        int col = rand() % 7;
        bool ok = _playingField->tryStone(col, this->name);
        if (ok)
        {
            this->saveMove(_playingField->copyField(), col);
            _playingField->setStone(col, this->name);
            return col;
        }
    }
}
