//
// Created by Britta on 28.11.2018.
//

#include <iostream>
#include "Player.h"
#include "CmdInputPlayer.h"
#include "PlayingField.h"


int CmdInputPlayer::play(PlayingField* _playingField){
    int col;
    _playingField->print(),
    std::cout << "Player " << name << ", choose column to play: ";
    std::cin >> col;
    return col-1;
}