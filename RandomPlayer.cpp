//
// Created by Britta on 28.11.2018.
//
#include "Player.h"
#include <functional>
#include "RandomPlayer.h"
#include "PlayingField.h"

int RandomPlayer::play(PlayingField *_playingField) {
    return rand() % 7;
}
