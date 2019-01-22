//
// Created by Britta on 28.11.2018.
//

#include <iostream>
#include "CmdInputPlayer.h"
#include "../Move.h"

int CmdInputPlayer::play(PlayingField *_playingField)
{

    _playingField->print();
    std::cout << "Player " << this->name << ", choose column to play: ";
    int col = 0;
    while (true)
    {
        std::cin >> col;
        col--;
        bool ok = _playingField->tryStone(col, this->name);
        if (ok)
        {
            this->saveMove(_playingField->copyField(), col);
            _playingField->setStone(col, this->name);
            return col;
        }
        std::cout << "Column is already full, choose another one: ";
    }
}
