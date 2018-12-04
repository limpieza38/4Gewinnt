//
// Created by Britta on 03.12.2018.
//

#include <iostream>
#include "Player.h"
#include "PlayingField.h"
#include "GameMachine.h"


int GameMachine::playAGame(Player* playerA, Player* playerB) {
    PlayingField field = PlayingField(playerA, playerB);
    playingField = &field;
    while (true) {
        playOneMove();
        if (playingField->proofWinner()) {
            if (print) {
                std::cout << "Player " << playingField->currentPlayer->name << " wins!" << std::endl;
                playingField->print();
            }
            playingField->currentPlayer->printStorageToFile();
            return playingField->currentPlayer->name;
        }
        if (playingField->isFull()) {
            if (print) {
                std::cout << "Remis!" << std::endl;
            }
            return 0;
        }
        playingField->switchPlayer();
    }
}

void GameMachine::playOneMove() {
    Move move;
    bool ok = false;
    int col;
    if (print) {
        playingField->print();
    }
    while (!(ok || playingField->isFull())) {
        col = playingField->currentPlayer->play(playingField);
        ok = playingField->setStone(col);
        if (!ok && print) {
            std::cout << "Column " << col << " is already full!" << std::endl;
        }
    }
}

