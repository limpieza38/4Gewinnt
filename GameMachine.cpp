//
// Created by Britta on 03.12.2018.
//

#include "GameMachine.h"
#include <iostream>

Player *GameMachine::playAGame(Player *player1, Player *player2)
{
    this->currentPlayer = player1;
    this->waitingPlayer = player2;
    this->playingField = new PlayingField();
    while (true)
    {
        playOneMove();
        if (this->playingField->proofWinner())
        {
            if (print)
            {
                this->playingField->print();
                std::cout << "Player " << this->currentPlayer->name << " wins!" << std::endl;
            }
            return this->currentPlayer;
        }
        if (this->playingField->isFull())
        {
            if (print)
            {
                std::cout << "Remis!" << std::endl;
            }
            return 0;
        }
        this->switchPlayer();
    }
}

void GameMachine::playOneMove()
{
    bool ok = false;
    if (print)
    {
        this->playingField->print();
    }
    std::array<std::array<int, 7>, 6> currentField = this->playingField->copyField();
    bool chooseOther = false;
    while (!ok && !this->playingField->isFull())
    {
        int col = 0;
        if (chooseOther)
        {
            col = this->currentPlayer->chooseOtherColumn();
        }
        else
        {
            col = this->currentPlayer->play(this->playingField);
        }
        ok = this->playingField->setStone(col, this->currentPlayer->name);
        if (ok)
        {
            this->currentPlayer->saveMove(currentField, col);
        }
        else
        {
            chooseOther = true;
        }
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
