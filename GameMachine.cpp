//
// Created by Britta on 03.12.2018.
//

#include <iostream>
#include "Player/Player.h"
#include "PlayingField.h"
#include "GameMachine.h"

Player *GameMachine::playAGame(Player *playerA, Player *playerB)
{
    playingField = new PlayingField(playerA, playerB);
    while (true)
    {
        playOneMove();
        if (playingField->proofWinner())
        {
            if (print)
            {
                playingField->print();
                std::cout << "Player " << playingField->currentPlayer->name << " wins!" << std::endl;
            }
            return playingField->currentPlayer;
        }
        if (playingField->isFull())
        {
            if (print)
            {
                std::cout << "Remis!" << std::endl;
            }
            return 0;
        }
        playingField->switchPlayer();
    }
}

void GameMachine::playOneMove()
{
    bool ok = false;
    int col;
    if (print)
    {
        playingField->print();
    }
    while (!ok && !playingField->isFull())
    {
        col = playingField->currentPlayer->play(playingField);
        ok = playingField->setStone(col);
        if (!ok && print)
        {
            std::cout << "Column " << col << " is already full!" << std::endl;
        }
    }
}

void GameMachine::switchPlayer()
{
    Player *lastPlayer = this->currentPlayer;
    this->currentPlayer = this->waitingPlayer;
    this->waitingPlayer = lastPlayer;
}
